#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

vector<pair<char,int> > data[120];
int n ;

long long work(){
    long long ans = 0 ;
    char buffer[200];
    
    scanf("%d\n",&n);
    for ( int i = 0 ; i < n ; ++i )
        data[i].clear();
    for ( int i = 0 ; i < n ; ++i ){
        scanf("%s\n",buffer);
        int length = strlen(buffer);

        int cnt = 1 ;
        for ( int j = 1 ; j <= length ; ++j ){
            if ( buffer[j] != buffer[j-1] ){
                data[i].push_back( make_pair( buffer[j-1] , cnt ) );
                cnt = 1 ;
            }
            else ++cnt ;
        }
        //for ( int j = 0 ; j < data[i].size(); ++j )
        //  cout<<data[i][j].first<<','<<data[i][j].second<<endl;
    }
    for ( int i = 1 ; i < n ; ++i )
        if ( data[i].size() != data[0].size() )
            return -1; //fail
    for ( int i = 0 ; i < data[0].size(); ++i ){
        vector <int> tmp ;
        tmp.push_back( data[0][i].second );
        
        for ( int j = 1 ; j < n ; ++j )
            if ( data[j][i].first != data[0][i].first )
                return -1;
            else
                tmp.push_back( data[j][i].second );

        sort( tmp.begin() , tmp.end() );
        int mid = tmp[ (tmp.size()-1)/2 ]  ;
        //cout<<mid<<endl;
        for ( int j = 0 ; j < tmp.size() ; ++j ){
            ans += abs( tmp[j] - mid );
        }
    }
    return ans;
}
int main(){
    int t ;
    scanf("%d",&t);
    for ( int i = 0 ; i < t; ++i ){
        cout<<"Case #"<<i+1<<": ";
        long long ans = work();
        if ( ans < 0 )
            cout<<"Fegla Won"<<endl;
        else
            cout<<ans << endl ;
    }
}
