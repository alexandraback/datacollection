#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

const int MAXN = 110;
typedef pair<char,int> pp;
vector <pp> v[MAXN];
typedef vector <pp>::iterator iter;

int _;
int N;
char s[110];
void work(int p){
    v[p].clear();
    scanf("%s",s);
    char c=s[0];
    int cnt=1;
    for (int i=1;s[i];i++){
        if (s[i]!=c){
            v[p].push_back(make_pair(c,cnt));
            //cout << c << " " << cnt <<" ";
            c = s[i];
            cnt = 1;
        } else {
            cnt++;
        }
    }
    v[p].push_back(make_pair(c,cnt));
   // cout << c << " " << cnt <<" ";
    //cout << endl;
}

int ABS(int p){
    return p<0?-p:p;
}

int main(){
    //freopen("in.txt","r",stdin);
    //freopen("A-small-attempt1.in","r",stdin);
    //freopen("A-small-attempt1.out","w",stdout);
    scanf("%d",&_);
    int cas=0;
    while(_--){
        scanf("%d",&N);
        for (int i=1;i<=N;i++) work(i);
        int L = v[1].size();
        bool flag = true;
        for (int i=1;i<=N && flag;i++){
            if (v[i].size()!=L){
                flag = false;
            }
        }
        long long ans = 0;
        if (flag){
            for (int i=0;i<L && flag;i++){
                char c=v[1][i].first;
                vector <int> vv;
                vv.clear();
                for (int j=1;j<=N && flag;j++){
                    if (v[j][i].first!=c) flag = false;
                    vv.push_back(v[j][i].second);
                }
                sort(vv.begin(),vv.end());
                int mid = vv[N/2];
                //cout << mid << endl;
                for(vector<int>::iterator k=vv.begin();k!=vv.end();k++){
                    ans += ABS(*k-mid);
                }
            }
        }
        if (flag) printf("Case #%d: %I64d\n",++cas,ans); else
        printf("Case #%d: Fegla Won\n",++cas);
    }
}
