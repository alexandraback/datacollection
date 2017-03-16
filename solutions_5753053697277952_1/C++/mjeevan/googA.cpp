#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<set>

using namespace std ;

bool fun1( pair<char,int> a , pair<char,int> b ) 
	{
	 return a.second > b.second ; 
	}

int main()
	{
	 int T ;
	 cin >> T ;
	 for( int i = 0 ; i < T ; i++)
	   {
	     int N ;
	     cin >> N ;
             vector<pair<char,int> > ar ;
	     int max = 0 ;
	     int cnt = 0 ;
	    cout << "Case #" << i + 1 << ": " ;
	    for( int j = 0 ; j < N; j++)
	      {
		char c = 'A' + j ;
	        int t ; cin >> t ;
		ar.push_back(make_pair( c , t ) ) ;
		cnt += t ; 
	        //if( ar[j] > max ) { max = ar[j] ; maxcnt = 1 ; }
	        //if( ar[j] == max ) { max = ar[j] ; maxcnt++ ; }
	       }
	    while( cnt != 0 ) {
	    sort( ar.begin() , ar.end() , fun1 ) ;
	    if( ar[0].second == ar[1].second ) { if( ar[0].second == ar[2].second  && ar[0].second == 1) { ar[0].second-- ; cnt -= 1 ; cout << ar[0].first << " " ; }
						 else {
						 ar[0].second-- ;
						 ar[1].second-- ;
					         cnt -= 2 ;
						 cout << ar[0].first << ar[1].first << " " ;
							}
						}
	   else { if( ar[0].second > 1 ) { ar[0].second -= 2 ; cnt -= 2 ;
					   cout << ar[0].first << ar[0].first << " " ;
					 }
		  else { ar[0].second -= 1 ; cnt -= 1 ; cout << ar[0].first << " " ;
			}
	         }
	   }
	  cout << endl ;
	}
	
	
	return 0 ;
	}
