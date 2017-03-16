#include<stdio.h>
#include<string.h>
char array[105][105],back_array[105],character;//a array ::b back_array :: ch character
int length_modified[105],position_modified[105],temporary[105];//len length_modified :: pos position_modified ::temp temporary
int merge(int left,int right)
{
    int i,j,k=0,mid,temp[right-left+1];
    mid=(left+right)/2;
    if(left<right)
    {
        mid=(left+right)/2;
        merge(left,mid);
        merge(mid+1,right);
    }
    i=left;
    j=mid+1;
    while((i<=mid)&&(j<=right))
    {
        if(temporary[i]<=temporary[j])
        {
            temp[k]=temporary[i];
            k++;
            i++;
        }
        else
        {
            temp[k]=temporary[j];
            k++;
            j++;
        }
    }
    while(i<=mid)
    {
        temp[k]=temporary[i];
        k++;
        i++;
    }
    while(j<=right)
    {
        temp[k]=temporary[j];
        k++;
        j++;
    }
    for(i=0;i<k;i++)
        temporary[i+left]=temp[i];
    return 0;
}
int main()
{
    int result_accepted,t,i,j,got_flag,tem,xcoordinate,n,middle,ycoordinate;
    #ifndef ONLINE_JUDGE
        freopen("input.c","r",stdin);
        freopen("output.c","w",stdout);
    #endif // ONLINE_JUDGE
    scanf("%d",&t);
    int l;
    for(l=1;l<=t;l++)
    {
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            scanf("%s",array[i]);
            length_modified[i]=strlen(array[i]);
            position_modified[i]=0;
        }
        xcoordinate=0;
        result_accepted=0;
        got_flag=0;
        while(1)
        {
            for(i=0;i<n;i++)
            {
                back_array[i]=array[i][position_modified[i]];
            }
            character=back_array[0];
            for(i=1;i<n;i++)
            {
                if(back_array[i]!=character)
                {
                    got_flag=1;
                    break;
                }
            }
            for(i=0;i<n;i++)
            {
                tem=position_modified[i];
                while(array[i][position_modified[i]]==back_array[i])
                {
                    position_modified[i]++;
                    if(position_modified[i]==length_modified[i])
                    {
                        xcoordinate=1;
                        break;
                    }
                }
                temporary[i]=position_modified[i]-tem;
            }
            merge(0,n-1);
            middle=temporary[n/2];
            for(i=0;i<n;i++)
            {
                ycoordinate=middle-temporary[i];
                if(ycoordinate<0)
                    ycoordinate=-ycoordinate;
                result_accepted=result_accepted+ycoordinate;
            }
            if(xcoordinate==1)
            {
                for(i=0;i<n;i++)
                {
                    if(position_modified[i]!=length_modified[i])
                        break;
                }
                if(i<n)
                    got_flag=1;
                else
                    break;
            }
            if(got_flag==1)
                break;
        }
        if(got_flag==1)
            printf("Case #%d: Fegla Won\n",l);
        else
            printf("Case #%d: %d\n",l,result_accepted);
    }
    return 0;
}

