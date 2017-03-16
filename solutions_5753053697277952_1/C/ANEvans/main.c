#include <stdio.h>
#include <stdlib.h>

typedef struct Pair
{
	char party;
	int count;
} Pair;

// sort from high to low
int sorter(const void* one, const void* two)
{
	Pair* a = (Pair*)one;
	Pair* b = (Pair*)two;
	
	return b->count - a->count;
}

int main(int argc, char* argv[])
{
	int ndata;
	scanf("%d", &ndata);
	
	for (int asdf = 0; asdf < ndata; asdf++)
	{
		int nparties;
		scanf("%d\n", &nparties);
		
		Pair* counts = (Pair*)malloc(sizeof(Pair) * nparties);
		int sum = 0;
		
		for (int i = 0; i < nparties; i++)
		{
			scanf("%d", &counts[i].count);
			counts[i].party = 'A' + i;
			sum += counts[i].count;
		}
		
		// solve the problem
		printf("Case #%d:", asdf+1);
		qsort(counts, nparties, sizeof(Pair), sorter);
		
		if (sum % 2 == 1)
		{
			counts[0].count--;
			printf(" %c", counts[0].party);
		}
		
		qsort(counts, nparties, sizeof(Pair), sorter);
		
		while (counts[0].count != 0)
		{
			if (counts[0].count == 0)
			{
				break;
			}
			
			int one = (counts[0].count == 0 ? -1000 : counts[0].count);
			int two = (counts[1].count == 0 ? -1000 : counts[1].count);
			
			if (one-1 >= two)
			{
				printf(" %c%c", counts[0].party, counts[0].party);
				counts[0].count -= 2;
			}
			else
			{
				printf(" %c%c", counts[0].party, counts[1].party);
				counts[0].count--;
				counts[1].count--;
			}
			
			qsort(counts, nparties, sizeof(Pair), sorter);
		}
		
		printf("\n");
	}
	
	return 0;
}




















