#include<bits/stdc++.h>
using namespace std;

class TrieNode {
    public:
    TrieNode *left;
    TrieNode *right;
};

void insert(TrieNode *head, int value) {
    TrieNode *curr = head;
    for (int i = 31; i >= 0; i--) {
        int bit = (value>>i)&1;
        if (bit == 1) {
            if (!curr->right)
            	curr->right = new TrieNode();
           	curr = curr->right; 
        } else {
            if (!curr->left)
            	curr->left = new TrieNode();
            curr = curr->left;
        }
    }
}

int maxXOR(int arr[], int n, TrieNode *head) {
    int maxSum = 0;
    int curr_value = 0;
    for (int i = 0; i < n; i++) {
        curr_value = curr_value^arr[i];
        TrieNode *curr = head;
        int xorSum = 0;
        for (int j = 31; j >= 0; j--) {
            int bit = (curr_value>>j)&1;
            if (bit == 1) {
                if (curr->left) {
                    xorSum += pow(2, j);
                    curr = curr->left;
                } else {
                    curr = curr->right;
                }
            } else {
                if (curr->right) {
                    xorSum += pow(2, j);
                    curr = curr->right;
                } else {
                    curr = curr->left;
                }
            }
        }
        if (max(curr_value, xorSum) > maxSum) {
            maxSum = max(curr_value, xorSum);
        }
        insert(head, curr_value);
    }
    return maxSum;
}

int main() {

	int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    TrieNode *head = new TrieNode();
    insert(head, 0);
    cout << maxXOR(arr, n, head) << endl;
    return 0;
}

