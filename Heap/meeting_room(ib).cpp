/*
Problem Description

Given an 2D integer array A of size N x 2 denoting time intervals of different meetings.

Where:

A[i][0] = start time of the ith meeting.
A[i][1] = end time of the ith meeting.
Find the minimum number of conference rooms required so that all meetings can be done.

*/
bool compare (vector<int> a,vector<int> b)
{
    return a[0]<b[0];
}
int Solution::solve(vector<vector<int> > &A)
{
    sort(A.begin(),A.end(),compare); //sort according to starting time
    priority_queue<int,vector<int>,greater<int>> pq; //min heap
    pq.push(A[0][1]);  //insert ending time in minheap
    for(int i=1;i<A.size();i++)
    {
        int top = pq.top();
        if(A[i][0]>=top){
            pq.pop();
        }
        pq.push(A[i][1]);
    }
    return pq.size();
}
