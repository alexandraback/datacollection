#include<iostream>
#include<fstream>
#include<string>
#include<algorithm>
#include<cstring>
using namespace std;
int main()
{
      //   ifstream cin("aa.txt");
    //  ofstream cout("bb.txt");
            int t , tt = 1;
       cin >> t;
       while(t--) {
           int r , c , n;
           cin >> r >> c >> n;
           string x;
           for(int i = n+1 ; i <= r*c ; ++i )
            x+=(char)(0+'0');
           for(int i = 1 ; i <=  n ; ++i )
            x+=(char)(1+'0');
              int ans = 1e9;
                  do {
                        int arr[r+5][c+5];
                  memset(arr,0,sizeof arr);
                  int rr = 0;
                   for(int i = 1 ; i <=r ; ++i  )
                   {
                       for(int j = 1; j <= c ; ++j )
                       {
                           if(x[rr]-'0' == 1)
                             arr[i][j] = 1;
                           rr++;
                       }
                   }
                    int tot = 0;
                    for(int i = 1; i <= r ; ++i )
                    {
                        for(int j = 1; j <= c ; ++j )
                        {
                             if(arr[i][j] == 1 )
                             {
                                 if(arr[i+1][j]==1)
                                    tot++;
                                 if(arr[i][j+1]==1)
                                    tot++;
                             }
                        }
                    }

                    ans = min( ans , tot);
                  }
                  while(next_permutation(x.begin(),x.end()));


           cout <<"Case #"<<tt++<<": "<<ans<<endl;
       }
       return 0;
}
