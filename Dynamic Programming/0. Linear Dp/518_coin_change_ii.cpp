class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> dp(amount+1,0);
        dp[0] = 1; // if your amount is 0 you will not pick any coins so it is a way
     for(int i = 0; i<= coins.size()-1; i++)
        {
         for(int j = coins[i]; j<= amount; j++)            {
                    dp[j] += dp[j-coins[i]];
            }
        }
        return dp[amount];
    }
};