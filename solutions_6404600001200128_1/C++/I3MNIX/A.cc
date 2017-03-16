#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int n;
vector <int> arr;

int main(){
  int t;
  cin >> t;
  for (int idx = 1; idx <= t; idx++){
    cout << "Case #" << idx << ": ";
    cin >> n;
    arr.resize(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    int one = 0;
    int diff = 0;
    for (int i = 1; i < n; i++){
      if (arr[i] < arr[i-1]) one += (arr[i-1] - arr[i]);
      diff = max(diff, arr[i-1] - arr[i]);
    }
    long long two = 0;
    for (int i = 0; i < n-1; i++){
      two += min(diff, arr[i]);
    }

    cout << one << " " << two << endl;
    
  }

  return 0;
}
