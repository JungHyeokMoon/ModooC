#include <stdio.h>
int read_char(void *p, int byte);
int main(){
    int arr[1]={0x12345678};

    printf("%x \n", arr[0]);
    read_char(arr,4);
}
//임의의 주소값 p로부터 byte만큼 읽은 함수,리틀엔디안 형식으로 읽고있다.
int read_char(void *p, int byte){
    do{
        printf("%x \n",*(char * )p);
        byte--;

        p=(char *)p+1;
    }while(p && byte);

    return 0;

}