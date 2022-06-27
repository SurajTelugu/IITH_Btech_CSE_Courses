#include "student_record_t.h"

student_record_t :: student_record_t(const std::string& _name,const unsigned& _height)
{
    name = _name ;
    height = _height ;

}

 std::string student_record_t ::  getname() {return name;}
 unsigned    student_record_t :: getheight() {return height;}
