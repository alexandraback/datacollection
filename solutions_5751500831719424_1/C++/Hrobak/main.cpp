#include <bits/stdc++.h>
#include <QtCore>

using namespace std;

vector <int> mmd [110];
vector <int> man [110];
string eth;

int moves (int j, const string &s1)
{
    string a1;
    char prc = 0; int temp = 0;
    for (int i = 0; i < s1.length(); ++i)
        if (s1[i] != prc && prc != 0)
        {
            mmd[j].push_back(temp);
            a1.push_back(prc);
            prc = s1[i];
            temp = 1;
        }
        else if (0 == prc)
        {
            prc = s1[i];
            ++temp;
        }
        else
            ++temp;
    a1 += prc;
    //cout << a1 << endl;
    if (eth.empty())
        eth = a1;
    if (a1 != eth)
        return 100;
    mmd[j].push_back(temp);
    return 0;

}

int main ()
{
    ios_base::sync_with_stdio(0);
    ifstream cin ("/home/misha/A-large.in");
    ofstream cout ("/home/misha/AOut2");
    int t;
    cin >> t;
    vector <string> data(110);
    for (int i = 0; i < t; ++i)
    {
        goto A;
        HELL: ++i;
        if (i >= t)break;
        A:for (int j = 0; j < 110; ++j){
            mmd[j].clear(); man[j].clear();}
        eth.clear();
        int n;
        cin >> n;
        vector <long long> answers;
        cout << "Case #" << i + 1 << ": ";

        for (int j = 0; j < n; ++j)
        {
            cin >> data[j];
        }

        for (int j = 0; j < n; ++j)
        {
            if (moves(j, data[j]) != 0)
            {
                cout << "Fegla Won" << endl;
                goto HELL;
            }
        }

        //cout << mmd[0][0] << mmd[0][1] << mmd[0][2] << endl;

        for (int j = 0; j < mmd[0].size(); ++j)
        {
            for (int k = 1; k <= 100; ++k)
            {
                int r = 0;
                for (int l = 0; l < n; ++l)
                {
                    //cout << mmd[l][j] << endl;
                    r += (abs(mmd[l][j] - k));

                    //cout << r << endl;

                }
                man[j].push_back(r);
            }
        }

        for (int j = 0; j < mmd[0].size();++j)
        {
            answers.push_back(*min_element(man[j].begin(), man[j].end()));
        }
        cout << accumulate(answers.begin(), answers.end(),0) << endl;



    }
}


