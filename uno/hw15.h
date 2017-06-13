#ifndef HW15_H
#define HW15_H

class hw15
{
    static hw15* ms_instance;

public:
    static hw15* Instance();
    static void Release();

private:
    hw15();
    ~hw15();

};

#endif // HW15_H
