#include <iostream>
#include <vector>

using namespace std;

int get_max(vector<int> &data)
{
  int max_v = -1;
  int max_n = -1;
  for (int i = 0; i < data.size(); ++i)
  {
    if (data[i] > max_v)
    {
      max_v = data[i];
      max_n = i;
    }
  }
  if (max_v > 0)
  {
    data[max_n] --;
    return max_n;
  }
  else
    return -1;
}

int main()
{
  int T; cin >> T;
  for (int t=0; t<T; t++)
  {
    cout << "Case #" << t+1 << ":";
    
    int n; cin >> n;
    vector<int> data(n);
    int sum = 0;
    for (int i = 0; i < n; ++i)
    {
      cin >> data[i];
      sum += data[i];
    }
    
    while (true)
    {
      int v = get_max(data);
      if (v < 0) break;
      cout << " " << (char)('A' + v);
      sum --;
      if (sum != 2)
      {
        int v = get_max(data);
        if (v < 0) break;
        cout << (char)('A' + v);
        sum --;
      }
    }
    cout << endl;
  }
  return 0;
}