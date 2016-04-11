#pragma once

#include <string>

class HashTab
{
public:
virtual void hash(int hash_size);
virtual int &operator [] (const char *);
};
