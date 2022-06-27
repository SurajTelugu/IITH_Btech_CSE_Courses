#include <iostream>
#include <math.h>

using namespace std;

int main()
{
  unsigned sales_amnt;
   float disnt,fin_amnt;
  
  cout<<"Enter sales amount:";
  cin>>sales_amnt;

  if(sales_amnt > 5000)
  {
    disnt = 0.1 * sales_amnt;
    fin_amnt = sales_amnt - disnt;
    cout<<"Final price of product is "<<fin_amnt<<endl;
  }

  else
  {
    disnt = 0.05 * sales_amnt;
    fin_amnt = sales_amnt - disnt;
    cout<<"Final price of product is "<<fin_amnt<<endl;
  }


 return 0;
}