#include<bits/stdc++.h>
 int oddpower(int n)
{
  int i=1;
  while(pow(2,i)<=n) i+=2;
  return i-2;
}
using namespace std;
int main()
{
int n,diff,x,flag=0,k=1,t;
cin>>t;
while(t--)
{
cin>>n>>x;
diff=n-pow(2,oddpower(n));
if(n==x) cout<<1<<endl;
else if(diff!=0&&x==0) cout<<-1<<endl;
else if(diff==0) cout<<1<<endl;
else
{
while(diff>=0)
{
    if(diff<=x)
    {
        flag=1;
        break;
    }
    diff-=pow(2,oddpower(diff));
    k++;
}
if(flag==1) cout<<k+1<<endl;
else cout<<-1<<endl;
}
}
return 0;
}
