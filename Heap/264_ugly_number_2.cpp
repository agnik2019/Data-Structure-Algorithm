class Solution {
public:
    int nthUglyNumber(int n) {
        set<long long> s;
        n--;
        long long x = 1;
        while(n--)
        {
            s.insert(x*2);
            s.insert(x*3);
            s.insert(x*5);
            x = *(s.begin());
            s.erase(s.begin());
        }
        return (int)x;
    }
};