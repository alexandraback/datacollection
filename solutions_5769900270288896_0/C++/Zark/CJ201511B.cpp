#include <cstdio>
#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>
#include <list>
#include <stack>
#include <algorithm>
#include <queue>
#include <map>
#include <cstdlib>
#include <set>
#include <string>
#include <cstring>
#include <memory>

#pragma comment(linker, "/STACK:104857600,104857600")

using namespace std;

#define FILE_IO

class Solver
{
public:
	void exe();
	
private:
	void input();
	void run();
	void output();
	int cal(int c[], int remain);
	
private:
	int caseNum, caseIndex;
	int r, c, n;
	int result;
};

void Solver::exe()
{
	scanf("%d", &caseNum);
	for(caseIndex = 1; caseIndex <= caseNum; ++caseIndex)
	{
		input();
		run();
		output();
	}
}

void Solver::input()
{
    scanf("%d%d%d", &r, &c, &n);
}

void Solver::run()
{
    if(r < c) swap(r, c);
    int x, y;
    x = 0; y = 0;
    int count[2][3];
    memset(count, 0, sizeof(count));
    if(c == 1)
    {
        x = r - r / 2;
        y = r / 2;
        if(r % 2 == 0)
        {
            count[0][0] = 1;
            count[1][0] = 1;
        }
        else
        {
            count[0][0] = 2;
        }
        
        count[0][1] = x - count[0][0];
        count[1][1] = y - count[1][0];
    }
    else
    {
        for(int i = 0; i < r; ++i)
        {
            if(i % 2 == 0)
            {
                x += c - c / 2;
                y += c / 2;
            }
            else
            {
                x += c / 2;
                y += c - c / 2;
            }
            
            if(i == 0)
            {
                if(c % 2 == 0)
                {
                    ++count[0][1];
                    ++count[1][1];
                }
                else
                {
                    ++count[0][1];
                    ++count[0][1];
                }
                
                count[0][2] += c - c / 2;
                count[1][2] += c / 2;
            }
            else if(i == r - 1)
            {
                if(c % 2 == 0)
                {
                    ++count[0][1];
                    ++count[1][1];
                }
                else if(i % 2 == 0)
                {
                    ++count[0][1];
                    ++count[0][1];
                }
                else
                {
                    ++count[1][1];
                    ++count[1][1];
                }
                
                if(i % 2 == 0)
                {
                    count[0][2] += c - c / 2;
                    count[1][2] += c / 2;
                }
                else
                {
                    count[0][2] += c / 2;
                    count[1][2] += c - c / 2;
                }
            }
            else
            {
                if(c % 2 == 0)
                {
                    ++count[0][2];
                    ++count[1][2];
                }
                else if(i % 2 == 0)
                {
                    ++count[0][2];
                    ++count[0][2];
                }
                else
                {
                    ++count[1][2];
                    ++count[1][2];
                }
            }
        }
        
        count[0][2] -= count[0][1];
        count[1][2] -= count[1][1];
    }
    
    if(max(x, y) >= n)
    {
        result = 0;
    }
    else
    {
        result = min(cal(count[0], n - y), cal(count[1], n - x));
    }
}

int Solver::cal(int c[], int remain)
{
    int ret = 0;
    if(remain <= c[0])
    {
        ret += remain * 1;
        remain = 0;
    }
    else
    {
        ret += c[0] * 1;
        remain -= c[0];
    }
    
    if(remain <= c[1])
    {
        ret += remain * 2;
        remain = 0;
    }
    else
    {
        ret += c[1] * 2;
        remain -= c[1];
    }
    
    if(remain <= c[2])
    {
        ret += remain * 3;
        remain = 0;
    }
    else
    {
        ret += c[2] * 3;
        remain -= c[2];
    }
    
    ret += remain * 4;
    return ret;
}

void Solver::output()
{
    cout << "Case #" << caseIndex << ": " << result << endl;
}

Solver instance;
int main()
{
#ifdef FILE_IO
	freopen("C:\\Users\\Zee\\Desktop\\B.in", "r", stdin);
	freopen("C:\\Users\\Zee\\Desktop\\B.out", "w", stdout);
#endif
	
	instance.exe();
	return 0;
}

