#include <stdio.h>
#include <assert.h>
#define Assert(expression, message) assert(expression && message)
int main(){
    FILE * fp=fopen("some_data.txt","r+");
    char c;

    Assert(fp!=NULL,"���Ͽ��� ����");

    while((c=fgetc(fp))!=EOF){
        if('A'<=c && c<='Z'){
            fseek(fp,-1,SEEK_CUR);
            fputc((c-'A')+'a',fp);
        }
        //�а� ���� ��ȯ�� ����
        
        else if('a'<=c && c<='z'){
            fseek(fp,-1,SEEK_CUR);
            fputc((c-'a')+'A',fp);
        }
        fseek(fp,0,SEEK_CUR);
    }
    fclose(fp);
    return 0;
}