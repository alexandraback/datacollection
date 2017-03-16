#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <math.h>
#include <vector>
#include <string>
#include <queue>
#include <iostream>
using namespace std;

bool fless(double a,double b){ return b-a>1e-6; }
bool fequal(double a,double b){ return fabs(b-a)<=1e-6; }

int main(){
    int tt; scanf("%d",&tt);
    for (int ti=1;ti<=tt;ti++){
        int ans1; scanf("%d", &ans1);
        int a[17], b[17];
        int t;
        for (int i=0;i<4;i++) {
            for (int j=0;j<4;j++) {
                scanf("%d", &t);
                a[t] = i+1;
            }
        }
        int ans2; scanf("%d", &ans2);
        for (int i=0;i<4;i++) {
            for (int j=0;j<4;j++) {
                scanf("%d", &t);
                b[t] = i+1;
            }
        }
        
        int ans = -1;
        int cnt = 0;
        for (int i=1;i<=16;i++) {
            //printf("~%d: %d %d\n", i, a[i], b[i]);
            if (a[i] == ans1 && b[i] == ans2) {
                ans = i; 
                cnt ++;
            }
        }

        if (cnt == 1) {
            printf("Case #%d: %d\n",ti,ans);
        } else if (cnt == 0) {
            printf("Case #%d: Volunteer cheated!\n", ti);
        } else {
            printf("Case #%d: Bad magician!\n",ti);
        }

    }
    return 0;
}

