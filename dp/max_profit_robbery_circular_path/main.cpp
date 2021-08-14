#include<iostream>
#include<stdc++.h>
using namespace std;

typedef long long int int64;
typedef unsigned long long int  uint64;

long long int maxAmount(vector<int> value, int n, bool isFirstChosen)
{
    if (n - 1 < 0) return 0;
    if (n - 1 == 0) {
        if (isFirstChosen) return 0;
        else return value[0];
    }
    return max(value[n - 1] + maxAmount(value, n - 2, isFirstChosen), 
               maxAmount(value, n - 1, isFirstChosen));
}

long long int houseRobber(vector<int>& valueInHouse)
{
    int size = valueInHouse.size();
    long long int ans1 = maxAmount(valueInHouse, size, true);
    long long int ans2 = maxAmount(valueInHouse, size - 1, false);
    long long int maxA = max(ans2, ans1);
    return maxA;
}

int main(){

    //*********************************
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    //*********************************
    
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> v;
        for (int i = 0; i < n; i++) {
            int temp;
            cin >> temp;
            v.push_back(temp);
        }
        cout << houseRobber(v) << endl;
    }
    return 0;
}
