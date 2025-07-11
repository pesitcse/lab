10.)SUM OF SUBSET
#include<stdio.h>
int count=0;
int w[10];
int d;
int x[10];

void subset(int cs,int k,int r)
{
    int i;
    x[k]=1;
    if(cs+w[k]==d)
    {
        printf("\nSubset solution=%d\n",++count);
        for(i=0;i<=k;i++)
        {
            if(x[i]==1)
                printf("%d    ",w[i]);
        }
    }
    else if(cs+w[k]+w[k+1]<=d)
        subset(cs+w[k],k+1,r-w[k]);
    if((cs+r-w[k]>=d)&&(cs+w[k+1]<=d))
    {
        x[k]=0;
        subset(cs,k+1,r-w[k]);
    }
}

void main()
{

    int sum=0,i,n;
    printf("\nEnter the number of elements\n");
    scanf("%d",&n);

    printf("\nEnter the elements in ascending order:\n");
    for(i=0;i<n;i++)
        scanf("%d",&w[i]);

    printf("\nEnter the required sum:");
    scanf("%d",&d);

    for(i=0;i<n;i++)
            sum+=w[i];

    if(sum<d)
    {
        printf("\nNo solution exists\n");
        return;
    }
    printf("\nThe solution is:\n");
    subset(0,0,sum);
}




