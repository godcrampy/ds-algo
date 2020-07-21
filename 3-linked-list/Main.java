class Main {
  public static void main(String[] args) throws Exception {
    SinglyLinkedList sll = new SinglyLinkedList();
    sll.push(11);
    sll.push(12);
    sll.push(13);
    sll.printList();
    sll.removeAtIndex(0);
    sll.printList();
  }
}