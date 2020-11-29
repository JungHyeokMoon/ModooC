#include <stdio.h>
int main(){
    FILE * fp =fopen("a.txt","r");
    if(fp==NULL){
        printf("Error!\n");
        return 0;
    }
    fseek(fp,4,SEEK_SET);
    char c=fgetc(fp);
    printf("범위를 벗어났을때는 어떻게 될 것인가?%c \n",c);
    //범위를 벗어나면 이상한 글자가 나옴
    return 0;
}