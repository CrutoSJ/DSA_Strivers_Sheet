// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/common-elements1132/1

// Date-> 18/10/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // Function to find common elements in three arrays.
    vector<int> commonElements(vector<int> &arr1, vector<int> &arr2, vector<int> &arr3) {
        vector<int> res;
        
        int i=0, j=0, k=0;
        
        while(i<arr1.size() && j<arr2.size() && k<arr3.size()){
            if(arr1[i] == arr2[j] && arr1[i] == arr3[k]){
                int last = -1;
                if(!res.empty()){
                    last = res.back();
                }
                if(last == -1 || last != arr1[i]){
                    res.push_back(arr1[i]);
                }
                i++, j++, k++;
            } else if(arr1[i] <= arr2[j] && arr1[i] <= arr3[k]){
                i++;
            } else if(arr2[j] <= arr1[i] && arr2[j] <= arr3[k]){
                j++;
            } else if(arr3[k] <= arr2[j] && arr3[k] <= arr1[i]){
                k++;
            } 
            if(i>=arr1.size() && j>=arr2.size() && k>=arr3.size()){
                break;
            }
        }
        return res;
    }
};