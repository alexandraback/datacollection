/* بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ */
/* رَّبِّ زِدْنِى عِلْمًا */



#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <iostream>
#include <string>
#include <map>
#include <list>
#include <stack>

using namespace std;

#define OUTPUT freopen("myfile.txt","w",stdout);
#define INPUT freopen("A-small-attempt0 (2).in","r",stdin);
#define DEBUG(a) cout<<a<<endl;
#define PI acos(-1.0)
#define MAX 100005
#define MOD 1000000009
#define EPS 1e-9
#define BIGGER(a,b) (a>=b ? a : b)
#define SMALLER(a,b) (a<=b ? a : b)
#define getInt(a) scanf("%d",&a);
#define getLong(a) scanf("%lld",&a);
#define pb push_back
#define ppb pop_back

#define INF 1000000000


int main()
{
    //Bismillahir Rahmanir Rahim
    //Rabbi Zidni Ilma

    int T,tp;
    int N;
    int P[40];
    int total,half;
    int test,check;
    vector <int> a;
    vector <int> b;
    int i,j;

    INPUT
    OUTPUT

    getInt(T)

    while(T--)
    {
        getInt(N)

        total=0;

        for(i=0;i<N;i++)
        {
            getInt(P[i])
            total+=P[i];
        }

        while(total>0)
        {
            test=0;

            for(i=0;i<N;i++)
            {
                check=1;

                if(P[i]>0)
                    P[i]--;
                else
                    continue;

                total--;
                half=total/2;

                for(j=0;j<N;j++)
                {
                    if(P[j]>half)
                    {
                        check=0;
                        break;
                    }
                }

                if(check==1)
                {
                    a.pb(i);
                    b.pb(-1);
                    test=1;
                    break;
                }

                else
                {
                    P[i]++;
                    total++;
                }
            }

            if(test==1)
                continue;

            for(i=0;i<N;i++)
            {
                for(j=0;j<N;j++)
                {
                    check=1;

                    if(P[i]>0)
                        P[i]--;
                    else
                        continue;

                    if(P[j]>0)
                        P[j]--;
                    else
                    {
                        P[i]++;
                        continue;
                    }

                    total-=2;

                    half=total/2;

                    for(int k=0;k<N;k++)
                    {
                        if(P[k]>half)
                        {
                            check=0;
                            break;
                        }
                    }

                    if(check==1)
                    {
                        a.pb(i);
                        b.pb(j);
                        break;
                    }

                    else
                    {
                        P[i]++;
                        P[j]++;
                        total+=2;
                    }
                }
            }

        }

        printf("Case #%d:",tp );
        tp++;

        for(i=0;i<a.size();i++)
        {
            printf(" %c",a[i]+'A');

            if(b[i]!=-1)
                printf("%c",b[i]+'A');
        }

        printf("\n");

        a.clear();
        b.clear();

    }


    return 0;
}

