#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <algorithm>

void Evacuation(int N, int* P);
int MaxParty(int N, int* P);

int main()
{
    int T, N;
    std::cin >> T;

    for(int t = 0; t < T; t ++)
    {
        std::cin >> N;
        int P[N];
        for(int p = 0; p < N; p ++)
        {
            std::cin >> P[p];
        }
        std::cout << "Case #" << t + 1 << ": ";
        Evacuation(N, P);
    }
    return 0;
}

void Evacuation(int N, int* P)
{
    int sum = 0;
    for(int i = 0; i < N; i++)
    {
        sum += P[i];
    }

    while(sum > 0)
    {
        int max_index = MaxParty(N, P);
        std::cout << (char)('A'+max_index);
        P[max_index] --;
        sum --;

        max_index = MaxParty(N, P);
        if(2 * P[max_index] > sum)
        {
            std::cout << (char)(max_index + 'A');
            P[max_index] --;
            sum --;
        }

        std::cout << " ";
    }
    std::cout << std::endl;
}

int MaxParty(int N, int* P)
{
    int max_index = 0;
    for(int i = 0; i < N; i ++)
    {
        if(P[i] > P[max_index])
        {
            max_index = i;
        }
    }
    return max_index;
}
