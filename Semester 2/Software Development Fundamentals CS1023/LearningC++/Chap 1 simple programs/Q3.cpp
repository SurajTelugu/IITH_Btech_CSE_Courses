#include <iostream>
using namespace std;

int main()
{
 unsigned prpl_amnt,t; /*Time in years*/
 float i,fin_amnt; 

 cout <<"Enter principal amount taken:";
 cin>>prpl_amnt;
 cout <<"Enter intrest added per year:";
 cin>>i;
 cout <<"Enter time:";
 cin>>t;

 fin_amnt = prpl_amnt + prpl_amnt*i*t*0.01 ;

 cout << "The final amount after adding intrest is:"<<fin_amnt<<endl;



return 0;
}