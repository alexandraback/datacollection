#include <stdio.h>


int main()
{
	int nc, notc;
	scanf("%d", &notc);
	
	for(nc=1;nc<=notc;nc++)
	{
        int c1, c2;
        int i, j;
        int mati[4][4];
        int matl[4][4];
        
        scanf("%d", &c1);
        for(i=0;i<4;i++)
        {
            for(j=0;j<4;j++)
            {
                int a;
                scanf("%d", &a);
                mati[i][j] = a;
            }
        }
        scanf("%d", &c2);
        for(i=0;i<4;i++)
        {
            for(j=0;j<4;j++)
            {
                int a;
                scanf("%d", &a);
                matl[i][j] = a;
            }
        }
        
        int cnt = 0;
        int num = 0;
        c1--;
        c2--;
        for(i=0;i<4;i++)
        {
            for(j=0;j<4;j++)
            {
                if(mati[c1][i] == matl[c2][j])
                {
                    cnt++;
                    num = matl[c2][j];
                    break;
                }
            }
        }
        if(cnt == 1)
            printf("Case #%d: %d\n", nc, num);
        else if (cnt > 1)
            printf("Case #%d: Bad magician!\n", nc);
        else
            printf("Case #%d: Volunteer cheated!\n", nc);
	}
    return 0;
}

