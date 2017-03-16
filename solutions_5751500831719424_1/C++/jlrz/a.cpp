#include <iostream>
#include <map>
#include <list>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
#include <memory>
#include <cassert>
#include <set>
#include <numeric>

using namespace std;

#define MAPITR(a,b) map<a,b>::iterator
#define LISTITR(a)  list<a>::iterator

#define ITER(itr,a)   for( itr = (a).begin(); itr != (a).end(); ++itr )
#define ITERNI(itr,a) for( itr = (a).begin(); itr != (a).end();  )
#define FORI(i,a,b)   for( int i(a), _b(b); i < _b; ++i )
#define FORD(i,a,b)   for( int i(a), _b(b); i > _b; --i )
#define FORLE(i,a,b)  for( int i(a), _b(b); i <= _b; ++i )
#define FORGE(i,a,b)  for( int i(a), _b(b); i >= _b; --i )

#define DISCARD_LINE  { char buf[32]; cin.getline(buf, 32); }

using dword = unsigned int;
using qword = unsigned long long;

using lb = list<bool>;
using lc = list<char>;
using li = list<int>;
using ld = list<double>;
using ls = list<string>;

using vb = vector<bool>;
using vc = vector<char>;
using vi = vector<int>;
using vd = vector<double>;
using vs = vector<string>;
using vll = vector<long long>;

using vdw = vector<dword>;
using vqw = vector<qword>;

template <class T>
inline auto XY(T& a, size_t x, size_t y, size_t width) -> decltype(a[y*width + x]) { return a[y*width + x]; };
//////////////////////////////////////////////////////////////////////////////////////////////////////

struct mychar
{
    char ch;
    int  num;
};

using mystring = mychar[100];

bool equal(const mystring& a, const mystring& b, int start)
{
    FORI(i, start, 100)
    {
        if (a[i].ch != b[i].ch)
            return false;
        if (a[i].num != b[i].num)
            return false;

        if (a[i].num == 0)
            return true;
    }

    return true;
}

int play(vector<mystring>& strings, int start = 0, int depth = 0)
{
    bool done = true;
    int numStrings = strings.size();
    FORI(i, 1, numStrings)
    {
        if (!equal(strings[0], strings[i], start))
        {
            done = false;
            break;
        }
    }

    if (done)
        return depth;

    auto strCopy = vector<mystring>(numStrings);

    FORI(i, 0, numStrings)
    {
        memcpy_s(strCopy[i], 100 * sizeof(mychar), strings[i], 100 * sizeof(mychar));
    }


    vi median(numStrings);
    FORI(i, start, 100)
    {
        if ((strCopy[0])[i].num == 0)
            break;

        FORI(j, 0, numStrings)
        {
            median[j] = (strCopy[j])[i].num;
        }

        sort(begin(median), end(median));

        auto mid = median[median.size() / 2];

        for (auto &mystr : strCopy)
        {
            depth += abs(mystr[i].num - mid);
            mystr[i].num = mid;
        }
    }

    return depth;
}

void process()
{
    int numStrings;
    cin >> numStrings;

    DISCARD_LINE;

    auto strings = make_unique<string[]>(numStrings);
    auto myStrings = vector<mystring>(numStrings);

    FORI(i, 0, numStrings)
    {
        cin >> strings[i];

        auto c = &(myStrings[i])[0];
        auto &str = strings[i];

        c->ch = str[0];

        FORI(j, 0, str.length())
        {
            if (c->ch != str[j])
            {
                ++c;
                c->ch = str[j];
            }

            ++c->num;
        }
    }

    mystring& ref = myStrings[0];
    FORI(i, 1, numStrings)
    {
        mystring& comp = myStrings[i];
        FORI(j, 0, 100)
        {
            if (ref[j].ch != comp[j].ch)
            {
                cout << "Fegla Won";
                return;
            }

            if (ref[j].num == 0)
            {
                break;
            }
        }
    }

    cout << play(myStrings);
}

int main()
{
    int nCases;
    cin >> nCases;

    FORLE(i, 1, nCases)
    {
        cout << "Case #" << i << ": ";

        process();

        cout << endl;
    }

    return 0;
}