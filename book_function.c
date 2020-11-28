#include <stdio.h>
#include "book_function.h"
#include "str.h"
void print_book_list(BookInformation * library,int book_total_num){
    printf("책 전체 목록을 출력합니다.\n");
    int idx=0;
    for(idx=0; idx<book_total_num; idx++){
        printf("책의 번호 %d // 책의 이름 %s // 책 출판사 %s // 책 출판사 %s", idx,library[idx].book_name,library[idx].auth_name,library[idx].publ_name);
        if(library[idx].borrowed==1)
            printf(" 대출됨\n");
        else
            printf(" \n");
    }
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
int borrow_book_struct(BookInformation * library){
    int book_num;
    printf("빌릴 책의 번호를 입력하세요 :");
    scanf("%d", &book_num);
    if(library[book_num].borrowed==1)
        printf("이미 대출된 책입니다. \n");
    else{
        library[book_num].borrowed=1;
        printf("성공적으로 대출했습니다. 대출한 책의 번호는 %d // 책의 이름은 %s // 책의 저자는 %s // 책의 출판사는 %s 입니다.\n",book_num,library[book_num].book_name,library[book_num].auth_name,library[book_num].publ_name);
    }

    return 0;
}


int return_book(int * borrowed,char (*book_name)[30], char(*auth_name)[30], char(*publ_name)[30]){
    int book_num;
    printf("반납할 책의 번호를 입력하세요 : ");
    scanf("%d", &book_num);
    borrowed[book_num]=0;
    printf("성공적으로 반납했습니다. 반납한 책의 번호는 %d // 책의 이름은 %s // 책의 저자는 %s // 책의 출판사는 %s 입니다.\n",book_num,book_name[book_num],auth_name[book_num],publ_name[book_num]);
    return 0;
}
int return_book_struct(BookInformation * library){
    int book_num;
    printf("반납할 책의 번호를 입력하세요 : ");
    scanf("%d", &book_num);
    library[book_num].borrowed=0;
    printf("성공적으로 반납했습니다. 반납한 책의 번호는 %d // 책의 이름은 %s // 책의 저자는 %s // 책의 출판사는 %s 입니다.\n",book_num,library[book_num].book_name,library[book_num].auth_name,library[book_num].publ_name);
    return 0;
}
//search_book 리팩토링을 위한함수
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

void search_book_helper_struct(BookInformation * library, int user_choice, char * user_input,int book_total_num){
    int idx=0;
    if(user_choice==1){
        for(idx=0; idx<book_total_num; idx++){
            if(contain(library->book_name,user_input)){
                printf("찾는 책의 번호 %d // 책의 이름 %s // 책의 저자 %s // 책의 출판사 %s",idx, library[idx].book_name,library[idx].auth_name,library[idx].publ_name);
                if(library->borrowed==1)
                    printf(" 대출됨\n");
                else
                    printf("\n");
            }
        }
    }
    else if(user_choice==2){
        for(idx=0; idx<book_total_num; idx++){
            if(contain(library->auth_name,user_input)){
                printf("찾는 책의 번호 %d // 책의 이름 %s // 책의 저자 %s // 책의 출판사 %s",idx, library[idx].book_name,library[idx].auth_name,library[idx].publ_name);
                if(library->borrowed==1)
                    printf(" 대출됨\n");
                else
                    printf("\n");
            }
        }
    }
    else{
        for(idx=0; idx<book_total_num; idx++){
            if(contain(library->publ_name,user_input)){
                printf("찾는 책의 번호 %d // 책의 이름 %s // 책의 저자 %s // 책의 출판사 %s",idx, library[idx].book_name,library[idx].auth_name,library[idx].publ_name);
                if(library->borrowed==1)
                    printf(" 대출됨\n");
                else
                    printf("\n");
            }
        }
    }
}


int search_book_struct(BookInformation * library,int book_total_num){
    int user_choice;
    char user_input[100];

    printf("무슨 기준으로 찾을지 입력하세요.\n");
    printf("1. 책의 이름 \n");
    printf("2. 저자의 이름 \n");
    printf("3. 출판사의 이름 \n");
    scanf("%d",&user_choice);
    printf("검색어를 입력하세요 : ");
    scanf("%s",user_input);

    search_book_helper_struct(library,user_choice,user_input,book_total_num);
    

    return 0;
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
//구조체를 사용하지 않았을때 책을 추가하는 함수
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

int register_book(BookInformation * library,int * book_total_num){
    int idx=*book_total_num;
    if(idx==100){
        printf("용량이 가득 찼습니다.\n");
        return 0;
    }

    printf("책의 이름을 입력하세요 : ");
    scanf("%s",library[idx].book_name);

    printf("저자의 이름을 입력하세요 : ");
    scanf("%s",library[idx].auth_name);

    printf("출판사의 이름을 입력하세요 : ");
    scanf("%s", library[idx].publ_name);

    library[idx].borrowed=0;

    printf("추가 성공!\n");
    printf("추가한 책의 번호 %d // 책의 이름 %s // 책의 저자 %s // 책의 출판사 %s \n",idx,library[idx].book_name,library[idx].auth_name,library[idx].publ_name);
    (*book_total_num)++;
    printf("책의 총 갯수는 %d 개입니다.\n",*book_total_num);

    return 0;
}

