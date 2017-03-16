#include <iostream>
#include <cstdio>
#include <fstream>
#include <cmath>
#include <string>
#include <cstring>
#include <set>
#include <map>
#include <stack>
#include <vector>
#include <algorithm>
#include <queue>

#define F first
#define S second
#define x1 privet1
#define x2 privet2
#define y1 privet3
#define y2 privet4
#define hash privet5

using namespace std;

    int t, n, a[44], s=0;

int main(){
    freopen("A-large.in", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> t;
    for(int w=0; w<t; w++){
        cin >> n;
        s=0;
        pair< int, int> d;
        d.F = 0;
        for(int i=0; i<n; i++){
            cin >> a[i];
            d = max(d, make_pair(a[i], i));
            s+=a[i];
        }
        cout << "Case #" << w+1 << ":";
        if(s%2 == 1){cout << " " << (char)(d.S+'A'); a[d.S]--; s--;}
        for(int i=0; i<s; i+=2){
            pair<int, int> mx, mx1;
            mx.F = 0;
            mx1.F = 0;
            for(int q=0; q<n; q++) mx = max(mx, make_pair(a[q], q));
            for(int q=0; q<n; q++) if(q!=mx.S) mx1 = max(mx1, make_pair(a[q], q));
            if(mx.F >= mx1.F+1){
                cout << " " << (char)(mx.S+'A') << (char)(mx.S+'A');
                a[mx.S]-=2;
            } else {
                cout << " " << (char)(mx.S+'A') << (char)(mx1.S+'A');
                a[mx.S]--;
                a[mx1.S]--;
            }
        }
        if(w!=t-1) cout << "\n";
    }

}
/*
1212121112121124
111212
*/
