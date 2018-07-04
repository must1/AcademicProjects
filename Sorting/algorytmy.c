#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "algorytmy.h"

void shell_Sort(int *tab, int n)
{
    int i, j, increment, tmp;
    for(increment = n/2; increment > 0; increment /= 2)
    {
        for(i = increment; i < n; i++)
        {
            tmp = tab[i];
            for(j = i; j >= increment; j -= increment)
            {
                if(tmp < tab[j-increment])
                    tab[j] = tab[j-increment];
                else
                    break;
            }
            tab[j] = tmp;
        }
    }
}

void bubble_Sort(int *tab, int n)
{
    int j;
    bool swapped = true;
    int index =0;

    while(index < n-1 && swapped)
    {
        swapped = false;
        for(j = 0; j < n -1 ; j++)
            if(tab[j] > tab[j+1])
            {
                swap(tab,j,j+1);
                swapped = true;
            }
        index++;
    }
}

void insert_Sort(int *tab, int n)
{
    int i,x,j;

    for(i=1; i<n; i++)
    {
        x=tab[i];
        j=i-1;
        while(tab[j]>x && j>=0)
        {
            tab[j+1]=tab[j];
            j--;
        }
        tab[j+1]=x;
    }
}

void select_Sort(int *tab, int n)
{
    int minIndex,i,j;

    for(i=0; i<n; i++)
    {
        minIndex = i;

        for(j = i+1 ; j< n; j++)
        {
            if(tab[minIndex]>tab[j])
            {
                minIndex = j;
            }
        }
        if(minIndex!=i)
        {
            swap(tab,minIndex,i);
        }
    }
}

void swap(int *tab, int index1, int index2)
{
    int temp = tab[index1];
    tab[index1] = tab[index2];
    tab[index2] = temp;
}

void heap_Sort(int *tab, int n)
{
    int i;
    for( i = n / 2 - 1; i >= 0; i--)
    {
        checkMaxHeap(tab, n, i);
    }

    for( i = n - 1; i > 0; i--)
    {
        swap(tab, 0, i);
        --n;
        checkMaxHeap(tab, n, 0);
    }
}

void checkMaxHeap(int *tab, int heapSize, int parentIndex)
{
    int maximumIndex = parentIndex;
    int leftChild = parentIndex * 2 + 1;
    int rightChild = parentIndex * 2 + 2;

    if(leftChild < heapSize && tab[leftChild] > tab[maximumIndex])
    {
        maximumIndex = leftChild;
    }
    if(rightChild < heapSize && tab[rightChild] > tab[maximumIndex])
    {
        maximumIndex = rightChild;
    }
    if(maximumIndex != parentIndex)
    {
        swap(tab, maximumIndex, parentIndex);
        checkMaxHeap(tab, heapSize, maximumIndex);
    }
}

void quick_Sort(int *tab, int left, int right)
{
    int i=left,j=right,s,temp;

    s=tab[(i+j)/2];
    do
    {
        while (tab[i]<s)
            i++;
        while (tab[j]>s)
            j--;
        if(i<=j)
        {
            temp=tab[i];
            tab[i]=tab[j];
            tab[j]=temp;
            i++;

            j--;
        };
    }
    while(i<=j);
    if(j>left)
        quick_Sort(tab,left,j);
    if(i<right)
        quick_Sort(tab,i,right);
}
