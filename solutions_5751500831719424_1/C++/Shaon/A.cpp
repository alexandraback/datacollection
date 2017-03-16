#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <utility>
#include <set>
#include <map>
#include <iostream>
#include <queue>
#include <climits>

using namespace std;

typedef long long LL;

#define PB push_back
#define FRO freopen("in.txt","r",stdin);

#define CLR(arr) memset( (arr),0,sizeof(arr) );
#define NEG(arr) memset( (arr),-1,sizeof(arr) );

#define X first
#define Y second

#define MP make_pair

#define snuke(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)


typedef pair<int,int> pint;
typedef map<int,int> mint;

#define SIZE 110

int func( vector< pair<char,int> >& v ){



    int mx = v[0].Y;
    for (int i=0;i<v.size();++i){
        mx= max( mx, v[i].Y );
    }

    int sum = INT_MAX;

    for (int i=1;i<=mx;++i){
        int tmp = 0;
        for (int j=0;j<v.size();++j){
            tmp+= abs( i-v[j].Y );
        }
        sum=min( sum,tmp );
    }
    /*
    snuke( v,itr ){
        cout<<itr->Y<<" ";
    }cout<<sum<<endl;
    */
    return sum;
}

char arr[SIZE][SIZE];

int main(){

    freopen("A-large.in","r",stdin);
    freopen("out2.out","w",stdout);

    int kase;
    scanf("%d",&kase);

    //cout<<kase<<endl;

    for (int kk=1;kase--;++kk){
        int n;
        scanf("%d",&n);

        vector< pair<char,int> > tmp[SIZE];

        int fin = -1;
        bool pos = true;
        for (int i=0;i<n;++i){
            scanf("%s",arr[i]);

            int cnt = 0;
            for (int j=0;arr[i][j];++j){
                if ( j==0 ){
                    tmp[cnt].PB( MP( arr[i][j] , 1 ) );
                }else{
                    if ( arr[i][j] == arr[i][j-1] ){
                        tmp[cnt].back().Y += 1 ;
                    }else{
                        cnt++;
                        tmp[cnt].PB( MP( arr[i][j] , 1 ) );
                    }
                }
            }

            if ( fin != -1 && fin!= cnt ){
                pos=false;
            }
            fin =  cnt;
        }

        for (int i=0;i<=fin;++i){
            for (int j=1;j<tmp[i].size();++j){
                if ( tmp[i][j].X != tmp[i][j-1].X ){
                    pos=false;
                }
            }
        }

        printf("Case #%d: ",kk);
        if ( !pos ){
            printf("Fegla Won\n");
        }else{
            int ans = 0;
            for (int i=0;i<=fin;++i){
                ans += func( tmp[i] );
            }
            printf("%d\n",ans);
        }

    }


    return 0;
}
