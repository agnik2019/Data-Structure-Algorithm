class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int sd= 0;
        int bd = 0;
        int profit=0;
        for(int i = 1;i< prices.size(); i++)
        {
            if(prices[i]>=prices[i-1])
                sd++;
            else{
                profit+= (prices[sd]-prices[bd]);
                bd=sd=i;
            }
        }
        profit+= (prices[sd]-prices[bd]);      
        return profit;
    }
};





// simple one pass Approach 2
class Solution {
public:
    int maxProfit(vector<int>& A) {
    int profit=0;
     for(int i = 1; i< A.size(); i++)
     {
         if(A[i] > A[i-1])
            profit += (A[i]-A[i-1]);
    }
      return profit;
    }
};