#include<iostream>
using namespace std;
#include<string>
#include<vector>

vector<int> prefix_fun(string s){
    int n = s.size();
    vector<int> pi(n,0);
    for(int i = 1; i<s.size(); i++){
        int j= pi[i-1];
        while(j>0 && s[i] != s[j])
            j = pi[j-1];
        if(s[i] == s[j]) j++;
        pi[i] = j;
    }
    return pi;
}
int kmpalgo(string text, string pat){
    int pos = -1;
    int i(0),j(0);
    vector<int> pi = prefix_fun(pat);
    while(i< text.length()){
        if(text[i] == pat[j]){
            i++; 
            j++;
        }
        else{
            if(j) j = pi[j-1];
            else i++;
        }
        if(j == pat.length()){
            pos = i-pat.length();
            break;
        }
    }
    return pos;
}
int main(){
    string t = "agniksahagniss";
    string p = "ks";
    cout<<kmpalgo(t,p)<<endl;
    return 0;
    
}