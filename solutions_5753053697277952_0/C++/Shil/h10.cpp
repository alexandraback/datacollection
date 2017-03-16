// There is nothing in a caterpillar that tells you its going to be a butterfly!
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pi pair<ll,ll>
#define f first
#define s second
#define pb push_back
#define rep(i,n) for(int i=0;i<n;i++)
#define mod 1000000007
int P[50];
int main(){
    freopen("A-small-attempt0.in","r",stdin);
    freopen("output.txt","w",stdout);
    int T;
    int cur=1;
    cin >> T;
    while(T--){
        int N;
        cin >> N;
        set<pi>s;
        int tot=0;
        rep(i,N){
            cin >> P[i];
            s.insert({-P[i],i});
            tot+=P[i];
        }
        cout<<"Case #"<<cur<<": ";
        if(N==2){
            while(P[0]>P[1]){
                P[0]--;
                cout<<"A ";
            }
            while(P[1]>P[0]){
                P[1]--;
                cout<<"B ";
            }
            while(P[0]>0){
                P[0]--;
                cout<<"AB ";
            }
        }
        else{
            int m=100000;
            rep(i,N){
                m=min(m,P[i]);
            }
            while(s.size()){
                int i=s.begin()->s;
                if(P[i]==m) break;
                s.erase(s.begin());
                P[i]--;
                s.insert({-P[i],i});
                cout<<char(i+'A')<<" ";
            }
            while(P[0]>0){
                P[0]--;
                if(P[0])
                    rep(i,N){
                        cout<<char(i+'A')<<" ";
                    }
                else{
                    if(N%2){
                        cout<<'A'<<" ";
                        for(int i=1;i<N;i+=2){
                            cout<<char(i+'A')<<char(i+'A'+1)<<" ";
                        }
                    }
                    else{
                        rep(i,N/2){
                            cout<<char(2*i+'A')<<char(2*i+'A'+1)<<" ";
                        }
                    }
                }
            }

        }
        cur++;
        cout<<"\n";
    }
}
