#include <cstdio>
#include <algorithm>

using namespace std;

int get(int r, int c, int n)
{
    int ans = 0, i;
    int sum[5] = {0};
    
    for (i = 0; i < r; i++) {
        if (i % 2 == 0) {
            sum[0] += (c + 1) / 2;
        } else {
            sum[0] += c / 2;
        }
        
        if (r == 1) {
            if (c % 2 == 0) sum[1]++;
            
            sum[2] += (c - 1) / 2;
        } else if (i == 0 || i == r - 1) {
            int x = (c + i % 2) / 2;
            
            if (c % 2 == 0) {
                sum[2]++;
                x--;
            }
            
            if (c % 2 == 1 && i % 2 == 1) {
                sum[2] += 2;
                x -= 2;
            }
            
            sum[3] += x;
        } else {
            int x = (c + i % 2) / 2;
            
            if (c % 2 == 0) {
                sum[3]++;
                x--;
            }
            
            if (c % 2 == 1 && i % 2 == 1) {
                sum[3] += 2;
                x -= 2;
            }
            
            sum[4] += x;
        }
    }
    
    for (i = 0; i < 5 && n > 0; i++) {
        if (sum[i] >= n) {
            ans += n * i;
            n = 0;
        } else {
            ans += sum[i] * i;
            n -= sum[i];
        }
    }
    
    return ans;
}

int get2(int r, int c, int n)
{
    int ans = r * (c - 1) + (r - 1) * c, i;
    int sum[5] = {0};
    
    for (i = 0; i < r; i++) {
        if (r == 1) {
            if (c % 2 == 0) sum[1]++;
            
            sum[2] += (c - 1) / 2;
        } else if (i == 0 || i == r - 1) {
            int x = (c + 1 - i % 2) / 2;
            
            if (c % 2 == 0) {
                sum[2]++;
                x--;
            }
            
            if (c % 2 == 1 && i % 2 == 0) {
                sum[2] += 2;
                x -= 2;
            }
            
            sum[3] += x;
        } else {
            int x = (c + 1 - i % 2) / 2;
            
            if (c % 2 == 0) {
                sum[3]++;
                x--;
            }
            
            if (c % 2 == 1 && i % 2 == 0) {
                sum[3] += 2;
                x -= 2;
            }
            
            sum[4] += x;
        }
    }
    
    n = r * c - n;
    
    for (i = 4; i >= 0 && n > 0; i--) {
        if (sum[i] >= n) {
            ans -= n * i;
            n = 0;
        } else {
            ans -= sum[i] * i;
            n -= sum[i];
        }
    }
    
    return ans;
}

int main()
{
    int t, i;
    
    scanf("%d", &t);
    
    for (i = 0; i < t; i++) {
        int r, c, n;
        
        scanf("%d %d %d", &r, &c, &n);
        
        printf("Case #%d: %d\n", i + 1, min(get(r, c, n), min(get(c, r, n), min(get2(r, c, n), get2(c, r, n)))));
    }
    
    return 0;
}
