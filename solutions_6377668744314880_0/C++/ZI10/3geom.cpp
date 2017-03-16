#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

struct pt
{
    long double x;
    long double y;
    pt()
    {
        x = 0;
        y = 0;
    }
};

pt operator+(struct pt a, struct pt b)
{
    pt c;
    c.x = a.x + b.x;
    c.y = a.y + b.y;
    return c;
}

pt operator-(struct pt a, struct pt b)
{
    pt c;
    c.x = a.x - b.x;
    c.y = a.y - b.y;
    return c;
}

bool func(struct pt a, struct pt b, struct pt c, struct pt p)
{
    pt v1 = a - b;
    pt v2 = a - c;
    pt v11 = c - b;
    pt v12 = p - b;
    pt v21 = b - c;
    pt v22 = p - c;
    if (((v12.x * v1.y - v12.y * v1.x) * (v11.x * v1.y - v11.y * v1.x)) < 0)
    {
        return 1;
    }
    if (((v22.x * v2.y - v22.y * v2.x) * (v21.x * v2.y - v21.y * v2.x)) < 0)
    {
        return 1;
    }
    return 0;
}


bool fu1(struct pt a, struct pt b, struct pt c, struct pt p)
{
    pt v1 = c - b;
    pt v12 = p - b;
    pt v11 = a - b;
    if (((v12.x * v1.y - v12.y * v1.x) * (v11.x * v1.y - v11.y * v1.x)) < 0)
    {
        return 1;
    }
    return 0;
}

bool fu2(struct pt a, struct pt b, struct pt c, struct pt p)
{
    pt v1 = c - b;
    pt v12 = p - b;
    pt v11 = a - b;
    if (((v12.x * v1.y - v12.y * v1.x) * (v11.x * v1.y - v11.y * v1.x)) > 0)
    {
        return 1;
    }
    return 0;
}

int main()
{
    freopen("input.txt", "r",stdin);
    freopen("output.txt", "w",stdout);
    int T;
    cin >> T;
    for (int z = 0; z < T; ++z)
    {
        int N;
        cin >> N;
        vector <pt> A(N);
        for (int i = 0; i < N; ++i)
        {
            cin >> A[i].x >> A[i].y;
        }
        cout << "Case #" << z + 1 << ": " << endl;
        for (int i = 0; i < N; ++i)
        {
            int Ans = N - 3;
            if (Ans < 0)
            {
                Ans = 0;
            }
            for (int j = 0; j < N; ++j)
            {
                for (int k = j + 1; k < N; ++k)
                {
                    if (i != j && i != k)
                    {
                        pt v1 = A[i] - A[j];
                        pt v2 = A[i] - A[k];
                        int cut = 0;
                        if ((v1.x * v2.y - v1.y * v2.x) == 0)
                        {
                            pt Pr = A[i];
                            if (A[j].x == A[k].x)
                            {
                                Pr.x += 1;
                            }
                            else
                            {
                                Pr.y += 1;
                            }
                            for (int z = 0; z < N; ++z)
                            {
                                if (z != i && z != j && z != k)
                                {
                                    //cout << i << " " << j << " " << k << " " << z << endl;
                                    if (fu1(Pr, A[j], A[k], A[z]))
                                    {
                                        ++cut;
                                    }
                                }
                            }
                            Ans = min(Ans, cut);
                            cut = 0;
                            for (int z = 0; z < N; ++z)
                            {
                                if (z != i && z != j && z != k)
                                {
                                    //cout << i << " " << j << " " << k << " " << z << endl;
                                    if (fu2(Pr, A[j], A[k], A[z]))
                                    {
                                        ++cut;
                                    }
                                }
                            }
                            Ans = min(Ans, cut);
                            /* if (i == 4)
                                   {


                                    cout << i << "sd " << j << " " << k << "d " << Ans << endl;

                            }*/
                        }
                        else
                        {
                            for (int z = 0; z < N; ++z)
                            {
                                if (z != i && z != j && z != k)
                                {
                                   if (i == 4)
                                   {


                                 //   cout << i << " " << j << " " << k << " " << z << endl;

                            }
                                    if (func(A[i], A[j], A[k], A[z]))
                                    {
                                        ++cut;
                                    }
                                }
                            }
                            if (i == 4)
                            {


                            //cout << cut << endl;
                            }
                        }
                        Ans = min(Ans, cut);
                    }
                }
            }
            cout << Ans << endl;
        }
    }
    return 0;
}
