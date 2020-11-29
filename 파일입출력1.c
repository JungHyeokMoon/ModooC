#include <stdio.h>
int main(){
    char buf[100];
    printf("파일 경로를 입력하세요 : ");
    scanf("%s",buf);
    // printf("%s\n", buf);

    FILE * fp=fopen(buf,"w");
    if(fp==NULL)
        printf("Error!\n");
    else{
        fputs("a",fp);
        fclose(fp);
    }   

    return 0;
}