#include <cstdio>

#define SMALL
//#define LARGE

int T, n, nums[30], out[30];

int main()
{
#ifdef SMALL
  freopen("A-small.in", "r", stdin);
  freopen("A-small.out", "w", stdout);
#endif
#ifdef LAREG 
  freopen("A-large.in", "r", stdin);
  freopen("A-large.out", "w", stdout);
#endif

  scanf("%d", &T);
  for (int Case = 1; Case <= T; ++Case) {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
      scanf("%d", &nums[i]);
    printf("Case #%d:", Case);
    while (1) {
      int top = 0, id = 0;
      for (int i = 0; i < n; ++i) {
        if (nums[id] < nums[i])
          id = i, top = 0;
        if (nums[id] == nums[i])
          out[top++] = i;
      }
      if (nums[out[0]] == 0) {
        printf("\n");
        break;
      }
      printf(" ");
      if (top == 3 && nums[out[0]] == 1) {
        printf("%c", 'A' + out[0]);
        --nums[out[0]];
        continue;
      }
      for (int i = 0; i < 2 && i < top; ++i) {
        printf("%c", 'A' + out[i]);
        --nums[out[i]];
      }
    }
  }
  return 0;
}
