#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

const int MAXN = 5;

int a[5][5] , b[5][5] ;

int main(){
    freopen("A-small-attempt0.in","r",stdin);
    freopen("A-small-attempt0.out","w",stdout);
    int _;scanf("%d",&_);
    int cas=0;
    while (_--){
        int row1,row2;
        vector<int> v1,v2;
        scanf("%d",&row1);
        for (int i=0;i<4;i++)
            for (int j=0;j<4;j++)
            {
                scanf("%d",&a[i][j]);
                if (i==row1-1) v1.push_back(a[i][j]);
            }
        scanf("%d",&row2);
        for (int i=0;i<4;i++)
            for (int j=0;j<4;j++)
            {
                scanf("%d",&b[i][j]);
                if (i==row2-1) v2.push_back(b[i][j]);
            }
        set<int> gao;
        for (int i=0;i<v1.size();i++)
            for (int j=0;j<v2.size();j++)
                if (v1[i]==v2[j]) gao.insert(v1[i]);
        printf("Case #%d: ",++cas);
        if ((int)gao.size()==0)
            printf("Volunteer cheated!\n");
        else if ((int)gao.size()==1)
            printf("%d\n",(*gao.begin()));
        else
            printf("Bad magician!\n");

    }
    return 0;
}
