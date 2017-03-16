#include <bits/stdc++.h>
using namespace std;
bool tab[1000];
int r, c, n;
bool g(int a, int b) {
    if(a < 0 || a >= r)
        return 0;
    if(b < 0 || b >= c)
        return 0;
    return tab[a * c + b];
}
int main() {
    int t;
    cin >> t;
    for(int T = 1; T <= t; T++) {
        cin >> r >> c >> n;
        for(int i = 0; i < r*c-n; i++)
            tab[i] = 0;
        for(int i = r*c-n; i < r*c; i++) 
            tab[i] = 1;
        int rekord = 1000000000;
        do {
            int sum = 0;
            for(int i = 0; i < c; i++) {
                for(int j = 0; j < r; j++) {
                    if(g(j, i)) {
                        sum += g(j+1, i) + g(j, i+1);
                    }
                }
            }
            rekord = min(rekord, sum);
        }
        while(next_permutation(tab, tab + r*c));
        printf("Case #%d: %d\n", T, rekord);
    }
    
    
    return  0;
}