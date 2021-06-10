class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        /*
        bsp--->brought state profit ---> ssp-prices[i]
            ssp---> sold state profit ---> bsp+prices[i]-fee
            
            */
        int obsp = -prices[0];
        int ossp = 0;
        for(int i = 1; i< prices.size(); i++)
        {

            obsp = max(ossp - prices[i], obsp);
            ossp = max(obsp+prices[i]-fee,ossp);
           
        }
        return ossp;
    }
};