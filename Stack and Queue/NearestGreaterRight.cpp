using namespace std;
#include<iostream>
#include<vector>
#include<stack>

vector<int> NGR(vector<int> nums)
{
    vector<int> res(nums.size());
    stack<int> st;
    for(int i = nums.size()-1; i>= 0; i--)
    {
        while(st.size() > 0 && st.top() < nums[i]) st.pop();
        res[i] = st.size()>0 ? st.top() : -1;
        st.push(nums[i]);
    }
    return res;
}

int main(){
    vector<int> v = {5,4,8,3,1,2};
    cout<<" Next Greater elements " <<" ";
    vector<int> res =  NGR(v);
    for(int r : res)
        cout<< r<<" ";
    return 0;
}