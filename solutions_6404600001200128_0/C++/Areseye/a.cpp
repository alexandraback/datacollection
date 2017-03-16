#include"iostream"
#include"string"
#include"vector"
#include"algorithm"

using namespace std;

int main(){
    freopen("d:A-small-attempt0.in","r",stdin);
    freopen("d:A.out","w",stdout);

    int T;
    int casenum=0;
    cin>>T;
    while(casenum++<T){
        int N;
        cin>>N;
        vector<int>seq;

        for(int i=0;i<N;i++){
            int tmp;
            cin>>tmp;
            seq.push_back(tmp);
        }
        int ans1,ans2;
        ans1=ans2=0;
        int max_r=0;
        for(int i=0;i<N-1;i++){
            if(seq[i]>seq[i+1]){
                max_r=max(max_r,seq[i]-seq[i+1]);
                ans1+=seq[i]-seq[i+1];
            }
        }
        for(int i=0;i<N-1;i++){
            if(seq[i]>=max_r){
                ans2+=max_r;
            }else {
                ans2+=seq[i];
            }
        }

        printf("Case #%d: %d %d\n",casenum,ans1,ans2);


    }


return 0;}
