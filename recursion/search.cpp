//find firsr & last occurance of a number
//return the index
#include<iostream>
using namespace std;

int first_ocur(int arr[],int n,int i, int key)
{
    if(i==n) return -1;
    if(arr[i] == key) return i;
    return first_ocur(arr,n,i+1,key);
}

int last_ocur(int arr[],int n,int i, int key)
{
    if(i==n) return -1; //base condition
    int restArray = last_ocur(arr,n,i+1,key);
    if(restArray != -1) return restArray;
    if(arr[i] == key) return i;
    return -1;
}
int main()
{
    int arr[]={5,7,3,4,2,3,1};
    cout<<first_ocur(arr,7,0,3)<<endl;
    cout<<last_ocur(arr,7,0,3)<<endl;
    return 0;
}