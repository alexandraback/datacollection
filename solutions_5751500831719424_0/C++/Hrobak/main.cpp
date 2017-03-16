#include <bits/stdc++.h>
#include <QtCore>

using namespace std;

int moves (const string &s1, const string &s2)
{
    vector <int> m1, m2;
    string a1, a2;
    char prc = 0; int temp = 0;
    for (int i = 0; i < s1.length(); ++i)
        if (s1[i] != prc && prc != 0)
        {
            m1.push_back(temp);
            a1.push_back(prc);
            prc = s1[i];
            temp = 1;
        }
        else if (0 == prc)
            prc = s1[i];
        else
            ++temp;
    m1.push_back(temp);
    a1.push_back(prc);
    temp = 0; prc = 0;
    for (int i = 0; i < s2.length(); ++i)
        if (s2[i] != prc && prc != 0)
        {
            m2.push_back(temp);
            a2.push_back(prc);
            prc = s2[i];
            temp = 1;
        }
        else if (0 == prc)
                prc = s2[i];
        else
            ++temp;
    m2.push_back(temp);
    a2.push_back(prc);
    if (a1 != a2)
        return INT_MAX;
    int ans = 0;
    //cout << m1.size() << endl;
    for (int i = 0; i < m1.size(); ++i)
        ans += abs(m1[i] - m2[i]);
    return ans;
}

int main ()
{
    ios_base::sync_with_stdio(0);
    ifstream cin ("/home/misha/A-small-attempt0.in");
    ofstream cout ("/home/misha/AOut");
    int t;
    cin >> t;
    vector <string> data(110);
    for (int i = 0; i < t; ++i)
    {
        int n;
        cin >> n;
        vector <long long> answers;
        for (int j = 0; j < n; ++j)
        {
            cin >> data[j];
        }

        for (int j = 0; j < n; ++j)
        {
            long long r = 0;
            for (int k = 0; k < n; ++k)
            {
                if (k != j)
                {
                    //cout << moves(data[j], data[k]);
                    r += (moves(data[j], data[k]));
                }
            }
            answers.push_back(r);
        }
        long long ans = *min_element(answers.begin(), answers.end());
        cout << "Case #" << i + 1 << ": ";
        if (ans == INT_MAX)
            cout << "Fegla Won" << endl;
        else
            cout << ans << endl;

    }
}
