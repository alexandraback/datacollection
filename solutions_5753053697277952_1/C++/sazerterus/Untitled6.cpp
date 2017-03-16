#include <bits/stdc++.h>

using namespace std;
struct data{
   char fc;
   char sc;
};

int dp[10][10][10];
data par[10][10][10];
int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int t;
    cin >> t;
    int index=1;
    while(t--){
        int n;
        cin >> n;
       int A[n+1];
       for(int i=1;i<=n;++i)
        cin >> A[i];
       priority_queue<pair<int,char> > Q;
       for(int i=1;i<=n;++i)
        Q.push(make_pair(A[i],'A'+i-1));
        int coun=0;
        vector<data> V;
       while(!Q.empty()){

            pair<int,char> a=Q.top();
       Q.pop();
            pair<int,char> b=Q.top();
            Q.pop();

            data p;
            if(a.first==2 && b.first==1){
           //     data p;
                p.fc=a.second;
                p.sc=0;
                a.first--;
                Q.push(a);
                Q.push(b);
            }

            else if(a.first>b.first){
              //  data p;
                p.fc=a.second;
                p.sc=a.second;
                a.first-=2;
                Q.push(a);
                Q.push(b);
            }
            else if(a.first==b.first){
              //  data p;
                if(Q.empty()){
                p.fc=a.second;
                p.sc=b.second;
                a.first--;
                b.first--;
                if(a.first!=0)
                    Q.push(a);
                if(b.first!=0)
                    Q.push(b);
                }
                else{
                    p.fc=a.second;
                    p.sc=0;
                    a.first--;
                    if(a.first!=0)
                        Q.push(a);
                    Q.push(b);
                }


            }
            V.push_back(p);

       }
       cout << "Case #" << index++ << ": ";
       for(int i=0;i<V.size();++i){
        cout << V[i].fc;
        if(V[i].sc!=0)
            cout << V[i].sc << " ";
        else
            cout << " ";
       }
       cout << endl;
    }

    return 0;
}
