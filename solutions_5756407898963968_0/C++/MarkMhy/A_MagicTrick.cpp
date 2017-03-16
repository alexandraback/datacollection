#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream.h>


char* getNext(char** src, int sp)
{
        char* s = strchr(*src, sp);
  char* sorg = *src;

  if (NULL == s)
  {
    int n = strlen(*src);
    if (n > 1 && ((0x0a == sorg[n-1]) || (0x0d == sorg[n-1])))
    {
      sorg[n-1] = 0;
    }
    if (n > 2 && ((0x0a == sorg[n-2]) || (0x0d == sorg[n-2])))
    {
      sorg[n-2] = 0;
    }
    return sorg;
  }

        *s = 0;
  *src = s+1;
  return sorg;
}

int getNextNum(char** src, int sp)
{
  char* s = getNext(src, sp);
  if (NULL == s)
  {
    return 0;
  }
  else
  {
    return atoi(s);
  }
}

int main (void)
{
	const int size = 4;
  int t = 0;
	cin >> t;

  for (int i = 0; i < t; i++)
  {
	  int r1 = 0;
	  int r2 = 0;
		cin >> r1;

		int tmpIn[size] = {0};
		int n1[size] = {0};
		int n2[size] = {0};

    for (int j = 0; j < size; j++)
    {
	    for (int k = 0; k < size; k++)
	    {
	    	cin >> tmpIn[k];
	    	if (j == (r1-1))
		    {
		    	n1[k] = tmpIn[k];	
		    }
	    }
  	}
  	
		cin >> r2;
    for (int j = 0; j < size; j++)
    {
	    for (int k = 0; k < size; k++)
	    {
	    	cin >> tmpIn[k];
	    	if (j == (r2-1))
		    {
		    	n2[k] = tmpIn[k];	
		    }
	    }
  	}

		int y = 0;
		int count = 0;
		for (int j = 0; j < size; j++)
		{
			for (int k = 0; k < size; k++)
			{
				if (n2[j] == n1[k])
				{
					if (count > 0)
					{
						count++;
						break;	
					}
					
					y = n2[j];
					count++;
				}
			}
			
			if (count > 1)
			{
				break;
			}
		}

		if (0 == count)
		{
			printf("Case #%d: Volunteer cheated!\n", i+1);	
		}
		else if (1 == count)
		{
			printf("Case #%d: %d\n", i+1, y);	
		}
		else
		{
			printf("Case #%d: Bad magician!\n", i+1);
		}
	}
  
  return 0;
}
