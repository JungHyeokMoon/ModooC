#include <stdio.h>
#include "book_function.h"
#include "str.h"
void print_book_list(BookInformation * library,int book_total_num){
    printf("å ��ü ����� ����մϴ�.\n");
    int idx=0;
    for(idx=0; idx<book_total_num; idx++){
        printf("å�� ��ȣ %d // å�� �̸� %s // å ���ǻ� %s // å ���ǻ� %s", idx,library[idx].book_name,library[idx].auth_name,library[idx].publ_name);
        if(library[idx].borrowed==1)
            printf(" �����\n");
        else
            printf(" \n");
    }
}

//å ������ �Լ�
int borrow_book(int * borrowed,char (*book_name)[30], char(*auth_name)[30], char(*publ_name)[30]){
    int book_num;
    printf("���� å�� ��ȣ�� �Է��ϼ��� :");
    scanf("%d", &book_num);

    if(borrowed[book_num]==1)
        printf("�̹� ����� å�Դϴ�. \n");
    else{
        borrowed[book_num]=1;
        printf("���������� �����߽��ϴ�. ������ å�� ��ȣ�� %d // å�� �̸��� %s // å�� ���ڴ� %s // å�� ���ǻ�� %s �Դϴ�.\n",book_num,book_name[book_num],auth_name[book_num],publ_name[book_num]);
    }
    return 0;
}
int borrow_book_struct(BookInformation * library){
    int book_num;
    printf("���� å�� ��ȣ�� �Է��ϼ��� :");
    scanf("%d", &book_num);
    if(library[book_num].borrowed==1)
        printf("�̹� ����� å�Դϴ�. \n");
    else{
        library[book_num].borrowed=1;
        printf("���������� �����߽��ϴ�. ������ å�� ��ȣ�� %d // å�� �̸��� %s // å�� ���ڴ� %s // å�� ���ǻ�� %s �Դϴ�.\n",book_num,library[book_num].book_name,library[book_num].auth_name,library[book_num].publ_name);
    }

    return 0;
}


int return_book(int * borrowed,char (*book_name)[30], char(*auth_name)[30], char(*publ_name)[30]){
    int book_num;
    printf("�ݳ��� å�� ��ȣ�� �Է��ϼ��� : ");
    scanf("%d", &book_num);
    borrowed[book_num]=0;
    printf("���������� �ݳ��߽��ϴ�. �ݳ��� å�� ��ȣ�� %d // å�� �̸��� %s // å�� ���ڴ� %s // å�� ���ǻ�� %s �Դϴ�.\n",book_num,book_name[book_num],auth_name[book_num],publ_name[book_num]);
    return 0;
}
int return_book_struct(BookInformation * library){
    int book_num;
    printf("�ݳ��� å�� ��ȣ�� �Է��ϼ��� : ");
    scanf("%d", &book_num);
    library[book_num].borrowed=0;
    printf("���������� �ݳ��߽��ϴ�. �ݳ��� å�� ��ȣ�� %d // å�� �̸��� %s // å�� ���ڴ� %s // å�� ���ǻ�� %s �Դϴ�.\n",book_num,library[book_num].book_name,library[book_num].auth_name,library[book_num].publ_name);
    return 0;
}
//search_book �����丵�� �����Լ�
void search_book_helper(char (*searchInfo)[30], char * user_input,int book_total_num,int *borrowed){
    int idx;
    for(idx=0; idx<book_total_num; idx++){
        if(contain(searchInfo[idx],user_input)){
            printf("ã�� å�� ��ȣ %d // å�� �̸� %s ",idx,searchInfo[idx]);
            if(borrowed[idx]==1)
                printf(" �����\n");
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
                printf("ã�� å�� ��ȣ %d // å�� �̸� %s // å�� ���� %s // å�� ���ǻ� %s",idx, library[idx].book_name,library[idx].auth_name,library[idx].publ_name);
                if(library->borrowed==1)
                    printf(" �����\n");
                else
                    printf("\n");
            }
        }
    }
    else if(user_choice==2){
        for(idx=0; idx<book_total_num; idx++){
            if(contain(library->auth_name,user_input)){
                printf("ã�� å�� ��ȣ %d // å�� �̸� %s // å�� ���� %s // å�� ���ǻ� %s",idx, library[idx].book_name,library[idx].auth_name,library[idx].publ_name);
                if(library->borrowed==1)
                    printf(" �����\n");
                else
                    printf("\n");
            }
        }
    }
    else{
        for(idx=0; idx<book_total_num; idx++){
            if(contain(library->publ_name,user_input)){
                printf("ã�� å�� ��ȣ %d // å�� �̸� %s // å�� ���� %s // å�� ���ǻ� %s",idx, library[idx].book_name,library[idx].auth_name,library[idx].publ_name);
                if(library->borrowed==1)
                    printf(" �����\n");
                else
                    printf("\n");
            }
        }
    }
}


