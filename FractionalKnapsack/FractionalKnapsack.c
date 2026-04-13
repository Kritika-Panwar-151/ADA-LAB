#include<stdio.h>
struct object
{
    float profit;
    float weight;
    float pw;
};
void sort(struct object o[],int n)
{
    struct object temp;
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(o[j].pw<o[j+1].pw)
            {
                temp=o[j];
                o[j]=o[j+1];
                o[j+1]=temp;
            }
        }
    }
}
int main()
{
    int n;
    printf("Enter number of objects:");
    scanf("%d",&n);
    struct object o[n];
    printf("Enter the profit and weight for:\n");
    for(int i=0;i<n;i++)
    {
        printf("Object %d:",i);
        scanf("%f %f",&o[i].profit,&o[i].weight);
        o[i].pw=o[i].profit/o[i].weight;
    }
    sort(o,n);
    int size;
    printf("Enter the size of the knapsack:");
    scanf("%d",&size);
    float total_profit=0;
    int rm=size;
    int i=0;
    while(rm!=0)
    {
        if(o[i].weight<rm)
        {
            total_profit+=o[i].profit;
            rm-=o[i].weight;
        }
        else
        {
            total_profit+=((o[i].profit*rm)/o[i].weight);
            rm=0;
        }
        i++;
    }
    printf("%-12s %-12s %-12s %-12s\n", "Object", "Profit", "Weight", "Ratio");

    for(int i = 0; i < n; i++)
    {
        printf("%-12d %-12.2f %-12.2f %-12.2f\n",
               i, o[i].profit, o[i].weight, o[i].pw);
    }

    printf("\nMaximum profit: %.2f\n", total_profit);
    return 0;
}
