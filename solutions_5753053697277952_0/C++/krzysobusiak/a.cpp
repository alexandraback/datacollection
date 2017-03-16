#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
  int t;
  cin >> t;
  
  for (int i = 1; i <= t; i++)
  {
    int n;
    cin >> n;
    
    vector<pair<int, int> > v;
    
    for (int j = 0; j < n; j++)
    {
      int p;
      cin >> p;
      v.push_back(make_pair(p, j));
    }
    
    cout << "Case #" << i << ":";

    if (n == 2)
    {
      for (int j = 0; j < v[0].first; j++)
        cout << " AB";
    }
    else
    {
      sort(v.begin(), v.end());
      
      for (int j = v.size() - 1; j > 0; j--)
        for (int k = v[j-1].first; k < v[j].first; k++)
          for (int l = j; l < v.size(); l++)
            cout << " " << char(v[l].second + 'A');
      
      for (int k = 0; k < v[0].first - 1; k++)
        for (int l = 0; l < v.size(); l++)
          cout << " " << char(v[l].second + 'A');

      for (int l = 0; l < v.size() - 2; l++)
        cout << " " << char(v[l].second + 'A');
      
      cout << " " << char(v[v.size() - 2].second + 'A') << char(v[v.size() - 1].second + 'A');
    }

    cout << endl;
  }
  
  return 0;
}
