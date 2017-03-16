#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <set>
#include <cstdio>
#include <string>
#include <queue>
#include <iterator>

using namespace std;

const long long p = 1000000007;

int main()
{
    freopen ("input.txt","r",stdin);
    freopen ("output.txt","w",stdout);

    int T;

    cin >> T;

    for(int test_case = 1; test_case <= T; ++test_case)
    {
        int N, Answer = 0;

        cin >> N;

        vector<string> data(N);

        for(int i = 0; i < N; ++i)
        {
            cin >> data[i];
        }

        string temp;

        vector< vector<int> > ololo(N, vector<int>(101));

        temp.push_back(data[0][0]);
        ++ololo[0][0];
        int count = 0;

        for(int i = 1; i < data[0].length(); ++i)
        {
            if(data[0][i] != temp[count])
            {
                temp.push_back(data[0][i]);
                ++count;
                ++ololo[0][count];
            }
            else
            {
                ++ololo[0][count];
            }
        }

        for(int i = 1; i < N; ++i)
        {
            int count = 0;

            if(data[i][0] != temp[0])
            {
                cout << "Case #" << test_case << ": "<< "Fegla Won" << endl;
                ++Answer;
                break;
            }
            else
            {
                ++ololo[i][0];
                for(int j = 1; j < data[i].length(); ++j)
                {
                    if(data[i][j] != data[i][j - 1])
                    {
                        ++count;
                        if(count >= temp.size())
                        {
                            cout << "Case #" << test_case << ": "<< "Fegla Won" << endl;
                            ++Answer;
                            break;
                        }
                        ++ololo[i][count];
                        if(data[i][j] != temp[count])
                        {
                            cout << "Case #" << test_case << ": "<< "Fegla Won" << endl;
                            ++Answer;
                            break;
                        }
                    }
                    else
                    {
                        ++ololo[i][count];
                    }
                }

                if(Answer)
                    break;

                if(!Answer && count < temp.size() - 1)
                {
                    cout << "Case #" << test_case << ": "<< "Fegla Won" << endl;
                    ++Answer;
                    break;
                }
            }

        }

        if(!Answer)
        {
            for(int s = 0; s < temp.size(); ++s)
            {
                int ololoAnswer = p;
                for(int n = 0; n < N; ++n)
                {
                    int tmpAnswer = 0;
                    for(int m = 0; m < N; ++m)
                    {
                        if(n != m)
                        {
                            tmpAnswer += abs(ololo[n][s] - ololo[m][s]);
                        }
                    }
                    ololoAnswer = min(ololoAnswer, tmpAnswer);
                }
                
                Answer += ololoAnswer;
            }

            cout << "Case #" << test_case << ": "<< Answer << endl;
        }
    } 

    return 0;
}