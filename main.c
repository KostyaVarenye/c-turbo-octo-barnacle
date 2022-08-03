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
    printf("\n");
}

int main()
{
    int n, i, x;
    printf("how many values would you like to create?\n");
    scanf("%d", &n);
    for(i=0; i<n; i++){
        printf("Enter the number \n");
        scanf("%d", &x);
        ll_insert(x);
        ll_print();
    }
    return 0;
}
