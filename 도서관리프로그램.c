#include <stdio.h>
#include "str.h"
#include "book_function.h"


int main() {
    int user_choice; /* ������ ������ �޴�*/
    // char book_name[100][30], auth_name[100][30], publ_name[100][30];
    // int borrowed[100],
    BookInformation library[100];
    int book_total_num=0;
    while (1) {
        printf("���� ���� ���α׷� \n");
        printf("�޴��� �����ϼ��� \n");
        printf("1. å�� ���� �߰��ϱ� \n");
        printf("2. å�� �˻��ϱ� \n");
        printf("3. å�� ������ \n");
        printf("4. å�� �ݳ��ϱ� \n");
        printf("5. å ����Ʈ ��� \n");
        printf("6. ���α׷� ����\n");


        printf("����� ������ : ");
        scanf("%d", &user_choice);
        if (user_choice == 1) {
            /*å�� �߰��ϴ� �Լ� ȣ��*/
            register_book(library,&book_total_num);
        } else if (user_choice == 2) {
            /* å�� �˻��ϴ� �Լ� ȣ�� */
            // search_book(book_name,auth_name,publ_name,borrowed,book_total_num);
            search_book_struct(library,book_total_num);
        } else if (user_choice == 3) {
            /* å�� ������ �Լ� ȣ�� */
            // borrow_book(borrowed,book_name,auth_name,publ_name);
            borrow_book_struct(library);
        } else if (user_choice == 4) {
            /* å�� �ݳ��ϴ� �Լ� ȣ�� */
            // return_book(borrowed,book_name,auth_name,publ_name);
            return_book_struct(library);
        } else if (user_choice == 5) {
            /* å ��� ��ü ��� */
            print_book_list(library, book_total_num);
            
        }else if(user_choice==6){
            /* ���α׷��� �����Ѵ�. */
            break;
        }
    }

  return 0;
}
