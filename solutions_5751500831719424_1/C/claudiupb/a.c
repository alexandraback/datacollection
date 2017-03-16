#include <stdio.h>
#include <strings.h>
#ifdef D
#define print_line() printf("%d\n",__LINE__)
#define print_int(a) printf("%d\n",a)
#define print_float(a) printf("%.7f\n",a)
#define print_char(a) printf("%c\n",a)
#define print_string(a) printf("%s\n",a)
#else
#define print_line()
#define print_int(a)
#define print_float(a)
#define print_char(a)
#define print_string(a)
#endif
char counts[100][100];
char strings[100][100];
char trimmed_string[100];
char min[100], max[100];
int impossible;

void trim_string(int );
int calculate_ops(int, int, int);

int main()
{
	int t,T,N;
	int i,j,k,size_trim;
	unsigned int total_ops, operations;
	scanf("%d\n",&T);
	for (t=1;t<=T;t++)
	{
		impossible = 0;
		memset(max,0, sizeof(max));
		memset(min,101, sizeof(min));
		scanf("%d\n",&N);
		printf("Case #%d: ",t);
		print_int(N);
		for(i=0;i<N; i++)
		{
			gets(strings[i]);
			print_string(strings[i]);
			trim_string(i);
			print_string(trimmed_string);
			print_string("AAAA");
			print_int(impossible);

		}
		if (impossible)
		{
			printf("Fegla Won\n");
			continue;
		}
		size_trim = strlen(trimmed_string);
		total_ops=0;
		for(j=0;j < size_trim; j++)
		{
			operations = calculate_ops(j,max[j],N);
			for(k= min[j]; k < max[j]; k++)
			{
				int o;
				o = calculate_ops(j,k,N);
				if (o < operations)
					operations = o;
			}
			//printf("operations for %d = %d (min=%d, max=%d)\n",j,operations,min[j],max[j]);
			total_ops += operations;
		}
		printf("%u\n",total_ops);
	}
	
	return 0;
}
void trim_string(int i)
{
	int ts_index=0,k=0,count;
	
	if (impossible)
		return;

	while (strings[i][k]!='\0')
	{
		count=1;
		if (!i)
			trimmed_string[ts_index] = strings[i][k];
		else if (trimmed_string[ts_index] != strings[i][k])
		{
			impossible=1;
			return;
		}
			
		while (strings[i][k+1]!='\0' && strings[i][k] == strings[i][k+1])
		{
			count++;
			k++;
		}
		counts[i][ts_index]=count;
		if (count < min[ts_index])
			min[ts_index] = count;
		if (count > max[ts_index])
			max[ts_index] = count;
		
		ts_index++;
		k++;
	}
	if (!i)
		trimmed_string[ts_index]='\0';
	else if (trimmed_string[ts_index]!='\0')
	{
		impossible=1;
		return;
	}
	
	counts[i][ts_index]='\0';
}

int calculate_ops(int j,int k, int N)
{
	int sum=0;
	int i;
	//printf("k=%d\n",k);
	for (i=0; i<N; i++)
	{
		//printf("counts=%d ",counts[i][j]);
		if (counts[i][j] > k)
			sum += counts[i][j] - k;
		else
			sum += k - counts[i][j];
	}
	
	//printf(" sum =%d\n",sum);
	return sum;
}

	