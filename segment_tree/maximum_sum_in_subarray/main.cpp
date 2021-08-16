#include<bits/stdc++.h>
using namespace std;

#define ll long long int

class Node {
    public:
    ll maxSum;
    ll totalSum;
    ll preSum;
    ll suffSum;
    
    public:
    Node(ll maxS, ll totalS, ll preS, ll suffS) {
        maxSum = maxS;
        totalSum = totalS;
        preSum = preS;
        suffSum = suffS;
    }
};

ll maxSumInFive(ll a, ll b, ll c, ll d, ll e) {
	ll max1 = max(a, b);
    ll max2 = max(c, d);
    ll max3 = max(max1, max2);
    return max(max3, e);
}

void buildTree(vector<ll> &a, ll start, ll end, vector<Node> &tree, ll node) {
    if (start == end) {
        Node temp(a[start], a[start], a[start], a[start]);
        tree[node] = temp;
        return;
    }
    ll mid = (start + end)/2;
    buildTree(a, start, mid, tree, 2*node);
    buildTree(a, mid + 1, end, tree, 2*node + 1);
    tree[node].totalSum = tree[2*node].totalSum + tree[2*node + 1].totalSum;
    ll bestPreSum = max(tree[2*node].preSum, tree[2*node].totalSum + tree[2*node + 1].preSum);
    ll bestSuffSum = max(tree[2*node + 1].suffSum, tree[2*node].suffSum + tree[2*node + 1].totalSum);
    tree[node].preSum = bestPreSum;
    tree[node].suffSum = bestSuffSum;
    tree[node].maxSum = maxSumInFive(tree[2*node].maxSum, tree[2*node + 1].maxSum, tree[2*node].suffSum + tree[2*node + 1].preSum, bestPreSum, bestSuffSum);
}

Node getMaxSumInSubArray(ll start, ll end, vector<Node> &tree, ll l, ll r, ll node) {
    Node temp(INT_MIN, INT_MIN, INT_MIN, INT_MIN);
    if (l > end || r < start) {
        return temp;
    } 
    else if (start >= l && end <= r) {
        return tree[node];
    }
    ll mid = (start + end)/2;
    if (r <= mid) {
        return getMaxSumInSubArray(start, mid, tree, l, r, 2*node);
    } else if (l > mid) {
        return getMaxSumInSubArray(mid + 1, end, tree, l, r, 2*node + 1);
    }
    Node left = getMaxSumInSubArray(start, mid, tree, l, r, 2*node);
    Node right = getMaxSumInSubArray(mid + 1, end, tree, l, r, 2*node + 1);
    temp.totalSum = left.totalSum + right.totalSum;
    ll bestPreSum = max(left.preSum, left.totalSum + right.preSum);
    ll bestSuffSum = max(right.suffSum, left.suffSum + right.totalSum);
    temp.preSum = bestPreSum;
    temp.suffSum = bestSuffSum;
    temp.maxSum = maxSumInFive(left.maxSum, right.maxSum, left.suffSum + right.preSum, bestPreSum, bestSuffSum);
    return temp;
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(0);
	ll n;
    cin >> n;
    vector<ll> a;
    for (int i = 0; i < n; i++) {
        ll temp;
        cin >> temp;
        a.push_back(temp);
    }
    ll q;
    cin >> q;
    vector<Node> tree(4*n, Node(INT_MIN, INT_MIN, INT_MIN, INT_MIN));
    buildTree(a, 0, n - 1, tree, 1);
    while (q--) {
        ll i, j;
        cin >> i >> j;
        Node ans = getMaxSumInSubArray(0, n - 1, tree, i - 1, j - 1, 1);
        cout << ans.maxSum << endl;
    }
    return 0;
}

