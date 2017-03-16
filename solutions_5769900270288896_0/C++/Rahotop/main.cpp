#include <iostream>
#include <fstream>

using namespace std;

int howTouch(bool **T, int r, int c)
{
    int res(0);
    for(int i(0); i < r; i++)
    {
        for(int j(0); j < c; j++)
        {
            if(T[i][j])
            {
                if(j < (c-1))
                    if(T[i][j+1])
                        res++;
                if(i != (r-1))
                {
                    if(T[i+1][j])
                        res++;
                }
            }
        }
    }

    return res;
}

int nbPersons(bool **T, int r, int c)
{
    int res(0);
    for(int i(0); i < r; i++)
        for(int j(0); j < c; j++)
            if(T[i][j])
                res++;
    return res;
}

void fillOneMore(bool **T, int r, int c)
{
    bool filled(false);
    if(!T[0][0] && !filled)
    {
        T[0][0] = true;
        filled = true;
    }
    if(!T[r-1][c-1] && !filled)
    {
        T[r-1][c-1] = true;
        filled = true;
    }
    if(!T[0][c-1] && !filled)
    {
        T[0][c-1] = true;
        filled = true;
    }
    if(!T[r-1][0] && !filled)
    {
        T[r-1][0] = true;
        filled = true;
    }
    for(int i(0); i < r && !filled; i++)
    {
        if(!T[i][0])
        {
            T[i][0] = true;
            filled = true;
        }
    }
    for(int i(0); i < c && !filled; i++)
    {
        if(!T[0][i])
        {
            T[0][i] = true;
            filled = true;
        }
    }
    for(int i(0); i < r && !filled; i++)
    {
        if(!T[i][c-1])
        {
            T[i][c-1] = true;
            filled = true;
        }
    }
    for(int i(0); i < c && !filled; i++)
    {
        if(!T[r-1][i])
        {
            T[r-1][i] = true;
            filled = true;
        }
    }
    for(int i(1); i < (r-1) && !filled; i++)
    {
        for(int j(1); j < (c-1) && !filled; j++)
        {
            if(!T[i][j])
            {
                T[i][j] = true;
                filled = true;
            }
        }
    }
}

void fillRest(bool **T, int r, int c, int n)
{
    for(int i(0); i < n; i++)
        fillOneMore(T, r, c);
}

int main()
{
    ifstream input("input.txt", ios::in);
    ofstream output("output.txt", ios::out | ios::trunc);

    if(input && output)
    {
        int nbTest;

        input >> nbTest;

        for(int i(1); i <= nbTest; i++)
        {
            int r, c, n;

            input >> r;
            input >> c;
            input >> n;

            bool **T = new bool*[r];
            for(int j(0); j < r; j++)
            {
                T[j] = new bool[c];
                for(int k(0); k < c; k++)
                {
                    T[j][k] = (j%2 != k%2);
                }
            }

            bool **T2 = new bool*[r];
            for(int j(0); j < r; j++)
            {
                T2[j] = new bool[c];
                for(int k(0); k < c; k++)
                {
                    T2[j][k] = (j%2 == k%2);
                }
            }


            if(nbPersons(T2, r, c) >= n)
                output << "Case #" << i << ": " << 0 << endl;
            else
            {
                fillRest(T, r, c, n - nbPersons(T, r, c));
                fillRest(T2, r, c, n - nbPersons(T2, r, c));

                int mini = howTouch(T, r, c);
                if(mini > howTouch(T2, r, c))
                    mini = howTouch(T2, r, c);
                output << "Case #" << i << ": " << mini << endl;
            }
        }
    }
    return 0;
}
