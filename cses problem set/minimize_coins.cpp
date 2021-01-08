/*By AGNIK SAHA */

#include<bits/stdc++.h>
using namespace std;

#define ll                long long int
#define ld                long double
#define mod             1000000007
#define inf             1e18 
#define ff              first
#define ss              second
#define int             long long
#define pb              push_back
#define mp              make_pair
#define pii             pair<int,int>
#define ump                unordered_map
#define vi              vector<int>
#define mii             map<int,int>
#define pq_max          priority_queue<int>
#define pq_min          priority_queue<int,vi,greater<int> >
#define loop(i,a,b)        for(int i =(a); i<=(b); i++)
#define loopprev(i,a,b) for(int i =(a); i<=(b); i--)            

 
void file_i_o()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}
 
int32_t main()
{
    file_i_o();
    int n,x;
    cin>>n>>x;
    vector<int>dp(x+1,INT_MAX);
    dp[0] = 0;
    vector<int> coins(n);
    loop(i,0,n-1) cin>>coins[i];
    loop(i,1,x)
    {
        loop(j,0,n-1)
        {
            if(coins[j]>i) continue;
            dp[i] = min(dp[i],1+dp[i-coins[j]]);
        }
    }
    if(dp[x] == INT_MAX) cout<<-1;
    else 
        cout<<dp[x];
    return 0;
}