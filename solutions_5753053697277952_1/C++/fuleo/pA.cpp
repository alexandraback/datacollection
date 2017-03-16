/*************************************************************************
	> File Name: pA.cpp
	> Author: fuyu0425/a0919610611
	> School: National Chiao Tung University
	> Team: NCTU_Ragnorok
	> Mail: a0919610611@gmail.com
	> Created Time: 2016/05/08 17:06:23   
 ************************************************************************/
#define op_io ios_base::sync_with_stdio(false); cin.tie(NULL);
#include <bits/stdc++.h>
using namespace std;
struct S
{
    int num,no;
    bool operator < (const S & a) const
    {
        return num>a.num;
    }
};
int n;
S p[30]={};
bool check(int total)
{
    for(int i=1;i<=n;i++)
    {
        if((double)p[i].num/total>0.5)
            
            return false;
    }
    return true;
}
int main()
{
    op_io;
    int T;
    cin>>T;
    int kase=0;
    while(T--)
    {
        if(kase++) cout<<endl;
        cout<<"Case #"<<kase<<":";
        cin>>n;
        int total=0;
        for(int i=1;i<=n;i++)
        {
            cin>>p[i].num;
            total+=p[i].num;
            p[i].no=i;
        }
        while(total>0)
        {
        //    cout<<total<<endl;
            string ans="";
            int t=0;
            sort(p+1,p+1+n);
            p[1].num--;total--;
            ans+=(char)p[1].no+'A'-1;
            if(!check(total))
            {
                sort(p+1,p+1+n);
            p[1].num--;total--;
            ans+=(char)p[1].no+'A'-1;
            }
            cout<<" "<<ans;
        }
    }
    return 0;
}
