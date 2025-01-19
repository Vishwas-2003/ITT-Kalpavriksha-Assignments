#include<stdio.h>
#include<stdlib.h>
struct Node{
    struct Node* next;
    int data;
};

struct Node* make_node(int n){
    struct Node* new_node=(struct Node*)malloc(sizeof(struct Node*));
    new_node->data=n;
    new_node->next=NULL;
    return new_node;
}

struct Node* add_in_beginning(struct Node* head,int n){
    if(head==NULL){
        head=make_node(n);
    }
    else{
        struct Node* temp=make_node(n);
        temp->next=head;
        head=temp;
    }
    return head;
}
struct Node* add_in_end(struct Node* head,int n){
    if(head==NULL){
        head=make_node(n);
    }
    else{
        struct Node* temp=head; 
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=make_node(n);
    }
    return head;
    
}
struct Node* add_at_k(struct Node* head,int n,int k){
    if(k==1){
        head=add_in_beginning(head,n);
    }
    else{
        struct Node* temp=head;
        while(temp!=NULL && temp->next!=NULL && k-1!=1){
            temp=temp->next;
            k--;
        }
        if(k-1==1){
            struct Node* new_node=make_node(n);
            new_node->next=temp->next;
            temp->next=new_node;
        }
        else{
            printf("Invalid index\n");
        }
    }
    return head;
}
void print_list(struct Node* head){
    printf("\nLinked List:");
    struct Node* temp=head;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}

void update_at_position(struct Node* head,int n,int position){
    struct Node* temp=head;
    while(temp!=NULL && temp->next!=NULL && position!=1){
        temp=temp->next;
        position--;
    }
    if(temp!=NULL && position==1){
        temp->data=n;
    }
    else{
        printf("Invalid Index\n");
    }
}
struct Node* delete_first_element(struct Node* head){
    if(head!=NULL){
        struct Node* temp=head->next;
        free(head);
        head=temp;
    }
    else{
        printf("No elements to delete\n");
    }
    return head;
}
struct Node* delete_last_element(struct Node* head){
    struct Node* temp=head;
    struct Node* prev=head;
    if(head!=NULL){
        while(temp->next!=NULL){
            prev=temp;
            temp=temp->next;
        }
        if(prev->next!=NULL){
            prev->next=NULL;
            free(temp);
        }
        else{
            head=NULL;
        }
    }
    else{
        printf("No elements to delete\n");
    }
    return head;
}
struct Node* delete_kth_element(struct Node* head,int k){
    if(k==1){
        head=delete_first_element(head);
    }
    else{
        struct Node* temp=head;
        struct Node* prev=NULL;
        while(temp!=NULL && temp->next!=NULL && k-1!=0){
            prev=temp;
            temp=temp->next;
            k--;
        }
        if(k-1==0){
            prev->next=temp->next;
            free(temp);
        }
        else{
            printf("Invalid Index\n");
        }
    }
    return head;
}
int main(){
    struct Node* head=NULL;
    int number_of_operations=0;
    printf("Number of operations:");
    scanf("%d",&number_of_operations);
    
    while(number_of_operations){
        printf("1 x: Add x to the end (x: is any number and pos: position)\n2 x: Add x at the beginning\n3 pos x: Add x at position pos (1-indexed)\n4: Display all elements\n5 pos x: Update the element at position pos to x\n6: Delete the first element\n7: Delete the last element\n8 pos: Delete the element at position pos (1-indexed)\n");
        int operation=0;
        scanf("%d",&operation);
                
        int n=0,k=0;
        switch(operation){
            case 1:
                printf("Enter Value:");
                scanf("%d",&n);
                head=add_in_end(head,n);
                break;
            case 2:
                printf("Enter Value:");
                scanf("%d",&n);
                head=add_in_beginning(head,n);
                break;
            case 3:
                printf("Enter Value and index:");
                scanf("%d%d",&n,&k);
                head=add_at_k(head,n,k);
                break;
            case 4:
                print_list(head);
                break;
            case 5:
                printf("Enter Value and index:");
                scanf("%d%d",&n,&k);
                update_at_position(head,n,k);
                break;
            case 6:
                head=delete_first_element(head);
                break;
            case 7:
                head=delete_last_element(head);
                break;
            case 8:
                printf("Enter index:");
                scanf("%d",&k);
                head=delete_kth_element(head,k);
                break;
            default:
                printf("Invalid Input\n");
                break;

        }
        number_of_operations--;
    }
    return 0;
}