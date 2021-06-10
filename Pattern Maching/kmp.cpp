class Solution {
public:
    void computeLPStable(string pat, int* lps)
    {
        int plen = pat.length();
        int i = 1, len = 0;
        lps[0] = 0;
        while(i< plen)
        {
            if(pat[i] == pat[len])
            {
                len++;
                lps[i++] = len;
            }
            else{
                if(len) len = lps[len-1];
                else lps[i++] = 0;
            }
        }
    }
    int kmp(string  text, string pattern)
    {
        int plen = pattern.length();
        int tlen = text.length();
        if(plen == 0) return 0;
         int lps[100000];
        computeLPStable(pattern, lps);
        int tindex = 0;
        int pindex = 0;
        while(tindex < tlen)
        {
            if(pattern[pindex] == text[tindex])
            {
                pindex++;
                tindex++;
            }
            if(pindex == plen)
            {
                return tindex-pindex;
                pindex = lps[pindex-1];
            }
            else if(tindex<tlen && pattern[pindex] != text[tindex])
            {
                if(pindex) pindex = lps[pindex-1];
                else tindex++;
            }
        }
        return -1;
    }
    int strStr(string haystack, string needle) {
        return kmp(haystack,needle);
    }
};