#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<vector>
#include<cassert>
#include<set>
#include<queue>
#include<map>

using namespace std;

#define vi vector < int >
#define pb push_back
#define ll long long
#define llu unsigned long long
#define MOD 1000000007
#define INF 2000000000
#define dbg(x) { cout<< #x << ": " << (x) << endl; }
#define all(x) x.begin(),x.end()
string s[102];
int cnt[102][26];
int n;
vector <int> len[102];
vector <int> a[102];

int get()
{
    int ret = 0;
    int i,j;
    for(i=0;i<n;i++)
    {
       for(j=0;j<len[i].size();j++)
       {
          a[j].pb(len[i][j]);
       }
    }
    
    for(i=0;i<len[0].size();i++)
    {
       sort(all(a[i]));
       
       for(j=0;j<n;j++)
       {
                     //  cout<<a[i][j]<<" ";
          ret += abs(a[i][j] - a[i][n/2]); 
       }
       //cout<<endl;
    }
    return ret;
}


int main()
{
    freopen("A.in","r",stdin);
    freopen("A.out","w",stdout);
    int t,tc=1,i,j;
    scanf("%d",&t);
    while(t--)
    {
              scanf("%d",&n);
              set <string> st;
              int f = 1;
              for(i=0;i<n;i++)
              {
                 cin>>s[i];
                 len[i].clear();
                 a[i].clear();
              }
              for(i=0;i<n;i++)
              {
                 string a = "";
                 char pre = '!';
                 int l = 0;
                 for(j=0;j<s[i].size();j++)
                 {
                    if(s[i][j] != pre)
                    {
                       if(pre != '!')
                       len[i].pb(l);
                       pre = s[i][j];
                       a+=pre;
                       l = 1;
                    }
                    else
                    {
                        l++;
                    }
                 }  
                 
                 if(l>0)
                 {
                        len[i].pb(l);
                 }
                 
                 if(st.find(a)==st.end() && i)
                 {
                    f = 0;
                    break;
                 }
                 else
                 {
                     st.insert(a);
                 }
              }
              printf("Case #%d: ",tc++);
              if(f)
              {
                   int ans = get();
                   printf("%d\n",ans);
              }
              else
              {
                  printf("Fegla Won\n");
              }
    }
    //system("pause");
    return 0;
}
