#include <stdio.h>
int strLen(char * str);
int stoi(char * str);

int main(int argc, char ** argv){
    if(argc<4)
        printf("인자의 갯수가 모자랍니다. \n");
    

    char operator=argv[2][0];
    int operand1=stoi(argv[1]);
    int operand2=stoi(argv[3]);

    printf(" 첫번째 연산자 %d // 연산기호는 %c // 두번째 연산자 %d \n", operand1,operator,operand2);
    if(operator=='+')
        printf("덧셈의 결과는 %d 입니다.\n", operand1+operand2);
    else if(operator=='-')
        printf("뺄셈의 결과는 %d 입니다.\n", operand1-operand2);
    else if(operator=='x')
        printf("곱셈의 결과는 %d 입니다.\n", operand1*operand2);
    else if(operator=='C')
        printf("나눗셈의 결과는 %f 입니다.\n",operand1/(double)operand2);
    else
        printf("잘못된 기호 입력\n");
    return 0;
}

int strLen(char *str){
    int i=0;
    while(str[i]){
        i++;
    }
    return i;
}
int stoi(char * str){
    int len=strLen(str);
    int num=0;
    int i=0, j=0;
    int powiter=len-1;
    for(i=0; i<len; i++){
        int pownum=1;
        for(j=0; j<powiter; j++){
            pownum*=10;
        }
        num+=(str[i]-'0')*pownum;
        // printf("%d \n",num);
        powiter--;
    }
    return num;
}