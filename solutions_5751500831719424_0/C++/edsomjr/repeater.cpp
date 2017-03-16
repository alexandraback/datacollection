#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Entry {
public:
	char c;
	unsigned char count;
};

typedef vector<Entry> Histogram;

bool check_size(const vector<Histogram>& histograms)
{
	size_t size = histograms[0].size();

	for (size_t i = 1; i < histograms.size(); i++)
	{
		if (histograms[i].size() != size)
			return false;
	}

	return true;
}

int median(const vector<int>& values)
{
	int size = values.size();

	if (size % 2)
		return values[size/2];
	else
		return (values[size/2] + values[size/2 - 1])/2;
}

Histogram create_histogram(const string& s)
{
	Histogram h;

	string word = s + '/';

	int size = word.size();
	int c = s[0];
	int count = 1;

	for (int i = 1; i < size; i++)
	{
		if (word[i] == c)
			count++;
		else
		{
			Entry e;
			e.c = c;
			e.count = count;

			h.push_back(e);
			count = 1;
			c = word[i];
		}
	}

	return h;
}

int main()
{
	int T;
	cin >> T;

	for (int test = 1; test <= T; test++)
	{
		int N;
		cin >> N;

		vector<string> words;
		for (int i = 0; i < N; i++)
		{
			string word;
			cin >> word;

			words.push_back(word);
		}

		vector<Histogram> histograms;

		for (int i = 0; i < N; i++)
		{
			Histogram h = create_histogram(words[i]);
			histograms.push_back(h);
		}			
		
		cout << "Case #" << test << ": ";
		
		if (check_size(histograms) == false)
			cout << "Fegla Won" << endl;
		else
		{
			int size = histograms[0].size();
			int moves = 0;
			bool possible = true;

			for (int j = 0; j < size; j++)
			{
				vector<int> values;

				possible = true;
				char c = histograms[0][j].c;
				int count = histograms[0][j].count;
				values.push_back(count);

				for (int i = 1; i < N; i++)
				{
					if (histograms[i][j].c == c)
					{
						count = histograms[i][j].count;
						values.push_back(count);
					} else
					{
						possible = false;
						break;
					}
				}

				if (possible == false)
				{
					cout << "Fegla Won" << endl;
					break;
				} else
				{
					sort(values.begin(), values.end());

					int m = median(values);
					
					for (size_t k = 0; k < values.size(); k++)
					{
						moves += abs(m - values[k]);
					}
				}
			}

			if (possible)
				cout << moves << endl;
		}
	}

	return 0;
}

