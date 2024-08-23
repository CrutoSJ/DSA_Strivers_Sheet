// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // Function to return a list containing the DFS traversal of the graph.
    void dfsCall(unordered_map<int, bool> &visited, vector<int> adj[], int node, vector<int> &ans){
        visited[node] = true;
        ans.push_back(node);
        
        for(auto &nbr : adj[node]){
            if(!visited[nbr]){
                dfsCall(visited, adj, nbr,ans);
            }
        }
    }
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        unordered_map<int, bool> visited;
        vector<int> ans;
        
        dfsCall(visited, adj, 0, ans);
        
        return ans;
    }
};