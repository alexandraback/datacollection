#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<stack>
#include<string>
#include<cmath>

using namespace std;

int N;
int table[30];
int sum;

void solve(){

    set<pair<int,int> >tmp;
    for(int i=0;i<N;i++){
        tmp.insert( make_pair( table[i], i ) );
    }

    while( sum > 0 ){

        if( sum == 3 ){
            set<pair<int,int> >::iterator it = tmp.end();
            --it;

            printf( " %c", it->second + 'A' );
            pair<int,int> t = *it;
            tmp.erase( it );
            tmp.insert( make_pair(t.first-1,t.second) );
            sum--;
        }else{
            set<pair<int,int> >::iterator it = tmp.end();
            --it;

            printf( " %c", it->second + 'A' );
            pair<int,int> t = *it;
            tmp.erase( it );
            tmp.insert( make_pair(t.first-1,t.second) );

            it = tmp.end();
            --it;
            printf( "%c", it->second + 'A' );
            t = *it;
            tmp.erase( it );
            tmp.insert(make_pair(t.first-1,t.second));
            sum-=2;
        }

    }
    printf( "\n" );
}

int main(){
    freopen( "input.txt", "r", stdin );
    freopen( "output.txt", "w", stdout );

    int T; cin>>T;
    for(int t=1;t<=T;t++){
        cin>>N;
        sum = 0;
        for(int i=0;i<N;i++){
            cin>>table[i];
            sum += table[i];
        }
        cout<<"Case #"<<t<<":";
        solve();
    }

	return 0;
}
