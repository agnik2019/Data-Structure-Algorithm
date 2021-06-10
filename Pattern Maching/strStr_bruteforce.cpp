int Solution::strStr(const string A, const string B) {
int m=A.length(),n=B.length();

for(int i=0;i<=m-n;i++)
{   int j=0;
    for(;j<n;j++)
    if(B[j]!=A[i+j])break;
    
    if(j==n)
    return i;
}
return -1;
}