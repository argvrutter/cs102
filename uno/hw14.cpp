#include "hw14.h"
#include <cstdlib> // NULL 

hw14* hw14::ms_instance = NULL;

hw14::hw14()
{
}

hw14::~hw14()
{
}

hw14* hw14::Instance()
{
    if (ms_instance == NULL) {
        ms_instance = new hw14();
    }
    return ms_instance;
}

void hw14::Release()
{
    if (ms_instance) {
        delete ms_instance;
    }
    ms_instance = NULL;
}

