#include "test.h"
#include <cstdlib> // NULL 

test* test::ms_instance = NULL;

test::test()
{
}

test::~test()
{
}

test* test::Instance()
{
    if (ms_instance == NULL) {
        ms_instance = new test();
    }
    return ms_instance;
}

void test::Release()
{
    if (ms_instance) {
        delete ms_instance;
    }
    ms_instance = NULL;
}

