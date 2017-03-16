/*
 * Created on: 2014-05-03 21:28
 * Created by: suren
 *
 * Distributed under beerware licence.
 */

#include <iostream>
#include <cstdio>
#include <map>
#include <string>
#include <cstring>
#include <vector>
#include <set>
#include <algorithm>
#include <cstdlib>
#include <cmath>

using namespace std;

typedef vector<int> vi;
typedef vector< vi > vvi;
typedef pair<int, int> ii;
typedef vector< ii > vii;

#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()

int main() {
    int T;
    cin >> T;
    for(int t = 1; t <= T; t++) {
        int n;
        cin >> n;
        vector<string> str(n);
        for(int i = 0; i < n; i++) {
            cin >> str[i];
        }
        int count[n];
        int done = 0;
        int ans = 0;
        while(1) {
            int xcount = 0;
            for(int i = 0; i < n; i++) {
                if(str[i].size() == 0)
                    xcount++;
            }
            if(xcount == n) {
                done = 1;
                break;
            }
            else if(xcount > 0) {
                done = -1;
                break;
            }
            for(int i = 0; i < n; i++) count[i] = 0;
            char x = str[0][0];
            int mi = 101;
            int mx = -1;
            for(int i = 0; i < n; i++) {
                while(str[i][0] == x) {
                    count[i]++;
                    str[i].erase(str[i].begin());
                }
                if(count[i] == 0) {
                    done = -1;
                    break;
                }
                mi = min(mi, count[i]);
                mx = max(mx, count[i]);
            }
            if(done == -1)
                break;
            int mans = 1e9;
            for(int d = mi; d <= mx; d++) {
                int tans = 0;
                for(int i = 0; i < n; i++)
                    tans += abs(count[i] - d);
                mans = min(mans, tans);
            }
            ans += mans;
        }
        if(done == -1)
            printf("Case #%d: Fegla Won\n", t);
        else
            printf("Case #%d: %d\n", t, ans);
    }
    return 0;
} 
