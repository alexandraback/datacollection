#include <stdio.h>
#include <stdlib.h>

int isVisited[1000000],f[1000000];

typedef struct n
{
    int data;
    struct n*next;
}node;

void addedge(node **n,int m)
{
    node *temp=(*n),*newnode =(node *)malloc(sizeof(node));
        newnode->data=m;
        newnode->next=NULL;
    if((*n)==NULL)
    {
        (*n)=newnode;
    }
    else
    {

        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=newnode;

    }
}
long long int ans=0;
int DFS(int i,int n,node **array)
{
  //  printf("%d\n",i);
    isVisited[i]=1;
    node *temp=array[i];
    int j;
    int k,mark[10000];
    for(k=0;k<10000;k++)
        mark[k]=0;
    while(temp!=NULL)
    {
        if(isVisited[temp->data]==0)
        {int kkk=DFS(temp->data,n,(array));
          //  printf("kkk:%d\n",kkk);
            mark[kkk]=1;
        }
        temp=temp->next;
    }
    for(k=1;k<=100;k++)
    {
        if(mark[k]==0)
        {
            f[i]=k;
            break;
        }
    }
  //  printf("f:%d\n",f[i]);
    ans+=f[i];
    return f[i];
}

int main()
{
freopen("corporate_gifting.txt", "r", stdin);
	freopen("output_111.txt", "w", stdout);
    int t;
    scanf("%d",&t);
    for(long long red=1;red<=t;red++)
    {
    	ans=0;
        int i,n;
        scanf("%d",&n);
        node *v[n+1];
        for(i=0;i<=n;i++)
        {
            isVisited[i]=0;
            v[i]=NULL;
        }
        int t;
        scanf("%d",&t);
        for(i=1;i<n;i++)
        {
            int m;
            scanf("%d",&m);
            addedge(&v[m-1],i);
        }
     //   for(i=0;i<n;i++)
       //     printf("f:%d ",f[i]);
       // printf("\ndfs:");
            DFS(0,n,v);
            printf("Case #%lld: %lld\n", red, ans);
    }
    return 0;
}
