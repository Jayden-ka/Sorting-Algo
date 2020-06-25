#include <stdio.h>
#include <stdlib.h>

#define size_array 100000 //I use it because i need 40mn to run 1M

void insertion_sort(long a[],long size){
    long key,j;
    int flag;
    for(long i=1;i<size;i++){
        key=a[i];
        j=i-1;
        while(j>=0 && key<a[j]){
            a[j+1]=a[j];
            --j;
        }
        a[j+1]=key;
    }

}
int main()
{
    long *a=malloc(sizeof(a)*size_array);
    for(long i=0;i<size_array;i++){
        a[i]= rand()%size_array;
    }
    insertion_sort(a,size_array);
    return 0;
}
