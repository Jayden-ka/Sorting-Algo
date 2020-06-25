#include <stdio.h>
#include <stdlib.h>

#define size_array 100000

typedef struct node
{
    long data;
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
void insert(List *list, long data)
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
void bubble_sort(List *a, long size){
    node *p, *q;
    long swap;
    int flag;
    for(long i=0;i<size-1;i++){
        p=a->head;
        q=p->next;
        flag=0;
        while(q!=NULL){
            if(p->data>q->data){
                swap = p->data;
                p->data=q->data;
                q->data=swap;
                p=p->next;
                q=q->next;
                flag=1;
            }
            else{
                p=p->next;
                q=q->next;
            }
        }
        if(flag==0) break;
    }
}
int main()
{
    List *a=create_list();

    for(long i=0; i<size_array;i++){
        insert(a,rand()%size_array);
    }
    bubble_sort(a,size_array);
    return 0;
}
