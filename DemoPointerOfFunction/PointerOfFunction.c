#include <stdio.h>
#include <stdbool.h>

void Swap(int *a, int *b);
void SortArray(int *arr, int size, bool state);
void Ascending(int *first, int *second);
void Descending(int *first, int *second);
void SortWithPointerOfFunction(int *arr, int size, void(*pCheck)(int *a, int *b));
int main(int argc, char const *argv[])
{
    //printf("%x\n", main);

    //Khai báo con trỏ hàm.
    // void (*pSwap)(int *a, int *b) = Swap;

    int arr[] = {0, 2, 1, 5, 3, 4, 6, 7, 9, 8};

    // SortArray(arr, 10, false);
    SortWithPointerOfFunction(arr, 10, Descending);

    printf("Mang sau khi sap xep:\n");
    for (int i = 0; i < 10; i++)
    {
        printf("%d\t", arr[i]);
    }
    
    return 0;
}

void Swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void SortArray(int *arr, int size, bool state)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (state && arr[i] > arr[j])
            {
                Swap(&arr[i], &arr[j]);
            }
            else if (!state && arr[i] < arr[j])
            {
                Swap(&arr[i], &arr[j]);
            }
        }
    }
}

void Ascending(int *first, int *second)
{
    if(*first > *second)
    {
        Swap(first, second);
    }
}

void Descending(int *first, int *second)
{
    if(*first < *second)
    {
        Swap(first, second);
    }
}

void SortWithPointerOfFunction(int *arr, int size, void(*pCheck)(int *a, int *b))
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            pCheck(&arr[i], &arr[j]);
        }
    }
}
