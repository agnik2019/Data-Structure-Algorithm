#include<iostream>
using namespace std;
void reverse_string(string s)
{
    if(s.length() == 0) return;
    string ros = s.substr(1);
    reverse_string(ros);
    cout<<s[0];

}
int main()
{
    string s = "Agnik";
    reverse_string(s);
    return 0;
}