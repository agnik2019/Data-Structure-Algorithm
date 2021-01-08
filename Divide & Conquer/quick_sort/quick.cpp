#include<iostream>
using namespace std;
#include <vector>

int partition(vector<int> &A,int l,int h)
{
    int pivot=A[l];
    int i=l,j=h;
    while(i<j)
    {
        while(A[i]<=pivot){i++; }
        while(A[j]>pivot){j--;}
        if(i<j) swap(A[i],A[j]);
    }
    swap(A[l],A[j]);
    return j;
}
void QuickSort(vector<int> &A, int l,int h)
{
    int j;
    if(l<h)
    {
        j=partition(A,l,h);
        QuickSort(A,l,j);
        QuickSort(A,j+1,h);
    }
}
int main()
{
    vector<int> A={11,13,7,12,16,9,24,5,10,3};

    int n=A.size();
  
    QuickSort(A,0,n);
    for(int i=0; i<n;i++)
    cout<<A[i]<<endl;
    return 0;
}