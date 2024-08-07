// #Question:-

// Link-> https://leetcode.com/problems/implement-trie-prefix-tree/submissions/

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class trieNode{
    public:
        char data;
        trieNode* children[26];
        bool isTerminal;

        trieNode(char ch){
            data = ch;
            for(int i=0; i<26; i++){
                children[i] = NULL;
            }
            isTerminal = false;
        }
};

class Trie {

    trieNode* root;

public:
    Trie() {
        root = new trieNode('\0');
    }
    
    void insertUtil(trieNode* root, string word){
        if(word.length() == 0){
            root->isTerminal = true;
            return ;
        }

        int idx = word[0] - 'a';
        trieNode* child;

        if(root->children[idx] != NULL){
            child = root->children[idx];
        } else{
            child = new trieNode(word[0]);
            root->children[idx] = child;
        }

        insertUtil(child, word.substr(1));
    }

    void insert(string word) {
        insertUtil(root, word);
    }

    bool searchUtil(trieNode* root, string word){
        if(word.length() == 0){
            return root->isTerminal;
        }

        int idx = word[0] - 'a';
        trieNode* child;

        if(root->children[idx] != NULL){
            child = root->children[idx];
        }else{
            return false;
        }

        return searchUtil(child, word.substr(1));
    }
    
    bool search(string word) {
        return searchUtil(root, word);
    }

    bool startsWUtil(trieNode* root, string word){
        if(word.length() == 0){
            return true;
        }

        int idx = word[0] - 'a';
        trieNode* child;

        if(root->children[idx] != NULL){
            child = root->children[idx];
        } else{
            return false;
        }

        return startsWUtil(child, word.substr(1));
    }
    
    bool startsWith(string prefix) {
        return startsWUtil(root, prefix);
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */