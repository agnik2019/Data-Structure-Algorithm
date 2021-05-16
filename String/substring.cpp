//this tutorial will describe substr in c++
#include<iostream>
using namespace std;
#include<string>
#include <sstream>

string fun(string s)
{
    return s.substr(2,2);
}
string reverseWords(string s) 
{
        string op="";
        istringstream ss(s);
        string word;
        while( ss>>word)
        {
            
        op = word+" "+op;
        }
        //op.pop_back();
        return op;
    }
 int main()
 {
     string s = "Agnik is good boy";
     string res = reverseWords(s);
     cout<<res<<endl;
     return 0;
 }