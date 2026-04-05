// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
  int count = 0;
  for (int i = 0; i < len; i++) {
      for (int j = i + 1; j < len; j++) {
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
              int n = right - left + 1;
              count += n * (n - 1) / 2;
              break;
          }
          int leftCount = 1;
          while (left + 1 < right && arr[left] == arr[left + 1]) {
              leftCount++;
              left++;
          }
          int rightCount = 1;
          while (right - 1 > left && arr[right] == arr[right - 1]) {
              rightCount++;
              right--;
          }
          count += leftCount * rightCount;
          left++;
          right--;
      } else if (sum < value) {
          left++;
      } else {
          right--;
      }
    }
    return count;
}
int binarySearch(int *arr, int left, int right, int target) {
  int first = -1, last = -1;
  int low = left, high = right - 1;
  while (low <= high) {
      int mid = low + (high - low) / 2;
      if (arr[mid] == target) {
          first = mid;
          high = mid - 1;
      }
      else if (arr[mid] < target) {
          low = mid + 1;
      }
      else {
          high = mid - 1;
      }
  }
  if (first == -1) return 0;
  low = first, high = right - 1;
  while (low <= high) {
    int mid = low + (high - low) / 2;
    if (arr[mid] == target) {
        last = mid;
        low = mid + 1;
    } else if (arr[mid] < target) {
        low = mid + 1;
    }
    else {
        high = mid - 1;
    }
  }
  return last - first + 1;
}

int countPairs3(int *arr, int len, int value) {
  int count = 0;
  for (int i = 0; i < len; i++) {
      int target = value - arr[i];
      int targetCount = binarySearch(arr, i + 1, len, target);
      count += targetCount;
  }
  return count;
}
