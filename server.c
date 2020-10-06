#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<unistd.h>
#include <netinet/in.h> 
#include<arpa/inet.h>
void create()
{
	char s[50]="ls>res.txt";
	system(s);
}
int search(char *st)
{
	FILE *ptr=fopen("res.txt","r");
	char *line=NULL;
	size_t len=0;
	int read;
	while((read=getline(&line,&len,ptr))!=-1)
	{
		line[read-1]='\0';
		if(strcmp(line,st)==0)
			return 1;
	}
	return 0;
}
int main(int a,char *arr[])
{
 int fd=socket(AF_INET,SOCK_STREAM,0);
 if(fd==-1)
  {
    printf("socket creation fail\n");
    exit(0);
   }
   else
  {
   printf ("socket creation succeeded\n");
  }
 struct sockaddr_in my_socket;
 my_socket.sin_family=AF_INET;
 my_socket.sin_port=htons(8080);
 my_socket.sin_addr.s_addr=INADDR_ANY;
 int bn=bind(fd,(const struct sockaddr*)(&my_socket),sizeof(struct sockaddr_in));
 if(bn==-1)
  {
    printf(" bind fail\n");
    exit(0);
   }
   else
  {
   printf ("bind succeeded\n");
  }
  struct sockaddr_in rec_socket;
  int len=sizeof(rec_socket);
  int list,f,g;
  list=listen(fd,5);
  f=accept(fd,(struct sockaddr*)&rec_socket,&len);

    create();
    FILE *ptr=fopen("res.txt","r");
	char str[100],rev_buff[100];
	while(1)
	{
		int c=fread(str,1,100,ptr);
		int so=send(f,str,c,0);
		memset(str,0,strlen(str));
		if(feof(ptr))
			{	
				printf("Resource FILE sent\n");
				break;
			}
	}
	fclose(ptr);
    int r=recv(f,rev_buff,sizeof(rev_buff),0);
    rev_buff[r]='\0';

    printf("FILE to be searched=%s",rev_buff);
    if(search(rev_buff))
    {
    	rev_buff[r]='\0';
    	FILE *nptr=fopen(rev_buff,"r");
    	printf("SENDING THE FILE..");
    	while(1)
		{
		printf("....");
		int c=fread(str,1,100,nptr);
		int so=send(f,str,c,0);
		memset(str,0,strlen(str));
		if(feof(nptr))
			{	
				printf("FILE sent");
				break;
			}
		}
		fclose(nptr);
		close(f);
		exit(1);
    }
    else
    {
    	strcpy(str,"file not found");
    	int s=send(f,str,strlen(str),0);
    	printf("FILE NOT FOUND\n");
    	close(f);
    	exit(1);
    }


}