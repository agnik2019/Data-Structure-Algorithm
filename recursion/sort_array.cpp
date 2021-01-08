#include<iostream>
#include<vector>
using namespace std; 
void insert(vector<int> &v, int temp)
{
    if(v.size()==0 || v[v.size()-1]<=temp)
    {
        v.push_back(temp);
        return;
    }
    int val = v[v.size()-1];
    v.pop_back();
    insert(v,temp);
    v.push_back(val);
    return;
}
void sortArr(vector<int> &v)
{
    if(v.size()==1) return;
    int temp = v[v.size()-1];
    v.pop_back();
    sortArr(v);
    insert(v,temp);
}
int main()
{
    vector<int> v={2,1,4,2,5,9,6};
    sortArr(v);
    for(int i : v)
        cout<<i<<" ";
    return 0;
}