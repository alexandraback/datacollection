#include <vector>
#include <string>
#include <cstring>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <ctime>
using namespace std;
#define length(x) (int)x.size()
const double pi=acos(-1);

int vt1[100], vt2[100];

void xuli()
{
    int sh1, sh2, luu, sl, x;
    cin>>sh1;
    for(int i=1; i<=4; i++)
        for(int j=1; j<=4; j++)
        {
            cin>>x; vt1[x] = i;
        }
    cin>>sh2;
    for(int i=1; i<=4; i++)
        for(int j=1; j<=4; j++)
        {
            cin>>x; vt2[x] = i;
        }
    sl = 0; luu = 0;
    for(int i=1; i<=16; i++)
        if (vt1[i] == sh1 && vt2[i] == sh2)
    {
        sl++; luu = i;
    }
    if (sl > 1)
        cout<<"Bad magician!"<<endl;
    else
        if (sl == 1)
            cout<<luu<<endl;
        else
            cout<<"Volunteer cheated!"<<endl;
}

int main()
{
     freopen("input.inp","r",stdin);
     freopen("output.out","w",stdout);
     int test, sotest;
     cin>>sotest;
     for(test = 1; test <= sotest; test++)
     {
         cout<<"Case #"<<test<<": ";
         xuli();
     }
     return 0;
}
