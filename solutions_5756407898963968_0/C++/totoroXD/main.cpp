#include <iostream>
#include <cmath>
#include <cstdio>
#include <vector>
using namespace std;
int kase=1, num[2][5][5], gs[2];

void input(){
    for(int k=0; k<2; k++){
        scanf("%d",&gs[k]);
        gs[k]--;
        for(int i=0; i<4; i++){
            for(int j=0; j<4; j++){
                scanf("%d",&num[k][i][j]);
            }
        }
    }
}
void solve(){
    vector<int> res;
    for(int i=0; i<4; i++){
        int a=num[0][gs[0]][i];
        for(int j=0; j<4; j++){
            if(a==num[1][gs[1]][j])
                res.push_back(a);
        }
    }
    printf("Case #%d: ",kase++);
    if(res.size()==1)
        printf("%d\n",res[0]);
    else if(res.size()==0)
        printf("Volunteer cheated!\n");
    else
        printf("Bad magician!\n");
}
int main()
{
    int zz;
    scanf("%d",&zz);
    while(zz--){
        input();
        solve();
    }
    return 0;
}
/*

3
2
1 2 3 4
5 6 7 8
9 10 11 12
13 14 15 16
3
1 2 5 4
3 11 6 15
9 10 7 12
13 14 8 16
2
1 2 3 4
5 6 7 8
9 10 11 12
13 14 15 16
2
1 2 3 4
5 6 7 8
9 10 11 12
13 14 15 16
2
1 2 3 4
5 6 7 8
9 10 11 12
13 14 15 16
3
1 2 3 4
5 6 7 8
9 10 11 12
13 14 15 16


*/
