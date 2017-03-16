#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#define LL long long
#define MP make_pair
#define PB push_back
#define ff first
#define ss second
#define DEBUG(x) cerr<<#x<<" "<<(x)<<endl;

using namespace std;
const int N = 105;
int n;
char word[N][N];
int jaka[N][N], ile[N][N];
int main()
{
  int t;
  scanf("%d", &t);
  for(int z=1; z<=t; z++)
  {

    int m = 0;
    int nie = 0;
    printf("Case #%d: ", z);
    scanf("%d", &n);
    for(int i=1; i<=n; i++)
    {
      scanf("%s", &word[i][1]);
      int in = 0;     
      int l = strlen(word[i]+1);
      for(int j=1; j<=l; j++)
      {
	if(word[i][j] != word[i][j-1])
	{
	  in++;
	  jaka[i][in] = word[i][j];
	  if(i > 1 && jaka[i][in] != jaka[i-1][in])
	    nie = 1;
	}
	ile[i][in]++;
      }      
      if(m != in && i > 1)
	nie = 1;
      m = max(in, m);
    }
    
    if(nie == 1)
    {
      
      for(int i=1; i<=n; i++)
      {
	int l = strlen(word[i]+1);
	for(int j=1; j<=l;j++)
	  word[i][j] = 0;
	for(int j=1; j<=m; j++)
	  ile[i][j] = jaka[i][j] = 0;
      }
    
      
      printf("Fegla Won\n");
      continue;
    }
    int wynik = 0;
    vector<int>v;
    for(int i=1; i<=m; i++)
    {
      v.clear();
      for(int j=1; j<=n; j++)
      {
	v.PB(ile[j][i]);
      }
      sort(v.begin(), v.end());
      
      int mediana = v[(n-1)/2];

      for(int j=1; j<=n; j++)
      {
	wynik += abs(mediana - ile[j][i]);
      }
    }
    printf("%d\n", wynik);
    for(int i=1; i<=n; i++)
    {
      int l = strlen(word[i]+1);
      for(int j=1; j<=l;j++)
	word[i][j] = 0;
      for(int j=1; j<=m; j++)
	ile[i][j] = jaka[i][j] = 0;
    }
  }
  return 0;
}