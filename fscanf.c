#include <stdio.h>
#include <assert.h>
#define Assert(expression, message) assert(expression && message)
int main(){
    FILE * fp=fopen("some_data.txt","r");
    char data[100];

    Assert(fp!=NULL, "���Ͽ������!\n");

    printf("�Է¹��� �ܾ�� \n");
    while(fscanf(fp,"%s",data)!=EOF){
        printf("%s \n",data);
    }
    fclose(fp);
    return 0;
}