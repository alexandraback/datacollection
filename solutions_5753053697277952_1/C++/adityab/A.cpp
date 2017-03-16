#include <iostream>
#include <cmath>

using namespace std;

int max_index(int* P, int length)
{
    int max_elem = 0;
    int max_idx = 0;
    for(int i=0; i<length; i++)
    {
        if(P[i] > max_elem)
        {
            max_elem = P[i];
            max_idx = i;
        }
    }
    return max_idx;
}

void print_letter(int ascii)
{
    char letter = ascii + 65;
    cout << letter;
}

bool check(int* P, int N, int total)
{
    int half = total/2;
    for(int i=0; i<N; i++)
    {
        if(P[i] > half)
            return false;
    }
    return true;
}

int main()
{
    //Solve
    int T, N;
    cin >> T;
    for(int i=0; i<T; i++)
    {
        //Solve
        cin >> N;
        int P[N];
        int total = 0;
        for(int j=0; j<N; j++)
        {
            cin >> P[j];
            total += P[j];
        }
        cout << "Case #" << i+1 << ": ";
        while(total != 2)
        {
            int k = max_index(P,N);
            print_letter(k);
            total--;
            P[k]--;
            if(check(P, N, total))
                cout << " ";
        }
        for(int j=0; j<N; j++)
        {
            if(P[j]==2)
            {
                print_letter(j);
                print_letter(j);
            }
            if(P[j]==1)
            {
                print_letter(j);
            }

        }

        cout << endl;
    }
}

