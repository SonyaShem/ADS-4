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
        } else {
          int leftVal = arr[left];
          int rightVal = arr[right];
          int leftCount = 0;
          int rightCount = 0;
          while (left <= right && arr[left] == leftVal) {
            left++;
            leftCount++;
          }
          while (right >= left && arr[right] == rightVal) {
            right--;
            rightCount++;
          }
          count += leftCount * rightCount;
        }
      } else if (sum < value) {
        left++;
      } else {
        right--;
      }
  }
  return count;
}
int binarySearch(int *arr, int left, int right, int target) {
  while (left <= right) {
    int mid = (left + right) / 2;
    if (arr[mid] == target) {
      return 1;
    }
    if (arr[mid] < target) {
      left = mid + 1;
    }
    else {
      right = mid - 1;
    }
  }
  return 0;
}

int countPairs3(int *arr, int len, int value) {
  int count = 0;
  for (int i = 0; i < len - 1; i++) {
    int target = value - arr[i];
    int pos = binarySearch(arr, i + 1, len - 1, target);
    if (pos != -1) {
        int k = pos;
        while (k >= i + 1 && arr[k] == target) {
            count++;
            k--;
        }
        k = pos + 1;
        while (k < len && arr[k] == target) {
            count++;
            k++;
        }
    }
  }
  return count;
}
