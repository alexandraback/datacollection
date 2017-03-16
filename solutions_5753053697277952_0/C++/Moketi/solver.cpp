
#include <stdio.h>


struct Problem
{
	int num_pt;
	int member[26];
	int total_member;
	void Load()
	{
		scanf("%d", &num_pt);
		total_member = 0;
		for (int i = 0; i < num_pt; i++)
		{
			scanf("%d", &member[i]);
			total_member += member[i];
		}
	}
};

class Solver
{
public:
	void SolveAndAnswer(Problem p)
	{
		while (p.total_member>0)
		{
			//search max
			int i_top ,i_2nd;
			if (p.member[0] >= p.member[1]){
				i_top = 0; i_2nd = 1;
			}
			else{
				i_top = 1; i_2nd = 0;
			}

			for (int i = 2; i < p.num_pt; i++)
			{
				if (p.member[i] > p.member[i_2nd])
				{
					if (p.member[i] > p.member[i_top])
					{
						i_2nd = i_top; i_top = i;
					}
					else
						i_2nd = i;
				}
				// check
				if (p.member[i] > p.total_member / 2)
				{
					printf("ERROR!\n");
					return;
				}
			}
			if (p.total_member == 2)
			{
				printf("%c%c\n", 'A' + i_top, 'A' + i_2nd);
				p.member[i_top]--;
				p.member[i_2nd]--;
				p.total_member -= 2;
			}
			else if (p.total_member == 3)
			{
				printf("%c ", 'A' + i_top);
				p.member[i_top]--;
				p.total_member -= 1;
			}
			else 
			{
				if (p.member[i_top] > p.member[i_2nd] + 1)
				{
					printf("%c%c ", 'A' + i_top, 'A' + i_top);
					p.member[i_top]-=2;
					p.total_member -= 2;
				}
				else
				{
					printf("%c%c ", 'A' + i_top, 'A' + i_2nd);
					p.member[i_top]--;
					p.member[i_2nd]--;
					p.total_member -= 2;
				}
			}
		}
	}
};


int main(int argc, char* argv[])
{

	int num;
	scanf("%d", &num);

	for (int i = 1; i < num + 1; i++)
	{
		Solver solver;
		Problem p;
		p.Load();
		printf("Case #%d: ", i);
		solver.SolveAndAnswer(p);
	}

	return 0;
}

