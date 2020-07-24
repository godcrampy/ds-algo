import java.util.ArrayList;
import java.util.List;

class MaxHeap {
  private List<Integer> h;

  MaxHeap() {
    h = new ArrayList<>();
  }

  MaxHeap(List<Integer> l) throws Exception {
    h = l;
    heapify();
  }

  private void heapify() throws Exception {
    int from = (h.size() - 2) / 2;

    while (from-- != 0) {
      shiftDown(from);
    }
  }

  private void swap(int i, int j) throws Exception {
    if (i < 0 || i >= h.size() || j < 0 || j >= h.size()) {
      throw new Exception("Error: Index out of bounds for swapping");
    }

    int temp = h.get(i);
    h.set(i, h.get(j));
    h.set(j, temp);
  }

  private void shiftDown() throws Exception {
    int i = 0;

    while (2 * i + 1 < h.size()) {
      int a = h.get(2 * i + 1);
      int b = 2 * i + 2 < h.size() ? h.get(2 * i + 2) : Integer.MIN_VALUE;
      if (h.get(i) > Math.max(a, b))
        break;

      if (a < b) {
        swap(i, 2 * i + 2);
        i = 2 * i + 2;
      } else {
        swap(i, 2 * i + 1);
        i = 2 * i + 1;
      }
    }
  }

  private void shiftDown(int i) throws Exception {
    while (2 * i + 1 < h.size()) {
      int a = h.get(2 * i + 1);
      int b = 2 * i + 2 < h.size() ? h.get(2 * i + 2) : Integer.MIN_VALUE;
      if (h.get(i) > Math.max(a, b))
        break;

      if (a < b) {
        swap(i, 2 * i + 2);
        i = 2 * i + 2;
      } else {
        swap(i, 2 * i + 1);
        i = 2 * i + 1;
      }
    }
  }

  private void shiftUp() throws Exception {
    int i = h.size() - 1;

    while (i != 0 && h.get((i - 1) / 2) < h.get(i)) {
      int parent = (i - 1) / 2;
      swap(i, parent);
      i = parent;
    }
  }

  public int getMax() throws Exception {
    if (h.size() == 0)
      throw new Exception("Error: Cannot getMax from empty heap");
    return h.get(0);
  }

  public void insert(int x) throws Exception {
    h.add(x);
    shiftUp();
  }

  public int remove() throws Exception {
    if (h.size() == 0)
      throw new Exception("Error: Cannot remove from empty heap");
    int res = getMax();
    swap(0, h.size() - 1);
    h.remove(h.size() - 1);
    shiftDown();
    return res;
  }

  public List<Integer> getHeap() {
    return h;
  }
}
