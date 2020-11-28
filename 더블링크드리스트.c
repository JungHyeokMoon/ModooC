#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
    int data;
    struct Node * prev;
    struct Node * next;
}Node;
Node* InsertNode(Node* current, int data);
void DestroyNode(Node* destroy, Node* head);
Node* CreateNode(int data);
void PrintNodeFrom(Node* from);
void PrintNodeFromReverse(Node * from);
int CountNode(Node * head);
int SearchNode(Node * head, Node * search);
int main(){
    Node * Node1=CreateNode(100);
    Node * Node2=InsertNode(Node1,200);
    Node * Node3=InsertNode(Node2,300);
    Node * Node4=InsertNode(Node2,400);

    printf("%d \n",CountNode(Node1));
    PrintNodeFrom(Node1);
    PrintNodeFromReverse(Node3);
    DestroyNode(Node2,Node1);
    PrintNodeFrom(Node1);
    PrintNodeFromReverse(Node3);
    return 0;
}

void DestroyNode(Node* destroy, Node* head){
    if(CountNode(head)==1)
        free(destroy);
    
    destroy->prev->next=destroy->next;
    destroy->next->prev=destroy->prev;
    free(destroy);

}

Node* CreateNode(int data){
    Node * newNode=(Node * )malloc(sizeof(Node));
    newNode->data=data;
    newNode->prev=NULL;
    newNode->next=NULL;

    return newNode; 
}
Node* InsertNode(Node* current, int data){
    Node * newNode=CreateNode(data);
    //current가 맨앞일경우
    if(current->next==NULL){
        current->next=newNode;
        newNode->prev=current;
    }
    else{
        newNode->next=current->next;
        newNode->prev=current;
        current->next->prev=newNode;
        current->next=newNode;
    }
    return newNode;
}
void PrintNodeFrom(Node* from){
    while(from){
        printf("%d ",from->data);
        from=from->next;
    }
    printf("\n");
}
int CountNode(Node * head){
    int cnt=0;
    while(head){
        cnt++;
        head=head->next;
    }
    return cnt;
}


void PrintNodeFromReverse(Node * from){
    while(from){
        printf("%d ",from->data);
        from=from->prev;
    }
    printf("\n");
}