/*
 * Author: fatboy_cw
 * Created Time:  2015/4/18 9:26:18
 * File Name: A.cpp
 */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <vector>
using namespace std;
const int maxint = -1u>>1;
template <class T> bool get_max(T& a, const T &b) {return b > a? a = b, 1: 0;}
template <class T> bool get_min(T& a, const T &b) {return b < a? a = b, 1: 0;}
const int maxn = 1000 + 5;

int t, n;

int get_first(const vector<int> &v) {
    int res = 0;
    for(int i = 1; i < v.size(); i++) {
        if(v[i] < v[i - 1]) {
            res += v[i - 1] - v[i];
        }
    }
    return res;
}

int rate_e(const vector<int> &v, int r) {
    int now = v[0], res = 0;
    for(int i = 1; i < v.size(); i++) {
        res += min(now, r);
        now = max(0, now - r);
        if(now > v[i]) return maxint;
        now = v[i];
    }
    return res;
}

int get_second(const vector<int> &v) {
    int res = maxint;
    for(int r = 0; r <= 10000; r++) {
        get_min(res, rate_e(v, r));
    }
    return res;
}

int ca;

int main() {
    freopen("A.out", "w", stdout);
    scanf("%d", &t);
    while(t--) {
        vector<int> v;
        scanf("%d", &n);
        for(int i = 0; i < n; i++) {
            int x;
            scanf("%d", &x);
            v.push_back(x);
        }
        int fir = get_first(v);
        int sec = get_second(v);
        printf("Case #%d: %d %d\n", ++ca, fir, sec);
    }
    return 0;
}

