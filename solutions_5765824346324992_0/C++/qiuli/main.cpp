//
//  main.cpp
//  B
//
//  Created by Li Qiu on 4/10/15.
//  Copyright (c) 2015 Li Qiu. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <stdio.h>
#include <cstring>

using namespace std;

int tcase = 0;
const int maxn = 1e5 + 10;

long long B, N;
long long m[maxn];

long long doing(long long k){
    long long res = 0;
    for(int i = 0; i < B; ++i ) res += (k + m[i] - 1) / m[i];
    return res;
}

vector<int> avail(long long k){
    vector<int> res;
    for(int i = 0; i < B; ++i )
        if( k % m[i] == 0 ) res.push_back( i + 1 );
    return res;
}


void solve(int tcase){
    long long lf = 0, rt = 1e15;
    long long t = -1;
    while( lf <= rt ){
        long long mid = lf + (rt - lf)/2;
        if( doing(mid) + avail(mid).size() >= N ){
            t = mid;    rt = mid - 1;
        }else lf = mid + 1;
    }
//    cout << t <<"===" << endl;
    vector<int> res = avail(t);
    printf("Case #%d: %d\n", tcase, res[ N - doing(t) - 1 ] );
}
int main(int argc, const char * argv[]) {
    // insert code here...
    freopen("/Users/liqiu/Desktop/B/B.in", "r", stdin );
    freopen("/Users/liqiu/Desktop/B/B.out", "w", stdout );
    int T;
    cin >> T;
    while(T-- ){
        tcase++;
        cin >> B >> N;
        for(int i = 0; i < B; ++i) cin >> m[i];
        solve( tcase );
    }
    return 0;
}
