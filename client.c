#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
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
 my_socket.sin_port=htons(5000);
 my_socket.sin_addr.s_addr=INADDR_ANY;
 char str[100];
 struct sockaddr_in rev_socket; //sendto
 int len=sizeof(struct sockaddr_in);
rev_socket.sin_family=AF_INET;
 rev_socket.sin_port=htons(8080);
 rev_socket.sin_addr.s_addr=INADDR_ANY;
 int c=connect(fd,(const struct sockaddr*)&rev_socket,len);
	FILE *ptr=fopen("cli.txt","w");
    int rec=1;
	while(rec)
	{
		rec=recv(fd,str,sizeof(str),0);
		fwrite(str,1,rec,ptr);
		memset(str,0,strlen(str));
		if(strlen(str)<100)break;
	}
	fclose(ptr);
	printf("Enter the File name to be fetched\n");
	char fname[100];
	scanf("%s",fname);
	int s=send(fd,fname,strlen(fname),0);
	if(s==-1)
	{
		printf("send FAILED");
	}
	else
		printf("SENT\n");

	FILE *rptr=fopen(fname,"w");
    rec=1;
	while(rec)
	{
		rec=recv(fd,str,sizeof(str),0);
		if(strcmp(str,"file not found")==0)
		{
			printf("file not found\n");
			break;
		}
		fwrite(str,1,rec,rptr);
		memset(str,0,strlen(str));
		if(strlen(str)<100)break;
	}
	fclose(rptr);


}