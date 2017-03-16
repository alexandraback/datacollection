#include <bits/stdc++.h>
using namespace std;
int test;
int t[31];
int n;
string abc;
int main()
{
    abc="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    cin>>test;
    for(int tt=1; tt<=test; tt++)
    {
        cin>>n;
        int sum=0;
        for(int i=1; i<=n; i++)
        {
            cin>>t[i];
            sum+=t[i];
        }
        cout<<"Case #"<<tt<<":";
        int eh, e, mh, m;
        e=0;
        m=0;
        eh=-1;
        mh=-1;
        for(int i=1; i<=n; i++)
            {
                if(t[i]>e)
                {
                    m=e;
                    mh=eh;
                    e=t[i];
                    eh=i;
                }
                else if(t[i]>m)
                {
                    m=t[i];
                    mh=i;
                }
            }
            if(e>m+1)
            {
                cout<<" "<<abc[eh-1]<<abc[eh-1];
                    t[eh]--;
                    t[eh]--;
            }
        int maxihely=1;
        if(sum%2==1)
        {
            for(int i=1; i<=n; i++)
            {
                if(t[maxihely]<t[i]) maxihely=i;
            }
            t[maxihely]--;
            cout<<" "<<abc[maxihely-1];
        }
        while(1)
        {
            int elsoh, elso, masoh, maso;
            elso=0;
            maso=0;
            elsoh=-1;
            masoh=-1;
            for(int i=1; i<=n; i++)
            {
                if(t[i]>elso)
                {
                    maso=elso;
                    masoh=elsoh;
                    elso=t[i];
                    elsoh=i;
                }
                else if(t[i]>maso)
                {
                    maso=t[i];
                    masoh=i;
                }
            }
            if(maso==0 && elso==0) break;
            if(maso==0)
            {
                cout<<" "<<abc[elsoh-1];
                t[elsoh]--;
                if(t[elsoh]>0)
                {
                    cout<<abc[elsoh-1];
                    t[elsoh]--;
                }
            }
            else
            {
                if(elso>maso)
                {
                    cout<<" "<<abc[elsoh-1]<<abc[elsoh-1];
                    t[elsoh]--;
                    t[elsoh]--;
                }
                else
                {
                    cout<<" "<<abc[elsoh-1]<<abc[masoh-1];
                    t[elsoh]--;
                    t[masoh]--;
                }
            }
        }
        cout<<endl;
    }
    return 0;
}
