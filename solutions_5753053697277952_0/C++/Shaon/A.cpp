#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>

using namespace std;
using namespace __gnu_pbds;

typedef long long LL;

typedef tree<
    int,
    null_type,
    less<int>,
    rb_tree_tag,
    tree_order_statistics_node_update>
ordered_set;
//find_by_order
//order_of_key

#define FO(i,a,b) for (int i = (a); i < (b); i++)

#define PB push_back
#define FRO freopen("in.txt","r",stdin);

#define CLR(arr) memset( (arr),0,sizeof(arr) );
#define NEG(arr) memset( (arr),-1,sizeof(arr) );
#define ALL(v) v.begin(),v.end()

#define X first
#define Y second
#define MP make_pair

typedef pair<int,int> pint;
typedef map<int,int> mint;

void show() {cout<<'\n';}
template<typename T,typename... Args>
void show(T a, Args... args) { cout<<a<<" "; show(args...); }
template<typename T>
void show_c(T& a) { for ( auto &x:a ){ cout<<x<<" ";}cout<<endl;  }



int n;

bool pos(int *cnt,int sum){
    int ret = 0;
    FO(i,0,n){
        ret = max( ret , cnt[i] );
    }
    if ( ret *2 > sum )return false;
    else return true;
}

int main(){

    freopen("A-small-attempt1.in","r",stdin);
    freopen("out.out","w",stdout);


    int kase;
    scanf("%d",&kase);

    for (int kk=1;kase--;++kk){

        scanf("%d",&n);

        int cnt[26]={0};

        int sum = 0;
        FO(i,0,n){
            scanf("%d",&cnt[i]);
            sum += cnt[i];
        }

        string ans = "";
        while ( sum > 0 ){

            bool fnd = false;
            for (int i=0;i<26;++i){
                cnt[i]--;
                if ( pos(cnt,sum-1) ){
                    fnd = true;
                    ans += " ";
                    ans += char( 'A' + i );
                    sum--;
                    break;
                }
                cnt[i]++;
            }
            if ( fnd )continue;
            for (int i=0;i<26;++i){
                cnt[i]--;
                for (int j=0;j<26;++j){
                    cnt[j]--;
                    if ( pos(cnt,sum-2) ){
                        fnd = true;
                        ans += " ";
                        ans += char( 'A' + i );
                        ans += char( 'A' + j );
                        sum -= 2;
                        goto hell;
                    }
                    cnt[j]++;
                }
                cnt[i]++;
            }
            hell:
                ;
        }

        printf("Case #%d: %s\n",kk,ans.c_str());
    }

    return 0;
}
