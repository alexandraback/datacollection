
 #include <bits/stdc++.h>
using namespace std;
 /*
  Mistakes -
   0) Dont rush to conclusion on seeing a question , keep yourself relaxed and go easy on ques .
   1) To see at each step if integer is not causing an error , best way is to use long long always.
   2) To see if my solution can be verified , if yes then do that .
   3) To see if my code can be simplified , if yes make it simple.
   4) If my code is wrong , dont be in a hurry to change to the code, first think for 2 min if any modification can be done to make it
      right.
   5) always typecast (int) arr.size() because   size_t does not support subtraction.
   6) Never use such expression   Int ct = max( ct ,left) ; (declartion should be done before assignment , absurd behaviour)
   7) Using long long for everything may cause Time Limit Exceeded some times , so better be sure
   8) appending at the end of the string takes too much time 339 Div2 - B
   9) n*n*log(n) doesnt wrk for n >1000 on codeforces
   10) read the question carefully and before submitting soln read ques , it will hardly take 1min and save u  time cost of 15-30 min
   11) Keep calm and Code.

 */
#define REP(i, a, b) for (int i = a; i <= b; i++)
#define FOR(i, n) for (int i = 0; i < n; i++)
#define foreach(it, ar) for ( typeof(ar.begin()) it = ar.begin(); it != ar.end(); it++ )
#define fill(ar, val) memset(ar, val, sizeof(ar))
#define PI 3.1415926535897932385
#define uint64 unsigned long long
#define Int long long
#define int64 long long
#define all(ar) ar.begin(), ar.end()
#define pb push_back
#define ff first
#define ss second
#define bit(n) (1<<(n))
#define Last(i) ( (i) & (-i) )
#define sq(x) ((x) * (x))
#define INF INT_MAX
#define mp make_pair


 int main()
{

  freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);

  int t ;
  cin >> t ;
  for( int p = 1 ; p <= t ; p ++ )
   {

        int  n ;
        cin >> n ;
        vector<Int>a(n , 0  );
        Int  cnt = 0 ;
        FOR( i, n ){  cin >> a[i]  ;  cnt  += a[i]; }
        cout<<"Case #"<<p<<": ";
        while( cnt  > 0 )
          {

             int mx1 = 0, id1 = 0 ;
             int mx2 = 0, id2 = 0 ;

             for( int i = 0 ; i< n ; i ++ )
                {
                  if( a[i] >=  mx1) { mx2 = mx1 ; id2 = id1 ; mx1 = a[i] ; id1 = i ;    }
                  else if(  a[i] >= mx2 ){  mx2 =  a[i] ;  id2 = i ;  }
                }
             // cout<<mx1 <<" "<< mx2<<" " <<id1 << " "<<id2 <<endl;
             if( (  (mx2*1.00) / ( (cnt-1)*1.00 ) ) <= 0.5 )
                 { char an =  id1 +  'A' ;  cout<<an<<" "; a[id1]--;  cnt--; continue;}

              cnt =  cnt - 2 ;
                  {
                     char an1 =  id1 +  'A';
                     char an =  id2 +  'A' ;
                     cout<<an1<< an<<" " ;
                     a[id1]--;
                     a[id2]--;

                  }

          }


        cout<<endl;


   }





}
