#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;
class Party{
public:
    char ch;
    int count;
    Party(){
    }
    Party(char c,int cnt){
        ch=c;
        count=cnt;
    }
    Party(const Party& s){
        ch=s.ch;
        count=s.count;
    }
    bool operator<(const Party& s)const{
        return count<s.count;
    }
};
int main(){
    int i,n,t,j,cnt,sum;
    char str[4];
    scanf("%d",&t);
    priority_queue<Party> senate;
    Party top,top1;
    for(i=1;i<=t;i++){
        scanf("%d",&n);
        sum=0;
        for(j=0;j<n;j++){
            scanf("%d",&cnt);
            sum+=cnt;
            senate.push(Party('A'+j,cnt));
        }
        printf("Case #%d: ",i);
        while(!senate.empty()){
            top=senate.top();
            senate.pop();
            if(!senate.empty()){
                top1=senate.top();
                senate.pop();
                if(top.count-1<=(sum-1)/2&&top.count>=1&&top1.count<=(sum-1)/2){
                    str[0]=top.ch;
                    str[1]='\0';
                    top.count=top.count-1;
                    sum--;
                    printf("%s ",str);
                }
                else if(top1.count<=(sum-2)/2&&top.count>=2){
                    str[0]=top.ch;
                    str[1]=top.ch;
                    str[2]='\0';
                    top.count=top.count-2;
                    sum-=2;
                    printf("%s ",str);
                }
                else{
                    str[0]=top.ch;
                    str[1]=top1.ch;
                    str[2]='\0';
                    top.count=top.count-1;
                    top1.count=top1.count-1;
                    sum-=2;
                    printf("%s ",str);
                }
            }
            if(top.count!=0)
                senate.push(top);
            if(top1.count!=0)
                senate.push(top1);
        }
        printf("\n");
    }
    return 0;
}
