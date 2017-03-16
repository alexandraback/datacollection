#include<stdio.h>
#include<string>
#include<string.h>
#include<stdlib.h>
using namespace std;

char inp[111][111];
int n;

string NORM;

string norm(int k){
    string ret="";
    for(int i = 0; inp[k][i]; ++i) if(i == 0 || inp[k][i]!=inp[k][i-1]) ret += inp[k][i];
    return ret;
}

int main(){
    freopen("A-small-attempt0.in","r",stdin);
    freopen("A_small_out.txt","w",stdout);

   	int T;scanf("%d",&T);
   	for(int t=1;t<=T;++t){
  		scanf("%d",&n);
		for(int i=0;i<n;++i)scanf("%s",inp[i]);
		bool fegla = false;
        NORM = norm(0);
        for(int i=0;i<n;++i)if(i>0 && norm(i) != NORM) fegla=1;

        printf("Case #%d: ",t);

        if(fegla) printf("Fegla Won\n");
        else{
            int ans = 0;
            int idx[111];
            memset(idx,0,sizeof(idx));
            for(int i = 0; i < NORM.size(); ++i){
                int tot = 0;
                int cnt[111]; memset(cnt,0,sizeof(cnt));
                for(int j = 0; j < n; ++j){
                    while(inp[j][idx[j]] && inp[j][idx[j]] == NORM[i]) ++tot, ++idx[j], ++cnt[j];
                }
                int avg = tot/n;
                for(int j=0;j<n;++j) ans += abs(avg - cnt[j]);
            }

            printf("%d\n",ans);
        }
    }
    	return 0;
}
