#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

char s[100][101];
int n;
char temoin[101];
int size_temoin;
int size_bloc[100][100];

bool can_solve(int k)
{
  if(k == 0)
    {
      size_temoin=0;
      int i = 0;
      while(s[0][i]!=0)
	{
	  temoin[size_temoin]=s[0][i];
	  size_bloc[0][size_temoin]=0;
	  while(s[0][i]==temoin[size_temoin])
	    {i++;size_bloc[0][size_temoin]++;}
	  size_temoin++;
	}
      temoin[size_temoin]=0;
      return true;
    }
  else
    {
      int i_t = 0;
      int i_s = 0;
      while(s[k][i_s]!=0)
	{
	  if(s[k][i_s]!=temoin[i_t])
	    return false;
	  size_bloc[k][i_t]=0;
	  while(s[k][i_s]==temoin[i_t])
	    {i_s++;size_bloc[k][i_t]++;}
	  i_t++;
	}
      if(s[k][i_s]!=temoin[i_t])
	return false;
      return true;
    }
}

int score(int i_t, int x)
{
  int sc = 0;
  for(int i = 0; i < n; i++)
        sc += max(x-size_bloc[i][i_t],size_bloc[i][i_t]-x);
  return sc;  
}

int main()
{
  int nb_cas;
  scanf("%d",&nb_cas);
  for(int cas = 1; cas <= nb_cas; cas++)
    {
      printf("Case #%d: ",cas);
      scanf("%d",&n);
      for(int i = 0; i < n; i++)
	scanf("%s",s[i]);
      bool can_do = true;
      for(int i = 0; i < n; i++)
	if(!can_solve(i))
	    can_do=false;
      if(!can_do)
	printf("Fegla Won\n");
      else
	{
	  int total_score = 0;
	  
	  for(int i_t= 0; i_t < size_temoin; i_t++)
	    {
	      int min_score = 100000;
	      for(int x = 1; x <= 100; x++)
		min_score = min(min_score,score(i_t,x));
	      total_score += min_score;
	    }
	  printf("%d\n",total_score);
	}
    }
  return 0;
}
