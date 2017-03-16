#include <algorithm>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

struct Element
{
    int count;
    char letter;
};

void processCase()
{
    string line;
    getline(cin, line);
    istringstream in(line);
    int N;
    in >> N;

    vector<vector<Element> > words(N);
    for (int i = 0; i < N; ++i)
    {
        string word;
        getline(cin, word);
        Element curr = { 1, word[0] };
        size_t pos = 1;
        while (pos < word.length())
        {
            if (word[pos] == curr.letter)
            {
                ++curr.count;
            }
            else
            {
                words[i].push_back(curr);
                curr.count = 1;
                curr.letter = word[pos];
            }
            ++pos;
        }
        words[i].push_back(curr);
    }

    // Verify equal length
    size_t length = words[0].size();
    for (int i = 1; i < N; ++i)
    {
        if (words[i].size() != length)
        {
            cout << "Fegla Won" << endl;
            return;
        }
    }

    // Verify same letters
    int moves = 0;
    vector<int> counts(N);
    for (size_t i = 0; i < length; ++i) {
        char letter = words[0][i].letter;
        counts[0] = words[0][i].count;
        for (size_t j = 1; j < words.size(); ++j)
        {
            if (words[j][i].letter != letter)
            {
                cout << "Fegla Won" << endl;
                return;
            }
            counts[j] = words[j][i].count;
        }
        int pos = N / 2;
        nth_element(counts.begin(), counts.begin() + pos, counts.end());
        int median = counts[pos];
        for (int j = 0; j < N; ++j)
        {
            if (counts[j] < median)
            {
                moves += median - counts[j];
            }
            else
            {
                moves += counts[j] - median;
            }
        }
    }
    cout << moves << endl;

}

int main()
{
    string line;
    getline(cin, line);
    istringstream in(line);
    int T;
    in >> T;
    for (int i = 1; i <= T; ++i)
    {
        cout << "Case #" << i << ": ";
        processCase();
    }
}