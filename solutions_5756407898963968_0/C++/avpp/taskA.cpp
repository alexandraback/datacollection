#include <iostream>

using namespace std;

int main()
{
  int T = 0;
  cin>>T;
  for (int t = 1; t <= T; t++)
  {
    int r1 = 0, r2 = 0, i = 0, j = 0, tmp = 0;
    cin>>r1;
    int l[4];

    for (i = 1; i < r1; i++)
      for (j = 0; j < 4; j++)
        cin>>tmp;
    for (i = 0; i < 4; i++)
      cin>>l[i];
    for (i = r1; i < 4; i++)
      for (j = 0; j < 4; j++)
        cin>>tmp;

    int ans = -1;

    cin >>r2;
    for (i = 1; i < r2; i++)
      for (j = 0; j < 4; j++)
        cin>>tmp;
    for (i = 0; i < 4; i++)
    {
      cin>>tmp;
      if (ans == -2)
        continue;
      for (j = 0; j < 4; j++)
      {
        if (ans == -1 && tmp == l[j])
          ans = j;
        else if (tmp == l[j])
          ans = -2;
      }
    }
    for (i = r2; i < 4; i++)
      for (j = 0; j < 4; j++)
        cin>>tmp;
    if (ans >= 0)
      cout<<"Case #"<<t<<": "<<l[ans]<<"\n";
    else
      cout<<"Case #"<<t<<": "<<((ans==-2)?"Bad magician!":"Volunteer cheated!")<<"\n";
  }
  return 0;
}
