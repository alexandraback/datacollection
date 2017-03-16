#include<bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  int n;
  int caso = 0;
  
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cout << "Case #" << ++caso << ": ";
    priority_queue<pair<int, char>> pq;
    while(!pq.empty()) pq.pop();
    int num;
    cin >> num;
    int all = 0;
    for (int j = 0; j < num; ++j) {
      int q;
      cin >> q;
      all += q;
      char c = char('A' + j);
      pq.push(pair<int,char>(q, c));
    }
    bool foi = 0;
    pair<int,char> aux;
    while (all) {
      //cout << all << endl;
      if (foi) cout << " ";
      foi = true;
      aux = pq.top();
      cout << aux.second;
      --aux.first;
      pq.pop();
      if (aux.first) pq.push(aux);
      --all;
      if (all) {
        aux = pq.top();
        pq.pop();
        if (!pq.empty()) {
          if ((all - 1) < (pq.top().first * 2)) {
            pq.push(aux);
          } else {
            cout << aux.second;
            --aux.first;
            if (aux.first) pq.push(aux);
            --all;
          }
        } else {
          cout << aux.second;
          --aux.first;
          if (aux.first) pq.push(aux);
          --all;
        }
      }
    }
    cout << endl;
  }
  return 0;
}
