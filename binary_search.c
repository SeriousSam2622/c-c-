#include<stdio.h>
void main()
{
	int array[10],n,i,search,first,last,middle;
	printf("enter the size of the array :\n");
	scanf("%d",&n);
	printf("enter the array elements :\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&array[i]);
	}
	printf("enter the element to be searched :\n");
	scanf("%d",&search);
	first=0;
	last=n-1;
	middle=(first+last)/2;
	while(first<=last)
	{
		if(array[middle]==search)
		{
			printf("element found at position %d",middle+1);
			break;
		}
		else if(array[middle]<search)
		{
			first=middle+1;
		}
		else
		{
			last=middle-1;
		}
		middle=(first+last)/2;
	}
}
