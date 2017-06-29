﻿#ifndef TRACER_HPP
#define TRACER_HPP

#include <cstdio>

class Trace
{
public:
    Trace()
    {
        std::printf("Trace() at %p\n", this);
        m_dynamic = new int[4];
        size = 4;
    }

    Trace(const Trace&)
    {
        std::printf("Trace(const Trace&) at %p\n", this);
        m_dynamic = new int[4];
        size = 4;
    }

    Trace(Trace&& _another)
    {
        std::printf("Trace(Trace&&) at %p\n", this);
        m_dynamic = _another.m_dynamic;
        size = _another.size;
        _another.m_dynamic = nullptr;
        _another.size = 0;
    }

    Trace& operator= (const Trace&)
    {
        delete[] m_dynamic;
        std::printf("Operator= at %p\n", this);
        m_dynamic = new int[4];
        size = 4;

        return *this;
    }

    ~Trace()
    {
        std::printf("~Trace() at %p\n", this);
        delete[] m_dynamic;
    }

    bool operator!= (const Trace&) const { return false; }
    bool operator== (const Trace&) const { return true; }

private:
    int *m_dynamic = nullptr;
    size_t size;
};

class NoCopy
{
public:
    NoCopy() = default;
    ~NoCopy() = default;
private:
    NoCopy(const NoCopy&);
};

#endif
