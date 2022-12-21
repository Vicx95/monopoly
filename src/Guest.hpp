#pragma once
#include <cstdio>

using Money = unsigned int;

class Guest {
public:
    virtual void addMoney(Money amount) = 0;
    virtual void substractMoney(Money amount) = 0;
};