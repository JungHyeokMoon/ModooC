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
  int user_choice;        /* ������ ������ �޴� */
  int num_total_book = 0; /* ���� å�� �� */
  BOOK *book_list;
  printf("�������� �ִ� ���� �弭 ���� �������ּ��� : ");
  scanf("%d", &user_choice);
  book_list = (BOOK *)malloc(sizeof(BOOK) * user_choice);
  while (1) {
    printf("���� ���� ���α׷� \n");
    printf("�޴��� �����ϼ��� \n");
    printf("1. å�� ���� �߰��ϱ� \n");
    printf("2. å�� �˻��ϱ� \n");
    printf("3. å�� ������ \n");
    printf("4. å�� �ݳ��ϱ� \n");
    printf("5. å���� ������ book_list.txt�� ��� \n");
    printf("6. ���α׷� ���� \n");
    printf("7. ���α׷� ���� \n");
    printf("����� ������ : ");
    scanf("%d", &user_choice);
    if (user_choice == 1) { /* å�� ���� �߰��ϴ� �Լ� ȣ�� */
      register_book(book_list, &num_total_book);
    } else if (user_choice == 2) { /* å�� �˻��ϴ� �Լ� ȣ�� */
      search_book(book_list, num_total_book);
    } else if (user_choice == 3) { /* å�� ������ �Լ� ȣ�� */
      borrow_book(book_list);
    } else if (user_choice == 4) { /* å�� �ݳ��ϴ� �Լ� ȣ�� */
      return_book(book_list);
    } else if (user_choice == 5) { /* å ��� ��� */
        print_book_list(book_list,num_total_book);
    }
    else if(user_choice==6){
        retrieve_book_info(&book_list,&num_total_book);
    }
    else if(user_choice==7){/* ���α׷��� �����Ѵ�. */
        break;
    }
  }
  free(book_list);
  return 0;
}
int register_book(BOOK * book_list, int *nth){
    int idx=*nth;
    printf("å �̸��� �Է��ϼ���: ");
    scanf("%s",book_list[idx].book_name);
    printf("å ���ڸ� �Է��ϼ���: ");
    scanf("%s",book_list[idx].auth_name);
    printf("å ���ǻ縦 �Է��ϼ���: ");
    scanf("%s",book_list[idx].publ_name);
    //���� ������ �ʾ����ϱ�
    book_list[idx].borrowed=0;

    
    printf("å �� �̸��� %s // ���� %s // ���ǻ� %s ",book_list[idx].book_name, book_list[idx].auth_name,book_list[idx].publ_name);
    (*nth)++;
    printf("�� %d�� �Դϴ�.\n",*nth);

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
    int user_input; /* ������� �Է��� �޴´�. */
    int i;
    char user_search[30];
    printf("��� ������ �˻� �� ���ΰ���? \n");
    printf("1. å ���� �˻� \n");
    printf("2. ������ �˻� \n");
    printf("3. ���ǻ� �˻� \n");
    scanf("%d", &user_input);
    printf("�˻��� �ܾ �Է����ּ��� : ");
    scanf("%s", user_search);
    printf("�˻� ��� \n");
    if(user_input==1){
        for(i=0; i<total_num_book; i++){
            if(contain(book_list[i].book_name,user_search)){
                printf("��ȣ : %d // å �̸� : %s // ������ : %s // ���ǻ� : %s \n", i,
                    book_list[i].book_name, book_list[i].auth_name,
                    book_list[i].publ_name);
            }
        }
    }
    else if(user_input==2){
        for(i=0; i<total_num_book; i++){
            if(contain(book_list[i].auth_name,user_search)){
                printf("��ȣ : %d // å �̸� : %s // ������ : %s // ���ǻ� : %s \n", i,
                    book_list[i].book_name, book_list[i].auth_name,
                    book_list[i].publ_name);
            }
        }
    }
    else if(user_input==3){
        for(i=0; i<total_num_book; i++){
            if(contain(book_list[i].publ_name,user_search)){
                printf("��ȣ : %d // å �̸� : %s // ������ : %s // ���ǻ� : %s \n", i,
                    book_list[i].book_name, book_list[i].auth_name,
                    book_list[i].publ_name);
            }
        }
    }
    
}
int borrow_book(BOOK *book_list){
    int book_num;
    printf("���� å�� ��ȣ�� �����ּ��� \n");
    printf("å ��ȣ : ");
    scanf("%d",&book_num);
    if(book_list[book_num].borrowed==1){
        printf("�̹� ����� å�Դϴ�.\n");
    }else{
        book_list[book_num].borrowed=1;
        printf("������ å�� �̸��� %s // å�� ���� %s // å�� ���ǻ� %s�Դϴ�.\n",book_list[book_num].book_name,book_list[book_num].auth_name,book_list[book_num].publ_name);
    }
    return 0;
}
int return_book(BOOK *book_list){
    int book_num;
    printf("�ݳ��� å�� ��ȣ�� ���ּ��� \n");
    printf("å ��ȣ : ");
    scanf("%d", &book_num);
    if(book_list[book_num].borrowed==0){
        printf("�̹� �ݳ��� å�Դϴ�.\n");
    }else
    {
        book_list[book_num].borrowed=0;
        printf("�ݳ��� å�� �̸��� %s // å�� ���� %s // å�� ���ǻ� %s�Դϴ�.\n",book_list[book_num].book_name,book_list[book_num].auth_name,book_list[book_num].publ_name);
    }
    
}
int print_book_list(BOOK *book_list, int total_num_book){
    FILE *fp = fopen("book_list.txt", "w");
    int i;
    Assert(fp!=NULL, "���Ͽ��� ����");
    fprintf(fp," å �̸�/���� �̸�/���ǻ�/�ݳ� ����\n");
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
        printf("������ ������ ã�� �� �����ϴ�!\n");
        return -1;
    }
    fscanf(fp,"%d",&total_book);
    *total_num_book=total_book;

    //�Լ��� ���ڷ� �����͸� �޾����� ������ �ϱ����ؼ��� ���������Ͱ� �ʿ��ϴ�
    //���������͸� �޾����Ƿ�
    free(*book_list);
    //���� �Ҵ�
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