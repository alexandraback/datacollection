#include <cstdio>
#include <set>
#include <vector>

using namespace std;

set<int> yolo()
{
    set<int> s;
    int x;
    scanf("%d", &x);
    for(int i = 1; i <= 4; i++)
    {
        for(int j = 1; j <= 4; j++)
        {
            int y;
            scanf("%d", &y);
            if(i == x) s.insert(y);
        }
    }
    return s;
}

int heh(set<int> a, set<int> b)
{
    vector<int> wsio;
    for(set<int>::iterator i = a.begin(); i != a.end(); i++)
        if(b.find(*i) != b.end())
            wsio.push_back(*i);
    if(wsio.empty()) return -1;
    if(wsio.size() > 1) return 0;
    return wsio[0];
}

void przyp()
{
    set<int> a = yolo();
    set<int> b = yolo();
    int x = heh(a, b);
    if(x == 0) printf("Bad magician!\n");
    else if(x < 0) printf("Volunteer cheated!\n");
    else printf("%d\n", x);
}

int main()
{
    int t;
    scanf("%d", &t);
    for(int i = 1; i <= t; i++)
    {
        printf("Case #%d: ", i);
        przyp();
    }
    return 0;
}
