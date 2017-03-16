/*
Google Code Jam 2016
Round 1C
AUTHOR: Phawin Prongpaophan
*/

#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;

int n;
int p[111];
int sum;
int party;

void showme()
{
    for(int i=0;i<n;i++) printf("%c: %d ",i+'A',p[i]);
    printf("\n");
}

void each(int tc)
{
    sum=0;
    scanf("%d",&n);
     party = n;
    for(int i=0;i<n;i++) {scanf("%d",&p[i]); sum+=p[i];}
    printf("Case #%d: ",tc);
    while(party>2)
    {
        int curbest = -1; int ind = -1;
        for(int i=0;i<n;i++)
            {
                if(p[i]<=curbest) continue;
        curbest = p[i];
        ind = i;
            }
        //Evacuate
        printf("%c ",'A'+ind);
        p[ind]--; sum--;
        if(p[ind]<=0) party--;
        //showme();
    }
    //Phase 2
    vector<int> left;
    vector<char> par;
    for(int i=0;i<n;i++)
    {
        if(p[i]==0) continue;
        left.push_back(p[i]);
        par.push_back('A'+i);
    }
    if(left[0]<left[1])
    {
        swap(left[0],left[1]);
        swap(par[0],par[1]);
    }
    //Make It Equal
    while(left[0]>left[1])
    {
        left[0]--;
        printf("%c ",par[0]);
    }
    while(left[0]>0)
    {
        printf("%c%c ",par[0],par[1]);
        left[0]--; left[1]--;
    }
    printf("\n");
    return;
}

int main()
{
    freopen("Ain.in","r",stdin);
    freopen("Aout.txt","w",stdout);

    int tcc; scanf("%d",&tcc);
    for(int tcnt=1;tcnt<=tcc;tcnt++)    each(tcnt);
    return 0;
}
