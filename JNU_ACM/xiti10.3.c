#include<stdio.h>
void input(int *p) {
    int i;
    for(i = 0; i < 10; i++) {
        scanf("%d", p++);
    }
}
 
void swap(int *p) {
    int i, j, max, min;
 
    for(max = *(p + 9), j = 0, i = 0; i < 9; i++) {
        if(*(p + i) > max) {
            max = *(p + i);
            j = i;
        }
    }
 
    max = *(p + 9);
    *(p + 9) = *(p + j);
    *(p + j) = max;
 
    for(min = *p, j = 0, i = 1; i <10; i++) {
        if(*(p + i) < min) {
            min = *(p + i);
            j = i;
        }
    }
 
    min = *p;
    *p = *(p + j);
    *(p + j) = min;
}
 
void display(int *p) {
    int i;
    for(i = 0; i < 10; i++)
        printf("%d ", *(p + i));
 
    printf("\n");
}
 
int main(void) {
    int p[10];
    input(p);
    swap(p);
    display(p);
    return 0;
}