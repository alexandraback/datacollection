#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
    int freq[501][27], t, m;
    scanf("%d", &t);
    for(int i=1; i<=t; i++){
        int n, a;
        m=0;
        for(int j=0; j<=500; j++) for(int k=0; k<=26; k++) freq[j][k]=0;
        scanf("%d", &n);
        for(int j=1; j<=n; j++){
            scanf("%d", &a);
            for(int k=1; k<=a; k++){
                m=max(m, a);
                freq[k][0]++;
                freq[k][freq[k][0]]=j;
            }
        }
        printf("Case #%d: ", i);
        
        for(int j=m; j>=1; j--){
            if(freq[j][0]%2==1){
                printf("%c", freq[j][freq[j][0]]+'A'-1);
                freq[j][0]--;
                if(j==1 && freq[j][0]==0) printf("\n");
                else printf(" ");
            }
            while(freq[j][0]!=0){
                printf("%c%c", freq[j][freq[j][0]-1]+'A'-1, freq[j][freq[j][0]]+'A'-1);
                freq[j][0]-=2;
                if(j==1 && freq[j][0]==0) printf("\n");
                else printf(" ");
            }
        }
    }
    return 0;
}