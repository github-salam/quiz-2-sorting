#include <stdio.h>

int partition(int arr[], int l, int h)
{
    int pivot = arr[l];
    int i = l, j = h;

    while (i < j)
    {
        while (arr[i] <= pivot)
        {
            i++;
        }
        while (arr[j] > pivot)
        {
            j--;
        }
        if (i < j)
        {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[l];
    arr[l] = arr[j];
    arr[j] = temp;

    return j;
}

void quicksort(int arr[], int l, int h){
    int j;
    if(l < h){
        j = partition(arr, l, h);
        quicksort(arr, l, j - 1);
        quicksort(arr, j+1, h);
    }
}

int main()
{

    int arr[] = {9, 4, 3, 11, 15, 20, 2, 24, 30, 1, 35};
    int size = sizeof(arr) / sizeof(arr[0]);
    int l = 0, h = size - 1;

    quicksort(arr, l, h);

    for(int i = 0; i < size; i++){
        printf("%d \t", arr[i]);
    }
    printf("\n");
    return 0;
}