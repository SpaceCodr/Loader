#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void main() {
  FILE *fp1,*fp2;
  int i,j,staddr1;
  char input[50],name[10],staddr[10];
  fp1=fopen("obfile.dat","r");
  fp2=fopen("output2.dat","w");
  fscanf(fp1,"%s",input);
  for (i=2,j=0;i<8,j<6;i++,j++)
    name[j]=input[i];
  name[j]='\0';
  fprintf(fp2,"name from program: %s\n",name);
  fscanf(fp1,"%s",input);
  do {
    if(input[0]=='T'){
      for(i=2,j=0;i<8,j<6;i++,j++)
        staddr[j]=input[i];
      staddr[j]='\0';
      staddr1=atoi(staddr);
      i=12;
      while(input[i]!='$'){
        if(input[i]!='^'){
          fprintf(fp2,"00%d \t %c%c\n", staddr1,input[i],input[i+1]);
          staddr1++;
          i=i+2;
        }
        else i++;
      }
    }
    else if(input[0]='E')
      fprintf(fp2,"jump to execution address:%s",&input[2]);
    fscanf(fp1,"%s",input);
  }while(!feof(fp1) );
  fclose(fp1);
  fclose(fp2);
}
