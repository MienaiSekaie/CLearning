#include <stdio.h>

#define LEN 8
int a[LEN] = {5, 2, 4, 7, 1, 3, 2, 6};

int partition(int start, int end);
void quick_sort(int start, int end);

int main(void)
{
    quick_sort(0, LEN - 1);
    printf("%d %d %d %d %d %d %d %d\n", a[0], a[1], a[2], a[3], a[4], a[5], a[6], a[7]);
    return 0;
}

void quick_sort(int start, int end)
{
    int mid;
    if (end > start){
        mid = partition(start, end);
        quick_sort(start, mid - 1);
        quick_sort(mid + 1, end);
    }
}

int partition(int start, int end)
{
    int mid, val = a[start];
    int i, j = 0, k = 0;
    int left[LEN], right[LEN];

    for (i = start + 1; i < end + 1; i++)
        if (a[i] < val)
            left[j++] = a[i];
        else
            right[k++] = a[i];
    mid = start + j;
    for (i = start; i < mid; i++)
        a[i] = left[i - start];
    a[mid] = val;
    for (i = mid + 1; i < end + 1; i++)
        a[i] = right[i - mid - 1];

    return mid;
}
