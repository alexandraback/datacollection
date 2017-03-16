#include<cstdio>
#include<string>
#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;
int main(){
    int t,c,n,i,j,k,ans;
    char s[200][200],pre;
    int a[200][200],len[200];
    scanf("%d",&t);
    for(c=1;c<=t;c++){
        scanf("%d",&n);
        for(i=0;i<n;i++){
            scanf("%s",s[i]);
            len[i]=0;
            pre=0;
            for(j=0;s[i][j];pre=s[i][j++]){
                if(s[i][j]!=pre){
                    a[i][len[i]]=1;
                    s[i][len[i]]=s[i][j];
                    len[i]++;
                }
                else{
                    a[i][len[i]-1]++;
                }
            }
        }
        bool flag=true;
        for(i=1;i<n;i++){
            if(len[i]!=len[0]) flag=false;
        }
        if(flag){
            for(i=1;i<n;i++){
                for(j=0;j<len[0];j++){
                    if(s[i][j]!=s[0][j]) flag=false;
                }
            }
        }
        if(!flag){
            printf("Case #%d: Fegla Won\n",c);
        }
        else{
            ans=0;
            vector<int> temp;
            for(i=0;i<len[0];i++){
                temp.clear();
                for(j=0;j<n;j++){
                    temp.push_back(a[j][i]);
                }
                sort(temp.begin(),temp.end());
                for(j=0;j<n;j++){
                    if(j<n/2) ans+=temp[n/2]-temp[j];
                    else ans+=temp[j]-temp[n/2];
                }

            }
            printf("Case #%d: %d\n",c,ans);
        }
    }
    return 0;
}
