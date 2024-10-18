// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/triplet-sum-in-array-1587115621/1

// Date-> 18/10/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:

    // Should return true if there exists a triplet in the
    // array arr[] which sums to x. Otherwise false
    bool find3Numbers(int arr[], int n, int x) {
        sort(arr, arr+n);
        
        for(int i=0; i<n-2; i++){
            int target = x-arr[i];
            int left   = i+1;
            int right  = n-1;
            
            while(left<right){
                if(arr[left] + arr[right] == target){
                    return true;
                } else if(arr[left] + arr[right] < target){
                    left++;
                } else{
                    right--;
                }
            }
        }
        return false;
    }
};