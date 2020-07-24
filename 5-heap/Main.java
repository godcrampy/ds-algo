import java.util.*;

class Main {
  public static void main(String[] args) throws Exception {
    List<Integer> l = new ArrayList<>();
    l.add(4);
    l.add(7);
    l.add(9);
    l.add(1);
    l.add(5);
    l.add(12);
    l.add(7);
    l.add(2);
    MaxHeap m = new MaxHeap(l);
    System.out.println(m.getMax());
    var h = m.getHeap();
    for (int i : h) {
      System.out.printf("%d ", i);
    }
    System.out.println();
  }
}