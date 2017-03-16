#include <stdio.h>
#include <algorithm>
using namespace std;
#define binary_gcd_dtype unsigned long long
long long binary_gcd_shift;
binary_gcd_dtype t;
binary_gcd_dtype binary_gcd_loop(binary_gcd_dtype u, binary_gcd_dtype v)
{
	if(!u)
		return v;
	if(!v)
		return u;
	for(binary_gcd_shift=0;!((u|v)&1);++binary_gcd_shift)
	{
		u>>=1;
		v>>=1;
	}
	while(!(u&1))
		u>>=1;
	do
	{
		while((v&1)==0)
			v>>=1;
		if(u>v)
		{
			t=v;
			v=u;
			u=t;
		}
		v=v-u;
	}while(v);
	return u<<binary_gcd_shift;
}

#define	merge_sort_dtype	unsigned long long
#define	merge_sort_maxsize	100005

unsigned long long merge_sort_i,merge_sort_j,merge_sort_k,merge_sort_halfsize;
merge_sort_dtype merge_sort_array[merge_sort_maxsize];

void merge_sort_recursive(merge_sort_dtype *array,unsigned long long size)
{
	if(size==1)
		return;
	merge_sort_recursive(array,size>>1);
	merge_sort_recursive(array+(size>>1),size-(size>>1));
	merge_sort_halfsize=(size>>1);
	for(merge_sort_i=0,merge_sort_j=merge_sort_halfsize,merge_sort_k=0;merge_sort_i<merge_sort_halfsize&&merge_sort_j<size;)
	{
		if(array[merge_sort_j]<array[merge_sort_i])
			merge_sort_array[merge_sort_k++]=array[merge_sort_j++];
		else
			merge_sort_array[merge_sort_k++]=array[merge_sort_i++];
	}
	while(merge_sort_i<merge_sort_halfsize)
		merge_sort_array[merge_sort_k++]=array[merge_sort_i++];
	for(merge_sort_i=0;merge_sort_i<merge_sort_k;merge_sort_i++)
		array[merge_sort_i]=merge_sort_array[merge_sort_i];
}

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
unsigned long long tree[200005],m[100005];
unsigned long long update_tree(unsigned long node, unsigned long node_start, unsigned long node_end)
{
	unsigned long temp;
	if(node_start==node_end)
	{
		tree[node]+=m[node_start];
		return node_start;
	}
    if(tree[node<<1]<=tree[(node<<1)+1])
    	temp=update_tree(node<<1,node_start,((node_start+node_end)>>1));
    else
    	temp= update_tree((node<<1)+1,((node_start+node_end)>>1)+1,node_end);
    tree[node]=tree[node<<1]<tree[(node<<1)+1]?tree[node<<1]:tree[(node<<1)+1];
    return temp;
}

int main()
{
	static unsigned long long test_cases,test_case,kam,b,n,lcm,gcd;
	register unsigned long long loop_variable;
	test_cases=fast_unsigned();
	for(test_case=1;test_case<=test_cases;test_case++)
	{
		fill(tree,tree+200005,0);
		lcm=1;
		b=fast_unsigned();
		n=fast_unsigned();
		lcm=gcd=m[1]=fast_unsigned();
		for(loop_variable=2;loop_variable<=b;loop_variable++)
		{
			m[loop_variable]=fast_unsigned();
			gcd=binary_gcd_loop(lcm,m[loop_variable]);
			lcm=((lcm*m[loop_variable])/gcd);
		}
		kam=0;
		for(loop_variable=1;loop_variable<=b;loop_variable++)
			kam+=(lcm/m[loop_variable]);
		n%=kam;
		if(n==0)
			n=kam;
		for(loop_variable=1;loop_variable<n;loop_variable++)
		{
			update_tree(1,1,b);
		}
		printf("Case #%llu: %llu\n",test_case,update_tree(1,1,b));		
	}
	return 0;
}