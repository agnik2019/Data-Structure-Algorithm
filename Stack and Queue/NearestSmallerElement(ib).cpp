vector<int> Solution::prevSmaller(vector<int> &A) {
    stack<int> st;
    vector<int> res(A.size());
    for(int i=0;i<A.size();i++)
    {
        while(st.size()>0 && st.top() >= A[i])
            st.pop();
        res[i] = st.size()>0 ? st.top():-1;
        st.push(A[i]);
    }
    return res;
}
