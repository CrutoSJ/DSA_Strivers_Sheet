// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/minimal-cost/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=minimal-cost

// Date-> 14/10/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int minimizeCost(int k, vector<int>& arr) {
        int n = arr.size();
        vector<int> dp(n, INT_MAX);
        dp[0] = 0;
        
        for(int i=1; i<n; i++){
            int mini = INT_MAX;
            for(int j=1; j<=k; j++){
                if(i-j >= 0){
                    int ans = dp[i-j] + abs(arr[i] - arr[i-j]);
                    mini = min(mini, ans);
                }
            }
            dp[i] = mini;
        }
        return dp[n-1];
        
    }
};