#include<bits/stdc++.h>
using namespace std;

int main(){
    int T, R, C, N;
    cin>>T;
    for(int tt=1; tt<=T; tt++){
        cin>>R>>C>>N;
        if(R>C) swap(R,C);
        int tot=2*R*C-R-C, odd=R*C%2;
        int cnt[2][5]={{}};
        if(R>=2){
            cnt[0][2]=odd?0:2, cnt[0][3]=odd?R+C-6:R+C-4, cnt[0][4]=((R-2)*(C-2)+1)/2;
            cnt[0][0] = R*C-(cnt[0][2]+cnt[0][3]+cnt[0][4]);
            cnt[1][3]=R+C-2, cnt[1][4]=(R-2)*(C-2)/2;
            cnt[1][0] = R*C-(cnt[1][2]+cnt[1][3]+cnt[1][4]);
        }else
            cnt[0][0]=(C+1)/2,cnt[0][1]=odd?0:1,cnt[0][2]=(C-1)/2;
        int M=R*C-N,MM=M,ans=tot;
        for(int i=4; i>=0; i--){
            if(cnt[0][i]<MM)
                ans-=i*cnt[0][i], MM-=cnt[0][i];
            else{
                ans-=i*MM, MM=0;
                break;
            }
        }
        if(R>=2&&odd){
            int ans2=tot, MM=M;
            for(int i=4; i>=0; i--)
            if(cnt[1][i]<MM)
                ans2-=i*cnt[1][i], MM-=cnt[1][i];
            else{
                ans2-=i*MM, MM=0;
                break;
            }
            ans = min(ans,ans2);
        }
        cout<<"Case #"<<tt<<": "<<ans<<endl;
    }
    return 0;
}
