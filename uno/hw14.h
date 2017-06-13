#ifndef HW14_H
#define HW14_H

class hw14
{
    static hw14* ms_instance;

public:
    static hw14* Instance();
    static void Release();

private:
    hw14();
    ~hw14();

};

#endif // HW14_H
