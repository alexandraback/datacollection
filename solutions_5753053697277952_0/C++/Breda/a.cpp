#include <bits/stdc++.h>

using namespace std;

void resolver(int t)
{
    int n, q[30], i, soma = 0, ma1, ma2, i1, i2, j, er, entrou = 0;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>q[i];
        soma+=q[i];
    }
    cout<<"Case #"<<t<<": ";
    while(soma>0)
    {
        ma1 = 0;
        ma2 = 0;
        i1 = -1;
        i2 = -1;
        for(i=0;i<n;i++)
        {
            if(q[i]>ma1)
            {
                ma2 = ma1;
                ma1 = q[i];
            }
            else if(q[i]>ma2)
            {
                ma2 = q[i];
            }

        }
        for(i=0;i<n;i++)
        {
            if(q[i]==ma1 && i1==-1)
            {
                i1 = i;
                er = 0;
                for(j=0;j<n;j++)
                {
                    if(j!=i)
                    {
                        if(q[j]>=(soma-2)/2)
                        {
                            er=1;
                        }
                    }
                }
                if(er==0 && q[i]>1)
                {
                    i2 = i;
                }
            }
            else if(q[i]==ma2 && i2==-1)
            {
                i2 = i;
            }
        }
        if(entrou==1)
            printf(" ");
        if(q[i2]>0 && (q[i1]>1 || soma==2))
        {
            q[i1]--;
            q[i2]--;
            soma-=2;
            printf("%c%c", 'A'+i1, 'A'+i2);
        }
        else
        {
            q[i1]--;
            soma-=1;
            printf("%c", 'A'+i1);
        }
        entrou = 1;
    }
    cout<<endl;
}

int main()
{
    int t, i;
    cin>>t;
    for(i=1;i<=t;i++)
    {
        resolver(i);
    }
    return 0;
}
