#include <stdio.h>

void print_array(int *arr, int arr_len) {
  for (int i = 0; i < arr_len; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

void swap(int *arr, int first, int second) {
  int tmp = arr[first];
  arr[first] = arr[second];
  arr[second] = tmp;
}

void quicksort(int *arr, int left, int right) {
  int pivot = right;
  int from_left = left;
  int from_right = right - 1;
  // printf("quicksort(arr, %d, %d)\n", left, right);

  // exit case
  if (from_left >= from_right) {
    if (arr[from_left] > arr[pivot]) {
      swap(arr, from_left, pivot);
    }
    return;
  }

  while (from_left < pivot) {
    if (arr[from_left] > arr[pivot]) {
      swap(arr, from_left, from_right);
      swap(arr, from_right, pivot);
      pivot--;
      from_right--;
    } else {
      from_left++;
    }
  }
  quicksort(arr, left, pivot - 1);
  quicksort(arr, pivot + 1, right);
}

int main() {

  int arr[] = {8, 5, 3, 6, 1, 19, 1, 0};
  int arr_len = sizeof(arr) / sizeof(arr[0]);
  printf("Array before sort: ");
  print_array(arr, arr_len);

  quicksort(arr, 0, arr_len - 1);

  printf("Array after sort:  ");
  print_array(arr, arr_len);
  return 0;
}
