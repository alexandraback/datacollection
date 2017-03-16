#include<bits/stdc++.h>
using namespace std ;
struct node {
  int cnt;
  char ch ;
  node() {}
  node( int _t , char _ch ) {
    cnt = _t ;
    ch = _ch ;
  }
  bool operator < ( const node & c )const {
    return cnt < c.cnt ;
  }
};

int main() {
  freopen("A-small-attempt2.in","r",stdin) ;
  freopen("A-small-attempt2.out","w",stdout) ;

  int cases , caseno = 1 ;
  cin >> cases ;
  while( cases -- ) {

    int  n ;
    cin >> n ;
    int arr[30] ;
    vector<node>V ;
    long long sum = 0 ;
    for( int i = 0 ; i < n ; i++ ) {
      cin >> arr[i]  ;
      V.push_back( node(arr[i],i+'A') ) ;
      sum+=arr[i] ;
    }
    cout << "Case #" << caseno++ << ":" ;
    while( sum > 0 ) {
      for( int i = 0 ; i < n ; i++ ) {
        sort( V.rbegin() , V.rend() ) ;
        for( int j = 0 ; j < n ; j++ ) {
          if( i == j && V[i].cnt>0) {
            V[i].cnt-- ;
            sum-- ;
            bool f = 0 ;
            for( int k = 0 ; k < n ; k++ ) {
              if( V[k].cnt*2 > sum ) {
                f = 1 ;
                break ;
              }
            }
            if( f == 0 ) {
              cout << " " << V[i].ch ;
              break ;
            } else {
              V[i].cnt++ ;
              sum++ ;
              if( V[i].cnt>0 && V[j].cnt>0) {
                V[i].cnt-- ;
                V[j].cnt-- ;
                sum-- ;
                sum-- ;
                bool f = 0 ;
                for( int k = 0 ; k < n ; k++ ) {

                  if( V[k].cnt*2 > sum ) {
                    f = 1 ;
                    break ;
                  }
                }
                if( f == 0 ) {
                  cout << " " << V[i].ch << V[j].ch ;
                  break ;
                } else {
                  V[i].cnt++ ;
                  V[j].cnt++ ;
                  sum++ ;
                  sum++ ;
                }
              }

            }
          } else if( V[i].cnt>0 && V[j].cnt>0) {
            V[i].cnt-- ;
            V[j].cnt-- ;
            sum-- ;
            sum-- ;
            bool f = 0 ;
            for( int k = 0 ; k < n ; k++ ) {
              if( V[k].cnt*2 > sum ) {
                f = 1 ;
                break ;
              }
            }
            if( f == 0 ) {
              cout << " " << V[i].ch << V[j].ch ;
              break ;
            } else {
              V[i].cnt++ ;
              V[j].cnt++ ;
              sum++ ;
              sum++ ;
            }
          }
        }
      }
    }
    cout << "\n" ;

  }
  return 0 ;
}
