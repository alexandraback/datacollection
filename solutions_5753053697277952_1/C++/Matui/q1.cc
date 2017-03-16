#include<iostream>
#include<algorithm>

using namespace std;
int N;
int A[26];
void solve();
int T,s;
int main(){
    cin>>T;
    int c_n=1;
    while(T--){
        cin>>N;
        s=0;
        for(int i=0;i<N;i++){
            cin>>A[i];
            s+=A[i];
        }
        cout<<"Case #"<<c_n++<<": ";
        solve();
        cout<<endl;
    }
}
void solve(){
    while(s--){
        int m1=-1,m2=-1,m3=-1;
        for(int i=0;i<N;i++){
            if(m1<0 || A[i]>A[m1]){
                m1=i;m2=-1;m3=-1;
            }
            else if(A[i]==A[m1]){
                if(m2==-1) m2=i;
                else m3 = i;
            }
        }
        //cout<<m1<<m2<<m3;
        if(m2==-1 || m3 != -1){
            A[m1]--;
            cout<<char('A'+m1)<<' ';
        }
        else{
            s--;
            A[m1]--;A[m2]--;
            cout<<char('A'+m1)<<char('A'+m2)<<' ';
        }
    }
}
