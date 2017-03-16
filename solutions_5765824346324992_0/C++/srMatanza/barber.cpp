#include <vector>
#include <iostream>
#include <string>
#include <math.h>
#include <algorithm>

using namespace std;

int lcm(vector<int> v)
{
    sort(v.begin(), v.end(), std::greater<int>());

    int l=v[0];
    for(int i=1; i<v.size(); i++)
    {
        int a = max(v[i], l);
        int b = min(v[i], l);
        if(a%b!=0)
            l=a*b;
    }

    return l;
}

int main()
{
    int N,i,j,k=0; cin>>N;

    for(int _i=0; _i<N; _i++)
    {
        int b, n; cin>>b>>n;
        int ans=0;
        vector<int> m(b);

        //cout << b << "\t" << n << endl;
        for(i=0; i<b; i++)
        {
            cin>>m[i];
            //cout << m[i] << endl;
        }

        int l = lcm(m);
        //cout << "lcm: " << l << endl;
        //ans = l-1;
        //n = n%l;
        if(n<b)
            ans=n;

        n-=b;

        bool bFound=false;
        for(i=0; i<1000 && bFound==false; i++)
        {
            for(j=0; j<b; j++)
            {
                //cout << "m[" << j<<"]:" << m[j] << "\t";
                if((i+1)%m[j] == 0) {
                    n--;
                    //cout << "j: " << j << "\t";
                }

                if(n<=0) {
                    ans=j;
                    bFound=true;
                    break;
                }
            }
        }

        cout << "Case #" << _i+1 << ": " << ans+1 << endl;
    }

    return 0;
}

