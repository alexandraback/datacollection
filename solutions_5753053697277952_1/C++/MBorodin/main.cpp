#include <cstdio>
#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
#include <set>
#include <map>
#include <stack>
#include <queue>

using namespace std;

int n;
int copyn;

vector <pair <int, char> > arr;

int main ()
{
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);
    int t;
    cin >> t;
    for (int i = 0;i < t;i++) {
        cin >> n;
        copyn = n;
        arr.clear();
        for (int j = 0;j < n;j++) {
            int a;
            cin >> a;
            arr.push_back(make_pair (a, (char) ('A' + j)));
        }
        printf ("Case #%d: ", i + 1);
        while (copyn > 2) {
            sort(arr.begin(), arr.end());
            printf ("%c ", arr[n - 1].second);
            arr[n - 1].first--;
            if (arr[n - 1].first == 0){
                copyn--;
            }
        }
        sort(arr.begin(), arr.end());
        while (arr[n - 1].first > arr[n - 2].first){
            printf ("%c ", arr[n - 1].second);
            arr[n - 1].first--;
        }
        for (int j = 0;j < arr[n - 1].first;j++){
            printf ("%c%c ", arr[n - 1].second, arr[n - 2].second);
        }
        printf ("\n");
    }
    return 0;
}
