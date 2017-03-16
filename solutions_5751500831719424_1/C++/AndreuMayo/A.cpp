#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
  int casos;
  cin >> casos;
  for (int cas = 1; cas <= casos; ++cas) {
    cout << "Case #" << cas << ": ";
    int n;
    cin >> n;
    vector<string> v(n);
    for (int i = 0; i < n; ++i) cin >> v[i];
    vector<int> ind(n, 0);
    
    bool perd = false;
    int total = 0;
    while (!perd) {
      bool fi = (ind[0] == v[0].size());
      for (int i = 0; i < n; ++i) {
        if ((ind[i] == v[i].size()) != fi) {
          perd = true;
          break;
        }
      }
      if (perd) break;
      if (fi) break;
      
      char act = v[0][ind[0]];
      vector<int> hiha(101, 0);
      for (int i = 0; !perd and i < n; ++i) {
        if (v[i][ind[i]] != act) {
          perd = true;
          break;
        }
        int j;
        for (j = ind[i]; j < v[i].size() and v[i][j] == act; ++j);
        hiha[j - ind[i]]++;
        ind[i] = j;
      }
      int e = 0;
      int d = 100;
      int ce = 0;
      int cd = 0;
      int t = 0;
//       for (int i = 0; i < 5; ++i) cout << hiha[i] << ' ';
//       cout << endl;
      while (e != d) {
        while (e != d and ce + hiha[e] <= cd + hiha[d]) {
          ce += hiha[e];
          t += ce;
          ++e;
        }
        while (e != d and ce + hiha[e] >= cd + hiha[d]) {
          cd += hiha[d];
          t += cd;
          --d;
        }
//         cout << "      " << ce << ' '  << cd << ' ' << endl;
      }
//       cout << t << endl;
      total += t;
//       for (int i = 0; i < n; ++i) cout << ind[i] << ' ';
//       cout << "--------------"<< endl;
    }
    if (perd) cout << "Fegla Won" << endl;
    else cout << total << endl;
  }
}
