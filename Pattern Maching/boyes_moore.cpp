class Solution {
public:
    //we wil implement this using boyer moore algorithm
    void fillHashTable(string s,int hashtable[256])
    {
        for(int i = 0; i< 256; i++)
            hashtable[i] = -1;
        for(int i = 0; i< s.length(); i++)
            hashtable[(int)s[i]] = i;
    }
    int strStr(string haystack, string needle) {
        int S = needle.length();
        int T = haystack.length();
        int i = 0;
        int hashtable[256];
        fillHashTable(haystack,hashtable);
        while( i<= (T-S))  //n-m
        {
            int j = S-1;
            while(j >= 0 && needle[j] == haystack[i+j])
                j--;
            if(j<0)
            {
                return i;
                i += (i+S < T) ? S-hashtable[haystack[i+S]]:1;
            } 
            else
                i += max(1, j-hashtable[haystack[i+j]]);
        }
        return -1;
    }
};