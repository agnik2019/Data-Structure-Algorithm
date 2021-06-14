class Solution {
public:
    bool static compare(vector<int> &x,vector<int> &y){
        return (x[1]>y[1]);
    }
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        int ans = 0;
        sort(boxTypes.begin(), boxTypes.end(),compare);
        for(int i = 0; i< boxTypes.size(); i++){
            int boxCount = min(boxTypes[i][0],truckSize);
            ans += (boxTypes[i][1]*boxCount);
            truckSize -= boxCount;
            if(truckSize==0) break;
        }
        return ans;
    }
};