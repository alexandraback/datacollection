#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;

const int INF = 1000000007;

int main(){
    int cs,no=0;
    scanf("%d",&cs);
    while(cs--){
        int n;
        scanf("%d",&n);
        vector<string> u[100];
        string a[100];
        for(int i=0;i<n;i++){
            char s[105];
            scanf("%s",s);
            u[i].push_back("");
            for(int j=0;s[j];j++){
                u[i].back()+=s[j];
                if(s[j]!=s[j+1]) u[i].push_back("");
            }
            u[i].pop_back();
            for(auto& s:u[i]) a[i]+=s[0];
        }
        printf("Case #%d: ",++no);
        bool ok=true;
        for(int i=1;i<n;i++) if(a[i]!=a[0]) ok=false;
        if(!ok){
            puts("Fegla Won");
        }else{
            int m=a[0].size(),ans=0;
            for(int i=0;i<m;i++){
                vector<int> c;
                for(int j=0;j<n;j++) c.push_back(u[j][i].size());
                int lo=*min_element(c.begin(),c.end());
                int hi=*max_element(c.begin(),c.end());
                int use=INF;
                for(int x=lo;x<=hi;x++){
                    int cnt=0;
                    for(int j=0;j<n;j++) cnt+=abs(x-c[j]);
                    use=min(use,cnt);
                }
                ans+=use;
            }
            printf("%d\n",ans);
        }
    }
}
