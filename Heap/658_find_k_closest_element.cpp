class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<pair<int,int>> maxh;
        for(auto a : arr)
        {
            if(maxh.size()<k)
            {
                maxh.push({abs(a-x),a});
            }
            else{
                if(maxh.top().first > abs(a-x))
                {
                    maxh.pop();
                    maxh.push({abs(a-x),a});
               }
            }
        }
        vector<int> ans;
        while(!maxh.empty())
        {
            ans.push_back(maxh.top().second);
            maxh.pop();
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};