typedef struct BookInformation{
    char book_name[30];
    char auth_name[30];
    char publ_name[30];
    int borrowed;
}BookInformation;
int add_book(char (*book_name)[30], char(*auth_name)[30], char(*publ_name)[30],int * borrowed, int * book_total_num);
int register_book(BookInformation * library,int * book_total_num);
int search_book(char (*book_name)[30], char(*auth_name)[30], char(*publ_name)[30],int * borrowed,int book_total_num);
int search_book_struct(BookInformation * library,int book_total_num);
int borrow_book(int * borrowed,char (*book_name)[30], char(*auth_name)[30], char(*publ_name)[30]);
int borrow_book_struct(BookInformation * library);
int return_book(int * borrowed,char (*book_name)[30], char(*auth_name)[30], char(*publ_name)[30]);
int return_book_struct(BookInformation * library);

void search_book_helper(char (*searchInfo)[30], char * user_input,int book_total_num,int * borrwowed);
// void search_book_helper(char (*searchInfo)[30], char * user_input,int book_total_num,BookInformation * library);
void search_book_helper_struct(BookInformation * library, int user_choice, char * user_input,int book_total_num);
void print_book_list(BookInformation * library,int book_total_num);