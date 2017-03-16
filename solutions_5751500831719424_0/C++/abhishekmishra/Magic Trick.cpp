#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
vector<string> v;
vector<int> nchar;
int main()
{
    freopen("A-small-attempt0.in","r",stdin);
    freopen("A-small-attempt0.out","w",stdout);
    int t,i,n,cnt,ans,l,j,f,cse=1,tmp,sum,avg;
    string s;
    char c;
    cin>>t;
    while(t--)
    {
        v.clear();
        f=0;
        ans=0;
        nchar.clear();
        cin>>n;
        nchar.resize(n);
        for(i=0;i<n;i++)
        {
            cin>>s;
            v.push_back(s);
        }
        f=0;
        while(1)
        {
            c='0';
            if(v[0].begin()!=v[0].end())
            {
                c = v[0][0];
            }
            //cout<<c<<endl;
            if(c=='0')
            {
                for(i=1;i<n;i++)
                {
                    if(v[i].begin()!=v[i].end())
                    {
                        break;
                    }
                }
                if(i!=n)
                {
                    f=1;
                    //cout<<"Case #"<<cse++<<": "<<"Fegla Won"<<endl;
                    //continue;
                }
                break;
            }
            for(i=0;i<n;i++)
            {
                nchar[i]=0;
            }
            for(i=0;i<n;i++)
            {
                j=0;
                cnt=0;
                l=v[i].size();
                while(j<l && v[i][j]==c)
                {
                    cnt++;
                    j++;

                }
                if(cnt==0)
                {
                    //f=1;
                    break;
                }
                nchar[i]=cnt;
                v[i].erase(0,cnt);
            }
            if(i!=n)
            {
                f=1;
                break;
                //cout<<"Case #"<<cse++<<": "<<"Fegla Won"<<endl;
                //continue;
            }
            else
            {
                sum=0;
                tmp=0;
                for(i=0;i<n;i++)
                {
                    sum+=nchar[i];
                }
                avg=sum/n;
                for(i=0;i<n;i++)
                {
                    if(avg>nchar[i])
                    {
                        tmp+=(avg-nchar[i]);
                    }
                    else
                    {
                        tmp+=(nchar[i]-avg);
                    }
                }
                ans+=tmp;
            }
        }
        if(f==0)
        {
            cout<<"Case #"<<cse++<<": "<<ans<<endl;
        }
        else
        {
            cout<<"Case #"<<cse++<<": "<<"Fegla Won"<<endl;
        }

    }
    return 0;
}