int search_book_struct(BookInformation * library,int book_total_num){
    int user_choice;
    char user_input[100];

    printf("���� �������� ã���� �Է��ϼ���.\n");
    printf("1. å�� �̸� \n");
    printf("2. ������ �̸� \n");
    printf("3. ���ǻ��� �̸� \n");
    scanf("%d",&user_choice);
    printf("�˻�� �Է��ϼ��� : ");
    scanf("%s",user_input);

    search_book_helper_struct(library,user_choice,user_input,book_total_num);
    

    return 0;
}
int search_book(char (*book_name)[30], char(*auth_name)[30], char(*publ_name)[30],int * borrowed,int book_total_num){
    int user_choice;
    char user_input[100];
    
    printf("���� �������� ã���� �Է��ϼ���.\n");
    printf("1. å�� �̸� \n");
    printf("2. ������ �̸� \n");
    printf("3. ���ǻ��� �̸� \n");
    scanf("%d",&user_choice);
    printf("�˻�� �Է��ϼ��� : ");
    scanf("%s",user_input);

    if(user_choice==1)
        search_book_helper(book_name,user_input,book_total_num,borrowed);
    else if(user_choice==2)
        search_book_helper(auth_name,user_input,book_total_num,borrowed);
    else
        search_book_helper(publ_name,user_input,book_total_num,borrowed);

    return 0;
}
//����ü�� ������� �ʾ����� å�� �߰��ϴ� �Լ�
int add_book(char (*book_name)[30], char(*auth_name)[30], char(*publ_name)[30],int * borrowed,int * book_total_num){
    //�޸� �б⸦ �ѹ��� �ϱ� ���ؼ� ����ϴ� idx
    int idx=*book_total_num;
    if(idx==100){
        printf("�뷮�� ���� á���ϴ�.\n");
        return 0;
    }

    printf("å�� �̸��� �Է��ϼ��� : ");
    scanf("%s",book_name[idx]);

    printf("������ �̸��� �Է��ϼ��� : ");
    scanf("%s",auth_name[idx]);

    printf("���ǻ��� �̸��� �Է��ϼ��� : ");
    scanf("%s", publ_name[idx]);

    //���� ������ �ʾ����Ƿ�
    borrowed[idx]=0;

    printf("�߰� ����!\n");
    printf("�߰��� å�� ��ȣ %d // å�� �̸� %s // å�� ���� %s // å�� ���ǻ� %s \n",idx,book_name[idx],auth_name[idx],publ_name[idx]);
    (*book_total_num)++;
    printf("å�� �� ������ %d ���Դϴ�.\n",*book_total_num);

    return 0;
}

int register_book(BookInformation * library,int * book_total_num){
    int idx=*book_total_num;
    if(idx==100){
        printf("�뷮�� ���� á���ϴ�.\n");
        return 0;
    }

    printf("å�� �̸��� �Է��ϼ��� : ");
    scanf("%s",library[idx].book_name);

    printf("������ �̸��� �Է��ϼ��� : ");
    scanf("%s",library[idx].auth_name);

    printf("���ǻ��� �̸��� �Է��ϼ��� : ");
    scanf("%s", library[idx].publ_name);

    library[idx].borrowed=0;

    printf("�߰� ����!\n");
    printf("�߰��� å�� ��ȣ %d // å�� �̸� %s // å�� ���� %s // å�� ���ǻ� %s \n",idx,library[idx].book_name,library[idx].auth_name,library[idx].publ_name);
    (*book_total_num)++;
    printf("å�� �� ������ %d ���Դϴ�.\n",*book_total_num);

    return 0;
}

