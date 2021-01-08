#include<iostream>
using namespace std;
void print_decrease(int n)
{
    if(n==0){return;} 
    cout<<n<<" ";
    print_decrease(n-1);
}
int main()
{
    int n;
    cin>>n;
    
    print_decrease(n);
    
}