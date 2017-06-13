#ifndef CASE4_H
#define CASE4_H

class case4
{
    static case4* ms_instance;

public:
    static case4* Instance();
    static void Release();

private:
    case4();
    ~case4();

};

#endif // CASE4_H
