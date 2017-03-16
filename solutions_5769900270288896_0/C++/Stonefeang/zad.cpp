#include <cstdio>
#include <bitset>
#include <algorithm>
using namespace std;

int t;
int n, r, c;

int tab[20][20];
int ile;
int wyn;
bitset <50> bity;
int aktu;

int main()
{
    scanf("%d", &t);
    for (int h=1; h<=t; h++)
    {
        scanf("%d%d%d", &r, &c, &n);
        wyn=1000000;
        for (int i=0; i<(1<<(r*c)); i++)
        {
            bity=i;
            ile=0;
            for (int j=0; j<r*c; j++)
            {
                if (bity[j])
                {
                    ile++;
                }
            }
            if (ile!=n)
            {
                continue;
            }
            for (int j=0; j<=19; j++)
            {
                for (int l=0; l<=19; l++)
                {
                    tab[j][l]=0;
                }
            }
            for (int j=1; j<=r; j++)
            {
                for (int l=1; l<=c; l++)
                {
                    tab[j][l]=bity[(j-1)*c+l-1];
                }
            }
            aktu=0;
            for (int j=1; j<=r; j++)
            {
                for (int l=1; l<=c; l++)
                {
                    aktu+=(tab[j][l]+tab[j+1][l]==2);
                    aktu+=(tab[j][l]+tab[j][l+1]==2);
                }
            }
            wyn=min(aktu, wyn);
        }
        printf("Case #%d: %d\n", h, wyn);
    }
    return 0;
}
