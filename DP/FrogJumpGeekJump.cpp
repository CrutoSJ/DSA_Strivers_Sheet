// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/geek-jump/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=geek-jump

// Date-> 13/10/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int minimumEnergy(vector<int>& height, int n) {
        vector<int> dp(n, 0);
        dp[0] = 0;
        dp[1] = abs(height[1] - height[0]);
        
        for(int i=2; i<n; i++){
            int ans = min(abs(height[i] - height[i-1]) + dp[i-1], abs(height[i] - height[i-2]) + dp[i-2]);
            dp[i] = ans;
        }
        
        return dp[n-1];
    }
};