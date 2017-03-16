#include<stdio.h>
#include<math.h>
#include<iostream>
#include<stack>
#include<queue>
#include<vector>
#include<set>
#include<map>
#include<algorithm>

using namespace std;

char str[1000][1000];
int main(){
    freopen("A-large.in","r",stdin);
    freopen("A-large.out","w",stdout);
    int t;
    cin >> t;
    for(int zz=1;zz<=t;zz++){
        int n;
        cin >> n;
        bool check=true;
        vector<pair<char,priority_queue<int> > > v;
        scanf("%s",&str[0][1]);
        int count=0;
        int countsame;
        for(int j=1;str[0][j];j++){
            if(str[0][j] != str[0][j-1]){
                if(count>0){
                        v[count-1].second.push(countsame);
                }
                count ++;
                countsame=1;
                v.push_back(make_pair(str[0][j],priority_queue<int>()));
            }else{
                countsame++;
            }
        }
        v[count-1].second.push(countsame);
        for(int i=1;i<n;i++){
            scanf("%s",&str[i][1]);
            count=0;
            for(int j=1;str[i][j];j++){
                if(str[i][j] != str[i][j-1]){
                    if(str[i][j]!=v[count].first){
                        check=false;
                        break;
                    }
                    if(count>0) v[count-1].second.push(countsame);
                    count++;
                    countsame=1;
                }else{
                    countsame++;
                }
            }
            if(check) v[count-1].second.push(countsame);
        }
/*
        for(int i=0;i<v.size();i++){
            printf("%c %d\n",v[i].first, v[i].second.size());
        }
*/

        for(int i=1;i<v.size();i++){
            if(v[i].second.size() != v[i-1].second.size()) check=false;
        }

        if(!check){
            printf("Case #%d: Fegla Won\n",zz);
        }else{
            int ans=0;
            for(int i=0;i<v.size();i++){
                int add=0,sub=0,nadd=0,nsub=0;
                int n = v[i].second.size();
                if(v[i].second.size()%2==1){
                    int mid = v[i].second.size()/2;
                    for(int j=0;j<mid;j++){
                        sub+=v[i].second.top();
                        v[i].second.pop();
                        nsub++;
                    }
                    int med = v[i].second.top();
                    while(!v[i].second.empty()){
                        add+=v[i].second.top();
                        v[i].second.pop();
                        nadd++;
                    }
                    //printf("%d %d %d\n",med,sub,add);
                    ans += sub-nsub*med + nadd*med-add;

                }else{
                    int mid = v[i].second.size()/2-1;
                    for(int j=0;j<mid;j++){
                        sub+=v[i].second.top();
                        v[i].second.pop();
                        nsub++;
                    }
                    int med = v[i].second.top();
                    sub+=v[i].second.top();
                    v[i].second.pop();
                    nsub++;
                    med += v[i].second.top();
                    add+=v[i].second.top();
                    v[i].second.pop();
                    nadd++;
                    med /= 2;
                    while(!v[i].second.empty()){
                        add+=v[i].second.top();
                        v[i].second.pop();
                        nadd++;
                    }
                    //printf("%d %d %d\n",med,sub,add);
                    ans += sub-nsub*med + nadd*med-add;
                }
            }
            printf("Case #%d: %d\n",zz,ans);
        }

    }

    return 0;
}
