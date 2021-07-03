class Solution {
public:
    int nthUglyNumber(int n) {
        if(n <= 0) return 0;
        if(n ==1) return 1;
        vector<int> ugly(n);
        ugly[0] = 1;
        int t2=0, t3=0,t5 = 0; // pointers to t2, t3, t5
        for(int i = 1; i<n; i++)
        {
            ugly[i] = min(min(ugly[t2]*2, ugly[t3]*3), ugly[t5]*5);
            if(ugly[i] == ugly[t2]*2) t2++;
            if(ugly[i] == ugly[t3]*3) t3++;
            if(ugly[i] == ugly[t5]*5) t5++;
        }
        return ugly[n-1];
    }
};