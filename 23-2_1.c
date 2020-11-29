#include <stdio.h>
#include <assert.h>
#define Assert(expression, message) assert(expression && message)
int main(){
    FILE * fp=fopen("some_data.txt","r+");
    char c;

    Assert(fp!=NULL,"파일열기 에러");

    while((c=fgetc(fp))!=EOF){
        if('A'<=c && c<='Z'){
            fseek(fp,-1,SEEK_CUR);
            fputc((c-'A')+'a',fp);
        }
        //읽고 쓸때 변환을 위해
        
        else if('a'<=c && c<='z'){
            fseek(fp,-1,SEEK_CUR);
            fputc((c-'a')+'A',fp);
        }
        fseek(fp,0,SEEK_CUR);
    }
    fclose(fp);
    return 0;
}