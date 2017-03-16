#include <bits/stdc++.h>
#define MIN(X,Y) X<Y?X:Y
#define MAX(X,Y) X>Y?X:Y
#define ISNUM(a) ('0'<=(a) && (a)<='9')
#define ISCAP(a) ('A'<=(a) && (a)<='Z')
#define ISSML(a) ('a'<=(a) && (a)<='z')
#define ISALP(a) (ISCAP(a) || ISSML(a))


using namespace std;

int senate[28];
int main(){
    int t;
    scanf("%d",&t);
    int cs=1;
    while(t--){
        int n;
        scanf("%d",&n);
        int total=0;
        for(int i=0;i<n;++i){
            scanf("%d",&senate[i]);
            total+=senate[i];
        }
        printf("Case #%d:",cs++);
        while(total>0){
            int mx1=-1;
            int mxchar1;
            int mx2=-1;
            int mxchar2;
            for(int i=0;i<n;++i){
                if(senate[i]>mx1){
                    mx1=senate[i];
                    mxchar1=i;
                }
            }
            for(int i=0;i<n;++i){
                if(senate[i]>mx2){
                    if(i==mxchar1){
                        if((senate[i]-1)>mx2){
                            mx2=senate[i]-1;
                            mxchar2=i;
                        }
                    }
                    else{
                        mx2=senate[i];
                        mxchar2=i;
                    }
                }
            }
            int loss1,loss2;
            vector<int>state1;
            vector<int>state2;
            for(int i=0;i<n;++i){
                int nw=senate[i];
                if(i==mxchar1){
                    nw--;
                }
                if(i==mxchar2){
                    nw--;
                }
                state1.push_back(nw);
            }
            for(int i=0;i<n;++i){
                int nw=senate[i];
                if(i==mxchar1){
                    nw--;
                }
                state2.push_back(nw);
            }
            //int total1=total-2;
            //int total2=total-1;
            int mxnext1=-1;
            int mxnext2=-1;
            for(int i=0;i<n;++i){
                if(state1[i]>mxnext1){
                    mxnext1=state1[i];
                }
            }
            for(int i=0;i<n;++i){
                if(state2[i]>mxnext2){
                    mxnext2=state2[i];
                }
            }
            if((mxnext1*(total-1))<=(mxnext2*(total-2))){
                //duijon ke sorabo
                senate[mxchar1]--;
                senate[mxchar2]--;
                printf(" %c%c",mxchar1+'A',mxchar2+'A');
                total-=2;
            }
            else{
                senate[mxchar1]--;
                printf(" %c",mxchar1+'A');
                total--;
            }
        }
        printf("\n");
    }
    return 0;
}
