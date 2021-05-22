class Solution {
public:
    int myAtoi(string s) {
        int i=0;
        while (s[i] == ' ') { i++; }
        int flag = 1;
        if(s[i] == '-') {flag = 0; i++;}
        else if(s[i] == '+') {flag = 1; i++;}
        
        long long int sum = 0;
        for(; i<s.length(); i++)
        {
            if(s[i] >= '0' && s[i] <= '9' )
                sum = sum*10 + (s[i]-'0');
            else break;
            if(sum>INT_MAX)
                return flag==0?INT_MIN:INT_MAX;
        }
        
      if(flag==0)return -1*(int)sum;
        else return (int)sum;

        
    }
};