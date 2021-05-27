using namespace std;
#include<iostream>
#include<vector>
int ceilOfArray(vector<int> &A, int B) {
  
    int l = 0;
    int h = A.size()-1;
    while(l<= h)
    {
        int mid = l+(h-l)/2;
        if(A[mid] == B) return mid;
        else if(A[mid]<B) l = mid+1;
        else h = mid-1;
    }
    return l;
}
int floorOfArray(vector<int> &A, int B) {
  
    int l = 0;
    int h = A.size()-1;
    while(l<= h)
    {
        int mid = l+(h-l)/2;
        if(A[mid] == B) return mid;
        else if(A[mid]<B) l = mid+1;
        else h = mid-1;
    }
    return h;
}
int main(){
    vector<int> arr = {2,6,9,14,33};
    cout<<"Ceil of the array(index) "<<ceilOfArray(arr,5)<<endl;
    cout<<"floor of the array(index) "<<floorOfArray(arr,5)<<endl;;
    return 0;
}
