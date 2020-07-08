class Main {
  static void quickSort(int[] arr, int l, int r) {
    if (l >= r) {
      return;
    }

    int pivot = (int) (Math.random() * (r - l + 1)) + l;
    int x = arr[pivot];
    arr[pivot] = arr[r];
    arr[r] = x;

    int j = l;
    for (int i = l; i < r; ++i) {
      if (arr[i] < x) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
        j++;
      }
    }

    int temp = arr[j];
    arr[j] = arr[r];
    arr[r] = temp;

    quickSort(arr, l, j - 1);
    quickSort(arr, j + 1, r);
  }

  static void quickSort(int[] arr) {
    quickSort(arr, 0, arr.length - 1);
  }

  public static void main(String[] args) {
    int[] arr = new int[] {1, 8, 3, 2, 2, 7, 9, 5};
    quickSort(arr);
    for (int i : arr) System.out.println(i);
  }
}
