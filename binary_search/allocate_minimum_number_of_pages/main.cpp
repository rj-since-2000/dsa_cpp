#include <bits/stdc++.h>
using namespace std;

bool isPossible(int arr[], int n, int m, int curr_min)
{
    int studentsRequired = 1;
    int curr_sum = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > curr_min)
            return false;
        if (curr_sum + arr[i] > curr_min)
        {
            studentsRequired++;
            curr_sum = arr[i];
            if (studentsRequired > m)
                return false;
        }
        else
            curr_sum += arr[i];
    }
    return true;
}

//Function to find minimum number of pages.
int findPages(int arr[], int n, int m)
{
    if (n < m)
        return -1;
    int max = 0;
    int min = 0;
    int minmax = -1;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > min)
            min = arr[i];
        max += arr[i];
    }
    while (min <= max)
    {
        int mid = (min + max) / 2;
        int sum = 0;
        int count = 1;
        if (isPossible(arr, n, m, mid))
        {
            minmax = mid;
            max = mid - 1;
        }
        else
        {
            min = mid + 1;
        }
    }
    return minmax;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int A[n];
        for (int i = 0; i < n; i++)
        {
            cin >> A[i];
        }
        int m;
        cin >> m;
        cout << findPages(A, n, m) << endl;
    }
    return 0;
}
