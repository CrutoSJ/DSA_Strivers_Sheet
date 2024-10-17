// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/implementation-of-priority-queue-using-binary-heap/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=implementation-of-priority-queue-using-binary-heap

// Date-> 15/10/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

int H[10009];
int s = -1;
int parent(int i) {
    return (i - 1) / 2;
}
int leftChild(int i) {
    return ((2 * i) + 1);
}
int rightChild(int i) {
    return ((2 * i) + 2);
}
void shiftUp(int i) {
    while (i > 0 && H[parent(i)] < H[i]) {
        swap(H[parent(i)], H[i]);
        i = parent(i);
    }
}
void shiftDown(int i) {
    int maxIndex = i;
    int l = leftChild(i);

    if (l <= s && H[l] > H[maxIndex]) {
        maxIndex = l;
    }
    int r = rightChild(i);

    if (r <= s && H[r] > H[maxIndex]) {
        maxIndex = r;
    }
    if (i != maxIndex) {
        swap(H[i], H[maxIndex]);
        shiftDown(maxIndex);
    }
}
void insert(int p) {
    s = s + 1;
    H[s] = p;
    shiftUp(s);
}

class Solution {
  public:
    int extractMax() {
        int res = H[0];
        H[0] = H[s];
        s--;
        shiftDown(0);
        return res;
    }
};