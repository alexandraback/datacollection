#include <iostream>

int  findMinimumDev(int* countChar, int N)
{

	int min = INT_MAX; 
	int max = INT_MIN;

	for(int i =  0; i < N; i++)
	{
		if(min > countChar[i])
			min = countChar[i];
		if(max < countChar[i])
			max = countChar[i];
	}

	int minit = INT_MAX;
	for(int j = min; j <= max; j++)
	{
		int sum = 0;
		for(int i =  0; i < N; i++)
		{
			sum += (abs(countChar[i] - j));
		}
		
		if(sum < minit)
		{
			minit = sum;
		}

	}
	return minit;
}

int main()
{
	char filename1[100] = "C:\\Users\\RezaulAkram\\Desktop\\A-large.in";
	char filename2[100] = "C:\\Users\\RezaulAkram\\Desktop\\op6.txt";
	FILE* file = fopen(filename1,"r");
	FILE* file2 = fopen(filename2,"w");
	int T;

	fscanf(file,"%d\n", &T);

	for(int i =0 ; i < T; i++)
	{
		int N = -1;
		char strings[100][101];
		fscanf(file,"%d\n", &N);

		for(int j = 0; j < N; j++)
		{
			fscanf(file, "%s", strings[j]);
		}

		int countChar[100];
		int character[100] = {0}; 
		int position[100] = {0};

		int done = 0, lastchar = 0;
		int iter = 0;
		int result;
		while(done != 1)
		{
			result = 0;
		
			for(int j = 0; j < N; j++)
			{
				countChar[j] =  1;
				int stringlen = strlen(strings[j]);

				if(position[j] >= stringlen)
				{
					character[j]= 0;
					lastchar = 1;
				}
				else
					character[j] = strings[j][position[j]];

				if(j != 0 && character[j] != character[0])
				{
					result = -1;
					break;
				}

				int k = position[j];
			
				while(( k < (stringlen - 1)) && (strings[j][k] == strings[j][k+1]))
				{
					k++;
					countChar[j]++;
				}

				position[j] = k+1;
			}


			if(result == -1)
				break;

			iter += findMinimumDev(countChar, N);

			if(lastchar == 1)
				done = 1;
		}
		
		
		if(result == -1)
			fprintf(file2,"Case #%d: Fegla Won\n", (i+1));
		else
			fprintf(file2,"Case #%d: %d\n", (i+1), iter);
	}
	fclose(file);
	fclose(file2);
}