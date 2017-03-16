#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main()
{
  int T;
  std::cin >> T;
  for (int t=1; t<=T; t++)
  {
    int N;
    std::cin >> N;
    std::vector<std::string> a(N);
    std::vector<std::string::const_iterator> cp(N);
    for (int i=0; i<N; i++)
    {
      std::cin >> a[i];
      a[i] += '#';
      cp[i] = a[i].begin();
    }

    int sum = 0;
    while(*cp[0] != '#')
    {
      char curch = *cp[0];
      std::vector<int> cnt(N);
      for (int j=0; j<N; j++)
      {
        if (*cp[j] != curch)
          goto fail;
        while(*cp[j] == curch)
        {
          cp[j]++;
          cnt[j]++;
        }
      }
      std::sort(cnt.begin(), cnt.end());
      int med = cnt[N/2];
      for (int j=0; j<N; j++)
        sum += abs(cnt[j] - med);
    }
    for (int i=0; i<N; i++)
      if (*cp[i] != '#')
        goto fail;
    std::cout << "Case #" << t << ": " << sum << std::endl;
    continue;
fail:
    std::cout << "Case #" << t << ": Fegla Won" << std::endl;
  }
  return 0;
}
