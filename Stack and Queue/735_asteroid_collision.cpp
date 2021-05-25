class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        for(int val : asteroids)
        {
            if(val>0) st.push(val);
            else
            {
                while(!st.empty() and st.top()>0 and st.top() < abs(val))
                    st.pop();
                if(!st.empty() and st.top() == abs(val))
                    st.pop();
                else if(!st.empty() and st.top() > abs(val))
                    continue;
                else 
                    st.push(val);
            }
        }
        vector<int> res(st.size());
        for(int i = st.size()-1; i>=0; i--){
            res[i] = st.top();
            st.pop();
        }
        return res;
        
    }
};