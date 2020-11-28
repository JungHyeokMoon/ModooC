#include "str.h"
int strLen(char *str){
    int i=0;
    while(str[i]){
        i++;
    }
    return i;
}
int contain(char * str1, char *str2){
    int str1Len=strLen(str1);
    int str2Len=strLen(str2);
    // printf("비교하는 문자열 %s %s",str1, str2);
    if(str1Len<str2Len)
        return 0;
    for(int i=0; i<str2Len; i++)
        if(str1[i]!=str2[i])return 0;
    return 1;
}