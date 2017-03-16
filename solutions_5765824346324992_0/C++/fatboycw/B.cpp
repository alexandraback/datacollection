/*
 * Author: fatboy_cw
 * Created Time:  2015/4/18 10:15:06
 * File Name: B.cpp
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
typedef long long lint;
lint t, n, b, m[maxn], l[maxn], ca;

lint check(lint t) {
    lint res = 0;
    for(int i = 0; i < b; i++) {
        res += t / m[i];
        res += (t % m[i] != 0);
    }
    return res;
}

bool last(lint t, lint bar) {
    lint pre_t = t - m[bar];
    if(pre_t < 0) return false;
    lint cnt = check(pre_t);
    for(int i = 0; i < b; i++) {
        l[i] = pre_t / m[i] * m[i];
    }
    lint last = -1;
    for(lint p = cnt + 1; p <= n; p++) {
        lint mv = -1;
        for(int i = 0; i < b; i++) {
            if(mv == -1 || mv > l[i]) {
                mv = l[i];
            }
        }
        for(int i = 0; i < b; i++) {
            if(l[i] == mv) {
                last = i;
                l[i] += mv;
                break;
            }
        }
    }
    if(last == bar) return true;
    return false;
}

lint first_free(lint t) {
    for(int i = 0; i < b; i++) {
        if(last(t, i)) return i + 1;
    }
}

int main() {
    freopen("B.out", "w", stdout);
    cin >> t;
    while(t--) {
        cin >> b >> n;
        lint mv = -1;
        for(int i = 0; i < b; i++) {
            cin >> m[i];
            get_max(mv, m[i]);
        }
        lint l = 0, r = mv * n, ans = -1;
        while(l <= r) {
            lint mid = (l + r) >> 1;
            if(check(mid) >= n) {
                r = mid - 1;
            }
            else {
                l = mid + 1;
                ans = mid;
            }
        }
        lint bar = -1;
        lint left = n - check(ans);
        for(int i = 0; i < b; i++) {
            if(ans % m[i] == 0) {
                left--;
            }
            if(left == 0) {
                bar = i + 1;
                break;
            }
        }
        cout << "Case #" << ++ca << ": " << bar << endl;
    }
    return 0;
}

