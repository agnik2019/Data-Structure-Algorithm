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
        int m = needle.length();
        int n = haystack.length();
        int s = 0;
        int hashtable[256];
        fillHashTable(haystack,hashtable);
        while( s<= (n-m))
        {
            int j = m-1;
            while(j >= 0 && needle[j] == haystack[s+j])
                j--;
            if(j<0)
            {
                return s;
                s += (s+m < n) ? m-hashtable[haystack[s+m]]:1;
            }
            else
                s += max(1, j-hashtable[haystack[s+j]]);
        }
        return -1;
    }
};