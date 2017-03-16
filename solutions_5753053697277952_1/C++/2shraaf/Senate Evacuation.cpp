
#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define fs first
#define sc second
typedef long long ll;
char prt(int n){
    return (char)('A'+n);

}


int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
        freopen ("file.out","w",stdout);
        freopen ("file.in","r",stdin);
        int t  , n , ai ;
        cin>>t;
        for(int p =1 ; p<=t ;p++){
            cin>>n;
            int sum = 0;
            vector<pair<int,int> > v;
            for(int i = 0 ;i< n ; i++){
                cin>>ai ;
                sum+=ai;
                v.push_back(make_pair(ai,i));
            }
            sort(v.begin(),v.end());
            cout<<"Case #"<<p<<": ";
            while(v.size()){
                int sz =v.size();
                if(v.size()==1){
                    if(v[0].fs ==1){
                        cout<<prt(v[0].sc)<<" ";
                        v[0].fs-=1;
                    }else{
                        cout<<prt(v[0].sc)<<prt(v[0].sc)<<" ";
                        v[0].fs-=2;
                    }
                }else if(v[sz-1].fs==v[sz-2].fs && sz==2){
                        cout<<prt(v[sz-1].sc)<<prt(v[sz-2].sc)<<" ";
                        v[sz-1].fs-=1;
                        v[sz-2].fs-=1;
                }else{
                        cout<<prt(v[sz-1].sc)<<" ";
                        v[sz-1].fs-=1;

                }
                vector<pair<int,int> > tm;
                for(int i = 0 ;i<sz ;i++){
                    if(v[i].fs){
                        tm.push_back(v[i]);
                    }

                }
                v.clear();
                for(int i = 0 ;i<tm.size() ;i++){
                    v.push_back(tm[i]);
                }
                sort(v.begin(),v.end());



            }
            cout<<'\n';



        }

    return 0;

}

