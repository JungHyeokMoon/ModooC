#include <stdio.h>
int add_book(char (*book_name)[30], char(*auth_name)[30], char(*publ_name)[30],int * borrowed, int * book_total_num);
int search_book(char (*book_name)[30], char(*auth_name)[30], char(*publ_name)[30],int * borrowed,int book_total_num);
int borrow_book(int * borrowed,char (*book_name)[30], char(*auth_name)[30], char(*publ_name)[30]);
int return_book(int * borrowed,char (*book_name)[30], char(*auth_name)[30], char(*publ_name)[30]);
int contain(char * str1, char *str2);
void search_book_helper(char (*searchInfo)[30], char * user_input,int book_total_num,int * borrwowed);
int strLen(char * str);

int main() {
    int user_choice; /* ������ ������ �޴�*/
    char book_name[100][30], auth_name[100][30], publ_name[100][30];
    int borrowed[100], book_total_num=0;
    printf("%d \n",book_total_num);
    while (1) {
        printf("���� ���� ���α׷� \n");
        printf("�޴��� �����ϼ��� \n");
        printf("1. å�� ���� �߰��ϱ� \n");
        printf("2. å�� �˻��ϱ� \n");
        printf("3. å�� ������ \n");
        printf("4. å�� �ݳ��ϱ� \n");
        printf("5. ���α׷� ���� \n");

        printf("����� ������ : ");
        scanf("%d", &user_choice);
        if (user_choice == 1) {
            /*å�� �߰��ϴ� �Լ� ȣ��*/
            add_book(book_name,auth_name,publ_name,borrowed,&book_total_num);
        } else if (user_choice == 2) {
            /* å�� �˻��ϴ� �Լ� ȣ�� */
            search_book(book_name,auth_name,publ_name,borrowed,book_total_num);
        } else if (user_choice == 3) {
            /* å�� ������ �Լ� ȣ�� */
            borrow_book(borrowed,book_name,auth_name,publ_name);
        } else if (user_choice == 4) {
            /* å�� �ݳ��ϴ� �Լ� ȣ�� */
            return_book(borrowed,book_name,auth_name,publ_name);
        } else if (user_choice == 5) {
            /* ���α׷��� �����Ѵ�. */
            break;
        }
    }

  return 0;
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

int return_book(int * borrowed,char (*book_name)[30], char(*auth_name)[30], char(*publ_name)[30]){
    int book_num;
    printf("�ݳ��� å�� ��ȣ�� �Է��ϼ��� : ");
    scanf("%d", &book_num);
    borrowed[book_num]=0;
    printf("���������� �ݳ��߽��ϴ�. ������ å�� ��ȣ�� %d // å�� �̸��� %s // å�� ���ڴ� %s // å�� ���ǻ�� %s �Դϴ�.\n",book_num,book_name[book_num],auth_name[book_num],publ_name[book_num]);
    return 0;
}
//serach_book �����丵�� �����Լ�
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