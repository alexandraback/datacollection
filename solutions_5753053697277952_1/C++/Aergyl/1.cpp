#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <queue>


using namespace std;


const bool OUTPUT_TO_FILE = true;


//Constants:
map<int, char> char_map;


//IO variables:
int t_in;
int n_in;
int nn[26];
string s_in;
stringstream out;


//Other global variables:
priority_queue<pair<int,int>> parties;




void setup()
{
    char_map[0] = 'A';
    char_map[1] = 'B';
    char_map[2] = 'C';
    char_map[3] = 'D';
    char_map[4] = 'E';
    char_map[5] = 'F';
    char_map[6] = 'G';
    char_map[7] = 'H';
    char_map[8] = 'I';
    char_map[9] = 'J';
    char_map[10] = 'K';
    char_map[11] = 'L';
    char_map[12] = 'M';
    char_map[13] = 'N';
    char_map[14] = 'O';
    char_map[15] = 'P';
    char_map[16] = 'Q';
    char_map[17] = 'R';
    char_map[18] = 'S';
    char_map[19] = 'T';
    char_map[20] = 'U';
    char_map[21] = 'V';
    char_map[22] = 'W';
    char_map[23] = 'X';
    char_map[24] = 'Y';
    char_map[25] = 'Z';
}

void reset_variables()
{
    while (!parties.empty())
    {
        parties.pop();
    }
}

void do_the_real_deal()
{
    cin >> n_in;
    for (int i = 0; i < n_in; i++)
    {
        cin >> nn[i];
    }

    for (int i = 0; i < n_in; i++)
    {
        parties.push({nn[i], i});
    }

    while (parties.size() > 2)
    {
        pair<int,int> p = parties.top();
        parties.pop();
        out << char_map[p.second] << " ";

        if (p.first > 1)
        {
            pair<int,int> p2 = {p.first - 1, p.second};
            parties.push(p2);
        }
    }

    while (true)
    {
        pair<int,int> p = parties.top();
        parties.pop();
        pair<int,int> p2 = parties.top();
        parties.pop();
        if (p.first > 1)
        {
            out << char_map[p.second] << char_map[p2.second] << " ";
        }
        else if (p.first == 1)
        {
            out << char_map[p.second] << char_map[p2.second];
        }
        else
        {
            break;
        }
        p = {p.first - 1, p.second};
        p2 = {p2.first - 1, p2.second};
        parties.push(p);
        parties.push(p2);
    }
}

void add_answer_to_output()
{
    
}





void print_output()
{
	if (OUTPUT_TO_FILE)
	{
		ofstream output_file;
		output_file.open("out.txt");
		output_file << out.rdbuf();
		output_file.close();
	}
	else
	{
		cout << out.rdbuf();
	}
}

int main()
{
    cout.sync_with_stdio(false);
    setup();
    cout << "Setup finished.\n";

	cin >> t_in;
	for (int run = 1; run <= t_in; run++)
	{
        reset_variables();
        out << "Case #" << run << ": ";
        do_the_real_deal();

        add_answer_to_output();
        out << "\n";
	}

    print_output();
}
