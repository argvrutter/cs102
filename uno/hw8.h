#ifndef HW8_H
#define HW8_H

class hw8
{
    static hw8* ms_instance;

public:
    static hw8* Instance();
    static void Release();

private:
    hw8();
    ~hw8();

};

#endif // HW8_H
