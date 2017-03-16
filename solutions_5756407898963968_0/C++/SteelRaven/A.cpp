#include <algorithm>
#include <iostream>
#include <iterator>

using namespace std;

int field[16];
int first[4];
int second[4];
int result[4];

void solve() {
  int choice;
  cin >> choice;
  copy_n(istream_iterator < int > (cin), 16, field);
  copy_n(field + (choice - 1) * 4, 4, first);
  sort(first, first + 4);
  cin >> choice;
  copy_n(istream_iterator < int > (cin), 16, field);
  copy_n(field + (choice - 1) * 4, 4, second);
  sort(second, second + 4);
  int resultCount = set_intersection(first, first + 4, second, second + 4, result) - result;
  if(resultCount == 0){
    cout << "Volunteer cheated!";
  }else if(resultCount == 1){
    cout << result[0];
  }else{
    cout << "Bad magician!";
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  for(int i = 1; i <= t; ++i){
    cout << "Case #" << i << ": ";
    solve();
    cout << '\n';
  }
}