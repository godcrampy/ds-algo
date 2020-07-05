import java.util.*;

public class Main {
  public static void main(String[] args) {
    Solution s = new Solution();
    List<Integer> l = new ArrayList<>(Arrays.asList(2, 5, 6, 9, 13, 15, 15, 28, 30));

    System.out.println(s.binarySearch(l, 14));
    System.out.println(s.binarySearch(l, 28));
    System.out.println(Collections.binarySearch(l, 14));
    System.out.println(s.lowerBound(l, 14));
    System.out.println(s.lowerBound(l, 15));
    System.out.println(s.lowerBound(l, 16));
    System.out.println(s.upperBound(l, 14));
    System.out.println(s.upperBound(l, 15));
    System.out.println(s.upperBound(l, 30));
  }
}

class Solution {
  public int binarySearch(List<Integer> list, int n) {
    int l = 0, r = list.size() - 1;

    while (l < r) {
      int m = l + (r - l) / 2;
      if (list.get(m) > n) {
        r = m - 1;
      } else if (list.get(m) < n) {
        l = m + 1;
      } else {
        return m;
      }
    }

    return -1;
  }

  public int lowerBound(List<Integer> list, int n) {
    int pos = Collections.binarySearch(list, n);
    if (pos < 0) {
      pos = -(pos + 1);
    }
    while (pos - 1 > 0 && list.get(pos - 1) == n) {
      --pos;
    }

    return pos;
  }

  public int upperBound(List<Integer> list, int n) {
    int pos = Collections.binarySearch(list, n);
    if (pos < 0) {
      pos = -(pos + 1);
    }
    while (pos < list.size() && list.get(pos) == n) {
      ++pos;
    }

    return pos;
  }
}
