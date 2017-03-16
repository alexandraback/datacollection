#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <vector>

using namespace std;

char s[103][106];
int f[103][500];

int main(){
    int t, n;

    scanf("%d", &t);
    for(int nt = 0; nt < t; ++nt){
        scanf("%d", &n);
        memset(f, 0, sizeof(f));
        for(int i = 0; i < n; ++i){
            scanf(" %s", s[i]);
        }
        vector<char> v;
        for(int i = 0; i < strlen(s[0]); ++i){
            if(i == 0 || s[0][i] != s[0][i-1])
                v.push_back(s[0][i]);
        }
        //verificar seq
        int pos = 1;
        for(int i = 1; i < n; ++i){
            vector<char> x;
            for(int j = 0; j < strlen(s[i]); ++j){
                if(j == 0 || s[i][j] != s[i][j-1])
                    x.push_back(s[i][j]);
            }
            if(x != v){
                pos = 0;
                break;
            }
        }

        int  i, j;
        /*for(i = 0; i < n; ++i){
            int k = 0, l = strlen(s[i]);
            for(j = 0; j < v.size(); ++j){
                if(s[i][k] != v[j]){
                    pos = 0; break;
                }
                while(k < l && s[i][k] == v[j]) k++;
            }
            if(j < v.size() || k < l) {pos = 0; break;}
            }*/
        if(!pos){
            printf("Case #%d: Fegla Won\n", nt+1); continue;
        }

        //contagem
        memset(f, 0, sizeof(f));
        for(i = 0; i < n; ++i){
            int k = 0, l = strlen(s[i]);
            for(j = 0; j < v.size(); ++j){
                while(k < l && s[i][k] == v[j]) {f[i][j]++; k++;}
            }
        }
        int res = 0;
        for(j = 0; j < v.size(); ++j){
            
            int mx = 0x3f3f3f3f;
            for(int k = 1; k < 103; ++k){
                int sum = 0;
                for(i = 0; i < n; ++i){
                    sum += abs(f[i][j]-k);
                }
                mx = min(mx, sum);
            }
            res += mx;
            
        }
        printf("Case #%d: %d\n", nt+1, res);

    }

    return 0;
}
