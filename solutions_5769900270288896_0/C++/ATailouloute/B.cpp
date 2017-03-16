#include <bits/stdc++.h>

using namespace std;

// odd + odd
int solve1(int r, int c, int n){
    int half = (r*c)/2;
    if(n <= half+1) return 0;
    n -= half;
    int ans = 0;
    if(n <= 4){
        return 2 * n;
    }else{
        ans += 8;
        n -= 4;
        int b = (r-2)/2 + (c-2)/2;
        if(n <= b) {
            ans += 3 * n;
        }else{
            ans += 3 * b;
            n -= b;
            ans += 4 * n;
        }
    }
    return ans;
}

// even  + even
int solve2(int r, int c, int n){
    int half = (r*c)/2;
    if(n <= half) return 0;
    n -= half;
    int ans = 0;
    if(n <= 2)
        return 2 * n;
    else {
        ans += 4;
        n -= 2;
        int b = r + c - 4;
        if(n <= b)
            ans += 3 * n;
        else {
            ans += 3 * b;
            n -= b;
            ans += 4 * n;
        }
    }
    return ans;
}

// odd + even
int solve3(int r, int c, int n){
    int half = (r*c)/2;
    if(n <= half) return 0;
    n -= half;
    int ans = 0;
    if(n <= 2)
        return 2 * n;
    else {
        ans += 4;
        n -= 2;
        int b = r + c - 4;
        if(n <= b)
            ans += 3 * n;
        else {
            ans += 3 * b;
            n -= b;
            ans += 4 * n;
        }
    }
    return ans;
}

int solve4(int r, int c, int n){
    if(r != 1) return solve4(c, r, n);
    if(c % 2 == 0){
        int ans = 0;
        n -= c / 2;
        if(n){
            n--;
            ans++;
        }
        if(n){
            ans += 2 * n;
        }
        return ans;
    }else{
        int half = c/2;
        if(n <= half+1) return 0;
        return (n - half) * 2;
    }
}

int solve(int r, int c, int n){
    if(r == 1 || c == 1) return solve4(r, c, n);
    bool re = (r&1);
    bool ce = (c&1);
    if(re && ce) return solve1(r, c, n);
    if(!re && !ce) return solve2(r, c, n);
    return solve3(r, c, n);
}

int main(){
   
    int T, r, c, n;
    scanf("%d", &T);
    
    for(int qq = 1; qq <= T; qq++) {
        scanf("%d %d %d", &r, &c, &n);
        printf("Case #%d: %d\n", qq, solve(r, c, n));
    }
    
    return 0;
}