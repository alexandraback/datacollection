#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;

#define st first
#define nd second
#define make(a,b) make_pair(a,b)

typedef pair<int,int> pun;
typedef long long ll;

int ile[N];

int test()
{
  int n;
  scanf("%d",&n);
  for (int i=0;i<n;i++){
    scanf("%d", ile+i);
  }
  while(1){
  int MAX = 0;
  int counter = 0;
  for (int i=0;i<n;i++){
    if ( ile[i] > MAX ){
      counter = 1;
      MAX = ile[i];
    }
    else if ( ile[i] == MAX ) counter++;
  }
  if ( MAX == 0 ) return 0;
  if ( counter == 2 ){
    for (int i=0;i<n;i++) {
      if (ile[i] == MAX){
        ile[i] --;
        printf("%c",'A'+i);
      }
    }
  }
  else{ for (int i=0;i<n;i++) {
      if (ile[i] == MAX){
        ile[i] --;
        printf("%c",'A'+i);
        break;
      }
    }
    }
  printf(" ");
  }
  printf("\n");
}

void print_test()
{
  auto x = test();
//  printf("%d ", x);
}

int main()
{
	int t;
	scanf("%d",&t);
	for (int i=1;i<=t;i++)
	{
		printf("Case #%d: ",i);
    print_test();
    printf("\n");
	}
}
