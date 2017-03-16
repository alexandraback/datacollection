/*=============================================================================
#     FileName: gcj_r2ba.cpp
#         Desc: 
#       Author: zhangc
#        Email: sirnodin@gmail.com
#     HomePage: 
#      Version: 0.0.1
#     CreateOn: 2014-05-04 00:06:31
#   LastChange: 2014-05-04 00:30:22
#      History:
=============================================================================*/
#include <cstdio>
#include <iostream>
#include <string>
using namespace std;
const size_t MAX_N=150;
string strs[MAX_N];
int strs_num[MAX_N][MAX_N];
int num;
size_t TEST_CASES;
size_t N;
int ans;
string handle(size_t index)
{
    string ret="";
    string & str=strs[index];
    char c=str[0];
    ret.push_back(c);
    size_t num_p=0;
    strs_num[index][num_p]=1;
    for(size_t i=1;i<str.size();++i)
    {
        if(str[i]==c)
        {
            strs_num[index][num_p]++;
        }
        else
        {
            c=str[i];
            num_p++;
            strs_num[index][num_p]=1;
            ret.push_back(c);
        }
    }
    return ret;
}
void solve()
{
    ans=0;
    int t_ans,t_ans2;
    for(int i=0;i<num;++i)
    {
        t_ans=1000000;
        for(size_t J=0;J<N;++J)
        {
            t_ans2=0;
            for(size_t K=0;K<N;++K)
            {
                t_ans2+=abs(strs_num[J][i]-strs_num[K][i]);
            }
            t_ans=t_ans2>t_ans?t_ans:t_ans2;
        }
        ans+=t_ans;
    }
    cout<<ans<<endl;
}
void presolve()
{
    string ok_str=handle(0);
    bool ok=true;
    for(size_t K=1;K<N;++K)
    {
        if(ok_str!=handle(K))
        {
            ok=false;
            break;
        }
    }
    if(ok)
    {
        num=ok_str.size();
        solve();
    }
    else
    {
        cout<<"Fegla Won"<<endl;
    }
}
int main()
{
    cin>>TEST_CASES;
    for(size_t CASE=0;CASE<TEST_CASES;++CASE)
    {
        cin>>N;
        for(size_t i=0;i<N;++i)
        {
            cin>>strs[i];
        }
        printf("Case #%ld: ",CASE+1);
        presolve();
    }
    return 0;
}
