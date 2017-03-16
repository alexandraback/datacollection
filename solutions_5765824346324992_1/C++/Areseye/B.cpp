#include"iostream"
#include"string"
#include"vector"
#include"algorithm"


using namespace std;

int main(){

    freopen("d:B-large.in","r",stdin);
    freopen("d:B.out","w",stdout);

    int T;
    int casenum=0;
    cin>>T;
    while(casenum++<T){
        int B;
        long long N;
        int ans=-1;

        cin>>B>>N;
        vector<int>Mi;

        for(int i=0;i<B;i++){
            int tmp;
            cin>>tmp;
            Mi.push_back(tmp);
        }
        int ok=false;

        for(int i=0;i<B;i++){
            //ans is i;
            //cout<<i<<endl;
            long long up=N+1;
            long long down=0;
            long long mid=(up+down)/2;
            while(down<=up){
                mid=(up+down)/2LL;
                // feasible:
                long long tm=(long long )mid*(long long)Mi[i];
                long long cutnum=mid;
                long long num_ready=1;
                vector<int>b_ready;

                for(int j=0;j<B;j++){
                    if(j==i){
                        b_ready.push_back(j);
                        continue;
                    }
                    long long ki=(long long)tm/(long long)Mi[j];

                    long long tmp=(long long)ki*(long long)Mi[j];
                    if(tmp==tm){
                        num_ready++;
                        b_ready.push_back(j);
                    }else {
                        ki++;
                    }
                    cutnum+=ki;

                }
                //printf("mid=%lld,cutnum=%lld,N=%lld,num_ready=%lld\n",mid,cutnum,N,num_ready);
//                if(cutnum==N){
//                    ok=true;
//                    ans=i;
//                    break;
//                }
                if(cutnum<=(long long)N-1&&cutnum+num_ready>=(long long)N){
                    //cout<<"OK"<<endl;
                    ok=true;
                    ans=b_ready[N-cutnum-1];
                    break;
                }else if(cutnum<N-1){
                    //printf("down:%lld,mid=%lld\n",down,mid);
                    down=mid+1;

                    //continue;
                }else {
                    //if(up==down)break;
                    up=mid-1;
                    //continue;
                }


                //if(casenum==7){
                //printf("up=%lld,down=%lld\n",up,down);

            }
            if(ok)break;
        }

        printf("Case #%d: %d\n",casenum,ans+1);
    }


return 0;}
