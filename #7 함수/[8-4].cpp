#include <stdio.h>
#define N 10

void selection_sort(int a[], int n);

int main(void)
{
  int a[N], i;

  printf("Enter %d numbers to be sorted: ", N);
  for (i = 0; i < N; i++)
    scanf("%d", &a[i]);

  selection_sort(a, N);

  printf("In sorted order:");
  for (i = 0; i < N; i++)
    printf(" %d", a[i]);
  printf("\n");

  return 0;
}

void selection_sort(int a[], int n)
{
  int i, largest = n - 1, temp;

  if (n == 1)
    return;

  for (i = 0; i < n - 1; i++)
    if (a[i] > a[largest])
      largest = i;

  if (largest < n - 1) {
    temp = a[n-1];
    a[n-1] = a[largest];
    a[largest] = temp;
  }

  selection_sort(a, n - 1);
}

