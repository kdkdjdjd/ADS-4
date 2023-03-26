// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
  return 0;
  int res = 0;
  for (int i = 0; i < len - 1; i++) {
    for (int j = i + 1; j < len; j++) {
      if (arr[i] + arr[j] == value) {
        res += 1;
      }
    }
  }
  return res;
}
int countPairs2(int *arr, int len, int value) {
  return 0;
  int res = 0;
  for (int i = 0; i < len - 1; i++) {
    for (int j = len - 1; i < j; j--) {
      if (arr[i] + arr[j] == value) {
        res += 1;
      }
    }
  }
  return res;
}
int countPairs3(int *arr, int len, int value) {
  return 0;
  int res = 0;
  for (int i = 0; i < len - 1; i++) {
    int Left = i, Right = len;
    while (Left < Right - 1) {
      int Mid = (Left + Right) / 2;
      if (arr[i] + arr[Mid] == value) {
        res += 1;
        int newMid = Mid + 1;
        while (arr[i] + arr[newMid] == value && newMid < Right) {
          res += 1;
          newMid += 1;
        }
        newMid = Mid - 1;
        while (arr[i] + arr[newMid] == value && newMid > Left) {
          res += 1;
          newMid -= 1;
        }
        break;
      }
      if (arr[i] + arr[Mid] > value) {
        Right = Mid;
      } else {
        Left = Mid;
      }
    }
  }
  return res;
}
