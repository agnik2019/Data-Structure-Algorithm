const int MOD = 1e9 + 7;
class Solution {
public:

    int maximumGap( vector<int> &A) 
    {
        if(A.size()<=1) return 0;
        priority_queue<int> pq;
        for(int i=0;i<A.size();i++){
            pq.push(A[i]);
        }
        int mx=INT_MIN;
        int x=pq.top();
        pq.pop();
        while(!pq.empty())
        {
            int y=pq.top();
            pq.pop();
            mx=max(mx,x-y);
            x=y;
        }
        return mx;
    }
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        // Find maximum consecutive difference
        // then get the area
        horizontalCuts.insert(horizontalCuts.begin(),0);
        horizontalCuts.push_back(h);
        verticalCuts.insert(verticalCuts.begin(),0);
        verticalCuts.push_back(w);
        long int a1 = maximumGap(horizontalCuts);
        long int a2 = maximumGap(verticalCuts);
        return (a1*a2)%MOD;
    }
};