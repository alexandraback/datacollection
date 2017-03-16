#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<char,double> pr;

bool pairCompare(const pr &p1,const pr &p2){
    return p1.second>p2.second;
}

int main(){
    ios_base::sync_with_stdio(false);
    int tt;
    cin>>tt;
    for(int t=0;t<tt;t++){
        printf("Case #%d: ",t+1);
        int n;
        cin>>n;
        vector<pr> vec(n);
        double sm=0;
        for(int i=0;i<n;i++){
            double tmp;
            cin>>tmp;
            vec[i]=make_pair('A'+i,tmp);
            sm+=tmp;
        }
        bool two=false;
        while(!vec.empty()){
            sort(vec.begin(),vec.end(),pairCompare);
            if(vec[0].second>=2.0){
                if(vec[1].second/(sm-2.0)<=0.5){
                    printf("%c%c ",vec[0].first,vec[0].first);
                    vec[0].second-=2.0;
                    sm-=2.0;
                    if(vec[0].second==0.0){
                        vec.erase(vec.begin());
                    }
                }
                else if(vec[1].second/(sm-1.0)<=0.5){
                    printf("%c ",vec[0].first);
                    vec[0].second-=1.0;
                    sm-=1.0;
                    if(two){
                        //printf(" ");
                        two=false;
                    }
                    else two=true;
                    if(vec[0].second==0.0){
                        vec.erase(vec.begin());
                    }
                }
                else{
                    printf("%c%c ",vec[0].first,vec[1].first);
                    vec[0].second-=1.0;
                    vec[1].second-=1.0;
                    sm-=2.0;
                    if(vec[0].second==0.0){
                        vec.erase(vec.begin());
                    }
                    if(vec[0].second==0.0){
                        vec.erase(vec.begin());
                    }
                }
            }
            else{
                if(vec[1].second/(sm-1.0)<=0.5){
                    printf("%c ",vec[0].first);
                    vec[0].second-=1.0;
                    sm-=1.0;
                    if(two){
                        //printf(" ");
                        two=false;
                    }
                    else two=true;
                    if(vec[0].second==0.0){
                        vec.erase(vec.begin());
                    }
                }
                else{
                    printf("%c%c ",vec[0].first,vec[1].first);
                    vec[0].second-=1.0;
                    vec[1].second-=1.0;
                    sm-=2.0;
                    if(vec[0].second==0.0){
                        vec.erase(vec.begin());
                    }
                    if(vec[0].second==0.0){
                        vec.erase(vec.begin());
                    }
                }
            }
            //printf(" ");
        }
        printf("\n");
    }
}