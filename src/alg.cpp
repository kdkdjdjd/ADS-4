// Copyright 2021 NNTU-CS
int cbinsearch(int* arr, int size, int value) {
    int res = 0;
    int left = 0;
    int right = size - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (value == arr[mid]) {
            int flag = mid + 1;
            while (value == arr[mid]) {
                mid--;
                res++;
            }
            while (value == arr[flag]) {
                flag++;
                res++;
            }
            return res;
        } else if (value < arr[mid]) {
            right = mid - 1;
        } else if (value > arr[mid]) {
            left = mid + 1;
        }
    }
    return 0;
}

int countPairs1(int *arr, int len, int value) {
  return 0;
    int res = 0;
    for (int i = 0; i < len - 1; i++) {
        for (int j = i + 1; j < len; j++) {
            if (arr[i] + arr[j] == value) {
                res++;
            }
        }
    }
    return res;
}

int countPairs2(int *arr, int len, int value) {
  return 0;
    int res = 0;
    int left = 0;
    int right = len - 1;
    while (left < right) {
        for (int i = left + 1; i <= right; i++) {
            if (arr[left] + arr[i] == value) {
                res++;
            }
        }
        left++;
        for (int j = right - 1; j > left; j--) {
            if (arr[right] + arr[j] == value) {
                res++;
            }
        }
        right--;
    }
    return res;
}

int countPairs3(int *arr, int len, int value) {
  return 0;
    int i = 0;
    int res = 0;
    int res2 = 0;
    for (i; arr[i] < value / 2; i++) {
        int flag = i + 1;
        res += cbinsearch(arr + flag, len - flag, value - arr[i]);
    }
    for (i; arr[i] == value / 2; i++) {
        int flag = i + 1;
        res2 += cbinsearch(arr + flag, len - flag, value - arr[i]);
    }
    res2 /= 2;
    return res + res2;
}
