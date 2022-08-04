#include <stdio.h>
#include <stdlib.h>

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

int main()
{
    ll_insert_nth(2,1);
    ll_insert_nth(3,2);
    ll_insert_nth(5,1);
    ll_print();
    //activate_ll_demo();
    return 0;
}
