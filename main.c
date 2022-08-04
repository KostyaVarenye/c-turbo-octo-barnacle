#include <stdio.h>
#include <stdlib.h>

void ll_insert(int);
void ll_insert(int);
void ll_print();
void ll_insert_nth(int, int);
void activate_ll_demo();
void activate_ll_insert_nth_demo();
void activate_ll_delete_nth(int);
void activate_ll_delete_nth_node_demo();
void ll_reverse();

struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

void ll_insert(int x){
    struct Node* tmp;
    tmp = (struct Node*)malloc(sizeof(struct Node*));
    tmp->data = x;
    tmp->next = NULL;
    if(head != NULL){
      tmp->next = head;
    }
    head = tmp;

}
void ll_print(){
    struct Node* tmp = head;
    while(tmp != NULL){
        printf("%d", tmp->data);
        tmp = tmp->next;
        printf(" -> ");
    }
    printf("NULL\n");
}
void ll_insert_nth(int data, int n){
    int i;
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node*));
    temp->data = data;
    temp->next = NULL;
    if(n == 1){
        temp->next = head;
        head = temp;
        return;
    }
    struct Node* temp1 = head;
    for(i = 0; i<n-2 ; i++){
        temp1 = temp1->next;
    }
    temp->next = temp1->next;
    temp1->next = temp;
}
void activate_ll_demo(){
    int n, i, x;
    printf("how many values would you like to create?\n");
    scanf("%d", &n);
    for(i=0; i<n; i++){
        printf("Enter the number \n");
        scanf("%d", &x);
        ll_insert(x);
        ll_print();
    }
}
void activate_ll_insert_nth_demo(){
    ll_insert_nth(2,1);
    ll_insert_nth(3,2);
    ll_insert_nth(5,1);
    ll_insert_nth(5,3);
    ll_insert_nth(19,2);
    ll_insert_nth(77,1);

    ll_print();
}
void activate_ll_delete_nth(int n){
    if(!head){
        // if head == NULL do nothing.
        return;
    }
    struct Node* temp1 = head;
    if(n == 1){
        head = temp1->next;
        free(temp1);
        return;
    }

    int i;
    for(i=0; i<n-2;i++){
        // advance until you reach node n-1
        temp1 = temp1->next;
    }
    struct Node* temp2 = temp1->next;
    temp1->next = temp1->next->next;
    free(temp2);
}
void activate_ll_delete_nth_node_demo(){
    activate_ll_insert_nth_demo(); //77 -> 5 -> 19 -> 2 -> 5 -> 3 -> NULL
    ll_print();
    activate_ll_delete_nth(2);//77 -> 19 -> 2 -> 5 -> 3 -> NULL
    ll_print();
    activate_ll_delete_nth(4);//77 -> 19 -> 2 -> 3 -> NULL
    ll_print();
    activate_ll_delete_nth(2);//77 -> 2 -> 3 -> NULL
    ll_print();
    activate_ll_delete_nth(1);//2 -> 3 -> NULL
    ll_print();
    activate_ll_delete_nth(1);//3 -> NULL
    ll_print();
    activate_ll_delete_nth(1);//NULL
    ll_print();
    activate_ll_delete_nth(1);//NULL
    ll_print();
}
void ll_reverse(){
    if(!head){
        return;
    }
    struct Node *curr, *prev, *next;
    curr = head;
    prev = NULL;

    while(curr){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
}
int main()
{
    //activate_ll_delete_nth_node_demo();
    activate_ll_demo();
    ll_reverse();
    ll_print();
    return 0;
}
