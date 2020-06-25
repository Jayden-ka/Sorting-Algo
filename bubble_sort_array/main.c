#include <stdio.h>
#include <stdlib.h>

#define size_array 100000 //I use it because i need 40mn to run 1M

void bubble_sort(long a[],long size){
    long swap;
    int flag;
    for(long i=0;i<size-1;i++){
        flag=0;
        for(long j=0;j<size-i-1;j++){
            if(a[j]>a[j+1]){
                swap=a[j];
                a[j]=a[j+1];
                a[j+1]=swap;
                flag=1;
            }
        }
        if(flag==0) break;
    }

}
int main()
{
    long *a=malloc(sizeof(a)*size_array);
    for(long i=0;i<size_array;i++){
        a[i]= rand()%size_array;
    }
    bubble_sort(a,size_array);
    return 0;
}
