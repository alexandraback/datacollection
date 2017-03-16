#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
int calcmid(int a[], int n ) {
   sort(a,a+n);
   int min = 100000000;
   for (int mid = a[0] ; mid <= a[n-1]; mid ++) {
      int tot = 0;
      for (int i = 0 ; i < n ; i++) 
          if (a[i] > mid) tot += (a[i] - mid); else tot+= (mid - a[i]);
      if (tot < min) min = tot;
   }
   return min;
}
int ff(vector<string> &VS) {
int pointers[100];
int n = VS.size();
int count[100];
for (int i = 0 ; i < n ; i++) { pointers[i] = 0; count[i] = 0;} 
int ans = 0;
while (pointers[0] < VS[0].size()) {
   char c = VS[0][pointers[0]];
   for (int i = 0; i<n;i++) {
       if (VS[i][pointers[i]]!=c) return -1;
       count[i] = 0;
       while (VS[i][pointers[i]]==c) {
          count[i] ++;
          pointers[i] ++;
       }
       
   }
   ans += calcmid(count,n);
}
return ans;
}
int main() {
  int t;
   cin >> t ;
  for (int ii = 1; ii<=t; ii++) {
     cout <<"Case #"<<ii<<": ";
     int siz;
     vector<string> VS; cin >> siz; //string tmp; cin >> tmp;
     for (int i = 0 ; i < siz; i++) {
     string s;
     cin >> s; s.push_back('#');
     VS.push_back(s);
     }
     int ans = ff(VS);
     if (ans >=0) cout << ans << endl;
         else cout << "Fegla Won"<<endl;
  }
  return 0;
}
