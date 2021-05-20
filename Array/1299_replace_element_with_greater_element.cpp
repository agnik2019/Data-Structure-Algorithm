#include<iostream>
#include<vector>
using namespace std;
#include<algorithm>
// 1299. Replace Elements with Greatest Element on Right Side


    vector<int> replaceElements(vector<int>& arr) {
        int mx = -1;
        for(int i = arr.size()-1; i>=0; i--)
        {
            int temp = arr[i];
            arr[i] = mx;
            mx = max(mx,temp);
        }
        return arr;
    }

    int main(){
        vector<int> arr = {17,18,5,4,6,1};
        vector<int> res = replaceElements(arr);
        for(int i = 0; i< res.size(); i++)
            cout<< res[i]<<" ";
        return 0;
    }