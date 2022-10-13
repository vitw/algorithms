#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_array(int *arr, int len) {
  for (int i = 0; i < len; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

void mergesort(int *arr, int left, int right) {
  int middle = (left + right) / 2;

  if (left >= right) {
    return;
  }
  // printf("mergesort(arr, %d, %d)\n", left, right);

  mergesort(arr, left, middle);
  mergesort(arr, middle + 1, right);

  int i = left;
  int j = middle + 1;
  int k = 0;
  int *res = malloc(sizeof(int) * (right - left + 1));
  while (1) {
    if (arr[i] > arr[j] && i <= middle && j <= right) {
      res[k] = arr[j];
      k++;
      j++;
    } else if (arr[i] < arr[j] && i <= middle && j <= right) {
      res[k] = arr[i];
      k++;
      i++;
    } else if (i <= middle) {
      res[k] = arr[i];
      k++;
      i++;
    } else if (j <= right) {
      res[k] = arr[j];
      k++;
      j++;
    } else {
      break;
    }
  }
  memcpy(arr + left, res, sizeof(int) * (right - left + 1));

  // print_array(arr, right + 1);
}

int main() {
  int arr[] = {2, 8, 3, 1, 7, 4, 0, 19, 1};
  int arr_len = sizeof(arr) / sizeof(arr[0]);
  printf("Array before sort: ");
  print_array(arr, arr_len);

  mergesort(arr, 0, arr_len - 1);

  printf("Array after sort:  ");
  print_array(arr, arr_len);
  return 0;
}
