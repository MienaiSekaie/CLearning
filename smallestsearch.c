#include <stdio.h>

#define LEN 8
int a[LEN] = {5, 2, 4, 7, 1, 3, 2, 6};

int s_search(void);
int sd_search(void);
int td_search(void);
int order_statistic(int start, int end, int k);
int partition(int start, int end);

int main(void)
{
    int min, sd_min, td_min;
    min = s_search();
    sd_min = sd_search();
    td_min = order_statistic(0, LEN - 1, 3);
    printf("%d %d %d %d %d %d %d %d\n", a[0], a[1], a[2], a[3], a[4], a[5], a[6], a[7]);
    printf("%d %d %d\n", min, sd_min, td_min);
    return 0;
}

int s_search(void)
{
    int min = 99999, i;
    for (i = 0; i < LEN; i++)
        if (min > a[i])
            min = a[i];
    return min;
}

int sd_search(void)
{
    int min, sd_min = 99999, i;
    min = s_search();
    for (i = 0; i < LEN; i++)
        if (a[i] > min && sd_min > a[i])
            sd_min = a[i];
    return sd_min;


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

int order_statistic(int start, int end, int k)
{
    int i;
    i = partition(start, end);
    if (k == a[i])
        return a[i];
    else if (k > a[i])
        return order_statistic(i + 1, end, k);
    else
        return order_statistic(start, i - 1, k);
}
