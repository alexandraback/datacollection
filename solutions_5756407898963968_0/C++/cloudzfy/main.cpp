#include <stdio.h>
#include <string.h>

int data[16];
int main()
{
    freopen("A-small-attempt0.in.txt","r",stdin);
	freopen("A-small-attempt0.out.txt","w",stdout);
    int t, T, A1, A2, card, ans;
    scanf("%d",&T);
    for(t=1; t<=T; t++)
    {
        memset(data, 0,sizeof(data));
        scanf("%d",&A1);
        for(int i=0; i<4; i++)
        {
            for(int j=0; j<4; j++)
            {
                scanf("%d", &card);
                if(i==A1-1)
                {
                    data[card-1]++;
                }
            }
        }
        scanf("%d",&A2);
        for(int i=0; i<4; i++)
        {
            for(int j=0; j<4; j++)
            {
                scanf("%d", &card);
                if(i==A2-1)
                {
                    data[card-1]++;
                }
            }
        }
        ans = 0;
        for(int i=0; i<16; i++)
        {
            if(data[i]==2&&ans==0) {
                ans = i+1;
            }
            else if(data[i]==2&& ans != 0) {
                ans = -1;
            }
        }
        printf("Case #%d: ", t);
        if(ans == 0) {
            printf("Volunteer cheated!\n");
        }
        else if(ans == -1) {
            printf("Bad magician!\n");
        }
        else {
            printf("%d\n", ans);
        }
    }
}