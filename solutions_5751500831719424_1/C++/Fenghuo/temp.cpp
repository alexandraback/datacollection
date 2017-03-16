#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;


int main()
{
    freopen("A-large.in", "r", stdin);
    freopen("op.txt", "w", stdout);

    int T,t;
    int i,j,k;

    int n;
    int r,rr,temp,m[100],c[100];



    cin>>t;
    T=t;
    while(t--)
    {
        for (i=0;i<100;i++) {m[i]=0;c[i]=0;}
        string s[100];
        string ss;
        temp=0;
        cin>>n;
        for (i=0;i<n;i++)
            cin>>s[i];

        ss+=s[0][0];j=0;
        for (i=1;i<s[0].size();i++)
            if (s[0][i]!=ss[j])
            {
                ss+=s[0][i];j++;
            }
        //cout<<ss<<endl;

        for (k=1;k<n;k++)
        {
            string sss;
            sss+=s[k][0];j=0;
            for (i=1;i<s[k].size();i++)
                if (s[k][i]!=sss[j])
                {
                    sss+=s[k][i];j++;
                }
            //cout<<sss<<endl;
            if (sss!=ss) {temp=-1;break;}
        }
        if (temp==-1) {cout<<"Case #"<<T-t<<": Fegla Won"<<endl;continue;}

        rr=0;
        for (i=0;i<ss.size();i++)
        {
            int minii=10000000;
            for (j=1;j<=100;j++)
            {
                int mini=0;
                for (k=0;k<n;k++)
                {
                    int l=m[k];
                    while (s[k][l]==ss[i]) {l++;}
                    c[k]=l;
                    l-=m[k];

                    if (l>j) mini=mini+l-j;
                    else mini=mini+j-l;
                }
                //cout<<"j="<<j<<" mini="<<mini<<endl;
                if (mini<minii) minii=mini;
            }
            rr+=minii;//cout<<minii<<endl;
            for (int p=0;p<n;p++) m[p]=c[p];
        }


        cout<<"Case #"<<T-t<<": "<<rr<<endl;

    }
    return 0;
}
