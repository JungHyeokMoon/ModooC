#include <stdio.h>
int main(){
    FILE * fp =fopen("a.txt","r");
    if(fp==NULL){
        printf("Error!\n");
        return 0;
    }
    fseek(fp,4,SEEK_SET);
    char c=fgetc(fp);
    printf("������ ��������� ��� �� ���ΰ�?%c \n",c);
    //������ ����� �̻��� ���ڰ� ����
    return 0;
}