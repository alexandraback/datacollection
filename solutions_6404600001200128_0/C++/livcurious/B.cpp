#include <stdio.h>
char fast_char_var;
#define	fast_unsigned_dtype	unsigned long long
fast_unsigned_dtype fast_unsigned_var;
fast_unsigned_dtype fast_unsigned()
{
	fast_char_var=getchar_unlocked();
	while(fast_char_var<48||fast_char_var>57)
		fast_char_var=getchar_unlocked();
	fast_unsigned_var=0;
	while(fast_char_var>47&&fast_char_var<58)
	{
		fast_unsigned_var=(fast_unsigned_var<<1)+(fast_unsigned_var<<3)+fast_char_var-48;
		fast_char_var=getchar_unlocked();
	}
	return fast_unsigned_var;
}
int main()
{
	static unsigned long long test_cases,test_case,ans1,ans2,n,a[1003],max;
	register unsigned long long loop_variable;
	test_cases=fast_unsigned();
	for(test_case=1;test_case<=test_cases;test_case++)
	{
		ans1=0;max=0;ans2=0;
		n=fast_unsigned();
		a[0]=fast_unsigned();
		for(loop_variable=1;loop_variable<n;loop_variable++)
		{
			a[loop_variable]=fast_unsigned();
			if(a[loop_variable-1]>a[loop_variable])
			{
				ans1+=a[loop_variable-1]-a[loop_variable];
				if((a[loop_variable-1]-a[loop_variable])>max)
					max=a[loop_variable-1]-a[loop_variable];
			}
		}
		for(loop_variable=0;loop_variable<(n-1);loop_variable++)
			ans2+=a[loop_variable]>max?max:a[loop_variable];
		printf("Case #%llu: %llu %llu\n",test_case,ans1,ans2);		
	}
	return 0;
}