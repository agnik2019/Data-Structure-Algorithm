class Solution {
public:
    int largestRectangleArea(vector<int>& h) {
        int n= h.size();
        if(n==1)
            return h[0];
        vector<int> lb(n,-1); // next smaller element of left
        vector<int> rb(n,n); //next smaller element on right
        stack<int> st;    //Monotonic stack
        for(int i=0;i<n;i++){
            while(!st.empty() && h[st.top()] >=h[i])
                st.pop();
            if(!st.empty())
                lb[i] = st.top();
            st.push(i);
        }
        while(!st.empty()) st.pop();
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && h[st.top()] >=h[i]){
                st.pop();
            }
            if(!st.empty())
                rb[i] = st.top();
            st.push(i);
        }
        int maxi = INT_MIN;
        for(int i=0;i<n;i++){
            maxi = max(maxi,(rb[i]-lb[i]-1)*(h[i]));
        }
            
        return maxi;
    }
};
