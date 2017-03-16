#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

static inline int ABS(int a)
{
    return a > 0 ? a : -a;
}

int main()
{
    int count[100][100];
    int T;
    cin >> T;
    for (int t = 0; t < T; t++)
    {
        int result = 0;
        int N;
        cin >> N;

        bool failed = false;
        string tmpl;
        for (int n = 0; n < N; n++) {
            string s;
            cin >> s;
            if (!failed) {
                int sect = -1;
                for (int i = 0; i < s.size(); i++)
                {
                    if (i == 0 || s[i] != s[i - 1]) {
                        sect ++;
                        count[sect][n] = 0;
                        if (n == 0) {
                            tmpl += s[i];
                        } else {
                            if (sect >= tmpl.size() || s[i] != tmpl[sect]) {
                                failed = true;
                                break;
                            }
                        }
                    }

                    count[sect][n] ++;
                }
                if (!failed) {
                    // cout << "sect: " << sect << " tmpl:" << tmpl << tmpl.size() << std::endl;
                    if(sect + 1 != tmpl.size()) {
                        failed = true;
                    }
                }
            }
        }

        if (!failed) {
            for (int i = 0; i < tmpl.size() ; i++) {
                if (N == 2) {
                    result += ABS(count[i][0] - count[i][1]);
                } else {
                    // nlogn is not optimal but acceptable.
                    int* cur = count[i];
                    sort(cur, cur + N);
                    int median = N / 2;
                    for (int n = 0; n < N; n++) {
                        result += ABS(cur[median] - cur[n]);
                    }
                }
            }
        }

        cout << "Case #" << t + 1 << ": ";
        if (failed) {
            cout << "Fegla Won";
        } else {
            cout << result;
        }
        cout << std::endl;
    }
}
