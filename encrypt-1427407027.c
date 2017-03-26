#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void read(char *temp){
	FILE *pFile=fopen(temp,"r");
	char ch;
	if(pFile==NULL){
		printf("Can't open file!");
		return ;
	}
    while(!feof(pFile)){
		fscanf(pFile,"%c",&ch);
		if(ch>='a' && ch<'z' || ch>='A' && ch<'Z')
	    	ch=ch+1;
		else if (ch=='Z' || ch=='z')
			ch=ch-25;
		putchar(ch);
	}
	fclose(pFile);
}

int main(int argc,char *argv[]){
	char ch;
	char *temp=(char *)malloc(10);
	int num=0;
	if(argc==1){
		printf("输入需要加密的字符串，以Ctrl+d结束.\n");
		ch=getchar();
		while(ch != EOF){
			if(ch>='a' && ch<'z' || ch>='A' && ch<'Z')
				temp[num]=ch+1;
			else if (ch=='Z' || ch=='z')
				temp[num]=ch-25;
			num++;
			ch=getchar();
		}
		
	}
	else{
		for(int i=1;i<argc;i++){
			read(argv[i]);
		}
	}
	printf("\n");
	for(int i=0;i<num;i++)
		printf("%c",temp[i]);
	
	return 1;
}
