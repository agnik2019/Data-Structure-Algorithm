class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> mp(26);
        vector<bool> visited(26,false);
        stack<char> st;
        for(int i = 0; i<s.length(); i++)
        {
            mp[s[i]-'a']++;
        }
        for(int i = 0; i<s.length(); i++)
        {
            mp[s[i]-'a']--;
            if(visited[s[i]-'a']) continue;
            while(st.size() > 0 && st.top()>s[i] && mp[st.top()-'a'] > 0)
            {
                char rem = st.top();st.pop();
                visited[rem-'a'] = false;
            }
            st.push(s[i]);
            visited[s[i]-'a'] = true;
        }
        string ans = "";
        while(!st.empty()){
            ans+= st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
            
    }
};