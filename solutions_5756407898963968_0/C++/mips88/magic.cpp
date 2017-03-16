#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#define FOR(i,n) for (int i = 0 ; i< n;i++)
#define FORI(i,s,e) for (int i = s ; i<= e;i++)
#define MP(x,y) make_pair(x,y)
#define PB(x) push_back(x)
#define ALL(x) x.begin(),x.end()
#define SZ(x) x.size()
#define FZ(x) memset(x,0,sizeof(x))
using namespace std;
FILE* fin;
FILE* fout;
int nTESTS;

int cnt[17];

void read()
{
    int r;
    FZ(cnt);
    FOR(kk,2)
    {
        fscanf(fin,"%d",&r);
        FOR(i,4)
        FOR(j,4)
        {
            int a;
            fscanf(fin,"%d",&a);
            cnt[a]+=(i==r-1);
        }
    }

}

bool cheat;
bool bad;
int lst;
void solve()
{
cheat = true;
bad = false;
    FORI(i,1,16)
    if (cnt[i] == 2)
    {
        if (!cheat)
        bad = true;
        cheat = false;
        lst = i;
    }



}

void write()
{
    if (cheat)
    fprintf(fout,"Volunteer cheated!");
    else
    if (bad)
    fprintf(fout,"Bad magician!");
    else
    fprintf(fout,"%d",lst);
}



int main()
{
    fin = fopen("input.txt","r");
    fout = fopen("output.txt","w");

    fscanf(fin,"%d",&nTESTS);

    FOR(crtTest,nTESTS)
    {
        read();
        solve();
        fprintf(fout,"Case #%d: ",crtTest+1);
        write();
        fprintf(fout,"\n");
    }
    fclose(fout);

    return 0;
}
