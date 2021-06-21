#include<iostream>
using namespace std;
#define int long long
const int N = 1e5+2, MOD = 1e9+7;
// ax+by = gcd(a,b)
struct triplet{
    int x,y,gcd;
};

triplet extended_euclid(int a, int b)
{
    if(b == 0)
    {
        triplet ans;
        ans.x = 1;
        ans.gcd = 1;
        ans.y = 0;
        return ans;
    }
    triplet smallAns = extended_euclid(b,a%b);
    triplet ans;
    ans.gcd = smallAns.gcd;
    ans.x = smallAns.y;
    ans.y = smallAns.x - (a/b)*smallAns.y;
    return ans;
}

signed main(){
    int a,b;
    cin>>a>>b;
    triplet ans = extended_euclid(a,b);
    cout<<ans.gcd <<" "<<ans.x<<" "<<ans.y<<endl;
    return 0;
}