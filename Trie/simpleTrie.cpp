#include<iostream>
#include<vector>
using namespace std;
class Trie{
    public:
    class node{
        public:
        bool end;
        node* next[26];
        node(){
            end = false;
            for(int i = 0; i< 26; i++)
                next[i] = NULL;
        }
    };
    node* trie;
    Trie(){
        trie = new node();
    }
    void insert(string word){
        int i = 0;
        node* it = trie;
        while(i< word.size())
        {
            if(!it-> next[word[i]-'a'])
                it -> next[word[i]-'a'] = new node();
            it = it-> next[word[i]-'a'];
            i++;
        }
        it->end = true;
    }
    bool search(string word){
        int i = 0;
        node* it = trie;
        while(i< word.size())
        {
            if(!it->next[word[i]-'a'])
                return false;
            it = it-> next[word[i]-'a'];
            i++;
        }
        return it->end;
    }
};
int main(){
    Trie* mytrie = new Trie();
    vector<string> words = {"agnik","anik","anamik"};
    for(auto word : words){
        mytrie->insert(word);
    }
    cout<<boolalpha<<mytrie->search("agnik")<<endl;
    cout<<boolalpha<<mytrie->search("fuad")<<endl;
    return 0;
}