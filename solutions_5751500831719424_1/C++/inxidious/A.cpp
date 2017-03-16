#include<cstdio>
#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
#include<stack>
#include<queue>
#include<cstring>
#include<cstdlib>
#include<map>
#include<set>

using namespace std;

#define REP(i,a,b) for(int i=(a);i<=(b);i++)
#define INF 2100000000
typedef long long int ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

vii datas[105];

int main(){
    freopen("Alarge.in","r",stdin);
    freopen("output.txt","w",stdout);
    bool valid;
    int tc,n,len,count,minim,total,tmp;
    vii::iterator I;
    char str[105];
    scanf("%d",&tc);
    REP(nc,1,tc){
        valid=true;
        total=0;
        printf("Case #%d: ",nc);
        scanf("%d",&n);
        REP(i,0,n-1){
            scanf("%s",str);
            len=strlen(str);
            count=1;
            REP(j,1,len){
                if(str[j]!=str[j-1]){
                   datas[i].push_back(make_pair(str[j-1],count));
                   count=1;
                }
                else
                    count++;
            }
            if(i>0&&datas[i].size()!=datas[i-1].size())
                valid=false;
        }
        /*REP(i,0,n-1){
            for(I=datas[i].begin();I!=datas[i].end();I++)
                printf("(%c %d),",(*I).first,(*I).second);
        }*/
        if(valid){
            len = datas[0].size();
            REP(i,0,len-1){
                minim=INF;
                REP(j,0,n-1)
                    if(j>0&&datas[j][i].first!=datas[j-1][i].first)
                        valid=false;
                if(!valid)
                    break;
                REP(j,0,n-1){
                    tmp=0;
                    REP(k,0,n-1){
                        if(k==j)
                            continue;
                        //printf("(%d %d)",datas[j][i].second,datas[k][i].second);
                        tmp+=(int)abs(datas[j][i].second-datas[k][i].second);
                    }
                    if(tmp<minim)
                        minim=tmp;
                }
                total+=minim;
            }
        }
        if(valid)
            printf("%d\n",total);
        else
            printf("Fegla Won\n");
        REP(i,0,n-1)
            datas[i].clear();
    }
    return 0;
}
