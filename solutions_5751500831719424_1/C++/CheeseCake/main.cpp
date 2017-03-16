#include <cstdio>
#include <algorithm>
#include <vector>
#include <deque>

#include <string>
using namespace std;
int maxnbclasses = 100;
void do_case()
{
  int n;
  scanf("%d", &n);
  vector<string> mots(n);
  char temp[105];
  for(int i = 0; i < n; i++)
  {
    scanf("%s", temp);
    mots[i] = temp;
  }
  int nbclasses = 0;
  vector<char> lclasse;
  vector< vector<int> > tailleclasseparmot(n);
  nbclasses++;
  lclasse.push_back( mots[0][0] );
  for(int index = 0; index < mots[0].length(); index ++)
  {
    if(mots[0][index] != lclasse.back())
    {
      nbclasses++;
      lclasse.push_back(mots[0][index]);
    }
  }

  bool possible = true;
  for(int i = 0; i < n; i++)
  {
    int nbclassesmot = 0;
    nbclassesmot ++;
    if(mots[i][0] != lclasse[0])
    {
      possible = false;
      break;
    }
    tailleclasseparmot[i].push_back(0);
    for(int index = 0; index < mots[i].length(); index++)
    {
      if(mots[i][index] != lclasse[nbclassesmot - 1])
      {
	nbclassesmot++;
	tailleclasseparmot[i].push_back(1);
	if(nbclassesmot > nbclasses || mots[i][index] != lclasse[nbclassesmot - 1])
	{
	  possible = false;
	  break;
	}
      }
      else
      {
	tailleclasseparmot[i].back()++;
      }

    }
    if(nbclassesmot < nbclasses)
    {
      possible = false;
      break;
    }
  }
  if(!possible)
  {
    printf("Fegla Won\n");
    return;
  }

  int reponse = 0;
  for(int classe = 0; classe < nbclasses; classe++)
  {
    int mini = 1000000;

    vector<int> values;
    int somme = 0;
    for(int i = 0; i < n; i++)
    {
     values.push_back(tailleclasseparmot[i][classe]); 
     somme += tailleclasseparmot[i][classe];
    }
    sort(values.begin(), values.end());
    int sommeactu = 0;
    for(int i = 0; i < n; i++)
    {
      int cout = i * values[i] - sommeactu + somme - sommeactu - (n - i) * values[i];
    sommeactu += values[i];

      if(cout < mini)
      {
	mini = cout;
      }
    }
    reponse += mini;
  }
  printf("%d\n", reponse);
  return;

}


int main()
{
  int t;
  scanf("%d", &t);
  for(int i = 1; i <= t; i++)
  {
    printf("Case #%d: ", i);
    do_case();

  }
  return 0;
}
