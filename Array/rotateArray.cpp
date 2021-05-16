// [1 2]
// [3 4]

// [3 1]
// [4 2]
#include<iostream>
#include<vector>
using namespace std;
void reverse(vector<int> v)
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
int main(){
    vector<vector<int>> a;
    int row, col;
    cin>>row;
    cin>> col;
    for(int i = 0; i<row; i++)
      for(int j = 0; j<col; j++)
            cin>> a[i][j];

    //so a[i][j] is our array
    //find transpose of the matrix
    // reverse each row
    for(int i = 0; i< row; i++)
    {
        for(int j = i; j< col; j++)
        {
            swap(a[i][j], a[j][i]);
        }
    }
    for(int i = 0; i< row; i++){
        reverse(a[i]);
    }
    for(int i = 0; i<row; i++)
    {
      for(int j = 0; j<col; j++)
      {
        cout<< a[i][j];
      }
      cout<<endl;
    }
    return 0;      
}