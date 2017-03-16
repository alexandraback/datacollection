#include<iostream>
#include<algorithm>
#include<cstdio>
#include<string>
#include<vector>

using namespace std;

int main()
{
   ios_base::sync_with_stdio(false);
   int t;
   cin >> t;
   for(int gg = 1; gg <= t; ++gg){
      cout << "Case #" << gg << ": ";
      int n;
      cin >> n;
      vector<pair<char,int> > b[100];
      for(int i = 0; i < n; ++i){
         string str;
         cin >> str;
         str += '-';
         int len = 1;
         for(int j = 1; j < str.size(); ++j){
            if(str[j] != str[j-1]){
               b[i].push_back(make_pair(str[j-1], len));
               len = 1;
            }else{
               ++len;
            }
         }
      }
      
      int ans = 0;
      for(int i = 1; i < n; ++i){
         if(b[i].size() != b[0].size()){
            cout << "Fegla Won" << endl;
            goto jizz;
         }
      }
      
      for(int i = 0; i < b[0].size(); ++i){
         int a[100];
         a[0] = b[0][i].second;
         for(int j = 1; j < n; ++j){
            if(b[j][i].first != b[0][i].first){
               cout << "Fegla Won" << endl;
               goto jizz;
            }
            a[j] = b[j][i].second;
         }
         
         sort(a, a+n);
         
         for(int j = 0, k = n-1; j <= k; ++j, --k){
            ans += a[k] - a[j];
         }
         
      }
      
      cout << ans << endl;
      
      jizz: ;
   }
   
   return 0;
}

