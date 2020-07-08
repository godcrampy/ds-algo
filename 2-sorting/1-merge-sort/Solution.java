class Main {
  static void mergeSort(int[] arr, int l, int r) {
    if (l >= r) {
      return;
    }

    int m = l + (r - l) / 2;
    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);

    int[] temp = new int[r - l + 1];

    for (int i = 0; i < temp.length; ++i) {
      temp[i] = arr[i + l];
    }

    int i = l;
    int j = m + 1;
    int k = l;

    while (i <= m || j <= r) {
      int a = i <= m ? temp[i - l] : Integer.MAX_VALUE;
      int b = j <= r ? temp[j - l] : Integer.MAX_VALUE;

      if (a < b) {
        arr[k++] = temp[i++ - l];
      } else {
        arr[k++] = temp[j++ - l];
      }
    }
  }

  static void mergeSort(int[] arr) {
    mergeSort(arr, 0, arr.length - 1);
  }

  public static void main(String[] args) {
    int[] arr = new int[] {1, 8, 3, 2, 2, 7, 9, 5};
    mergeSort(arr);
    for (int i : arr) System.out.println(i);
  }
}
