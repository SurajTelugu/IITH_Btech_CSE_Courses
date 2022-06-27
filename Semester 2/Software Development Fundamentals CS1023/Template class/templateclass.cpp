#include <iostream>
#include "student_record_t.h"

int main()
{
    student_record_t details("SURAJ",180);
    std::cout<<details.getname()<<":"<<details.getheight()<<std::endl;
    return 0; 
}