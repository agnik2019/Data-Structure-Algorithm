/*
There is a new alien language which uses the latin alphabet. However, the order among letters are unknown to you. You receive a list of non-empty words from the dictionary, where words are sorted lexicographically by the rules of this new language. Derive the order of letters in this language.
Example 1:
Given the following words in dictionary,
[
  "wrt",
  "wrf",
  "er",
  "ett",
  "rftt"
]
The correct order is: "wertf".
Example 2:
Given the following words in dictionary,
[
  "z",
  "x"
]
The correct order is: "zx".
Example 3:
Given the following words in dictionary,
[
  "z",
  "x",
  "z"
]
The order is invalid, so return "".
Note:
You may assume all letters are in lowercase.
You may assume that if a is a prefix of b, then a must appear before b in the given dictionary.
If the order is invalid, return an empty string.
There may be multiple valid order of letters, return any one of them is fine.

Thought process:
Topological sort:
Build graph: 
a map of character -> set of character.
Also get in-degrees for each character. In-degrees will be a map of character -> int.
Topological sort:
Loop through in-degrees. Offer the characters with in-degree of 0 to queue.
While queue is not empty:
Poll from queue. Append to character to result string.
Decrease the in-degree of polled character's children by 1.
If any child's in-degree decreases to 0, offer it to queue.
At last, if result string's length is less than the number of vertices, that means there is a cycle in my graph. The order is invalid.
*/
#include<iostream>
using namespace std;
#include<vector>
#include<unordered_map>
#include<queue>
#include<algorithm>
#include<list>

string alienOrder(vector<string>& words)
{
    //create 2 unordered_maps one for adjacency list and one for indegree
    unordered_map<char, list<char>> adjList;
    unordered_map<char, int> indegree;
    //initialize
    for(string &str: words)
    {
        for(char &ch : str)
        {
            indegree[ch] = 0;
            list<char> li;
            adjList[ch] = li;
        }
    }
    //we pick the words in pair and traverse all its character and get dependency graph
    for(int i = 0; i<words.size()-1; i++)
    {
        string w1 = words[i];
        string w2= words[i+1];
        //if w2 is prefix of w1,then we return ""
        auto res = mismatch(w2.begin(), w2.end(), w1.begin());
        if(w1.size() > w2.size() && res.first == w2.end()) 
                return "";
        //now we build the dependency graph
        for(int j = 0; j< min(w1.size(), w2.size()); j++)
        {
            if(w1[j] != w2[j])
            {
                adjList[w1[j]].push_back(w2[j]);
                indegree[w2[j]]+=1;
                break;
            }
        }
    }
    // now we apply topological sort :D
    //bfs traversal method
    string str = " ";
    queue<char> q;
    //first push all the 
    for(auto it = indegree.begin(); it != indegree.end(); it++)
    {
        if(indegree[it->first] == 0)
            q.push(it->first);
    }
    while(!q.empty())
    {
        char ch = q.front(); q.pop();
        str+= ch;
        for(char &neighbour : adjList[ch])
        {
            indegree[neighbour] -= 1;
            if(indegree[neighbour] == 0)
                q.push(neighbour);
        }
    }
    if(str.size() < indegree.size()) return ""; //cycle so no topo sort
    return str;
}
int main()
{
    vector<string> s = {"wrt","wrf","er","ett","rftt"};
    cout<< alienOrder(s)<<endl;
    return 0;
}