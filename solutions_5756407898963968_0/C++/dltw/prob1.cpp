#include <cstdio>
#include <iostream>

using namespace std;

void process(void) {
    int c1, c2, gar;
    int r[4];
    int s[4];
    bool flag = false;
    scanf("%d", &c1);
    for (int i = 1; i <=4; i++)
    {
        if (i == c1) {
            scanf("%d %d %d %d", &s[0],&s[1],&s[2],&s[3]);
            // printf("%d %d %d %d", s[0],s[1],s[2],s[3]);
        }
        else scanf("%d %d %d %d",&gar,&gar,&gar,&gar);
    }
    scanf("%d", &c2);
    for (int i = 1; i <=4; i++)
    {
        if (i == c2) {
            scanf("%d %d %d %d",&r[0],&r[1],&r[2],&r[3]);
            // printf("%d %d %d %d", r[0],r[1],r[2],r[3]);
        }
        else scanf("%d %d %d %d",&gar,&gar,&gar,&gar);
    }

    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            if (r[i] == s[j])
            {
                if(flag) {
                    printf("%s\n", "Bad magician!");
                    return;
                }
                else {
                    flag = true;
                    gar = r[i];
                }
            }
        }
    }
    
    if(flag){
        printf("%d\n", gar);
    }
    else{
        printf("%s\n", "Volunteer cheated!");
    }
}

int main(void)
{
    int T;
    scanf("%d", &T);
    for(int i=1;i<=T;i++) {
        printf("Case #%d: ", i);
        process();
    }
}