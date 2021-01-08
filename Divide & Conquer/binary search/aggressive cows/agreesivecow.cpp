#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool isvalid(long long stalls[],int n, int cows, long long distance)
{
    int last_pos = stalls[0];
    int count = 1;
    for(int i = 1; i< n; i++)
    {
        if(stalls[i] -last_pos >= distance)
        {
            last_pos = stalls[i];
            count++;
        }
        if(count == cows)
                return true;
    }
    return false;
}

int main()
{
    int t; //test cases
    int n,c;
    cin>>t;
    while(t--)
    {
        cin>>n>>c;
        long long arr[n];
        for (int i = 0; i < n; i++)
        {
           cin>> arr[i] ;
        }
        sort(arr, arr+n);
    long long start = 0;
    long long end = arr[n-1]-arr[0];
    long long ans = -1;
    while(start <= end)
    {
        long long mid = end + (start-end)/2;
        if(isvalid(arr,n,c,mid)){
           ans = mid;
           start = mid+1;
        }
        else
        {
           end = mid-1;
        }
        
    }
    cout<< ans <<endl;
    }
    return 0;

}