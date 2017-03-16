#include<cstdio>
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;
vector<int>v[1000000];
string s;
int t, x, X, n, i, j, nr, l, med;
long long int wynik;
char c[1000000];
bool e;
int main()
{
  scanf("%d", &t);
  
  for(nr = 1; nr <= t; nr++)
  {    
    scanf("%d", &n);
    
    cin>>s;
    c[0] = s[0];
    x = 0;
    l = 1;
    for(j = 1; j < s.size(); j++)
    {
      if (s[j] != s[j - 1])
      {
	v[x].push_back(l);
	l = 0;
	x++;
	c[x] = s[j];
      }
      l++;
    }
	v[x].push_back(l);
	l = 0;
	X = x + 1;
    
    e = true;
    
    for(i = 1; i < n; i++)
    {
      cin>>s;
      if (e == true)
      {
	if (s[0] != c[0]) {e = false;}
	l = 1;
	x = 0;
	for(j = 1; j < s.size(); j++)
	{
	  if (s[j] != s[j - 1])
	  {
	    if (x + 1 == X || s[j] != c[x + 1]){e = false;break;}
	    v[x].push_back(l);
	    l = 0;
	    x++;
	  }
	  l++;
	}
	    v[x].push_back(l);
	    l = 0;
	    if (x + 1 != X){e = false;}
      }  
    }
    
    printf("Case #%d: ", nr);
    
    if (e == false){printf("Fegla won\n");for(i = 0; i < X; i++){v[i].clear();}}
    else
    {
      wynik = 0;
      for(i = 0; i < X; i++)
      {
	sort(v[i].begin(), v[i].end());
	med = v[i][(v[i].size() - 1) / 2];
	for(j = 0; j < v[i].size(); j++)
	{
	  wynik += abs(v[i][j] - med);
	}
	v[i].clear();
      }
      printf("%lld\n", wynik);
    }
  }
  
return 0;
}