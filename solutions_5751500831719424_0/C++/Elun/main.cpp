#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

using namespace std;

int n;
char str[109][109];
char patC[109][109];
int patI[109][109];

void ReadData()
{
  scanf("%d%*c", &n);
  for(int i = 0; i < n; i++)
  {
    scanf("%s%*c", str[i]);
  }
}

bool answer;
int answerVal;

void Solve()
{
  answer = false;
  answerVal = 0;
  memset(patC, 0, sizeof(patC));
  memset(patI, 0, sizeof(patI));
  for(int i = 0; i < n; i++)
  {
    int len = strlen(str[i]);
    patC[i][0] = str[i][0];
    int cnt = 0;
    for(int j = 0; j < len; j++)
    {
      if(str[i][j] == patC[i][cnt])
      {
        patI[i][cnt]++;
      }
      else
      {
        cnt++;
        patC[i][cnt] = str[i][j];
        patI[i][cnt] = 1;
      }
    }
  }
  for(int T = 0; T < 109; T++)
  {
    if(patI[0][T] == 0)
    {
      for(int k = 0; k < n; k++)
      {
        if(patI[k][T] != 0)
        {
          return;
        }
      }
      answer = true;
      return;
    }
    int current = INT_MAX;
    for(int j = 1; j < 109; j++)
    {
      int acurrent = 0;
      for(int i = 0; i < n; i++)
      {
        if(patI[i][T] == 0 || patC[i][T] != patC[0][T])
        {
          return;
        }
        acurrent += abs(j - patI[i][T]);
      }
      current = min(current, acurrent);
    }
    answerVal += current;
  }
}

void WriteData()
{
  if(answer)
  {
    printf("%d\n", answerVal);
  }
  else
  {
    printf("Fegla Won\n");
  }
}

int main()
{
  int QWE;
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  scanf("%d", &QWE);
  for(int T = 0; T < QWE; T++)
  {
    printf("Case #%d: ", T + 1);
    ReadData();
    Solve();
    WriteData();
  }
  return 0;
}