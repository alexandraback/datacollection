#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<utility>
#include<vector>
#include<queue>
#include<set>
#include<map>
#include<string>
#include<cmath>
using namespace std;
#define PB push_back
#define PPB pop_back
#define MP make_pair
#define LL long long
#define ULL unsigned long long
#define fs first
#define sc second
#define pii pair<int,int>
#define pll pair<LL,LL>
#define ppii pair< pii,int >
#define big 2000000000
#define N 105

int avg,sum,kasus,jawab,jml,p,pjgtemp;
int las[N],pjg[N],cnt[N];
char kata[N][N];
bool bisa;
string temp;

int bul(int a,int b) {return (a > b) ? a-b : b-a;}

int main()
{
//    freopen("A-large.in","r",stdin);
//    freopen("a-large.out","w",stdout);
    scanf("%d",&kasus);
    for (int z=1;z<=kasus;z++)
    {
        scanf("%d",&jml);
        jawab = 0;
        for (int i=0;i<jml;i++)
        {
            scanf("%s",kata[i]);
            pjg[i] = strlen(kata[i]);
        }
        bisa = true;
        
        //making template
        temp = kata[0][0];
        for (int i=1;i<pjg[0];i++)
            if (kata[0][i] != kata[0][i-1])
                temp += kata[0][i];
        pjgtemp = temp.length();

        //cek keabsahan tiap kata
        for (int i=1;i<jml && bisa;i++)
        {
            p = 0;
            for (int j=0;j<pjg[i] && bisa;j++)
            {
                if (j==0)
                {
                    if (kata[i][j] != temp[p]) bisa = false;
                    p++;
                }
                else
                {
                    if (kata[i][j] == kata[i][j-1]) continue;
                    else if (p == pjgtemp) bisa = false;
                    else if (kata[i][j] != temp[p]) bisa = false;
                    p++;
                }
            }
            if (p != pjgtemp) bisa = false;
        }
        
        printf("Case #%d: ",z);
        if (!bisa) printf("Fegla Won\n");
        else
        {
            jawab = 0;
            memset(las,0,sizeof(las));
            for (int i=0;i<pjgtemp;i++)
            {
                sum = 0;
                for (int j=0;j<jml;j++)
                {
                    cnt[j] = 0;
                    while (las[j] < pjg[j] && kata[j][las[j]]==temp[i])
                    {
                        las[j]++;
                        cnt[j]++;
                        sum++;
                    }
                }
                avg = sum/jml;
                if (2 * (sum%jml) > sum) avg++;
//                cout << temp[i] << " " << sum << " " << avg << endl;
                
                for (int j=0;j<jml;j++) jawab += bul(cnt[j],avg);
            }
            printf("%d\n",jawab);
        }
    }
//    fclose(stdin);
//    fclose(stdout);
    return 0;
}
