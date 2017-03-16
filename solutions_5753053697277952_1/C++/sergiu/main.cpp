#include <fstream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

int no_senators[27];

class comparator
{
public:
    bool operator()(const int& a, const int& b)
    {
        return (no_senators[a] < no_senators[b]);
    }
};

priority_queue<int, std::vector<int>, comparator> pq;
vector <string> plan;

void make_plan(int total)
{
    int first, second;
    string evacuated;
    char temp[3];
    if (total % 2 == 1)
    {
        evacuated = "";
        first = pq.top();
        pq.pop();
        temp[0] = 'A' + first;
        temp[1] = '\0';
        evacuated = temp;
        plan.push_back(evacuated);
        no_senators[first]--;
        if (no_senators[first] > 0)
            pq.push(first);
    }
    while (!pq.empty())
    {
        evacuated = "";
        first = pq.top();
        pq.pop();
        temp[0] = 'A' + first;
        no_senators[first]--;
        if (no_senators[first] > 0)
            pq.push(first);
        second = pq.top();
        pq.pop();
        temp[1] = 'A' + second;
        no_senators[second]--;
        if (no_senators[second] > 0)
            pq.push(second);
        temp[2] = '\0';
        evacuated = temp;
        plan.push_back(evacuated);
    }
}

int main()
{
    int t, ii;
    int i;
    int total;
    int n;
    ifstream f("evac.in");
    ofstream g("evac.out");
    f >> t;
    for (ii = 1; ii <= t; ii++)
    {
        f >> n;
        total = 0;
        for (i = 0; i < n; i++)
        {
            f >> no_senators[i];
            total += no_senators[i];
            if (no_senators[i] > 0)
                pq.push(i);
        }
        plan.clear();
        make_plan(total);
        g << "Case #" << ii << ": ";
        for (i = 0; i < plan.size(); i++)
            g << plan[i] << " ";
        g << "\n";
    }
    f.close();
    g.close();
    return 0;
}
