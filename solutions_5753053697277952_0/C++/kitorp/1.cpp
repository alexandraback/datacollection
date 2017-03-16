#include<bits/stdc++.h>
using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("A-small-attempt0.in","r",stdin);
    freopen("A-small.txt","w",stdout);
    int T;
    cin>>T;
    for(int t_c=1;t_c<=T;t_c++){
        int n;
        cin>>n;
        priority_queue<pair<int,int> > pq;
        pair<int,int> temp,temp1;
        int ara[26];
        for(int i=0;i<n;i++){
            int a;
            cin>>a;
            ara[i]=a;
            temp.first=a;
            temp.second=i;
            pq.push(temp);
        }
        cout<<"Case #"<<t_c<<":";
        string s;
        bool flag=0;
        while(!pq.empty()){
            temp=pq.top();
            pq.pop();
            if(pq.empty()){
                for(int j=0;j<temp.first;j++){
                    char ch=temp.second+'A';
                    ara[temp.second]--;
                    cout<<" "<<ch;
                    flag=1;
                }
                break;
            }
            temp1=pq.top();
            pq.pop();
            char ch=temp.second+'A',ch1=temp1.second +'A';
            s+=" ";
            s+=ch;
            s+=ch1;
            //cout<<s.size()<<"  "<<s<<endl;
            temp.first--;
            temp1.first--;
            if(temp.first!=0) pq.push(temp);
            if(temp1.first!=0) pq.push(temp1);
        }
        cout<<s<<"\n";


    }


}
