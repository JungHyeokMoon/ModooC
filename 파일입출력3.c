#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(){
    FILE * fp=fopen("a.txt","r");
    if(fp==NULL){
        printf("Error!\n");
        return 0;
    }
    int size=0;
    while(fgetc(fp)!=EOF){
        size++;
    }
    printf("들어있는 글자 수 : %d \n",size);
    fseek(fp,0,SEEK_SET);
    char * str=(char*)malloc(sizeof(char)*size);
    fgets(str,size,fp);
    fclose(fp);
    fp=fopen("b.txt","w");
    if(fp==NULL){
        printf("Error2!\n");
        return 0;
    }
    for(int i=size-1; i>=0; i--){
        fputc(str[i],fp);
    }
    fclose(fp);
    return 0;
}