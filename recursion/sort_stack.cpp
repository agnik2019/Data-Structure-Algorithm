#include<iostream>
#include<stack>
using namespace std; 
void insert(stack<int> &v, int temp)
{
    if(v.size()==0 || v.top() <=temp)
    {
        v.push(temp);
        return;
    }
    int val = v.top();
    v.pop();
    insert(v,temp);
    v.push(val);
    return;
}
void sortStack(stack<int> &v)
{
    if(v.size()==1) return;
    int temp = v.top();
    v.pop();
    sortStack(v);
    insert(v,temp);
}
int main()
{
    stack<int> st;;
    st.push(5);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(1);
    sortStack(st);
    while(!st.empty())
    {
        cout<<st.top()<<" ";
        st.pop();
    }
    return 0;
}