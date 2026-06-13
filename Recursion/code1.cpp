#include<iostream>
using namespace std;
void printnumber(int n)
{
    if(n==1)
    {
        cout<<1<<endl;
        return;
    }
    cout<<n<<" ";
    printnumber(n-1);
}
int main()
{
    printnumber(100);
    return 0;
}