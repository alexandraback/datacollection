#include <bits/stdc++.h>
using namespace std;

void runTest(){
    set<int> R;
    int r, a[4], res = -1;
    for (int z = 0; z < 2; z++){
        scanf("%d", &r);
        for (int i = 0; i < 4; i++){
            for (int j = 0; j < 4; j++){
                scanf("%d", &a[i]);
                if (i + 1 == r){
                    if (R.count(a[i])){
                        if (res == -1) res = a[i];
                        else res = -2;
                    }
                    R.insert(a[i]);
                }
            }
        }
    }
    if (res == -1) printf("Volunteer cheated!\n");
    else if (res == -2) printf("Bad magician!\n");
    else printf("%d\n", res);
}

int main(){
    freopen("A.inp","r",stdin);
    freopen("A.out","w",stdout);
    int t; scanf("%d", &t);
    for (int i = 1; i <= t; i++){
        printf("Case #%d: ", i);
        runTest();
    }
    return 0;
}
