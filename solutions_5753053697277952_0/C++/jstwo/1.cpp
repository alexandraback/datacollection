
#include <vector>
#include <iostream>
#include <string>
#include <c++/cstring>
#include <map>


using namespace std;

void solve()
{
    int n;
    cin >> n;
    std::multimap<int,int, greater<int> > t;
    int total =0;
    for(int i =0; i < n;++i)
    {
        int tmp;
        cin >> tmp;
        total += tmp;
        t.insert(make_pair(tmp,i));
    }

    multimap<int, int>::iterator f, s;
    while(total >0)
    {
        char c;
        s = t.begin();
        f = s++;
        c=  'A' + f->second;
        cout <<c;
        total--;
        if((f->first -1) * 2 > total)
        {
            c = 'A' + f->second;
            total--;
            cout << c;
            t.insert(make_pair(f->first -2, f->second));
            t.erase(f);
        }
        else if(s != t.end() && s->first * 2 > total)
        {
            total--;
            c = 'A' + s->second;
            cout << c;
            t.insert(make_pair(f->first -1, f->second));
            t.insert(make_pair(s->first -1, s->second));
            t.erase(f);
            t.erase(s);
        }
        else
        {
            t.insert(make_pair(f->first -1, f->second));
            t.erase(f);
        }
        cout << " ";
    }
    cout << "\n";
}

int main() {
    int c;
    cin >> c;
    for(int i =0; i < c;++i)
    {
        std::cout << "Case #" << i +1 << ": ";
        solve();
    }
    return 0;
}
