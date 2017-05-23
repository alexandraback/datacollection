#include<iostream>
#include <algorithm>
#include <vector>
#include<string>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<set>
#include <utility>

using namespace std;

#define inf         freopen("in.txt", "r", stdin);
#define outf        freopen("out.txt", "w", stdout);
#define pf          printf
#define sf(n)       scanf("%d", &n)
#define sff(a,b)    scanf("%d %d", &a, &b)
#define mn          (long long)-9223372036854775807
#define mx          (long long) 9223372036854775807
#define mod          1000000009
#define LL           long long


//set<int>::iterator ii;



int main()
{
    ios::sync_with_stdio(false);

    inf;
    outf;

    int t, ca = 1;

    cin >> t;

    while( t-- )
    {
        cout << "Case #" << ca++ <<": ";
        int i, j, x = 0, y, n, m, a, b, c, maxx, d = 1;

    cin >> n ;

    int arr[1111];

    for( i=0; i<n; i++ )
        {
            cin >> arr[i];
            x += arr[i];
        }

    while( x > 0 )
    {
       maxx = 0;
       a = -1;
       b = -1;
       c = -1;
       for( i=0; i<n; i++ )
       {
          if( arr[i] > maxx )
          {
              maxx = arr[i];
              a = i;
              b = 0;
          }
          else if( arr[i] == maxx )
          {
              c = i;
              b = 1;
          }
       }

       if( maxx == 1 && n % 2 && d == 1 )
       {
          d = 0;
          char ch = 65+a;
          cout << ch;
          arr[a]--;
          x--;
       }

       else if( b == 0  )
       {
          char ch = 65+a;
          cout << ch;
          arr[a]--;
          x--;
       }
       else if( b == 1 )
       {
          char ch = 65+a;
          cout << ch;
          arr[a]--;
          ch = 65+c;
          cout << ch;
          arr[c]--;
          x -= 2;
       }

       cout << ' ';
    }
    cout << endl;


    }







    return 0;

}


