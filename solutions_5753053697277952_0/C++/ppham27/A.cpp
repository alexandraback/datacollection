#include <functional>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

vector<pair<char, char>> evacuate(const vector<pair<int, char>> &partySizes) {
  vector<pair<char, char>> evacuationOrder;
  priority_queue<pair<int, char>, vector<pair<int, char>>, less<pair<int, char>>> pq;
  for (pair<int, char> partySize : partySizes) pq.push(partySize);
  while (!pq.empty()) { // loop invariant is that there is no absolute majority
    // pq.size() != 1 ever or some party has absolute majority
    if (pq.size() == 3 && pq.top().first == 1) {
      pair<int, char> firstParty = pq.top(); pq.pop();
      evacuationOrder.emplace_back(firstParty.second, '*');
    } else {
      pair<int, char> firstParty = pq.top(); pq.pop();
      if (--firstParty.first > 0) pq.push(firstParty);
      pair<int, char> secondParty = pq.top(); pq.pop();
      if (--secondParty.first > 0) pq.push(secondParty);
      evacuationOrder.emplace_back(firstParty.second, secondParty.second);
    }
  }
  return evacuationOrder;
}

int main(int argc, char *argv[]) {
  ios::sync_with_stdio(false); cin.tie(NULL);
  int T; cin >> T;
  for (int t = 1; t <= T; ++t) {
    int N; cin >> N; // number of parties
    vector<pair<int, char>> partySizes; partySizes.reserve(N);
    for (int n = 0; n < N; ++n) {
      int partySize; cin >> partySize;
      partySizes.emplace_back(partySize, 'A' + n);
    }
    vector<pair<char, char>> evacuationOrder = evacuate(partySizes);
    cout << "Case #" << t << ": ";
    for (int i = 0; i < evacuationOrder.size(); ++i) {
      cout << evacuationOrder[i].first; 
      if (evacuationOrder[i].second != '*') cout << evacuationOrder[i].second; 
      if (i < evacuationOrder.size() - 1) cout << ' ';      
    }
    cout << '\n';
  }
  cout << flush;
  return 0;
}
