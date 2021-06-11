#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#include <deque>
#include <bitset>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <unordered_map>
#include <set>
#include <functional>
#include <numeric>
#include <utility>
#include <limits>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
using namespace std;
 
#define ll				long long int
#define ld				long double
#define mod 			1000000007
#define inf 			1e18 
#define ff              first
#define ss              second
#define pb              push_back
#define mp              make_pair
#define pii             pair<int,int>
#define ump				unordered_map
#define vi              vector<int>
#define mii             map<int,int>
#define pq_max          priority_queue<int>
#define pq_min          priority_queue<int,vi,greater<int> >
#define loop(i,a,b)		for(int i =(a); i<=(b); i++)
#define loopprev(i,a,b) for(int i =(a); i<=(b); i--)			
 
 
void file_i_o()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}
class TopoSort{
public:
  static vector<int> findOrder(int numCourses, vector<vector<int>>& edges) {
        vector<int> sortedorder;
     if(numCourses <= 0) {
         cout<<"IMPOSSIBLE";
        return vector<int>();
     }
    //initialization
        unordered_map<int, int> indegree;
        unordered_map<int, vector<int>> graph;
        for(int i = 0; i< numCourses; i++)
        {
            indegree[i] = 0;
            graph[i] = vector<int>();
        }
    //Build the graph
    for(int i = 0; i<edges.size(); i++)
    {
        int parent = edges[i][0], child = edges[i][1];
        graph[parent].push_back(child);
        indegree[child]++;
    }
    queue<int> q;
    for (auto i: indegree){
        if(i.second == 0)
            q.push(i.first);
    }
    while(!q.empty())
    {
        int vertex = q.front();
        q.pop();
        sortedorder.push_back(vertex);
        vector<int> children= graph[vertex];
        for(auto child: children)
        {
            indegree[child]--;
            if(indegree[child] == 0)
                q.push(child);
        }
    }
    if (sortedorder.size() < numCourses){
        cout<<"IMPOSSIBLE" ;
        return vector<int>();
    }
    return sortedorder;
    }
};
int main()
{
    file_i_o();
    int n,m; // no of courses and requirements
    cin>>n>>m;
     vector<vector<int>> arr(m, vector<int>(2));
     loop(i,0,m-1)
     {
         vector<int> temp;
     	loop(j,0,1)
     	{
     		int no;
     		cin>>no;
     		temp.push_back(no);
     	}
         arr.push_back(temp);
         temp.clear();
     }
     vector<int> res = TopoSort::findOrder(n,arr);
   for(auto num : res)
     {
     	cout<<num<<" ";
     }
    return 0;
}