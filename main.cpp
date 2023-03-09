#include <bits/stdc++.h>
using namespace std;

int lower_bound(const vector<int> &arr, int target);
int f(const vector<int> &arr, int target);
int main(int argc, char const *argv[])
{
    if (1 && 0)
        cout << "true" << endl;
    int x = 8;
    int64_t mid, left = 0, right = x;
    while (left < right)
    {
        mid = (left + right + 1) / 2;
        if (mid * mid <= x)
            left = mid;
        else
            right = mid - 1;
    }

    cout << left << " " << right << endl;
    return 0;
}

// left| right
int f(const vector<int> &arr, int target)
{
    int mid, left = -1, right = arr.size() - 1;
    while (left < right)
    {
        mid = (left + right) / 2 + 1;
        if (arr[mid] <= target)
            left = mid;
        else
            right = mid - 1;
    }

    return right;
}

//后继，[)，求左  5, 7, 7, 8, 8, 10
int lower_bound(const vector<int> &arr, int target)
{
    int mid, left = 0, right = arr.size();
    while (left < right)
    {
        mid = left + (right - left) / 2;
        if (arr[mid] >= target)
            right = mid;
        else
            left = mid + 1;
    }
    return right;
}
