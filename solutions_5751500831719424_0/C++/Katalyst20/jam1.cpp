#include<iostream>
#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;
int main()
{
    freopen("inp.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int n,t,i,j,k,l,test;
    cin>>t;
    for(test=1;test<=t;test++)
    {
        cin>>n;
        string s[n];
        for(i=0;i<n;i++)
            cin>>s[i];
        int co_arr[n][10000];
        int k_arr[10000],l=0;
        string str[n];
        int maxi[10000];
        maxi[-1]=0;
        for(i=0;i<n;i++)
        {
            for(j=0;j<10000;j++)
            {
                co_arr[i][j]=1;
                maxi[j]=0;
            }
        }
        for(i=0;i<n;i++)
        {
            k=0;
            for(j=0;j<s[i].length();j++)
            {
                if(s[i][j]==s[i][j+1])
                    co_arr[i][k]++;
                else
                {
                    //maxi[k]=max(maxi[k-1],co_arr[i][k]);
                    k++;
                    str[i]=str[i]+char(s[i][j]);
                }
            }
           /* cout<<str[i]<<": ";
            for(j=0;j<str[i].length();j++)
                cout<<co_arr[i][j]<<" ";
                cout<<endl<<endl;
*/
        }
        //checks
        /*for(i=0;i<n;i++)
            cout<<str[i]<<endl;
*/
        int f=1;
        for(i=0;i<n-1;i++)
        {
            if(str[i]!= str[i+1])
            {
                f=0;
                break;
            }
        }
        if(f==0)
        {
            cout<<"Case #"<<test<<": ";
            cout<<"Fegla Won"<<endl;
            continue;
        }
        int max1=0,max2=0;
        for(i=0;i<str[0].length();i++)
        {
            max1=0;
            for(j=0;j<n;j++)
            {
                max1=max(max1,co_arr[j][i]);
            }
            maxi[i]=max1;
        }
  /*      cout<<"maxAr  ";
        for(i=0;i<str[0].length();i++)
            cout<<maxi[i]<<" ";
            cout<<endl;
*/

        long int final1,out1=0,fin1=0,co;
        for(j=0;j<str[0].length();j++)
        {

            final1=99999999;
            for(co=1;co<=maxi[j];co++)
            {
                    fin1=0;
                    for(i=0;i<n;i++)
                    {
                        fin1+= abs(co_arr[i][j]-co);
                    }
                    final1=min(final1,fin1);
            }
            out1+=final1;
        }

    cout<<"Case #"<<test<<": ";
    cout<<out1<<endl;
    }


    return 0;
}
