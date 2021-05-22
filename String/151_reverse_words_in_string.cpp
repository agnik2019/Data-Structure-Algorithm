class Solution {
public:
    string reverseWords(string s) {
        vector<string> tmp;
        string f;
        for(int i = 0; i<s.length(); i++)
        {
            if(s[i]!= ' ')
                f += s[i];
            else{
                if(f.size() != 0)
                {
                    tmp.push_back(f);
                    f.clear();
                }
            }
                
        }
        if(f.size() != 0) tmp.push_back(f);
        s.clear();
        for(int i = tmp.size()-1; i>0 ; i--)
        {
            s+= tmp[i];
            s+= " ";
        }
        s+= tmp[0];
         return s;
        
    }
};