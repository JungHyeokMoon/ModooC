#include <stdio.h>
#include <assert.h>
#define Assert(expression, message) assert(expression && message)
int main(){
    FILE * fp=fopen("some_data.txt","r");
    char data[100];

    Assert(fp!=NULL, "파일열기오류!\n");

    printf("입력받은 단어들 \n");
    while(fscanf(fp,"%s",data)!=EOF){
        printf("%s \n",data);
    }
    fclose(fp);
    return 0;
}