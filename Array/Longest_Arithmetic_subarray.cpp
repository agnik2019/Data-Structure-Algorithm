#include<iostream>>
using namespace std;
#include<vector>
#include<algorithm>
int LongesrArithmeticSubarray(const vector<int> &A) {
    int ans = 2;
    int pd = A[1]-A[0];
    int j = 2;
    int curr = 2;
    while(j<A.size())
    {
        if(pd == A[j]-A[j-1])
            curr++;
        else
        {
            pd = A[j]-A[j-1];
            curr = 2;
        }
        ans = max(ans, curr);
        j++;
    }
    return ans;
}
