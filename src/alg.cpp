// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
  int count = 0;
  for (int i = 0; i < len ; i++) {
    for (int j = i + 1; j < len; j++) {
      if (arr[i] + arr[j] == value)
        count++;
    }
  }
  return count;
}
int countPairs2(int *array, int len, int target) {
    int count = 0;
    int upperBound = len - 1;

    while (upperBound > 0 && array[upperBound] > target) {
        upperBound--;
    }

    for (int l = 0; l < len; l++) {
        for (int r = upperBound; r > l; r--) {
            if (array[l] + array[r] == target) {
                count++;
            }
        }
    }
    return count;
}
int countPairs3(int *arr, int len, int value) {
  int count = 0;
  for (int i = 0; i < len; i++) {
    if (arr[i] >= value)
      continue;
    int target = value - arr[i];
    int left = i + 1;
    int right = len - 1;
    if (arr[right] < target || arr[left] > target)
      continue;
    while (left <= right) {
      int mid = left + (right - left) / 2;
    }
  }
}
