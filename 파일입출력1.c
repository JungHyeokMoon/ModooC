#include <stdio.h>
int main(){
    char buf[100];
    printf("���� ��θ� �Է��ϼ��� : ");
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