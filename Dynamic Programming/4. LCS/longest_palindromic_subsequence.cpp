/*
Problem Description

Given a string A, find the common palindromic sequence ( A sequence which does not need to 
be contiguous and is a pallindrome), which is common in itself.

You need to return the length of longest palindromic subsequence in A.

NOTE:

Your code will be run on multiple test cases (<=10). Try to come up with an optimised solution.


Problem Constraints
1 <= |A| <= 1005



Input Format
First and only argument is an string A.



Output Format
Return a integer denoting the length of longest palindromic subsequence in A.

*/


int LCS(string A,string B)
{
    int m = A.length();
    int n = A.length();
    //vector<vector<int>> lcs(0,vector<int>(0));
    int lcs[m+1][n+1];
    for(int i = 0; i<=m;i++)
    {
        for(int j = 0; j<=n;j++)
        {
            if(i == 0 || j==0)
                lcs[i][j]=0;
        }
    }
    for(int i = 1; i<=m;i++)
    {
        for(int j = 1; j<=n;j++)
        {
            if(A[i-1] == B[j-1])
                lcs[i][j] = 1+lcs[i-1][j-1];
            else
                lcs[i][j]= max(lcs[i-1][j],lcs[i][j-1]);
        }
    }
    return lcs[m][n];
}
int Solution::solve(string A) {
    string B=A;
    reverse(B.begin(),B.end());
    return LCS(A,B);
}