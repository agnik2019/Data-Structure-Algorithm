class Solution {
public:
    int compress(vector<char>& chars) {
        int i=0;
        int j = 0;
        while(i<chars.size())
        {
            char now = chars[i];
            chars[j++]= chars[i++];
            int count = 1;
                while(i<chars.size() && (now == chars[i])) 
                {
                    i++;
                    count++;
                }
            if(count > 1)  {
                for(char digit : to_string(count))
                chars[j++] = digit;
            }  
            
        }
        return j;
        
    }
};