// DP not used and needs to be implemented!

#include<iostream>
#include<stdc++.h>
using namespace std;

typedef long long int int64;
typedef unsigned long long int uint64;

int maxSum(vector<vector<int> > lrw, int n, int p, int i, int prevEnd) {
    if (p == 0) return 0;
    if (i == n) return INT_MIN;

    int lb = i;
    int ub = n - 1;
    int interval = -1;
    while(lb <= ub) {
        int mid = (lb + ub)/2;
        if (lrw[mid][0] > prevEnd) {
            interval = mid;
            ub = mid - 1;
        } else {
            lb = mid + 1;
        }
    }

    if (interval == -1) return INT_MIN;

    int end = lrw[interval][1];
    int sum = lrw[interval][2];

    int sum1 = sum + maxSum(lrw, n, p - 1, interval + 1, end);
    int sum2 = maxSum(lrw, n, p, i + 1, prevEnd);
    return max(sum1, sum2);
}

int main(){

    //*********************************
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    //*********************************
    
    int n, p;
    cin >> n >> p;

    vector<vector<int> > lrw;
    for (int i = 0; i < n; i++) {
        int li, ri, ki;
        cin >> li >> ri >> ki;
        vector<int> temp;
        temp.push_back(li);
        temp.push_back(ri);
        temp.push_back(ki);
        lrw.push_back(temp);
    }

    sort(lrw.begin(), lrw.end());
    cout << maxSum(lrw, n, p, 0, 0) << endl;
    return 0;
}

