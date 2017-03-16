#include <iostream>
#include <stdio.h>
#include <vector>
#include <stack>
#include <queue>
#include <string.h>
#include <math.h>

using namespace std;

int main()
{
    FILE *ptr = fopen("A-small-attempt0.in", "r");
    int i, t, j, k, a, b, first[4][4], second[4][4];
    fscanf(ptr, "%d", &t);
    for(i=1; i<=t; i++)
    {
        fscanf(ptr, "%d", &a);
        for(j=0; j<4; j++)
            for(k=0; k<4; k++)
                fscanf(ptr, "%d", &first[j][k]);
        fscanf(ptr, "%d", &b);
        for(j=0; j<4; j++)
            for(k=0; k<4; k++)
                fscanf(ptr, "%d", &second[j][k]);

        int count = 0;
        int ans = 0;
        for(j=0; j<4; j++)
        {
            for(k=0; k<4; k++)
            {
                if(first[a-1][j]==second[b-1][k])
                {
                    ans = first[a-1][j];
                    count++;
                }
            }
        }
        if(count==0)
            cout<<"Case #"<<i<<": Volunteer cheated!\n";
        else if(count==1)
            cout<<"Case #"<<i<<": "<<ans<<"\n";
        else
            cout<<"Case #"<<i<<": Bad magician!\n";
    }
    fclose(ptr);
    return 0;
}
