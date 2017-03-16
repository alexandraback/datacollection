#include<stdio.h>
#include<iostream>
#include<map>
#include<set>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>

#define MOD 1000000007
#define INF 2000000000

using namespace std;

int main()
{
    int t,i,j,k,n,x;
    //ios::sync_with_stdio(false);
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    
    string s;
    string tmp,chk;
    
    vector<int> v[104];
    
    //scanf("%d",&t);
    cin>>t;
    int sv=t;
    
    while(t--)
    {
              cin>>n;
              
              int f=1;
              tmp.clear();
              chk.clear();
              
              for(i=0;i<n;i++)
              {
                              v[i].clear();
                              cin>>s;
                              tmp+=s[0];
                              
                              for(j=1;j<int(s.length());j++)
                              {
                                                       x=1;
                                                       while(j<int(s.length()) && s[j]==s[j-1])
                                                       {
                                                                          x++;
                                                                          j++;
                                                       }
                                                       
                                                       if(j<int(s.length()) && s[j]!=s[j-1])
                                                        tmp+=s[j];
                                                       
                                                       v[i].push_back(x);
                                                       //idx++;
                              }
                              //cout<<tmp<<endl;
                              
                              if(s[int(s.length())-1]!=s[int(s.length())-2])
                               v[i].push_back(1);
                              
                              if(i==0)
                              {
                                      chk=tmp;
                              }
                              else if(chk!=tmp)
                              {
                                   //cout<<s<<endl<<chk<<endl<<tmp<<endl;
                                   f=0;
                              }
                              
                              tmp.clear();
              }
              
              if(f==0)
              {
                      cout<<"Case #"<<sv-t<<": "<<"Fegla Won"<<endl;
                      continue;
              }
              
              int ans=0;
              int y=v[0].size();
              
              for(j=0;j<y;j++)
              {
                                               int temp2=INF;
                                               
                                               for(k=1;k<=100;k++)
                                               {
                                                   int temp=0;
                                                   
                                                   for(i=0;i<n;i++)
                                                   {
                                                                  
                                                                                      temp+=abs(v[i][j]-k);
                                                                   
                                                   }
                                                   temp2=min(temp2,temp);
                                               }
                                               ans+=temp2;
              }
              
              cout<<"Case #"<<sv-t<<": "<<ans<<endl;
    }
                  
                              
                              
                                                                          
    
    return 0;
}
