#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#define SIZE 100
////////////////////////////////////////////
void Init(double *p, int n);
void QSort(double *p, int left, int right);
////////////////////////////////////////////
int main()
{
    int i;
    double *p = NULL;
    p = (double*)malloc(SIZE*sizeof(double));

    if(p == NULL)
    {
        printf("No memory.\n");
        exit(0);
    }

    Init(p, SIZE);
    QSort(p, 0, SIZE-1);

    for(i = 0; i < SIZE; i++)
    {
        printf("%g ", p[i]);
    }

    free(p);
    p = NULL;

    return 0;
}
////////////////////////////////////////////
void Init(double *p, int n)
{
    int i;
    srand((unsigned)time(NULL));
    for(i = 0; i < n; i++)
        p[i] = rand();
}
////////////////////////////////////////////
void QSort(double *p, int left, int right)
{
    int i = left;
    int j = right;
    double buf, middle = p[(left+right)/2];

    do
    {
        while(p[i] < middle && i < right)
            i++;
        while(middle < p[j] && j > left)
            j--;

        if(i <= j)
        {
            buf = p[i];
            p[i] = p[j];
            p[j] = buf;
            i++;
            j--;
        }

    }while(i <= j);

    if(left < j)
        QSort(p, left, j);
    if(i < right)
        QSort(p, i, right);

}
