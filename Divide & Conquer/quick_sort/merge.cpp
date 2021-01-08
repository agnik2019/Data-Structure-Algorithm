#include<iostream>
using namespace std;
#include<vector>
void merge(vector<int> &a, int l, int mid, int h)
{
    vector<int> b(h+1);
    int i = l, j=mid+1, k =l;
    while(i<= mid && j<=h)
    {
        if(a[i]<a[j]) b[k++] = a[i++];
        else b[k++] = a[j++];
    }
    for(;i<=mid; i++) b[k++]= a[i];
    for(;j<=h; j++) b[k++]= a[j];
    for(int i=l;i<=h; i++) a[i] = b[i];
}

void mergesort(vector<int> &A, int l, int h)
{
    if(l<h)
    {
        int mid = (l+h)/2;
        mergesort(A,l,mid);
        mergesort(A, mid+1,h);
        merge(A,l,mid,h);
    }
}

int main()
{
    vector<int> a={29,4,56,76,8,9};
    mergesort(a, 0, a.size());
    
    for(int i = 0; i< a.size(); i++)
        cout<<a[i]<<" ";
    return 0;
}