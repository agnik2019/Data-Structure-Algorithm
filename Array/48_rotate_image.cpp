#include<iostream>
#include<vector>
using namespace std;
void rev(vector<int> &v)
{
    int i = 0;
    int j = v.size() -1;
    while( i< j)
    {
        swap(v[i], v[j]);
        i++;
        j--;
    }
}
    void rotate(vector<vector<int>>& matrix) {

            
        for(int i = 0; i< matrix.size(); i++)
            for(int j = i; j < matrix[0].size(); j++)
                swap(matrix[i][j] , matrix[j][i]);
                        
        for(int i = 0; i< matrix.size(); i++)
            rev(matrix[i]);
        
        return;
        
    }
int main(){
    vector<vector<int>> arr = {{1,2,3},
                                {4,5,6},
                                {7,8,9}};
    rotate(arr);
    for(int i = 0; i< arr.size(); i++)
    {
        for(int j = 0; j<arr[0].size(); j++)
            cout<< arr[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}