#include <stdio.h>
#include <stdlib.h>
typedef struct Node{
    int data;
    struct Node * nextNode;
}Node;
Node* InsertNode(Node* current, int data);
void DestroyNode(Node* destroy, Node* head);
Node* CreateNode(int data);
void PrintNodeFrom(Node* from);
int CountNode(Node * head);
int SearchNode(Node * head, Node * search);
int main(){
    Node * Node1=CreateNode(100);
    Node * Node2=InsertNode(Node1,200);
    Node * Node3=InsertNode(Node2,300);
    Node * Node4=InsertNode(Node2,400);

    printf("%d\n",CountNode(Node1));
    printf("%d\n",SearchNode(Node1, Node3));
    // PrintNodeFrom(Node1);
    // DestroyNode(Node4,Node1);
    // PrintNodeFrom(Node1);
    // DestroyNode(Node3,Node1);
    // PrintNodeFrom(Node1);
    return 0;
}
int SearchNode(Node * head, Node * search){
    while(head){
        if(search==head)
            return search->data;
        head=head->nextNode;
    }
    return 0;
}
void DestroyNode(Node* destroy, Node* head){
    if(head==destroy){
        free(destroy);
        return;
    }
    Node * next=head;
    while(next){
        if(next->nextNode==destroy){
            next->nextNode=destroy->nextNode;
            free(destroy);
            return;
        }
        next=next->nextNode;
    }
}
void PrintNodeFrom(struct Node* from){
    while(from){
        printf("%d ",from->data);
        from=from->nextNode;
    }
    printf("\n");
}
Node * CreateNode(int data){
    Node * created=(Node *)malloc(sizeof(Node));
    created->data=data;
    created->nextNode=NULL;
    return created;
}

Node* InsertNode(Node* current, int data){
    Node * newNode=CreateNode(data);
    newNode->nextNode=current->nextNode;
    current->nextNode=newNode;
    return newNode;
}
int CountNode(Node * head){
    int cnt=0;
    while(head){
        cnt++;
        head=head->nextNode;
    }
    return cnt;
}