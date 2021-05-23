class Solution {
public:
    int maxPower(string s) {
        char prev = ' ';
        int maxLength = 0;
        int count = 0;
        for(int i = 0; i<s.length(); i++)
        {
            if(s[i] == prev){
                count++;
            }
            else {
                count = 1;
                prev = s[i];
            }
            maxLength = max(count, maxLength);
        }
        return maxLength;
    }
};