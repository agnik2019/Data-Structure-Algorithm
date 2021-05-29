int Solution::adjacent(vector<vector<int> > &A) {
    int include_element = max(A[0][0],A[1][0]);
    int exclude_element = 0;
    for(int i=1;i<A[0].size();i++){
        int temp = include_element;
        include_element = max(A[0][i],A[1][i]) + exclude_element;
        exclude_element = max(temp,exclude_element);
    }
    return max(include_element,exclude_element);
}
