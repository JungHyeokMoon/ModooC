#include <stdio.h>
int add_book(char (*book_name)[30], char(*auth_name)[30], char(*publ_name)[30],int * borrowed, int * book_total_num);
int search_book(char (*book_name)[30], char(*auth_name)[30], char(*publ_name)[30],int * borrowed,int book_total_num);
int borrow_book(int * borrowed,char (*book_name)[30], char(*auth_name)[30], char(*publ_name)[30]);
int return_book(int * borrowed,char (*book_name)[30], char(*auth_name)[30], char(*publ_name)[30]);
int contain(char * str1, char *str2);
void search_book_helper(char (*searchInfo)[30], char * user_input,int book_total_num,int * borrwowed);
int strLen(char * str);

int main() {
    int user_choice; /* 유저가 선택한 메뉴*/
    char book_name[100][30], auth_name[100][30], publ_name[100][30];
    int borrowed[100], book_total_num=0;
    printf("%d \n",book_total_num);
    while (1) {
        printf("도서 관리 프로그램 \n");
        printf("메뉴를 선택하세요 \n");
        printf("1. 책을 새로 추가하기 \n");
        printf("2. 책을 검색하기 \n");
        printf("3. 책을 빌리기 \n");
        printf("4. 책을 반납하기 \n");
        printf("5. 프로그램 종료 \n");

        printf("당신의 선택은 : ");
        scanf("%d", &user_choice);
        if (user_choice == 1) {
            /*책을 추가하는 함수 호출*/
            add_book(book_name,auth_name,publ_name,borrowed,&book_total_num);
        } else if (user_choice == 2) {
            /* 책을 검색하는 함수 호출 */
            search_book(book_name,auth_name,publ_name,borrowed,book_total_num);
        } else if (user_choice == 3) {
            /* 책을 빌리는 함수 호출 */
            borrow_book(borrowed,book_name,auth_name,publ_name);
        } else if (user_choice == 4) {
            /* 책을 반납하는 함수 호출 */
            return_book(borrowed,book_name,auth_name,publ_name);
        } else if (user_choice == 5) {
            /* 프로그램을 종료한다. */
            break;
        }
    }

  return 0;
}
//책 빌리는 함수
int borrow_book(int * borrowed,char (*book_name)[30], char(*auth_name)[30], char(*publ_name)[30]){
    int book_num;
    printf("빌릴 책의 번호를 입력하세요 :");
    scanf("%d", &book_num);

    if(borrowed[book_num]==1)
        printf("이미 대출된 책입니다. \n");
    else{
        borrowed[book_num]=1;
        printf("성공적으로 대출했습니다. 대출한 책의 번호는 %d // 책의 이름은 %s // 책의 저자는 %s // 책의 출판사는 %s 입니다.\n",book_num,book_name[book_num],auth_name[book_num],publ_name[book_num]);
    }
    return 0;
}

int return_book(int * borrowed,char (*book_name)[30], char(*auth_name)[30], char(*publ_name)[30]){
    int book_num;
    printf("반납할 책의 번호를 입력하세요 : ");
    scanf("%d", &book_num);
    borrowed[book_num]=0;
    printf("성공적으로 반납했습니다. 대출한 책의 번호는 %d // 책의 이름은 %s // 책의 저자는 %s // 책의 출판사는 %s 입니다.\n",book_num,book_name[book_num],auth_name[book_num],publ_name[book_num]);
    return 0;
}
//serach_book 리팩토링을 위한함수
void search_book_helper(char (*searchInfo)[30], char * user_input,int book_total_num,int *borrowed){
    int idx;
    for(idx=0; idx<book_total_num; idx++){
        if(contain(searchInfo[idx],user_input)){
            printf("찾는 책의 번호 %d // 책의 이름 %s ",idx,searchInfo[idx]);
            if(borrowed[idx]==1)
                printf(" 대출됨\n");
            else
                printf("\n");
        }
    }
}
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
    if(str1Len<str2Len)
        return 0;
    for(int i=0; i<str2Len; i++)
        if(str1[i]!=str2[i])return 0;
    return 1;
}
int search_book(char (*book_name)[30], char(*auth_name)[30], char(*publ_name)[30],int * borrowed,int book_total_num){
    int user_choice;
    char user_input[100];
    
    printf("무슨 기준으로 찾을지 입력하세요.\n");
    printf("1. 책의 이름 \n");
    printf("2. 저자의 이름 \n");
    printf("3. 출판사의 이름 \n");
    scanf("%d",&user_choice);
    printf("검색어를 입력하세요 : ");
    scanf("%s",user_input);

    if(user_choice==1)
        search_book_helper(book_name,user_input,book_total_num,borrowed);
    else if(user_choice==2)
        search_book_helper(auth_name,user_input,book_total_num,borrowed);
    else
        search_book_helper(publ_name,user_input,book_total_num,borrowed);

    return 0;
}
int add_book(char (*book_name)[30], char(*auth_name)[30], char(*publ_name)[30],int * borrowed,int * book_total_num){
    //메모리 읽기를 한번만 하기 위해서 사용하는 idx
    int idx=*book_total_num;
    if(idx==100){
        printf("용량이 가득 찼습니다.\n");
        return 0;
    }

    printf("책의 이름을 입력하세요 : ");
    scanf("%s",book_name[idx]);

    printf("저자의 이름을 입력하세요 : ");
    scanf("%s",auth_name[idx]);

    printf("출판사의 이름을 입력하세요 : ");
    scanf("%s", publ_name[idx]);

    //아직 빌리지 않았으므로
    borrowed[idx]=0;

    printf("추가 성공!\n");
    printf("추가한 책의 번호 %d // 책의 이름 %s // 책의 저자 %s // 책의 출판사 %s \n",idx,book_name[idx],auth_name[idx],publ_name[idx]);
    (*book_total_num)++;
    printf("책의 총 갯수는 %d 개입니다.\n",*book_total_num);

    return 0;
}