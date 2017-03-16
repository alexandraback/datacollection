#include"cstdio"
#include"iostream"
#include"map"
#include"string"
#include"cstring"
#include"vector"
#include"utility"
#include"algorithm"
#include"cmath"
#include"queue"
#include"stack"
#include"set"

using namespace std;
#define Nmax 19

bool vis[Nmax];

int ans;
int N;
int dx[4];
int dy[4];
int R,C;
int dfs(int ind,int cnt){
    if(ind>=R*C){return 1;}
    vis[ind]=true;
    if(cnt==N){
        //get min ans
        int cur_ans=0;
        for(int i=0;i<R;i++){
            for(int j=0;j<C;j++){
                if(j<C-1){
                    int a1=i*C+j;
                    int a2=i*C+j+1;
                    if(vis[a1]&&vis[a2]){
                        cur_ans++;
                    }
                }
                if(i>0){
                    int a1=i*C+j;
                    int a2=(i-1)*C+j;
                    if(vis[a1]&&vis[a2]){
                        cur_ans++;
                    }
                }
            }
        }
        if(cur_ans<ans){ans=cur_ans;}
    }else{
        dfs(ind+1,cnt+1);
    }
    vis[ind]=false;
    dfs(ind+1,cnt);

return 0;}

int main(){
    freopen("d:B-small-attempt0.in","r",stdin);
    freopen("d:B.out","w",stdout);

	int T;
	int casenum=0;
	cin>>T;
	while(casenum++<T){

        cin>>R>>C>>N;
        //Num=R*C;

        ans=R*(C-1)+C*(R-1);
        if(N==0)ans=0;
        else
        dfs(0,1);


        printf("Case #%d: %d\n",casenum,ans);
	}


return 0;}
