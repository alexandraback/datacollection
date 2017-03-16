#include <vector>
#include <iostream>
#include <set>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
#define N 1000006
int STEPS[N];

int solve(int r, int c, int x) {
    if(x<=1) return 0;
    if(r * c == x) {
        return 2 * x - r - c;
    }
    if (r > c) {
        swap(r, c);
    }
    if(r == 1) {
        return solve(r, c - 2, x-1);
    }
    if(r == 2) {
        if(x<=c) return 0;
        int i=1;
        while(true) {
            if (((c - i) * 2 + i) >= x) {i++; continue;}
            // cout << i << endl;
            if((c-i+1) == 1) return 2;
            if((c-i+1) == 2) {
                return 4;
            }
            return 3 + solve((c - i), 2, (c - i) * 2);
        }
    }
    if(r == 3) {
        if(c == 3) {
            if(x<=5) return 0;
            if(x==6) return 3;
            if(x==7) return 6;
            if(x==8) return 8;
        }
        if(c == 4) {
            if(x<=6) return 0;
            if(x==7) return 2;
            if(x==8) return 4;
            if(x==9) return 7;
            if(x==10) return 10;
            if(x==11) return solve(3, 4, 12) - 4;
        }
        if(c == 5) {
            if(x<=8) return 0;
            if(x==9) return 3;
            if(x==10) return 6;
            if(x==11) return 9;
            if(x==12) return 12;
            if(x==13) return 15;
            if(x==14) return solve(3, 5, 15) - 4;
        }
    }
    if(r == 4) {
        if(x<=8) return 0;
        if(x==9) return 2;
        if(x==10) return 4;
        if(x==11) return 7;
        if(x==12) return 10;
        if(x==13) return 13;
        if(x==14) return 16;
        if(x==15) return 20;

    }
}

void solve_case(int casen) {
    ll r, c, n;
    cin >> r >> c >> n;
    cout << "Case #" << casen << ": "  << solve(r, c, n) << endl;
}

int main() {
    int cases;
    cin >> cases;
    for(int i=1;i<=cases;i++) solve_case(i);    

    return 0;
}