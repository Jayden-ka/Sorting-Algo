#include <stdio.h>
#include <stdlib.h>

#define size_array 100000

typedef struct node
{
    int data;
    struct node *next;
} node;
typedef struct list
{
    node *head;
} List;
List *create_list()
{
    List *list= (List*) malloc(sizeof(List));
    list->head=NULL;
}
void insert(List *list, int data)
{
    node *tmp=NULL;
    tmp= (node*) malloc(sizeof(node));
    tmp->data=data;
    tmp->next=list->head;
    list->head=tmp;
}
void print(List *list)
{
    node *tmp=list->head;
    while(tmp!=NULL)
    {
        printf("[%d]",tmp->data);
        tmp=tmp->next;
    }
    printf("\n");
}
void insertion_sort(List *a){
    node *tmp=a->head;
    node *insertionpointer=tmp;
    node *current= a->head;
    current=current->next;
    while(current != NULL){
        insertionpointer=tmp;
        while(insertionpointer != current){
            if(insertionpointer->data > current->data){
                int swap=current->data;
                current->data=insertionpointer->data;
                insertionpointer->data=swap;
            }
            else{
                insertionpointer=insertionpointer->next;
            }
        }
        current=current->next;
    }
}
int main()
{
    List *a=create_list();

    for(int i=0; i<size_array;i++){
        insert(a,rand()%size_array);
    }
    insertion_sort(a);
    return 0;
}
