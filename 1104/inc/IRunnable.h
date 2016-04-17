#pragma once

class IRunnable
{
public:
   virtual bool prepare(int size) = 0;
   virtual bool run() = 0;
};
