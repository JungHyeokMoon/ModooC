#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#define Assert(expression, message) assert(expression && message)
typedef struct BOOK {
  char book_name[30];
  char auth_name[30];
  char publ_name[30];
  int borrowed;
}BOOK;


// char compare(char *str1, char *str2);
int register_book(BOOK * book_list, int *nth);
int search_book(BOOK *book_list, int total_num_book);
int borrow_book(BOOK *book_list);
int return_book(BOOK *book_list);
int contain(char * str1, char *str2);
int print_book_list(BOOK *book_list, int total_num_book);
int retrieve_book_info(BOOK **book_list, int *total_num_book);
int main() {
  int user_choice;        /* 유저가 선택한 메뉴 */
  int num_total_book = 0; /* 현재 책의 수 */
  BOOK *book_list;
  printf("도서관의 최대 보관 장서 수를 설정해주세요 : ");
  scanf("%d", &user_choice);
  book_list = (BOOK *)malloc(sizeof(BOOK) * user_choice);
  while (1) {
    printf("도서 관리 프로그램 \n");
    printf("메뉴를 선택하세요 \n");
    printf("1. 책을 새로 추가하기 \n");
    printf("2. 책을 검색하기 \n");
    printf("3. 책을 빌리기 \n");
    printf("4. 책을 반납하기 \n");
    printf("5. 책들의 내용을 book_list.txt에 출력 \n");
    printf("6. 프로그램 종료 \n");
    printf("7. 프로그램 종료 \n");
    printf("당신의 선택은 : ");
    scanf("%d", &user_choice);
    if (user_choice == 1) { /* 책을 새로 추가하는 함수 호출 */
      register_book(book_list, &num_total_book);
    } else if (user_choice == 2) { /* 책을 검색하는 함수 호출 */
      search_book(book_list, num_total_book);
    } else if (user_choice == 3) { /* 책을 빌리는 함수 호출 */
      borrow_book(book_list);
    } else if (user_choice == 4) { /* 책을 반납하는 함수 호출 */
      return_book(book_list);
    } else if (user_choice == 5) { /* 책 목록 출력 */
        print_book_list(book_list,num_total_book);
    }
    else if(user_choice==6){
        retrieve_book_info(&book_list,&num_total_book);
    }
    else if(user_choice==7){/* 프로그램을 종료한다. */
        break;
    }
  }
  free(book_list);
  return 0;
}
int register_book(BOOK * book_list, int *nth){
    int idx=*nth;
    printf("책 이름을 입력하세요: ");
    scanf("%s",book_list[idx].book_name);
    printf("책 저자를 입력하세요: ");
    scanf("%s",book_list[idx].auth_name);
    printf("책 출판사를 입력하세요: ");
    scanf("%s",book_list[idx].publ_name);
    //아직 빌리지 않았으니깐
    book_list[idx].borrowed=0;

    
    printf("책 의 이름은 %s // 저자 %s // 출판사 %s ",book_list[idx].book_name, book_list[idx].auth_name,book_list[idx].publ_name);
    (*nth)++;
    printf("총 %d권 입니다.\n",*nth);

    return 0;
}
int contain(char * str1, char *str2){
    int str1Len=strlen(str1);
    int str2Len=strlen(str2);
    if(str1Len<str2Len)
        return 0;
    for(int i=0; i<str2Len; i++)
        if(str1[i]!=str2[i])return 0;
    return 1;
}
int search_book(BOOK *book_list, int total_num_book){
    int user_input; /* 사용자의 입력을 받는다. */
    int i;
    char user_search[30];
    printf("어느 것으로 검색 할 것인가요? \n");
    printf("1. 책 제목 검색 \n");
    printf("2. 지은이 검색 \n");
    printf("3. 출판사 검색 \n");
    scanf("%d", &user_input);
    printf("검색할 단어를 입력해주세요 : ");
    scanf("%s", user_search);
    printf("검색 결과 \n");
    if(user_input==1){
        for(i=0; i<total_num_book; i++){
            if(contain(book_list[i].book_name,user_search)){
                printf("번호 : %d // 책 이름 : %s // 지은이 : %s // 출판사 : %s \n", i,
                    book_list[i].book_name, book_list[i].auth_name,
                    book_list[i].publ_name);
            }
        }
    }
    else if(user_input==2){
        for(i=0; i<total_num_book; i++){
            if(contain(book_list[i].auth_name,user_search)){
                printf("번호 : %d // 책 이름 : %s // 지은이 : %s // 출판사 : %s \n", i,
                    book_list[i].book_name, book_list[i].auth_name,
                    book_list[i].publ_name);
            }
        }
    }
    else if(user_input==3){
        for(i=0; i<total_num_book; i++){
            if(contain(book_list[i].publ_name,user_search)){
                printf("번호 : %d // 책 이름 : %s // 지은이 : %s // 출판사 : %s \n", i,
                    book_list[i].book_name, book_list[i].auth_name,
                    book_list[i].publ_name);
            }
        }
    }
    
}
int borrow_book(BOOK *book_list){
    int book_num;
    printf("빌릴 책의 번호를 말해주세요 \n");
    printf("책 번호 : ");
    scanf("%d",&book_num);
    if(book_list[book_num].borrowed==1){
        printf("이미 대출된 책입니다.\n");
    }else{
        book_list[book_num].borrowed=1;
        printf("대출한 책의 이름은 %s // 책의 저자 %s // 책의 출판사 %s입니다.\n",book_list[book_num].book_name,book_list[book_num].auth_name,book_list[book_num].publ_name);
    }
    return 0;
}
int return_book(BOOK *book_list){
    int book_num;
    printf("반납할 책의 번호를 써주세요 \n");
    printf("책 번호 : ");
    scanf("%d", &book_num);
    if(book_list[book_num].borrowed==0){
        printf("이미 반납된 책입니다.\n");
    }else
    {
        book_list[book_num].borrowed=0;
        printf("반납한 책의 이름은 %s // 책의 저자 %s // 책의 출판사 %s입니다.\n",book_list[book_num].book_name,book_list[book_num].auth_name,book_list[book_num].publ_name);
    }
    
}
int print_book_list(BOOK *book_list, int total_num_book){
    FILE *fp = fopen("book_list.txt", "w");
    int i;
    Assert(fp!=NULL, "파일열기 오류");
    fprintf(fp," 책 이름/저자 이름/출판사/반납 유무\n");
    for(int i=0; i<total_num_book; i++){
        fprintf(fp,"%s / %s / %s ",book_list[i].book_name,book_list[i].auth_name,book_list[i].publ_name);
        if(book_list[i].borrowed==0)
            fprintf(fp,"/ NO \n");
        else
            fprintf(fp," / YES \n");
    }
    fclose(fp);
}
int retrieve_book_info(BOOK **book_list, int *total_num_book){
    FILE *fp = fopen("book_list.txt", "r");
    int total_book;
    int i;
    char str[10];

    if(fp==NULL){
        printf("지정한 파일을 찾을 수 없습니다!\n");
        return -1;
    }
    fscanf(fp,"%d",&total_book);
    *total_num_book=total_book;

    //함수의 인자로 포인터를 받았을때 조작을 하기위해서는 더블포인터가 필요하다
    //더블포인터를 받았으므로
    free(*book_list);
    //새로 할당
    (*book_list)=(BOOK* )malloc(sizeof(BOOK)*(total_book));
    
    if(*book_list==NULL){
        printf("\n ERROR! \n");
        return -1;
    }

    for(int i=0; i<total_book; i++){
        fscanf(fp,"%s",(*book_list)[i].book_name);
        fscanf(fp,"%s",(*book_list)[i].auth_name);
        fscanf(fp,"%s",(*book_list)[i].publ_name);
        fscanf(fp,"%s",str);
        
        if(strcpy(str,"YES"))
            (*book_list)[i].borrowed=1;
        else if(strcpy(str,"NO"))
            (*book_list)[i].borrowed=0;
    }
    fclose(fp);
    return 0;
}