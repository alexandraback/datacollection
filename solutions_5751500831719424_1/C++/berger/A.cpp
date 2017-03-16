#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>

using namespace std;

int n;
char string[100][101];


int main() {
    
    int T, TT;
    scanf("%d", &TT);
    for (T = 1; T <= TT; T++) {
        printf("Case #%d: ", T);
        
        scanf("%d", &n);
        
        int i;
        for (i = 0; i < n; i++)
            scanf("%s", string[i]);
        
        char cc;
        int pos[100] = {0};
        bool possible = 1;
        int ans = 0;
        
        while (pos[0] != strlen(string[0]) && possible) {
            cc = string[0][pos[0]];
            
            int count[100] = {0};
            
            for (i = 0; i < n; i++) {
                if (string[i][pos[i]] != cc) {
                    possible = 0;
                    break;
                }
                for (; string[i][pos[i]] == cc; pos[i]++)
                    count[i]++;
            }
            
            sort(count, count+n);
            int med = count[n/2];
            
            for (i = 0; i < n; i++)
                ans += abs(med-count[i]);
        }
        
        for (i = 0; i < n; i++)
            if (string[i][pos[i]] != '\0')
                possible = 0;
        
        if (!possible)
            printf("Fegla Won\n");
        else
            printf("%d\n", ans);
    }
    
}