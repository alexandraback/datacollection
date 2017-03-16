#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
using namespace std;
int main()
{
    ifstream cin("A-small-attempt0.in");
    ofstream cout("output.txt");
    int n, i;
    cin>>n;
    for (i=0;i<n;++i)
    {
        int x, y, j, k, z, res, r=0;
        map<int, int> m;
        cin>>x;
        for (j=0;j<4;++j)
        {
            for (k=0;k<4;++k)
            {
                cin>>z;
                if (j==x-1)
                {
                    ++m[z];
                }
            }
        }
        cin>>x;
        for (j=0;j<4;++j)
        {
            for (k=0;k<4;++k)
            {
                cin>>z;
                if (j==x-1)
                {
                    ++m[z];
                }
            }
        }
        for (j=1;j<=16;++j)
        {
            if (m[j]==2)
            {
                ++r;
                res=j;
            }
        }
        cout<<"Case #"<<i+1<<": ";
        if (r>1)
        {
            cout<<"Bad magician!\n";
        }
        else if (r==0)
        {
            cout<<"Volunteer cheated!\n";
        }
        else
        {
            cout<<res<<endl;
        }
    }
    return 0;
}
