#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int solve1(vector<int> &arr, int n) {
    int ans = 0;
    for (int i=1; i<n; i++) {
        if (arr[i] < arr[i-1])
            ans += arr[i-1] - arr[i];
    }
    return ans;
}

int solve2(vector<int> &arr, int n) {
    int ans = 0, mx = 0;
    for (int i=1; i<n; i++) {
        if (arr[i-1] - arr[i] > mx)
            mx = arr[i-1] - arr[i];
    }
    for (int i=1; i<n; i++) {
        if (arr[i-1] < mx)
            ans += arr[i-1];
        else
            ans += mx;
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    int t, n;
    cin >> t;
    for (int i=1; i<=t; i++) {
        cin >> n;
        vector<int> arr(n);
        for (int i=0; i<n; i++) {
            cin >> arr[i];
        }
        cout << "Case #" << i << ": " << solve1(arr, n) << " " << solve2(arr, n) << '\n';
    }
    return 0;
}
