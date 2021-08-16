#include<bits/stdc++.h>
using namespace std;

#define ll long long int

pair<ll, ll> maxPairOfFour(ll a, ll b, ll c, ll d) {
	ll max1 = max(a, b);
    ll min1 = min(a, b);
    ll max2 = max(c, d);
    ll min2 = min(c, d);
    ll firstMax = max(max1, max2);
    ll secondMax = min(max(max1, min2), max(max2, min1));
    return {firstMax, secondMax};
}

void buildTree(vector<ll> &a, ll start, ll end, vector<pair<ll, ll> > &tree, ll node) {
    if (start == end) {
        tree[node] = {a[start], INT_MIN};
        return;
    }
    ll mid = (start + end)/2;
    buildTree(a, start, mid, tree, 2*node);
    buildTree(a, mid + 1, end, tree, 2*node + 1);
    tree[node] = maxPairOfFour(tree[2*node].first, tree[2*node].second, tree[2*node + 1].first, tree[2*node + 1].second);
}

void updateTree(ll start, ll end, vector<pair<ll, ll> > &tree, ll x, ll y, ll node) {
    if (start == end) {
        tree[node] = {y, INT_MIN};
        return;
    }
    ll mid = (start + end)/2;
    if (x <= mid) {
        updateTree(start, mid, tree, x, y, 2*node);
    } else {
        updateTree(mid + 1, end, tree, x, y, 2*node + 1);
    }
    tree[node] = maxPairOfFour(tree[2*node].first, tree[2*node].second, tree[2*node + 1].first, tree[2*node + 1].second);
}

pair<ll, ll> getMaxPair(ll start, ll end, vector<pair<ll, ll> > &tree, ll l, ll r, ll node) {
    if (l > end || r < start) {
        return {INT_MIN, INT_MIN};
    } 
    else if (start >= l && end <= r) {
        return {tree[node].first, tree[node].second};
    }
    ll mid = (start + end)/2;
    pair<ll, ll> pair1 = getMaxPair(start, mid, tree, l, r, 2*node);
    pair<ll, ll> pair2 = getMaxPair(mid + 1, end, tree, l, r, 2*node + 1);
    return maxPairOfFour(pair1.first, pair1.second, pair2.first, pair2.second);
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
    vector<pair<ll, ll> > tree(4*n, {-1, -1});
    buildTree(a, 0, n - 1, tree, 1);
    while (q--) {
        char c;
        ll i, j;
        cin >> c >> i >> j;
        if (c == 'Q') {
            // query to print maximum pair sum in (i, j)
            pair<ll, ll> maxPair = getMaxPair(0, n - 1, tree, i - 1, j - 1, 1);
            ll pairSum = maxPair.first + maxPair.second;
            cout << pairSum << endl;
        } else if (c == 'U') {
            // query tp update a[i] = j
            updateTree(0, n - 1, tree, i - 1, j, 1);
        } else {
            cout << "INVALID INPUT" << endl;
        }
    }
    return 0;
}

