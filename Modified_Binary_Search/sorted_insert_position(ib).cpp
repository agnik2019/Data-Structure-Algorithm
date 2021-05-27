/*
Problem Description

Given a sorted array A and a target value B, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You may assume no duplicates in the array.



**Problem Constraints**
1 <= |A| <= 100000

1 <= B <= 109



**Input Format**
First argument is array A.

Second argument is integer B.



**Output Format**
Return an integer, the answer to the problem.

*/

int Solution::searchInsert(vector<int> &A, int B) {
  
    int l = 0;
    int h = A.size()-1;
    while(l<= h)
    {
        int mid = l+(h-l)/2;
        if(A[mid] == B) return mid;
        else if(A[mid]<B) l = mid+1;
        else h = mid-1;
    }
    return l;
}
