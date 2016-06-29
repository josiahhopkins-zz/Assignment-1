#include <stdio.h>
#include <stdlib.h>

#define STRINGS_SIZE 32
#define DATA_SIZE 10000000

#define SWAP(a,b) {int temp; temp = a; a = b; b = temp;}

void quick_sort(int *, int);
void quick_sort_sub(int *, int, int);

void quick_sort(int *data, int data_size)
{
    quick_sort_sub(data, 0, data_size - 1);
}

void quick_sort_sub(int *data, int left, int right)
{
    int left_index = left;
    int right_index = right;
    int pivot = data[(left + right) / 2];

    while (left_index <= right_index) {
        for ( ; data[left_index] < pivot; left_index++)
            ;

        for ( ; data[right_index] > pivot; right_index--)
            ;

        if (left_index <= right_index) {
            SWAP(data[left_index], data[right_index]);
            left_index++;
            right_index--;
        }
    }

    if (right_index > left) {
        quick_sort_sub(data, left, right_index);
    }
    if (left_index < right) {
        quick_sort_sub(data, left_index, right);
    }
}

int main(int argc, char *argv[])
{
    int i = 0;
    int data[DATA_SIZE];
    char str[STRINGS_SIZE];

    FILE *fp;

    if ((fp = fopen("print", "r")) == NULL) {
        printf("file open error.\n");
        return 1;
    }

    while (fgets(str, STRINGS_SIZE, fp) != NULL) {
        data[i] = atoi(str);
        i++;
    }

    fclose(fp);

    quick_sort(data, DATA_SIZE);
    for (i = 0; i < DATA_SIZE; i++) {
        printf("%d\n", data[i]);
    }

    return 0;
}