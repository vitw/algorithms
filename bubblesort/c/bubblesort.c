#include <stdio.h>

void swap(int *arr, int first, int second) {
  int tmp = arr[first];
  arr[first] = arr[second];
  arr[second] = tmp;
}

void print_array(int *arr, int len) {
  for (int i = 0; i < len - 1; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

void bubblesort(int *arr, int len) {
  for (int i = 0; i < len - 1; i++) {
    for (int j = 0; j < (len - 1) - i; j++) {
      if (arr[j] > arr[j + 1]) {
        swap(arr, j, j + 1);
        printf("swap(arr, %d, %d)\n", j, j + 1);
      }
    }
  }
}

int main() {
  int arr[] = {2, 8, 3, 1, 7, 4, 0};
  int arr_length = sizeof(arr) / sizeof(arr[0]);
  bubblesort(arr, arr_length);
  print_array(arr, arr_length);

  return 0;
}
