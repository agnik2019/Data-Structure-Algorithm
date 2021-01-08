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
    // vector<vector<int>> arr(n, vector<int>(n,0));
     int arr[n][n];
     loop(i,0,n-1)
     {
     	loop(j,0,n-1)
     	{
     		char ch;
     		cin>>ch;
     		arr[i][j]= (ch == '.')?0:1;
     	}
     }

   // vector<vector<int>> dp(n, vector<int>(n,0));
     int d[n][n];
     loopprev(i,n-1,0)
     {
     	loopprev(j,n-1,0)
     	{
     		if(i == n-1 && j == n-1 ) dp[i][j]= 1;
     		else 
     			{
     				int op1 = (j==n-1)? 0 : dp[i][j+1];
     				int op2 = ( i==n-1 ) ? 0 : dp[i+1][j];
     				dp[i][j] = (op1+op2)%mod;

     				if(arr[i][j]) dp[i][j] = 0;
     			}
     	}
     
     }

     if(arr[n-1][n-1]) cout<<0;
     else cout<<dp[0][0];
     return 0;
 }