#include<bits/stdc++.h>
using namespace std;

void buildTree(vector<int> &a, int start, int end, vector<int> &tree, int node) {
    if (start == end) {
        tree[node] = a[start];
        return;
    }
    int mid = (start + end)/2;
    buildTree(a, start, mid, tree, 2*node);
    buildTree(a, mid + 1, end, tree, 2*node + 1);
    tree[node] = min(tree[2*node], tree[2*node + 1]);
}

void updateTree(int start, int end, vector<int> &tree, int x, int y, int node) {
    if (start == end) {
        tree[node] = y;
        return;
    }
    int mid = (start + end)/2;
    if (x <= mid) {
        updateTree(start, mid, tree, x, y, 2*node);
    } else {
        updateTree(mid + 1, end, tree, x, y, 2*node + 1);
    }
    tree[node] = min(tree[2*node], tree[2*node + 1]);
}

int getMinInSubArray(int start, int end, vector<int> &tree, int l, int r, int node) {
    if (l > end || r < start) {
        return INT_MAX;
    } 
    else if (start >= l && end <= r) {
        return tree[node];
    }
    int mid = (start + end)/2;
    return min(getMinInSubArray(start, mid, tree, l, r, 2*node), getMinInSubArray(mid + 1, end, tree, l, r, 2*node + 1));
}

int main() {

	int n, q;
    cin >> n >> q;
    vector<int> a;
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        a.push_back(temp);
    }
    vector<int> tree(4*n, INT_MAX);
    buildTree(a, 0, n - 1, tree, 1);
    while (q--) {
        char c;
        int i, j;
        cin >> c >> i >> j;
        if (c == 'q') {
            // query to print minimum in sub array (i, j)
            cout << getMinInSubArray(0, n - 1, tree, i - 1, j - 1, 1) << endl;
        } else if (c == 'u') {
            // query tp update a[i] = j
            updateTree(0, n - 1, tree, i - 1, j, 1);
        } else {
            cout << "INVALID INPUT" << endl;
        }
    }
    return 0;
}

