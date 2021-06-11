using namespace std;
#include<iostream>

void bubble(int arr[], int n)
{
    for(int counter = 1; counter<n; counter++)
    {
        for(int i = 0; i<n-counter; i++)
        {
            if(arr[i]>arr[i+1])
                swap(arr[i], arr[i+1]);        
        }
    }

}
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++)
        cin>> arr[i];
    bubble(arr,n);
    for(int i =0; i<n; i++)
        cout<<arr[i]<<" ";
}