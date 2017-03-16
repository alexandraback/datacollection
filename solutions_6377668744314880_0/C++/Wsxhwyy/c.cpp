#include <iostream>
#include <algorithm>
#include <bitset>

using namespace std;

const int MaxN = 100;
struct TPoint
{
    long long x, y;
    int tag;
};
bool cmp(const TPoint& A, const TPoint& B)
{
    if (A.x != B.x)
        return A.x < B.x;
    return A.y < B.y;
}
int N;
TPoint P[MaxN], Q[MaxN];
int Stack[MaxN], Top, Limit;
int CrossProduct(TPoint A, TPoint B, TPoint C)
{
    return (B.x - A.x) * (C.y - A.y) - (B.y - A.y) * (C.x - A.x);
}
void Update(int i)
{
    while (Top > Limit && CrossProduct(P[Stack[Top - 1]], P[Stack[Top]], P[i]) < 0)
    {
	Stack[Top] = Stack[Top + 1];
	Top --;
    }
    Stack[++ Top] = i;
}
void Graham_Scan()
{
    sort(P, P + N, cmp);
    Top = 0;
    Limit = 1;
    memset(Stack, 0, sizeof(Stack));
    for (int i = 0; i < N; i ++)
        Update(i);
    Limit = Top;
    for (int i = N - 2; i >= 0; i --)
        Update(i);
    Top --;
}

int res[100];
int main()
{
    int T;
    cin >> T;
    for (int ca = 1; ca <= T; ca++)
    {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
	    cin >> Q[i].x >> Q[i].y;
	    Q[i].tag = i;
	    Q[i].x = Q[i].x + 1000001;
	    Q[i].y = Q[i].y + 1000001;
	}
	memcpy(P, Q, sizeof(P));
	memset(res, 0, sizeof res);
	for (int i = 0; i < n; i++)
	    res[i] = n;
	N = n;
	for (int mask = (1 << N) - 1; mask >= (1 << N) - 1; mask--)
	{
	    memset(P, 0, sizeof(P));
	    int rem = 0;
	    for (int i = 0; i < n; i++)
		if (mask & (1 << i))
		{
		    P[rem] = Q[i];
		    rem++;
		}
	    N = rem;
	    Graham_Scan();
	    for (int i = 1; i <= Top; i++)
	    {
		int ans = n - rem;
		if (res[P[Stack[i]].tag] > ans)
		    res[P[Stack[i]].tag] = ans;
	    }
	}
	cout << "Case #" << ca << ":" << endl;
	for (int i = 0; i < n; i++)
	    cout << res[i] << endl;
    }
}
