#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string>
#include <map>
#include <set>
#include <cmath>
#include <algorithm>
#include <vector>
#include <iterator>
#include <queue>
#include <limits.h>


#define MIN(a,b) (a>b)?b:a
using namespace std;

string A[105],B[105];

int main()
{
    freopen("F:\input.txt","r", stdin);
    freopen("F:\output.txt", "w", stdout);
    int T,N,i;
    int j,K,t;


    cin>>T;

    for(t=1; t<=T; t++)
    {
        vector<int> C[105];
        cin>>N;

        for(i=0; i<N; i++)
            cin>>A[i];

        for(i=0; i<N; i++)
        {
            B[i]="";

            B[i]+=A[i][0];

            C[i].push_back(1);

            for(j=1; j<A[i].size(); j++)
            {
                if(A[i][j]!=B[i][B[i].size()-1])
                {
                    B[i]+=A[i][j];
                    C[i].push_back(1);
                }
                else
                    C[i][C[i].size()-1]++;
            }
        }


        for(i=1; i<N; i++)
        {
            if(B[i]!=B[0])
            {
                cout<<"Case #"<<t<<": ";
                cout<<"Fegla Won\n";
                break;
            }
        }
        if(i==N)
        {
            int total=0;

            for(i=0; i<C[0].size(); i++)
            {
                int min=INT_MAX;
                for(j=0; j<N; j++)
                {
                    int totalsum=0;
                    for(K=0; K<N; K++)
                    {
                        totalsum=totalsum+abs(C[K][i]-C[j][i]);
                    }
                    if(totalsum<min) min=totalsum;
                }
                total += min;
            }
            cout<<"Case #"<<t<<": ";
            cout<<total<<endl;
        }
    }
    return 0;
}
