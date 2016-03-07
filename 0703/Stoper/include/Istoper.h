#ifndef ISTOPER_H
#define ISTOPER_H


class Istoper
{
    public:
        Istoper();
        virtual ~Istoper();
        double getElapsedTime();

    private:
    int dumpToFile();
};

#endif // ISTOPER_H
