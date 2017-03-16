#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>

int main()
{
  int T;
  scanf("%d", &T);
  for (int t=1; t<=T; ++t) {
    int N;
    scanf("%d", &N);
    char str[200];
    char str2[200];
    std::vector<std::string> v2;
    std::vector<std::vector<int> > v3(N);
    for (int i=0; i<N; ++i) {
      scanf("%s", str);
      int z=0;
      for (int x=0; str[x]; ) {
	int y;
	str2[z++] = str[x];
	for (y=x+1; str[x] == str[y]; ++y) {}
	v3[i].push_back(y-x);
	x = y;
      }
      str2[z] = 0;
      v2.push_back(str2);
    }
    int sum=0;
    for (int i=1; i<N; ++i) {
      if (v2[i-1] != v2[i]) {
	printf("Case #%d: Fegla Won\n", t);
	goto done;
      }
    }
    for (unsigned i=0; i<v3[0].size(); ++i) {
      std::vector<int> v(N);
      for (int j=0; j<N; ++j) {
	v[j] = v3[j][i];
      }
      std::sort(v.begin(), v.end());
      int middle = N/2;
      for (int j=0; j<middle; ++j)
	sum += v[middle] - v[j];
      for (int j=middle+1; j<N; ++j)
	sum += v[j] - v[middle];
    }
    printf("Case #%d: %d\n", t, sum);
  done:{}
  }
  return 0;
}
