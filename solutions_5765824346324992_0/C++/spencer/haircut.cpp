#include <cassert>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

long long head_of_line(const long long T, const vector<long long>& speed)
{
    long long served = 0;
    for (int i = 0; i < (int)speed.size(); i++)
    {
        if (T % speed[i] == 0) served += T / speed[i];
        else served += T / speed[i] + 1;
    }
    return served + 1;
}

int solve()
{
    int B; long long N; cin >> B >> N;
    vector<long long> speed;
    speed.resize(B);
    for (int i = 0; i < B; i++)
        cin >> speed[i];

    long long mini = 1, maxi = 1e16;
    while (mini < maxi)
    {
        long long guess = (mini + maxi) / 2;
        if (head_of_line(guess, speed) > N) maxi = guess;
        else mini = guess + 1;
    }

    const long long time = mini - 1;
    long long place = N - head_of_line(time, speed) + 1;
    assert(place >= 1);
    for (int i = 0; i < B; i++)
    {
        if (time % speed[i] == 0) place--;
        if (place == 0) return i + 1;
    }

    assert(false);
    return -1;
}

int main()
{
    int T; cin >> T;
    for (int t = 1; t <= T; t++)
        printf("Case #%d: %d\n", t, solve());
    return 0;
}
