/*
 * MagicTrick.c
 *
 *  Created on: 2014. 4. 12.
 *      Author: Administrator
 */



#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

struct reader
{
	char buf[512];
	int idx;
	int size;
};

typedef struct reader* READER;


READER reader_init(void)
{
	READER rdr = calloc(1, sizeof(struct reader));

	return rdr;
}


int reader_refresh(READER rdr)
{
	rdr->size = fread(rdr->buf, 1, 512, stdin);
	if(rdr->size<0)
	{
		fprintf(stderr, "failed to fread. %s\n", strerror(errno));
		return -1;
	}
	rdr->idx = 0;
	return rdr->size;
}


char reader_next(READER rdr)
{
	if(rdr->size <= rdr->idx)
	{
		reader_refresh(rdr);
	}

	return rdr->buf[rdr->idx++];
}


char* nextStr(READER rdr)
{
	int idx = 0;
	int size = 32;
	char* buf = NULL;

	while(1)
	{
		char ch = reader_next(rdr);
		if(isspace(ch))
		{
			if(buf==NULL) continue;
			else return buf;
		}

		if(buf==NULL) buf = malloc(size);
		if(idx==size)
		{
			size *= 2;
			buf = realloc(buf, size);
		}

		buf[idx++] = ch;
	}

	return NULL;
}


int nextInt(READER rdr)
{
	int started = 0;
	int res = 0;

	while(1)
	{
		char ch = reader_next(rdr);
		if(isspace(ch))
		{
			if(!started) continue;
			else return res;
		}

		if(isdigit(ch))
		{
			started = 1;
			res *= 10;
			res += ch - '0';
		}

	}

	return -1;
}


void solve(READER rdr, int n)
{
	int b[17] = {0, };

	int idx = nextInt(rdr);
	int row;

	for(row=1; row<=4; row++)
	{
		if(idx==row)
		{
			b[nextInt(rdr)] = 1;
			b[nextInt(rdr)] = 1;
			b[nextInt(rdr)] = 1;
			b[nextInt(rdr)] = 1;
		}
		else
		{
			nextInt(rdr);
			nextInt(rdr);
			nextInt(rdr);
			nextInt(rdr);
		}
	}

	int ans = 0;
	idx = nextInt(rdr);
	for(row=1; row<=4; row++)
	{
		if(idx==row)
		{
			int col;
			for(col=0; col<4; col++)
			{
				int card = nextInt(rdr);
				if(b[card])
				{
					if(ans==0)
					{
						ans = card;
					}
					else
					{
						ans = -1;
					}
				}
			}
		}
		else
		{
			nextInt(rdr);
			nextInt(rdr);
			nextInt(rdr);
			nextInt(rdr);
		}
	}

	if(ans==0)
		fprintf(stdout, "Case #%d: Volunteer cheated!\n", n);
	else if(ans==-1)
		fprintf(stdout, "Case #%d: Bad magician!\n", n);
	else
		fprintf(stdout, "Case #%d: %d\n", n, ans);

	return;
}


int main(int argc, char** argv)
{
	READER rdr = reader_init();

	int n = nextInt(rdr);
	fprintf(stderr, "%d cases\n", n);
	int i;
	for(i=1; i<=n; i++)
	{
		solve(rdr, i);
	}

	return 0;
}
