#include <cstdio>
#define scanf(args...) (scanf(args) ? : 0)

const int MAXN = 4;

int array[MAXN][MAXN][2];
int occuring[MAXN*MAXN+1];

int main() {
    int t;
    scanf("%d", &t);

    for (int test=1; test<=t; test++) {
        for (int i=0; i<=MAXN*MAXN; i++)
            occuring[i] = 0;

        int l1;
        scanf("%d", &l1);
        l1--;

        for (int i=0; i<MAXN; i++)
            for (int j=0; j<MAXN; j++)
                scanf("%d", &array[i][j][0]);
        for (int i=0; i<MAXN; i++)
            occuring[array[l1][i][0]]++;

        int l2;
        scanf("%d", &l2);
        l2--;

        for (int i=0; i<MAXN; i++)
            for (int j=0; j<MAXN; j++)
                scanf("%d", &array[i][j][1]);
        for (int i=0; i<MAXN; i++)
            occuring[array[l2][i][1]]++;
        
        int count = 0, value = -1;
        for (int i=1; i<=MAXN*MAXN; i++)
            if (occuring[i] == 2) {
                count++;
                value = i;
            }
        
        printf("Case #%d: ", test);
        if (count > 1)
            printf("Bad magician!\n");
        else if (count == 1)
            printf("%d\n", value);
        else
            printf("Volunteer cheated!\n");
    }
}
