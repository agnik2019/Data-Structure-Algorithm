using namespace std;
#include<iostream>
#include<vector>
#include<string>
int p = 31;
const int N = 1e5+7, mod = 1e9+7;
vector<long long> power(N);
int main(){

    string t = "agniksahannik";
    string s = "nik";
    int T = t.size(), S= s.size();
    power[0] = 1;
    for(int i = 1; i<N; i++)
        power[i] = (power[i-1]*p)%mod;

    vector<long long> h(T+1,0);
    for(int i = 0; i<T;i++)
        h[i+1] = (h[i]+(t[i]-'a'+1)*power[i])%mod;
    long long h_s = 0;
    for(int i = 0; i<S; i++)
        h_s = (h_s+(s[i]-'a'+1)*power[i])%mod;

    for(int i = 0; i+S-1<T; i++)
    {
        long long cur_hash = (h[i+S]-h[i]+mod)%mod;
        if(cur_hash == (h_s*power[i])%mod)
            cout<<i<<" ";
    }
    return 0;
}