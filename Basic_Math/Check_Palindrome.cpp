// #Question:-

// Given an integer x, return true if x is a palindrome, and false otherwise.

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        long long RevNum = 0;
        int Duplicate = x;
        while (x > 0){
            int ld = x % 10;
            RevNum = (RevNum * 10 ) + ld;
            x = x / 10;
            
        }
        
        if(RevNum == Duplicate){
            return true;
        }
        else{
            return false;
        }
    }
};