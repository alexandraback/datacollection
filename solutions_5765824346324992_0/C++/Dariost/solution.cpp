#include <bits/stdc++.h>

using namespace std;

typedef long long int lli;

template<typename T>
ostream& operator << (ostream& o, vector<T>& v)
{
    o << "[";
    for(size_t i = 0; i < v.size(); i++)
    {
        o << v[i];
        if(i != v.size() - 1)
            o << ", ";
    }
    o << "]";
    return o;
}

int main(int argc, char* argv[])
{
    (void)argc; (void)argv;
    FILE* useless;
    (void)useless;
    useless=freopen("B-small-attempt1.in", "r", stdin);
    useless=freopen("B-small-attempt1.out", "w", stdout);
    int n_casi;
    cin >> n_casi;
    vector<vector<lli> > barbers;
    vector<lli> n_position;
    vector<lli> solutions;
    solutions.resize(n_casi+1);
    n_position.resize(n_casi+1);
    barbers.resize(n_casi+1);
    for(int caso = 1; caso <= n_casi; caso++)
    {
        int tmp;
        cin >> tmp;
        cin >> n_position[caso];
        for(int i = 0; i < tmp; i++)
        {
            lli tmp2;
            cin >> tmp2;
            barbers[caso].push_back(tmp2);
        }
    }
    //#pragma omp parallel for schedule(dynamic)
    for(int caso = 1; caso <= n_casi; caso++)
    {
        lli time_passed = 0;
        priority_queue<pair<int, lli>, vector<pair<int, lli> >, greater<pair<int, lli> > > less_barber;
        priority_queue<pair<lli, int>, vector<pair<lli, int> >, greater<pair<lli, int> > > time_schedule;
        vector<lli> places;
        for(size_t i = 0; i < barbers[caso].size(); i++)
        {
            less_barber.push(make_pair(i, barbers[caso][i]));
        }
        int last_barber = less_barber.top().second;
        for(int costumer = 1; costumer <= n_position[caso]; costumer++)
        {
            if(!less_barber.empty())
            {
                last_barber = less_barber.top().first;
                places.push_back(last_barber);
                time_schedule.push(make_pair(time_passed + barbers[caso][less_barber.top().first], less_barber.top().first));
                less_barber.pop();
            }
            else
            {
                assert(!time_schedule.empty());
                lli min_time = time_schedule.top().first;
                while(!time_schedule.empty() && time_schedule.top().first == min_time)
                {
                    less_barber.push(make_pair(time_schedule.top().second, barbers[caso][time_schedule.top().second]));
                    time_schedule.pop();
                }
                time_passed = min_time;
                last_barber = less_barber.top().first;
                if(time_schedule.empty())
                {
                    int to_search = (n_position[caso]-1) % places.size();
                    last_barber = places[to_search];
                    break;
                }
                places.push_back(last_barber);
                time_schedule.push(make_pair(time_passed + barbers[caso][less_barber.top().first], less_barber.top().first));
                less_barber.pop();
            }
        }
        solutions[caso] = last_barber+1;
        cerr << "Case #" << caso << ": " << solutions[caso] << endl;
    }
    for(int caso = 1; caso <= n_casi; caso++)
    {
        cout << "Case #" << caso << ": " << solutions[caso] << endl;
    }
    return EXIT_SUCCESS;
}
