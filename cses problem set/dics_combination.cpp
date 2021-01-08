/*By AGNIK SAHA */

#include<bits/stdc++.h>
using namespace std;

#define ll				long long int
#define ld				long double
#define mod 			1000000007
#define inf 			1e18 
#define ff              first
#define ss              second
#define int             long long
#define pb              push_back
#define mp              make_pair
#define pii             pair<int,int>
#define ump				unordered_map
#define vi              vector<int>
#define mii             map<int,int>
#define pq_max          priority_queue<int>
#define pq_min          priority_queue<int,vi,greater<int> >
#define loop(i,a,b)		for(int i =(a); i<=(b); i++)
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
    int n;
    cin>>n;
   	vector<int> dp(n+1,0);
   	dp[0]=dp[1]=1;
   	loop(i,2,n)
   	{
   		loop(j,1,6)
   		{
   			if(j>i) continue;
   			dp[i] = (dp[i]+dp[i-j])%mod;
   		}
   	}
   	cout<<dp[n]%mod;
   	return 0;
}