#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include<time.h>
#include "algorytmy.h"


int main()
{
    int n, sortOption, typeOption,i ;

    printf("How many numbers do you want to sort?\n");
    scanf("%d", &n);

    int *tab = (int*)malloc(sizeof(int)*n);

    printf("Please input which numbers you want to sort <-100,100>:\n");
    printf("1. Random numbers\n2. Numbers sorted descending\n3. Numbers sorted ascending\n");
    scanf("%d", &typeOption);

    printf("Which type of sorting do you want to use?\n");
    printf("1. Bubble sort \n2. Insert Sort\n3. Select Sort\n4. Shell Sort\n5. Heap Sort\n6. Quick Sort\n");
    scanf("%d",&sortOption);

    switch(typeOption)
    {
    case 1:
    {
        FILE* fp = fopen("danetest1.txt", "r");
        for(i = 0 ; i < n ; i++)
        {
            fscanf(fp, "%d", &tab[i]);
        }
        fclose(fp);
        break;
    }

    case 2:
    {
        FILE* fp = fopen("danetest2.txt", "r");
        for(i = 0 ; i < n ; i++)
        {
            fscanf(fp, "%d", &tab[i]);
        }
        fclose(fp);
        break;
    }
    case 3:
    {
        FILE* fp = fopen("danetest3.txt", "r");
        for(i = 0 ; i < n ; i++)
        {
            fscanf(fp, "%d", &tab[i]);
        }
        fclose(fp);
        break;
    }
    }

    clock_t start,stop;
    double time;
    start=clock();

    switch(sortOption)
    {
    case 1:
        bubble_Sort(tab,n);
        break;
    case 2:
        insert_Sort(tab,n);
        break;
    case 3:
        select_Sort(tab,n);
        break;
    case 4:
        shell_Sort(tab,n);
        break;
    case 5:
        heap_Sort(tab,n);
        break;
    case 6:
        quick_Sort(tab,0,n);
        break;
    }

    stop=clock();
    time=(double)(stop-start) / CLOCKS_PER_SEC;
    printf("Algorithm needed  %f seconds",time);
    free(tab);
}
