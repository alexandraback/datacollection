#include<iostream>
#include<cstring>
#include<cstdio>

using namespace std;

int p1[20],p2[20],kasus,t1,t2;

int main() {
    scanf("%d",&kasus);
    for (int l=1;l<=kasus;++l) {
        scanf("%d",&t1);
        int temp;
        for (int i=1;i<=4;++i) {
            for (int j=1;j<=4;++j) {
                scanf("%d",&temp);
                p1[temp] = i;
            }
        }
        
        scanf("%d",&t2);
        for (int i=1;i<=4;++i) {
            for (int j=1;j<=4;++j) {
                scanf("%d",&temp);
                p2[temp] = i;
            }
        }
        
        int temu = 0;
        int jawab = -1;
        for (int i=1;i<=16;++i) {
            if (p1[i] == t1 && p2[i] == t2) {
                ++temu;
                jawab = i;
            }
        }
        
        printf("Case #%d: ",l);
        if (!temu) printf("Volunteer cheated!\n");
        else if (temu == 1) printf("%d\n",jawab);
        else printf("Bad magician!\n");
    }
    return 0;
}
