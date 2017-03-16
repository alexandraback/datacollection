/*
    xxx_joker/codersumit
*/
#include <bits/stdc++.h>
#define bitcnt(x) __builtin_popcountll(x)
#define sd(a) scanf("%d",&a)
#define sld(a) scanf("%lld",&a)
#define ss(a) scanf("%s",a)
#define sc(a) scanf("%c",&a)
#define pd(a) printf("%d",a)
#define ps(a) printf("%s",a)
#define pc(a) printf("%c",a)
#define space printf(" ");
#define nw printf("\n")
#define pb push_back
#define FOR(i,a,b) for(i=a;i<b;i++)
#define FORR(i,a,b) for(i=a;i>=b;i--)
#define all(v) v.begin(),v.end()
#define mp make_pair
#define MAX 1000005
#define MAXX 1<<13
#define inf 1e9
#define mod 1000000007

typedef long long ll;
typedef unsigned long long ull;
using namespace std;
inline void fastread(int *a)
{
 register char c=0;
 while (c<33) c=getchar();
 *a=0;
 while (c>33)
 {
     *a=*a*10+c-'0';
     c=getchar();
 }
}
/*int dfs(int num){
    cout<<"num= "<<num<<endl;
    if(num<=1)
        return 1;
    if(ans[num]!=-1)
        return ans[num];
    int rev,temp,a,b,dig,flag=0;
    a=b=1e8;
    if(visit[num-1]==0){
        visit[num-1]=1;
        a=1+dfs(num-1);
    }
    temp=num;
    rev=0;
    while(temp>0){
        dig=temp%10;
        if(dig==0 && flag==0){
            temp/=10;
            continue;
        }
        else if(dig!=0)
            flag=1;
        rev=(rev*10)+dig;
        temp/=10;
    }
    //cout<<"rev= "<<rev<<endl;
    if(visit[rev]==0){
        visit[rev]=1;
        b=1+dfs(rev);
    }
    a=min(a,b);
    ans[num]=a;
    return a;
}*/
queue<pair<int,int> > q;
int visit[17][17]={0};
int main(){//while(1){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int ans,test,k=1,r,c,n,temp,x,y,cnt,flag=0,i,j;
    sd(test);
    while(test--){
        flag=ans=0;
        /*if(k>1){
        FOR(i,0,r){
            FOR(j,0,c){
                cout<<visit[i][j]<<" ";
            }
            cout<<endl;
        }
        }*/
        sd(r);sd(c);sd(n);
        FOR(i,0,r){
            FOR(j,0,c)
                visit[i][j]=1;
        }
        ans=(r*(c-1));
        ans+=(c*(r-1));
        cnt=r*c;
        if(cnt==n){
            printf("Case #%d: %d\n",k,ans);
            k++;
            continue;
        }
        FOR(i,0,r){
            FOR(j,0,c){
                if(visit[i][j]){
                    temp=0;
                    if((i-1)>=0)
                        temp+=visit[i-1][j];
                    if((i+1)<r)
                        temp+=visit[i+1][j];
                    if((j-1)>=0)
                        temp+=visit[i][j-1];
                    if((j+1)<c)
                        temp+=visit[i][j+1];
                    if(temp==4){
                        visit[i][j]=0;
                        cnt--;
                        ans-=4;
                    }
                    if(cnt==n){
                        flag=1;
                        break;
                    }
                }
            }
        }
        if(flag==1){
            printf("Case #%d: %d\n",k,ans);
            k++;
            continue;
        }
        FOR(i,0,r){
            FOR(j,0,c){
                if(visit[i][j]){
                    temp=0;
                    if((i-1)>=0)
                        temp+=visit[i-1][j];
                    if((i+1)<r)
                        temp+=visit[i+1][j];
                    if((j-1)>=0)
                        temp+=visit[i][j-1];
                    if((j+1)<c)
                        temp+=visit[i][j+1];
                    if(temp==3){
                        visit[i][j]=0;
                        cnt--;
                        ans-=3;
                    }
                    if(cnt==n){
                        flag=1;
                        break;
                    }
                }
            }
        }
        if(flag==1){
            printf("Case #%d: %d\n",k,ans);
            k++;
            continue;
        }
        FOR(i,0,r){
            FOR(j,0,c){
                if(visit[i][j]){
                    temp=0;
                    if((i-1)>=0)
                        temp+=visit[i-1][j];
                    if((i+1)<r)
                        temp+=visit[i+1][j];
                    if((j-1)>=0)
                        temp+=visit[i][j-1];
                    if((j+1)<c)
                        temp+=visit[i][j+1];
                    if(temp==2){
                        visit[i][j]=0;
                        cnt--;
                        ans-=2;
                    }
                    if(cnt==n){
                        flag=1;
                        break;
                    }
                }
            }
        }
        if(flag==1){
            printf("Case #%d: %d\n",k,ans);
            k++;
            continue;
        }
        FOR(i,0,r){
            FOR(j,0,c){
                if(visit[i][j]){
                    temp=0;
                    if((i-1)>=0)
                        temp+=visit[i-1][j];
                    if((i+1)<r)
                        temp+=visit[i+1][j];
                    if((j-1)>=0)
                        temp+=visit[i][j-1];
                    if((j+1)<c)
                        temp+=visit[i][j+1];
                    if(temp==1){
                        visit[i][j]=0;
                        cnt--;
                        ans-=1;
                    }
                    if(cnt==n){
                        flag=1;
                        break;
                    }
                }
            }
        }
        if(flag==1){
            printf("Case #%d: %d\n",k,ans);
            k++;
            continue;
        }
        FOR(i,0,r){
            FOR(j,0,c){
                if(visit[i][j]){
                    temp=0;
                    if((i-1)>=0)
                        temp+=visit[i-1][j];
                    if((i+1)<r)
                        temp+=visit[i+1][j];
                    if((j-1)>=0)
                        temp+=visit[i][j-1];
                    if((j+1)<c)
                        temp+=visit[i][j+1];
                    if(temp==0){
                        visit[i][j]=0;
                        cnt--;
                        ans-=0;
                    }
                    if(cnt==n){
                        flag=1;
                        break;
                    }
                }
            }
        }
        if(flag==1){
            printf("Case #%d: %d\n",k,ans);
            k++;
            continue;
        }
    }
    return 0;
}
