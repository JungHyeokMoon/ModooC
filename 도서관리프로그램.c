#include <stdio.h>
#include "str.h"
#include "book_function.h"


int main() {
    int user_choice; /* 유저가 선택한 메뉴*/
    // char book_name[100][30], auth_name[100][30], publ_name[100][30];
    // int borrowed[100],
    BookInformation library[100];
    int book_total_num=0;
    while (1) {
        printf("도서 관리 프로그램 \n");
        printf("메뉴를 선택하세요 \n");
        printf("1. 책을 새로 추가하기 \n");
        printf("2. 책을 검색하기 \n");
        printf("3. 책을 빌리기 \n");
        printf("4. 책을 반납하기 \n");
        printf("5. 책 리스트 출력 \n");
        printf("6. 프로그램 종료\n");


        printf("당신의 선택은 : ");
        scanf("%d", &user_choice);
        if (user_choice == 1) {
            /*책을 추가하는 함수 호출*/
            register_book(library,&book_total_num);
        } else if (user_choice == 2) {
            /* 책을 검색하는 함수 호출 */
            // search_book(book_name,auth_name,publ_name,borrowed,book_total_num);
            search_book_struct(library,book_total_num);
        } else if (user_choice == 3) {
            /* 책을 빌리는 함수 호출 */
            // borrow_book(borrowed,book_name,auth_name,publ_name);
            borrow_book_struct(library);
        } else if (user_choice == 4) {
            /* 책을 반납하는 함수 호출 */
            // return_book(borrowed,book_name,auth_name,publ_name);
            return_book_struct(library);
        } else if (user_choice == 5) {
            /* 책 목록 전체 출력 */
            print_book_list(library, book_total_num);
            
        }else if(user_choice==6){
            /* 프로그램을 종료한다. */
            break;
        }
    }

  return 0;
}
