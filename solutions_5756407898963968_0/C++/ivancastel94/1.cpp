#include<iostream>
#include<vector>
#include<cstring>
#include<cstdio>
using namespace std;
int main(){
    freopen("a.in","r",stdin);
    freopen("a.out","w",stdout);
    int i,j,a,t,row1,row2,cases;
    bool b[20];
    cin>>t;
    for(cases=1;cases<=t;cases++){
        memset(b,0,sizeof(bool)*20);
        vector<int> v1;
        cin>>row1;
        row1--;
        for(i=0;i<4;i++){
            for(j=0;j<4;j++){
                cin>>a;
                if(i!=row1){
                    b[a]=1;
                }
            }
        }
        cin>>row2;
        row2--;
        for(i=0;i<4;i++){
            for(j=0;j<4;j++){
                cin>>a;
                if(i!=row2){
                    b[a]=1;
                }
            }
        }
        cout<<"Case #"<<cases<<": ";
        for(i=1;i<=16;i++){
            if(!b[i])v1.push_back(i);
        }
        if(v1.size()==1){
            cout<<v1[0]<<endl;
        }
        if(v1.size()==0){
            cout<<"Volunteer cheated!"<<endl;
        }
        if(v1.size()>1){
            cout<<"Bad magician!"<<endl;
        }
    }
}
