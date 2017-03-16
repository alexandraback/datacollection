#include <iostream>
#include <string>

int main()
{
    int T;
    std::cin >> T;
    for (int t = 1 ; t <= T ; ++t)
    {
        int r, c, n;
        std::cin >> r >> c >> n;
        int res = 0;
        n -= (r * c + 1) / 2;
        if (r == 3 && c == 3 && n == 3)
        {
            n = 0;
            res = 8;
        }
        if (n > 0)
        {
            if (r % 2 == 1 && c % 2 == 0)
                std::swap(r, c);
            if (c == 1 || r == 1)
            {
                r = r * c;
                if (r % 2 == 0)
                {
                    res += 1;
                    n -= 1;
                }
                if (n > 0)
                {
                    res += n * 2;
                    n = 0;
                }
            }
            /*else if (c == 2 || r == 2)
            {
                // r is even
                int max = c + r - 2;
                if (n < max)
                    max = n;
                n -= max;
                if (max-- > 0)
                    res += 2;
                if (max-- > 0)
                    res += 2;
                if (max < (std::max(r, c) - 2 + 1) / 2
                if (max > 0)
                    res += max * 3;
            }*/
            else if (r % 2)
            {
                // r and c are odd
                // no corners
                // fill top and bottom
                if (n > 1)
                {
                    n += (r * c + 1) / 2;
                    n -= (r * c) / 2;
                    for (int i = 0 ; i < 4 ; ++i)
                        if (n > 0)
                        {
                            --n;
                            res += 2;
                        }
                    int max = ((c - 2) / 2) * 2 + ((r - 2) / 2) * 2;
                    if (n < max)
                        max = n;
                    n -= max;
                    res += max * 3;
                }
                else
                {
                    int max = (c / 2) * 2 + (r / 2) * 2;
                    if (n < max)
                        max = n;
                    n -= max;
                    res += max * 3;
                }
                /*
                if (n == c / 2 * 2 + 1)
                {
                    res += (n - 1) * 3 + 2;
                    n = 0;
                }
                else if (n == r / 2 * 2 + 1)
                {
                    res += (n - 1) * 3 + 2;
                    n = 0;
                }
                else
                {
                    int max = (c / 2) * 2 + (r / 2) * 2;
                    if (n < max)
                        max = n;
                    n -= max;
                    res += max * 3;
                }
                */
            }
            else
            {
                // r is even
                int max = c + r - 2;
                if (n < max)
                    max = n;
                n -= max;
                if (max-- > 0)
                    res += 2;
                if (max-- > 0)
                    res += 2;
                if (max > 0)
                    res += max * 3;
            }
        }
        if (n > 0)
        {
            res += n * 4;
        }
        std::cout << "Case #" << t << ": ";
        std::cout << res;
        std::cout << "\n";
    }
    return 0;
}

