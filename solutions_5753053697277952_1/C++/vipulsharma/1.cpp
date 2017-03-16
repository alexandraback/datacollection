#include<bits/stdc++.h>
using namespace std;
int main(){
   cin.sync_with_stdio(false);
   ifstream cin("a.txt");
   ofstream cout("b.txt");
       int t, tt = 1;
       cin >> t;
       while( t-- ){
             int N;
             cin >> N;
             int a[N+1];
             int sm = 0;
             for(int i = 1 ; i <= N ; ++i ){
               cin >> a[i];
               sm += a[i];
               }
               vector< string > ans;
               while( sm ){
                   int flag = 0;
                    for(int i = 1 ; i <= N ; ++i ){
                      if(a[i]){
                         a[i]--;
                        int fl = 1;
                        int total = 0;
                        for(int j = 1 ; j <= N ; ++j )
                          total += a[j];
                          for(int j = 1 ; j <= N ; ++j )
                               if( a[j] > (total - a[j])  )
                                fl = 0;
                        if(fl){
                        string x;
                        x = (i + 'A' - 1 );
                     ans.push_back(x);
                     sm--;
                     flag = 1;
                     break;
                        }
                        else
                        a[i]++;
                      }
                    }
                    if(!flag){
                      for(int i = 1 ; i <= N ; ++i ){
                       for(int j = 1 ; j <= N ; ++j ){
                             if( a[i] && a[j] ){
                               a[i]--;
                               a[j]--;
                               int fl = 1;
                               int total = 0;
                               for(int k = 1 ; k <= N ; ++k )
                               total += a[k];
                               for(int k = 1 ; k <= N ; ++k )
                                 if( a[k] > (total - a[k]))
                                  fl = 0;
                                   if(fl){
                        string x;
                        x = (i + 'A' - 1 );
                        x += (j + 'A' - 1 );
                     ans.push_back(x);
                     sm = sm - 2 ;
                     flag = 1;
                     break;
                        }
                        else {
                        a[i]++;
                        a[j]++;
                        }
                             }
                       }
                      }

                    }

               }
               cout << "Case #"<<tt++<<": ";
               for(int i = 0 ; i < ans.size() ; ++i )
               cout << ans[i] <<" ";
               cout << endl;
       }
  return 0;
}
