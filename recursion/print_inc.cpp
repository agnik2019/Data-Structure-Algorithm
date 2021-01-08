#include<iostream>
using namespace std;
void print_inc(int n)
{
    if(n==1) {
        cout<<"1"<<endl;
        return ;
    }
    print_inc(n-1);
    cout<<n<<endl;
}
int main()
{
    int n;
    cin>>n;
    print_inc(n);
    return 0;
}