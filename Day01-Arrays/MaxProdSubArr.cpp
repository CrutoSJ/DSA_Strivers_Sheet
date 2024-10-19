// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/maximum-product-subarray3604/1

// Date-> 19/10/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:

    // Function to find maximum product subarray
    long long maxProduct(vector<int> &arr) {
        int n = arr.size();
        long long maxi   = INT_MIN;
        long long prefix = 1;
        long long suffix = 1;
        
        for(int i=0; i<n; i++){
            if(prefix == 0){
                prefix = 1;
            }
            if(suffix == 0){
                suffix = 1;
            }
            
            prefix *= arr[i];
            suffix *= arr[n-i-1];
            
            maxi = max(maxi, max(prefix, suffix));
        }
        
        return maxi;
    }
};