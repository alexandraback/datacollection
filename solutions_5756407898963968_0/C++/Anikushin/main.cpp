#include<iostream>
#include<fstream>
#include<cstdlib>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<cmath>
#include<map>
#include<set>
#include<cassert>
#define ll long long
#define ld long double
#define mp make_pair
#define pb push_back
#define fi first
#define hash hash_asdjkhasjkdh
#define se second
#define next next_aslkjdhasmnhd
#include<string>
#include <iomanip>
#include <queue>
#include<string>
using namespace std;


int main(){
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  int T;
  cin >> T;
  for (int t = 0; t < T; t++){ 
     vector<vector<int> > a(4,vector<int>(4)),b(4,vector<int>(4));
     int x,y;
     cin >> x;
     for (int i = 0; i < 4; i++) {
       for (int j = 0; j < 4; j++) {
         cin >> a[i][j];
       }
     }
     cin >> y;
     for (int i = 0; i < 4; i++) {
       for (int j = 0; j < 4; j++) {
         cin >> b[i][j];
       }
     }
     int k = 0;
     int w = 0;
     x--;
     y--;
     for (int i = 0; i < 4; i++) {
       for (int j = 0; j < 4; j++) {
          if (a[x][i] == b[y][j]) {
            k++;
            //cerr << t << " " << i << " " << j << " " << a[x][i] << " " << b[y][j] << endl;
            w = a[x][i];
          }
       }
     }
     cout << "Case #" << t+1 << ": ";
     if (k == 1)
       cout << w << endl;
     else if (k > 1)
       cout << "Bad magician!\n";
     else
      cout << "Volunteer cheated!\n";
  }
  return 0;
}