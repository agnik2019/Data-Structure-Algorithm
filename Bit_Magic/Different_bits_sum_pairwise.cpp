#include<iostream>
#include<vector>
using namespace std;
// BRute forece solution
int countsetBit(int n){
    int count = 0;
    while(n){
        n &= (n-1);
        count++;
    }
    return count;
}
int cntBits(vector<int> &A) {
    int res = 0;
    for(int i = 0; i<A.size(); i++)
    {
        for(int j = 0; j<A.size(); j++)
        {
           int x = A[i]^A[j];
           res+= countsetBit(x);
        }
    }
    return res;
}

// Efficient solution
int cntBits2(vector<int> &A) {
        long long int ans=0,n=A.size();
        long long int count;
        for(int i=0;i<31;i++){
            count=0;
            for(int j=0;j<n;j++){
                if(A[j]&(1<<i))
                 count++;
            }
            ans=(ans+count*(n-count)*2)%1000000007;
        }
        return ans;
}

int main(){
    vector<int> ip={1,3,5};
    int res = cntBits(ip);
    cout<< res<<endl;
    return 0;
}
