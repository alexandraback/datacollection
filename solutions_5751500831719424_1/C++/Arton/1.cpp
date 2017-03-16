#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

vector<string> strings;

typedef struct Char_Count
{
    char c;
    int count;
} Char_Count;

vector< vector<Char_Count> > data;

void fill_data()
{
    data.clear();
    for ( int i = 0; i < strings.size(); ++i )
    {
        vector<Char_Count> seq;
        string str = strings[i];
        char prev = 0;
        Char_Count cur_char_count;
        cur_char_count.c = 0;
        cur_char_count.count = 0;
        for ( int j = 0; j < str.size(); ++j )
        {
            if ( str[j] == prev )
            {
                cur_char_count.count++;
            }
            else
            {
                if ( cur_char_count.count != 0 )
                {
                    seq.push_back( cur_char_count );
                    // cout << cur_char_count.c << " " << cur_char_count.count << endl;
                }
                cur_char_count.c = str[j];
                cur_char_count.count = 1;
                prev = str[j];
            }
        }
        seq.push_back( cur_char_count );
        data.push_back( seq );
    }
}

bool print_if_lose()
{
    int freg_count = data[0].size();
    for ( int r = 1; r < data.size(); ++r )
        if ( data[r].size() != freg_count )
        {
            cout << "Fegla Won";
            return false;
        }

    for ( int c = 0; c < data[0].size(); ++c )
    {
        char ch = data[0][c].c;
        for ( int r = 1; r < data.size(); ++r )
        {
            if ( data[r][c].c != ch )
            {
                cout << "Fegla Won";
                return false;
            }
        }
    }

    return true;
}

void print_count()
{
    int ans = 0;
    for ( int c = 0; c < data[0].size(); ++c )
    {
        vector<int> cs;
        for ( int r = 0; r < data.size(); ++r )
        {
            cs.push_back( data[r][c].count );
            // cout << data[r][c].count << " ";
        }
        sort( cs.begin(), cs.end() );
        int mid = cs[(cs.size()-1)/2];
        for ( int i = 0; i < cs.size(); ++i )
        {
            ans += abs( cs[i] - mid );
            // cout << mid << " ";
        }
    }

    cout << ans;
}

void print_ans()
{
    fill_data();
    if ( print_if_lose() )
    {
        print_count();
    }
}

int main()
{
    int case_num;
    cin >> case_num;
    for ( int i = 0; i < case_num; ++i )
    {
        strings.clear();
        int string_num;
        cin >> string_num;
        for ( int j = 0; j < string_num; ++j )
        {
            string temp;
            cin >> temp;
            strings.push_back( temp );
        }
        printf( "Case #%d: ", i + 1 );
        print_ans();
        printf( "\n" );
    }
    return 0;
}

