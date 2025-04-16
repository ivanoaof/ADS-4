// Copyright 2021 NNTU-CS
#include <iostream>
#include <algorithm>

int countPairs1(int *arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < len; ++i) {
        for (int j = i + 1; j < len; ++j) {
            if (arr[i] + arr[j] == value) {
                count++;
            }
        }
    }
    return count;
}

int countPairs2(int *arr, int len, int value) {
    int count = 0;
    int left = 0;
    int right = len - 1;
    while (left < right) {
        int sum = arr[left] + arr[right];
        if (sum == value) {
            if (arr[left] == arr[right]) {
                count += (right - left + 1) * (right - left) / 2;
                break;
            }
            int left_val = arr[left];
            int right_val = arr[right];
            int left_count = 1;
            int right_count = 1;
            while (left + 1 < right && arr[left + 1] == left_val) {
                left++;
                left_count++;
            }
            while (right - 1 > left && arr[right - 1] == right_val) {
                right--;
                right_count++;
            }
            count += left_count * right_count;
            left++;
            right--;
        }else if (sum < value) {
            left++;
        }else {
            right--;
        }
    }
    return count;
}

int findFirst(int *arr, int start, int end, int target) {
    while (start <= end) {
        int mid = start + (end - start) / 2;
        if (arr[mid] < target) {
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }
    return start;
}

int findLast(int *arr, int start, int end, int target) {
    while (start <= end) {
        int mid = start + (end - start) / 2;
        if (arr[mid] <= target) {
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }
    return end;
}

int countPairs3(int *arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < len - 1; ++i) {
        int target = value - arr[i];
        int first = findFirst(arr, i + 1, len - 1, target);
        int last = findLast(arr, i + 1, len - 1, target);
        if (first <= last) {
            count += last - first + 1;
        }
    }
    return count;
}
