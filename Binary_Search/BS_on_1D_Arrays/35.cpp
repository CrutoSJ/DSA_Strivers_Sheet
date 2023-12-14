// #Question:-

// Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

// You must write an algorithm with O(log n) runtime complexity.

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int s=0;
        int e=nums.size()-1;
        
        int mid= s + (e-s)/2;
        int ans=-1;
        
        while(s<=e){
            if(nums[mid]==target){
                return mid;
            }
            
            if(nums[mid]<target){
                ans=mid;
                s=mid+1;
            }
            
            else{
                e=mid-1;
            }
            
            mid = s + (e-s)/2;
        }
        
        return ans+1;
    }
};