#include<stdio.h>
int main()
{
	int x,y;
	char o,h;
	printf("enter first number:\n enter second number:\n");
	scanf("%d%d",&x,&y);
	printf("enter operator:\n");
	scanf("%c",&h);
	scanf("%c",&o);
	switch(o)
	{
		case'+': printf("%d",x+y);
		break;
		case'-': printf("%d",x-y);
		break;
		case'*': printf("%d",x*y);
		break;
		case'/': printf("%d",x/y);
		break;
		default: printf("invalid input");
	}

return 0;	
}