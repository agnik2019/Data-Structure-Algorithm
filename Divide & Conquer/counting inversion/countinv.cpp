#include<iostream>
#include<vector>
using namespace std;


// Complete the countInversions function below.
long merge(vector<int> arr, long left, long mid, long right)
{
    long i = left,j = mid, k= 0, count = 0;
    vector<int> temp(right-left+1);
    while(i<mid && j<= right)
    {
        if(arr[i] <= arr[j])
        {
            temp[k++]= arr[i++];
        }
        else{
            temp[k++]= arr[j++];
            count += mid-i;
        }
    }
    while(i<mid) temp[k++]=arr[i++];
    while(j<right) temp[k++] = arr[j++];
    for(int i = left, k = 0; i<=right; i++,k++)
        arr[i] = temp[k];
    return count;
}
long mergesort(vector<int> arr, long left, long right)
{
    while(right > left)
    {
        long mid = (left+right)/2;
        long left_count = mergesort(arr,left,mid);
        long right_count = mergesort(arr,mid+1, right);
        long mycount = merge(arr,left,mid,right);
        return left_count+right_count+mycount;
        
    }
    return 0;
    
}


long countInversions(vector<int> arr) {
    long left = 0;
    long right = arr.size()-1;
    return mergesort(arr,left,right);
}
int main()
{
    vector<int> A={2,1,4,6,8};
    return countInversions(A);
}