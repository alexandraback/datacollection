#include<fstream>
#include<vector>
using namespace std;

int main()
{
  ifstream cin("1.in");
  ofstream cout("1.out");

  int t, T;
  cin >> T;
  for (t = 1; t <= T; t ++)
  {
    int n;
    cin >> n;
    vector<int> num;
    for (int i = 0; i < n; i ++)
    {
      int tmp;
      cin >> tmp;
      num.push_back(tmp);
    }

    int ret1 = 0, ret2 = 0;
    int maxd = 0;
    for (int i = 0; i < n - 1; i ++)
    {
      if (num[i] > num[i + 1])
      {
        ret1 += num[i] - num[i + 1];
        if (num[i] - num[i + 1] > maxd)
          maxd = num[i] - num[i + 1];
      }
    }
    for (int i = 0; i < n - 1; i ++)
    {
      ret2 += min(maxd, num[i]);
    }
    cout << "Case #"  << t << ": ";
    cout << ret1 << ' ' << ret2 << endl;
  }
  return 0;
}
