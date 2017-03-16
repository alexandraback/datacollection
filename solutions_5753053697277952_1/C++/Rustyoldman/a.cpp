// ****************************************************************************
// Code developed starting from Rustyoldman's Google Code jam template
// May 8, 2016
// I am coding from a campground in Colorado at 3AM for this contest.
// I didn't remember to load any of my library code onto this new laptop
// before starting this trip. I reconstructed this boilerplate by downloading
// a previous GCJ round's submission and editing out the solution.
//
// This should be interesting.
// ****************************************************************************
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <list>
#include <cstdlib>
#define enld endl
using namespace std ;
// ****************************************************************************
int getchar ( )
// ****************************************************************************
{
if ( cin.eof() )
   return -1 ;
int ch = cin.get() ;
if ( cin.fail() )
   return -1 ;
return ch ;
}
// ****************************************************************************
string tokenstartchars 
= "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ" ;
string tokenchars 
= ".0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ" ;
// ****************************************************************************
string gettoken ( )
// ****************************************************************************
{
int ch ;

ch = cin.get() ;

while ( ! cin.eof () && (ch == ' ' || ch == '\n') )
   ch = getchar ( ) ;

if ( ch == -1 )
   return "ERROR" ;

string ans = "" ;
if ( tokenstartchars.find( (char) ch ) != string::npos ) 
   {
   while ( tokenchars.find ( (char) ch ) != string::npos)
      {
      ans.push_back((char) ch) ;
      ch = getchar ( ) ;
      }
   cin.putback((char)ch) ;
   return ans ;
   }

ans = "" ;
ans.push_back ( (char) ch ) ;
return ans ;
}
// ****************************************************************************
double getdouble ( ) 
// ****************************************************************************
{
double a ;
cin >> a ;
return a ;
}
// ****************************************************************************
int getint ( ) 
// ****************************************************************************
{
while ( cin.peek ( ) == ' ' || cin.peek ( ) == '\n' )
   getchar ( ) ;
int sign = 1 ;
if ( cin.peek ( ) == '-' )
   {
   sign = -1 ;
   getchar ( ) ;
   }
string toke = gettoken ( ) ;
if ( sign == -1 && toke == "2147483648" )
   return -2147483648 ;

return sign * atoi ( toke.c_str() ) ;
}
// ****************************************************************************
void do_case ( int case_number )
// ****************************************************************************
{
int pc ;
cin >> pc ;
 vector<int> pop ( pc ) ;
 for ( int i = 0 ; i < pc ; ++i )
   cin >> pop[i] ;
 vector<string> plan ;

//  for ( int i = 0 ; i < pc ; ++i )
//    cout << pop[i] << " " ;
//  cout << endl ;

 int p1 = 0 ;
 for ( int i = 0 ; i < pc ; ++i )
   if ( pop[i] > pop[p1] )
     p1 = i ;
 int p2 = 0 ;
 if ( p1 == 0 )
   p2 = 1 ;
 for ( int i = 0 ; i < pc ; ++i )
   if ( pop[i] > pop[p2] && i != p1 )
     p2 = i ;

//  cout << "p1 = " << p1 << " p2 = " << p2 << endl ;

 while ( pop[p1] > pop[p2] )
   {
     string s ;
     s.resize(1) ;
     s[0] = (char)('A' + p1) ;   
     plan.push_back ( s ) ;
     pop[p1] -- ;
   }

 for ( int i = 0 ; i < pc ; ++i )
   if ( i != p1 && i != p2 )
     for ( int j = 0 ; j < pop[i] ; ++j )
       {
	 string s ;
	 s.resize(1) ;
	 s[0] = (char)('A' + i) ;   
	 plan.push_back ( s ) ;
       }
 for ( int i = 0 ; i < pop[p1] ; ++i )
   {
     string s ;
     s.resize(2) ;
     s[0] = (char)('A' + p1) ;   
     s[1] = (char)('A' + p2) ;   
     plan.push_back ( s ) ;
   }


cout << "Case #" << case_number << ":" ;
 for ( int i = 0 ; i < plan.size() ; ++i )
   cout << " " << plan[i] ;
cout << endl ;
}
// ****************************************************************************
int main ( int argc , char ** argv )
// ****************************************************************************
{
int n ;
cin >> n ; getchar() ;
for ( int i = 1 ; i <= n ; i ++ )
   do_case ( i ) ;
}
// ****************************************************************************
