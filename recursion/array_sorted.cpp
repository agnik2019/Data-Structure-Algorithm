#include<iostream>
using namespace std;
bool array_sorted(int arr[],int n)
{
    if(n==1) return true;
    bool restArray = array_sorted(arr+1,n-1);
    return (arr[0]<arr[1] && restArray);
}
int main(){
    int arr[] = {2,4,9,6,8};
    cout<<array_sorted(arr,8)<<endl;
    return 0;
}