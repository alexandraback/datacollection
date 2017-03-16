#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

pair<int,int> max_and_length(vector<int>& ps)
{
    int mx=*max_element(ps.begin(),ps.end());
    int cnt=0;
    for(int i=0;i<ps.size();i++)
    {
        if(ps[i]==mx)
            cnt++;
    }
    return make_pair(mx,cnt);
}

char int_to_char(int i)
{
    return (char)((int)'A'+i);
}

int main()
{
    ifstream in;
    ofstream out;
    in.open("in.in");
    out.open("out.txt");
    int T,N;
    vector<int> ps;
    in>>T;
    int t,mx,cnt,sum;
    pair<int,int> tmp;
    for(t=1;t<=T;t++)
    {
        in>>N;
        ps.resize(N);
        for(int i=0;i<N;i++)
            in>>ps[i];
        sum=0;
        sum=accumulate(ps.begin(),ps.end(),0);
        out<<"Case #"<<t<<": ";
        while(sum>0)
        {
            tmp=max_and_length(ps);
            mx=tmp.first;
            cnt=tmp.second;
            if (cnt>2)
            {
                for(int i=0;i<N;i++)
                {
                    if(ps[i]==mx)
                    {
                        ps[i]--;
                        out<<int_to_char(i)<<" ";
                        sum--;
                        break;
                    }
                }
            }
            if (cnt==2)
            {
                for(int i=0;i<N;i++)
                {
                    if(ps[i]==mx)
                    {
                        ps[i]--;
                        sum--;
                        out<<int_to_char(i);
                        break;
                    }
                }
                for(int i=0;i<N;i++)
                {
                    if(ps[i]==mx)
                    {
                        ps[i]--;
                        sum--;
                        out<<int_to_char(i)<<" ";
                        break;
                    }
                }
            }
            if (cnt==1)
            {
                for(int i=0;i<N;i++)
                {
                    if(ps[i]==mx)
                    {
                        ps[i]--;
                        out<<int_to_char(i)<<" ";
                        sum--;
                        break;
                    }
                }
            }
        }
        out<<endl;
    }

    in.close();
    out.close();
    return 0;
}
