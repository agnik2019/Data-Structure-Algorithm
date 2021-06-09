int Solution::singleNumber(const vector<int> &A) {
    vector<int> f(32,0);
    for(int e : A)
    {
        for(int i = 0;i<32;i++)
            if(e & (1<<i)) f[i]++;
    }
    int res = 0; 
    for(int i =0;i<32;i++)
        if(f[i] % 3 == 1) res+= (1<<i);
    return res;
}
