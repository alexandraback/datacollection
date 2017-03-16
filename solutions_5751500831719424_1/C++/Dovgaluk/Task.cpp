#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <stdio.h>

int main()
{
	int T;
	std::cin >> T;
	for (int t = 1 ; t <= T ; ++t)
	{
        std::string s;
        int n;
        std::cin >> n;
        std::vector<std::vector<int> > v(n);
        std::getline(std::cin, s);
        std::string s0;
        bool fegla = false;
        std::cout << "Case #" << t << ": ";
        for (int i = 0 ; i < n ; ++i)
        {
            //std::getline(std::cin, s);
            char buf[1024];
            scanf("%s", buf);
            s = buf;
            std::string ss;
            for (size_t j = 0 ; j != s.size() ; ++j)
            {
                if (j == 0 || s[j] != s[j-1])
                {
                    v[i].push_back(1);
                    ss.push_back(s[j]);
                }
                else
                {
                    ++v[i].back();
                }
            }
            if (i == 0)
            {
                s0 = ss;
            }
            else
            {
                if (s0 != ss)
                {
                    fegla = true;
                    break;
                }
            }
        }
        if (fegla)
            std::cout << "Fegla Won\n";
        else
        {
            int res = 0;
            for (size_t j = 0 ; j != s0.size() ; ++j)
            {
                int m = 1000000;
                for (int i = 0 ; i < n ; ++i)
                {
                    int r = 0;
                    for (int ii = 0 ; ii < n ; ++ii)
                        r += std::abs(v[i][j] - v[ii][j]);
                    if (r < m)
                        m = r;
                }

                res += m;
            }
            std::cout << res << "\n";
        }
	}
	return 0;
}

