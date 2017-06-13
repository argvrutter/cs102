#ifndef PRACTICE_H
#define PRACTICE_H

class practice
{
    static practice* ms_instance;

public:
    static practice* Instance();
    static void Release();

private:
    practice();
    ~practice();

};

#endif // PRACTICE_H
