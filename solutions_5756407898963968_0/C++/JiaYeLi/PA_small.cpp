#include<iostream>
#include<cstdlib>
#include<cstdio>
using namespace std;
#define ONLINE

void readCard(int card[4][4])
{
    for(int i=0; i<4; i++)
        for(int j=0; j<4; j++)
            scanf("%d",&card[i][j]);
}

int setInstersect(int ans[4], int setA[4], int setB[4])
{
    int top = 0;
    for(int i=0; i<4; i++)
    {
        for(int j=0; j<4; j++)
        {
            if(setA[i]==setB[j])
                ans[top++] = setA[i];
        }
    }
    return top;
}

#ifndef ONLINE

void showCard(int card[4][4])
{
    for(int i=0; i<4; i++)
    {
        for(int j=0; j<4; j++)
            printf(" %d",card[i][j]);
        printf("\n");
    }
}

void showRow(int a[4], int n)
{
    for(int i=0; i<n; i++)
        printf(" %d",a[4]);
    printf("\n");
}

#endif // ONLINE

int main()
{
    int n;
    scanf("%d",&n);
    for(int c=0; c<n; c++)
    {
        int row_n1;
        int card_arrange1[4][4];
        int row_n2;
        int card_arrange2[4][4];

        scanf("%d",&row_n1);
        readCard(card_arrange1);

        scanf("%d",&row_n2);
        readCard(card_arrange2);

        #ifndef ONLINE

        printf("Card set 1:\n");
        printf("row = %d\n", row_n1);
        showCard(card_arrange1);
        printf("\n");

        printf("Card set 2:\n");
        printf("row = %d\n", row_n2);
        showCard(card_arrange2);
        #endif // ONLINE


        int set1[4];
        int set2[4];
        //load card id from row

        for(int i=0; i<4; i++)
        {
            set1[i]=card_arrange1[row_n1-1][i];
            set2[i]=card_arrange2[row_n2-1][i];
        }

        int ans_set[4];
        int set_size = 0;
        set_size = setInstersect(ans_set, set1, set2);

        #ifndef ONLINE
        printf("set 1:\n");
        showRow(set1, 4);
        printf("set 2:\n");
        showRow(set2, 4);
        printf("set intersection:\n");
        showRow(ans_set, set_size);
        #endif // ONILEE



        switch(set_size)
        {
            case 0:
                printf("Case #%d: Volunteer cheated!\n",c+1);
                break;
            case 1:
                printf("Case #%d: %d\n",c+1,ans_set[0]);
                break;
            default:
                printf("Case #%d: Bad magician!\n",c+1);
                break;
        }

    }
    return 0;
}
