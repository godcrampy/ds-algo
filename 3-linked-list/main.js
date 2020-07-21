class SLLNode {
  val = 0;
  next = null;
  constructor(val = 0) {
    this.val = val;
  }
}

class SinglyLinkedList {
  head = null;
  last = null;

  /**
   * @param {SLLNode} head
   * @returns {void}
   * @works
   */
  constructor(head = null) {
    this.head = head;
    this.last = head;
  }

  /**
   * @returns {void}
   * @works
   */
  printList() {
    let head = this.head;
    while (head != null) {
      process.stdout.write(`${head.val} `);
      head = head.next;
    }
    console.log();
  }

  /**
   * @returns {SLLNode}
   * @works
   */
  _secondLastElement() {
    if (this.head == null || this.head == this.last) {
      throw 'Error: List length less than two. Cannot fetch second last element';
    }
    let head = this.head;
    while (head.next != this.last) {
      head = head.next;
    }

    return head;
  }

  /**
   * @returns {number}
   * @works
   */
  pop() {
    if (this.head == null) {
      throw 'Error: Cannot pop from empty list'
    }
    let res = this.last.val;
    if (this.head == this.last) {
      this.head = null;
      this.last = null;
      return res;
    }
    this.last = this._secondLastElement();
    this.last.next = null;
    return res;
  }

  /**
   * @returns {number}
   * @works
   */
  get length() {
    let head = this.head;
    let length = 0;
    while (head != null) {
      head = head.next;
      ++length;
    }
    return length;
  }

  /**
   * @param {number} val
   * @returns {void}
   * @works
   */
  push(val = 0) {
    let node = new SLLNode(val);
    if (this.head == null) {
      this.head = node;
    } else {
      this.last.next = node;
    }
    this.last = node;
  }

  /**
   * @works
   */
  insertAtIndex(index, val = 0) {
    let node = new SLLNode(val);
    if (index < 0 || index > this.length) {
      throw 'Error: index out of bounds';
    }
    let dummy = new SLLNode();
    dummy.next = this.head;
    let itr = dummy;
    while (index--) {
      itr = itr.next;
    }
    node.next = itr.next;
    itr.next = node;
    this.head = dummy.next;
  }

  /**
   * @param {number} index
   * @return {number} value at removed index
   */
  removeAtIndex(index = 0) {
    if (index < 0 || index >= this.length) {
      throw 'Error: index out of bounds';
    }
    let dummy = new SLLNode();
    dummy.next = this.head;
    let itr = dummy;
    while (index--) {
      itr = itr.next;
    }

    let res = itr.next.val;
    itr.next = itr.next.next;
    this.head = dummy.next;
    return res;
  }
}

let ll = new SinglyLinkedList();
ll.push(11);
ll.push(22);
ll.push(33);
ll.push(44);
ll.printList();
ll.removeAtIndex(2);
ll.printList();
