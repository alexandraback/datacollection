#include<bits/stdc++.h>
using namespace std;
int x[101];
int n;
int main(){
    int T,n;
    FILE *in = fopen("in.txt","r");
    FILE *out = fopen("output.txt","w");
    fscanf(in,"%d",&T);
    for(int t=1;t<=T;t++){
        fscanf(in,"%d",&n);
        printf("%d\n",n);
        fprintf(out,"Case #%d: ",t);
        int total=0;
        int pnum=n;
        for(int i=0;i<n;i++){
            fscanf(in,"%d",&x[i]);
            printf("%d\n",x[i]);
            total+=x[i];
        }
        while(pnum!=0){
            if(pnum==2){
                int a=-1,b=-1;
                for(int i=0;i<n;i++){
                    if(x[i]!=0 && a==-1) a=i;
                    else if(x[i]!=0) b=i;
                }
                if(x[a]==x[b]){
                    x[a]--;
                    x[b]--;
                    if(x[a]==0) pnum--;
                    if(x[b]==0) pnum--;
                    fprintf(out,"%c%c",'A'+a,'A'+b);
                    if(pnum==0) fprintf(out,"\n");
                    else fprintf(out," ");
                }
                else if(x[a]>x[b]) {
                    x[a]--;
                    if(x[a]==0) pnum--;
                    fprintf(out,"%c ",'A'+a);
                }
                else {
                    x[b]--;
                    if(x[b]==0) pnum--;
                    fprintf(out,"%c ",'A'+b);
                }
                continue;
            }
            int now=0,ans=-1;
            for(int i=0;i<n;i++){
                if(x[i]>now) {
                    now=x[i];
                    ans=i;
                }
            }
            x[ans]--;
            if(x[ans]==0) pnum--;
            fprintf(out,"%c ",'A'+ans);
        }
    }
}
