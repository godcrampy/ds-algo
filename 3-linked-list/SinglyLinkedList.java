class SinglyLinkedList {
  private class Node {
    public int val;
    public Node next = null;

    Node() {
      val = 0;
    }

    Node(int val) {
      this.val = val;
    }
  }

  private Node head;
  private Node tail;

  // @works
  public void push(int val) {
    Node n = new Node(val);
    if (head == null) {
      head = n;
    } else {
      tail.next = n;
    }
    tail = n;
  }

  // @works
  public void printList() {
    Node i = head;
    while (i != null) {
      System.out.printf("%d ", i.val);
      i = i.next;
    }
    System.out.println();
  }

  // @works
  public int pop() throws Exception {
    if (head == null) {
      throw new Exception("Error: Cannot pop from empty list");
    }

    if (head == tail) {
      int res = head.val;
      head = null;
      tail = null;
      return res;
    }

    Node temp = secondLastElement();
    int res = tail.val;
    tail = temp;
    temp.next = null;
    return res;
  }

  // @works
  private Node secondLastElement() throws Exception {
    if (head == null || head == tail) {
      throw new Exception("Error: List length less than two. Cannot fetch second last element");
    }

    Node i = head;
    while (i.next != tail) {
      i = i.next;
    }

    return i;
  }

  // @works
  public int size() {
    Node i = head;
    int size = 0;
    while (i != null) {
      i = i.next;
      ++size;
    }
    return size;
  }

  public void insertAtIndex(int index, int val) throws Exception {
    if (index < 0 || index > size()) {
      throw new Exception("Error: Index out of bounds");
    }
    Node d = new Node();
    d.next = head;
    Node i = d;
    Node n = new Node(val);

    while (index-- != 0) {
      i = i.next;
    }

    n.next = i.next;
    i.next = n;
    head = d.next;
  }

  // @works
  public int removeAtIndex(int index) throws Exception {
    if (index < 0 || index >= size()) {
      throw new Exception("Error: Index out of bounds");
    }
    Node d = new Node();
    d.next = head;
    Node i = d;

    while (index-- != 0) {
      i = i.next;
    }

    int res = i.next.val;
    i.next = i.next.next;
    head = d.next;
    return res;
  }
}
