// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/bfs-traversal-of-graph/1

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    void BFSCall(unordered_map<int, bool> &visited, vector<int> adj[], int node, vector<int> &ans){
        queue<int>q;
        q.push(node);
        visited[node] = true;
        
        while(!q.empty()){
            auto front = q.front();
            q.pop();
            
            ans.push_back(front);
            
            for(auto &nbr : adj[front]){
                if(!visited[nbr]){
                    visited[nbr] = true;
                    q.push(nbr);
                }
            }
        }
    }
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        unordered_map<int, bool> visited;
        vector<int> ans;

        BFSCall(visited, adj, 0, ans);

        
        return ans;
    }
};