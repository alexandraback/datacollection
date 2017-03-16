//#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>
#include<vector>
#include<cmath>
#include<fstream>

using namespace std;

ifstream cin ("1Ba.in");
ofstream cout ("1BD.out");


int main()
{
    int N, T, i, j, k, moves, tcase, sum, TOT, min;
    bool poss;
    string IN[101];
    int ct[101], p[101];
    char curr = 'x';
    cin>>T;
    for ( tcase = 1; tcase <= T; tcase++ )
    {
        cin>>N;
        poss = true; TOT = 0;
        memset(ct,0,sizeof(ct));
        memset(p,0,sizeof(p));
        for ( i = 0; i < N; i++ )
        {
            cin>>IN[i];

        }

        while ( 1 )
        {

            min = 0;
            sort(p,p+N);
            for ( i = 0; i < N; i++ )
            {
                min += abs(p[i]- p[N/2]);

            }
            TOT += min;

            for ( i = 0; i < N; i++ )
            {
                if ( IN[i][ct[i]] != '\0' ) break;
            }
            if ( i == N ) break;

            memset(p,0,sizeof(p));
            for ( i = 0; i < N; i++ )
            {

                if ( !i )
                {
                    curr = IN[0][ct[0]];
//                    cout<<curr<<endl;
                }
                else if ( IN[i][ct[i]] != curr )
                {
                    poss = false;
                    break;
                }


                while ( 1 )
                {
                    ct[i]++;
                    p[i]++;
                    if ( IN[i][ct[i]] != curr )
                    {
                        break;
                    }
                }
//                cout<<"i "<<i<<" ct "<<ct[i]<<" p "<<p[i]<<endl;
            }
            if ( !poss ) break;

        }
        cout<<"Case #"<<tcase<<": ";
        if ( poss )
        {
            cout<<TOT<<endl;
        }
        else
        {
            cout<<"Fegla Won"<<endl;
        }

    }

    return 0;
}
