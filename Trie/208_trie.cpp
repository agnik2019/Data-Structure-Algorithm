#include<iostream>
using namespace std;
class Trie {
    struct trienode{
        int val;
        int count;
        int endsHere;
        trienode* child[26];
    };
    trienode* root;
    trienode* getnode(int index)
    {
        trienode* newnode = new trienode();
        newnode->val = 'a'+index;
        newnode->count = newnode->endsHere = 0;
        for(int i = 0; i<26; i++)
            newnode->child[i] = NULL;
        return newnode;
    }
public:
    /** Initialize your data structure here. */
    Trie() {
        root = getnode('/'-'a');
    }
    
    /** Inserts a word into the trie. */
    void insert(string word)
    {
        trienode* curr = root;
        int index;
        for(int i = 0; word[i] !='\0'; i++)
        {
            index = word[i]-'a';
            if(curr->child[index] == NULL)
                curr->child[index] = getnode(index);
            curr->child[index]-> count += 1;
            curr = curr->child[index];
        }
        curr->endsHere += 1;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        trienode* curr = root;
        int index;
        for(int i = 0; word[i] !='\0'; i++)
        {
            index = word[i]-'a';
            if(curr->child[index] == NULL)
                return false;
            curr = curr->child[index];
        }
        return (curr->endsHere > 0);
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        trienode* curr = root;
        int index;
        for(int i = 0; prefix[i] !='\0'; i++)
        {
            index = prefix[i]-'a';
            if(curr->child[index] == NULL)
                return false;
            curr = curr->child[index];
        }
        return (curr->count > 0);
    }
};

int main()
{
    Trie* trie = new Trie();

    trie->insert("apple");
    cout<< boolalpha <<trie->search("apple")<<endl;   // returns true
    cout<< boolalpha <<trie->search("app")<<endl;     // returns false
    cout<< boolalpha <<trie->startsWith("app")<<endl; // returns true
    trie->insert("app");   
    cout<< boolalpha <<trie->search("app")<<endl;     // returns true
    return 0;
}