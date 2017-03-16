#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
#include <queue>
using namespace std;
int arr[30];
int n;
int sum;
priority_queue< pair<int,int> > p;

void out(bool check)
{
    if(p.empty())return;
    int num = p.top().first;
    int id = p.top().second;

    p.pop();


    //CHECK
    if(check&&!p.empty())
    {
        int tnum = p.top().first;
        if((sum-1)/2<tnum)
        {
            p.push(make_pair(num,id));
            return;
        }
    }

    cout<<(char)('A'+id);
    num--;
    sum--;
    if(num>0)
    {
        p.push(make_pair(num,id));
    }

}
int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int t;
    cin>>t;
    for(int ti=1;ti<=t;ti++)
    {
        cout<<"Case #"<<ti<<": ";
        cin>>n;
        sum=0;
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
            sum+=arr[i];
            p.push(make_pair(arr[i],i));
        }
        bool flag=false;
        while(!p.empty())
        {
            if(!flag)
            {
                cout<<' ';
            }
            else
            {
                flag=true;
            }
            out(false);
            out(true);
        }


        cout<<endl;
    }

    return 0;
}
