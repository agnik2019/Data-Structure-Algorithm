#include<iostream>
#include<vector>
using namespace std;
// private recursive helper to implement diceRolls logic
int sumAll(const vector<int>& v) 
{
    int sum = 0;
    for (int k : v) { sum += k; }
    return sum;
}
void diceRollHelper(int dice, int desiredSum, vector<int>& chosen,vector<vector<int>> &res) 
{
    if (dice == 0){
        if(sumAll(chosen) == desiredSum) 
        {
            res.push_back(chosen);
            return ;
        }
    } 
    else 
    {
        for (int i = 1; i <= 6; i++) 
        {
            chosen.push_back(i); // choose
            diceRollHelper(dice - 1, desiredSum,chosen,res); // explore
            chosen.pop_back(); // un-choose
        }
    }
}
// Prints all possible outcomes of rolling the given
// number of six-sided dice in {#, #, #} format.
void diceRolls(int dice,int desiredSum,vector<vector<int>> &res) 
{
    vector<int> chosen;
    diceRollHelper(dice, desiredSum,chosen,res);
}
int main(){
    int n,sum; 
    cout<<"Enter the available dice numbers ";
    cin>>n;
    cout<<" desired sum ";
    cin>>sum;
    vector<vector<int>> res;
    diceRolls(n,sum,res);
    cout<<"[";
    for(int i = 0; i<res.size(); i++)
    {
        cout<<'[';
        for(int j = 0; j<res[i].size(); j++)
        {
            cout<<res[i][j]<<" ";
        }
        cout<<']';
    }
    cout<<']';
    return 0;
}