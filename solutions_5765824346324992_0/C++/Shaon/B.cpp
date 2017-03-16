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

#define SIZE 1010

int arr[SIZE];
int b;


LL sum( LL x ){
    LL tmp = 0;
    for (int i=0;i<b;++i){
        tmp += x/arr[i] + ( x%arr[i] !=0 ) ;
    }
    return tmp;
}

int main(){

    freopen("B-small-attempt0.in","r",stdin);
    freopen("out2.out","w",stdout);


    int kase;
    scanf("%d",&kase);

    for (int kk=1;kase--;++kk){


        LL n;
        scanf("%d %lld",&b,&n);
        for (int i=0;i<b;++i){
            scanf("%d",&arr[i]);
        }

        LL low = 0,high = (1LL<<55);
        LL ans = -1;
        while ( low<=high ){
            LL mid = (low+high)/2;
            if ( sum(mid) >= n ){
                high = mid-1;
                ans = mid;
            }else{
                low = mid+1;
            }
        }

        LL ser = n-sum(ans-1);
        //show( ans,ser );
        int ind = -1;
        for (int i=0;i<b;++i){
            if ( (ans-1) % arr[i] == 0 ){
                ser--;
            }
            if ( ser == 0 ){
                ind = i;
                break;
            }
        }

        printf("Case #%d: %d\n",kk,ind+1);

    }

    return 0;
}
