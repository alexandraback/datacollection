#include <stdio.h>
#include <vector>

int recScore(int R, int C, int x, int y, bool *tab, int N, int currentScore)
{
    if(N == 0)
	return currentScore;
    int id = x+y*R;
    int neighbor = 0;
    if(x > 0 && tab[id-1])
	neighbor++;
    if(y > 0 && tab[id-R])
	neighbor++;
    tab[id] = true;
    int nextX, nextY;
    if(x < R-1)
    {
	nextX = x+1;
	nextY = y;
    }
    else
    {
	nextX = 0;
	nextY = y+1;
    }
    int score1 = recScore(R, C, nextX, nextY, tab, N-1, currentScore+neighbor);
    tab[id] = false;
    if(N == R*C - id)
	return score1;
    int score2 = recScore(R, C, nextX, nextY, tab, N, currentScore);
    return std::min(score1, score2);
}

int score(int R, int C, int N)
{
    bool *tab = new bool[R*C];
    for(int i = 0; i < R*C; i++)
	tab[i] = false;
    return recScore(R, C, 0, 0, tab, N, 0);
}

int main()
{
    int num;
    scanf("%d", &num);
    for(int i = 0; i < num; i++)
    {
	int R,C, N;
        scanf("%d %d %d", &R, &C, &N);
        printf("Case #%d: %d\n", i+1, score(R, C, N));
    }
    return 0;
}
