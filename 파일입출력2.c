#include <stdio.h>
#include <string.h>
void contain(char * str1, char * str2);

int main(){
    FILE *fp =fopen("a.txt","r");
    if(fp==NULL){
        printf("Error!\n");
        return 0;
    }else{
        char buf[100];
        fgets(buf,100,fp);
        printf("�˻��� ���ڿ� �Է� : ");
        char searchBuf[100];
        scanf("%s",searchBuf);
        contain(buf,searchBuf);
        return 0;
    }

    return 0;
}
void contain(char * str1, char * str2){
    int str1Len=strlen(str1);
    int str2Len=strlen(str2);
    if(str1Len<str2Len){
        printf("ã�� ���߽��ϴ�.\n");
        return;
    }
    for(int i=0; i<str2Len; i++){
        if(str1[i]!=str2[i]){
            printf("��ġ���� �ʽ��ϴ�.\n");
            return ;
        }
    }
    printf("ã�� ���ڿ� : %s \n",str1);

}