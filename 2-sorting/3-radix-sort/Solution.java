import java.util.*;

class Solution {
  static void radixSort(int[] l) {
    Queue<Integer> zero = new ArrayDeque<>();
    Queue<Integer> one = new ArrayDeque<>();

    for (int i = 0; i < 31; ++i) {
      for (int n : l) {
        if ((n & (1 << i)) != 0) {
          one.add(n);
        } else {
          zero.add(n);
        }
      }

      int k = 0;
      while (!zero.isEmpty()) {
        l[k++] = zero.remove();
      }

      while (!one.isEmpty()) {
        l[k++] = one.remove();
      }
    }
  }

  public static void main(String[] args) {
    int[] l = new int[] {1, 8, 3, 2, 2, 7, 9, 5};
    radixSort(l);
    for (int i : l) System.out.println(i);
  }
}
