#ifndef TEST_H
#define TEST_H

class test
{
    static test* ms_instance;

public:
    static test* Instance();
    static void Release();

private:
    test();
    ~test();

};

#endif // TEST_H
