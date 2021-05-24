class Solution {
public:
    int trap(vector<int>& height) {
        if(height.size() == 0) return 0;
        vector<int> maxl(height.size());
         vector<int> maxr(height.size());
        maxl[0] = height[0];
        for(int i = 1; i< height.size(); i++)
        {
            maxl[i] = max(maxl[i-1],height[i] );
        }
        maxr[height.size()-1] = height[height.size()-1];
        for(int i = height.size()-2; i>=0; i--)
        {
            maxr[i] = max(maxr[i+1],height[i] );
        }
        vector<int> water(height.size());
        for(int i = 0; i< height.size(); i++)
        {
            water[i] = min(maxl[i], maxr[i]) - height[i];
        }
        int total = 0;
        for(int i = 0; i< height.size(); i++)
        {
            total+= water[i];
        }
        return total;
    }
};