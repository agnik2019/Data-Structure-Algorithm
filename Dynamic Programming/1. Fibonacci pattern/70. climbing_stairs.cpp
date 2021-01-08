class Solution {
public:
    int climbStairs(int n) {
        if(n == 1) return 1;   
        vector<int> fibo(n);

        fibo[0]= 1;
        fibo[1] = 2;
        for(int i = 2; i<n; i++)
            fibo[i] = fibo[i-1] + fibo[i-2];
        return fibo[n-1];
        
    }
};