#include <cstdio>
#define MAXN 1005

using namespace std;

int v[MAXN];
int b, n;

bool ok(int idx) {
  int left = 1;
  int right = n;
  long long count;
  while(left != right) {
    int mid = ((left + right) >> 1) + 1;
    count = mid;
    for(int i = 0; i < b; i++) {
      if(i+1 != idx) {
	count += (((double) ((long long) (mid - 1) * v[idx - 1])) / v[i]);
	if(i+1 < idx) {
	  count++;
	} else {
	  if(((long long) (mid - 1) * v[idx - 1]) % v[i] != 0)
	    count++;
	}
      }
    }
    if(count > n) {
      right = mid - 1;
    } else {
      left = mid;
    }
  }
  
  count = left;
  for(int i = 0; i < b; i++) {
    if(i+1 != idx) {
      count += (((double) ((long long) (left - 1) * v[idx - 1])) / v[i]);
      if(i+1 < idx) {
	count++;
      } else {
	if(((long long) (left - 1) * v[idx - 1]) % v[i] != 0)
	  count++;
      }
    }
  }
  return count == n;
}

int main() {
  int tc;
  scanf("%d", &tc);
  for(int kase = 1; kase <= tc; kase++) {
    scanf("%d %d", &b, &n);
    for(int i = 0; i < b; i++) {
      scanf("%d", &v[i]);
    }
    int ans;
    for(ans = 1; ans <= b; ans++) {
      if(ok(ans)) {
	break;
      }
    }
    printf("Case #%d: %d\n", kase, ans);
  }
  return 0;
}
