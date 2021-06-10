class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()==0) return 0;
        int obsp = -prices[0]; //bought state profit
        int ossp = 0;   //selling state profit
        int ocsp = 0;   //cooldown state profit
        for(int i = 1; i<prices.size(); i++)
        {
            int nbsp = 0;
            int nssp = 0;
            int ncsp = 0;
            nbsp = max(ocsp - prices[i], obsp);
            nssp = max(obsp + prices[i], ossp);
            ncsp = max(ocsp, ossp);
            obsp = nbsp;
            ossp = nssp;
            ocsp = ncsp;
        }
        return ossp;
    }
};