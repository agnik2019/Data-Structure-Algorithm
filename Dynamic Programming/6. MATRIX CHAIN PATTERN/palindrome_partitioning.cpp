int static t[1001][1001];
bool ispalindrome(string s, int i, int j)
{
    if(i==j || i>j) return true;
    while(i<j)
    {
        if(s[i]!=s[j]) return false;
        i++;
        j--;
    }
    return true;
}
int palinpart(string s, int i, int j)
{
    if(i>=j) return 0;
    if(ispalindrome(s,i,j)== true) return 0;
    
    if(t[i][j]!=-1) return t[i][j];
    int mn = INT_MAX;
    int left,right;
    for(int k = i;k<= j-1; k++)
    {
       // int temp = 1+palinpart(s,i,k)+palinpart(s,k+1,j);
       if(t[i][k] != -1) left = t[i][k];
       else{
           left = palinpart(s, i,k);
           t[i][k] = left;
       }
      if(t[k+1][j] != -1) right = t[k+1][j];
       else{
           right = palinpart(s, k+1,j);
           t[k+1][j] = right;
       }
       
       
       int temp = 1+left+right;
       if(temp<mn) mn = temp;
      
    }
      return t[i][j] = mn;
    
}
int Solution::minCut(string A) {
    memset(t,-1,sizeof(t));
    return palinpart(A,0,A.length()-1);
    
}
