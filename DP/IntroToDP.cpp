// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/introduction-to-dp/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=introduction-to-dp

// Date-> 12/10/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
  int MOD = 1e9+7;
    long long int solveMem(int n, vector<int> &dp){
        if(n==0 || n==1){
            return n;
        } 
        
        if(dp[n] != -1){
            return dp[n];
        }
        
        return dp[n] = (solveMem(n-1, dp)%MOD + solveMem(n-2, dp)%MOD)%MOD;
    }
    
    long long solveTab(int n){
        vector<int> dp(n+1);
        dp[0] = 0;
        dp[1] = 1;
        
        for(int i=2; i<=n; i++){
            int ans = (dp[i-1]%MOD + dp[i-2]%MOD)%MOD;
            dp[i] = ans;
        }
        
        return dp[n];
    }
    
    long long int topDown(int n) {
        vector<int> dp(n+1, -1);
        return solveMem(n,dp);
    }
    
    long long int bottomUp(int n) {
        return solveTab(n);
    }
};