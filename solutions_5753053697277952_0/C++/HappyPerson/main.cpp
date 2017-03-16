#include <cstdio>

using namespace std;

const int MAXP=26;

int cases, parties, m1, m2;
int pList[MAXP+5];

int main()
{
  scanf("%d", &cases);
  for(int q=1; q<=cases; q++)
  {
    m1=0, m2=0;
    scanf("%d", &parties);
    for(int i=1; i<=parties; i++)
      scanf("%d", &pList[i]);
    printf("Case #%d: ", q);

    for(int i=1; i<=parties; i++)
      if(pList[i]>pList[m1])
        m1=i;
    for(int i=1; i<=parties; i++)
      if(pList[i]>pList[m2] && i!=m1)
        m2=i;

    for(; pList[m1]>pList[m2]; pList[m1]--)
      printf("%c ", 'A'+m1-1);

    for(int i=1; i<=parties; i++)
      if(i!=m1 && i!=m2)
        for(int j=1; j<=pList[i]; j++)
          printf("%c ", 'A'+i-1);

    for(; pList[m1]; pList[m1]--)
      printf("%c%c ", 'A'+m1-1, 'A'+m2-1);

    printf("\n");
  }
}
