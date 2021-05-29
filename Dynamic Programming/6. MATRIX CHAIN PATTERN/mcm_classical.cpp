using namespace std;
#include<iostream>
#include<algorithm>
#include <cstring>
#define INT_MAX 2147483647
int static t[1001][1001];
int mcm(int arr[], int i, int j)
{
    if(i>=j) return 0;
    if(t[i][j] != -1) return t[i][j];
    int mn = INT_MAX;
    for(int k = i; k<j; k++)
    {
        int tempAns = mcm(arr,i,k)+mcm(arr,k+1,j)+arr[i-1]*arr[k]*arr[j];
        mn = min(tempAns,mn);
    }
    t[i][j] = mn;
    return t[i][j];
}

int main(){
    int arr[] = { 1, 2, 3, 4, 3 };
    int n = sizeof(arr) / sizeof(arr[0]);
    memset(t,-1, sizeof(t));
 
    cout << "Minimum number of multiplications is "
         << mcm(arr, 1, n - 1);

    return 0;
}