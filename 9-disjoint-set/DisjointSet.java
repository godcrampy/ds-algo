class DisjointSet {
  private class Subset {
    public int rank;
    public int parent;
    Subset(int parent, int rank) {
      this.rank = rank;
      this.parent = parent;
    }

    Subset(int parent) {
      this(parent, 0);
    }
  }

  public int capacity;
  public Subset[] ds;
  DisjointSet(int capacity) {
    this.capacity = capacity;
    this.ds = new Subset[capacity];
    for (int i = 0; i < capacity; ++i) {
      ds[i] = new Subset(i);
    }
  }

  int find(int a) throws IndexOutOfBoundsException {
    if (a < 0 || a >= capacity)
      throw new IndexOutOfBoundsException();

    if (ds[a].parent == a)
      return a;

    return find(ds[a].parent);
  }

  void join(int a, int b) throws IndexOutOfBoundsException {
    if (a < 0 || a >= capacity || b < 0 || b >= capacity)
      throw new IndexOutOfBoundsException();

    int ar = find(a);
    int br = find(b);

    if (ds[ar].rank < ds[br].rank) {
      ds[ar].parent = br;
    } else if (ds[ar].rank > ds[br].rank) {
      ds[br].parent = ar;
    } else {
      ds[br].parent = ar;
      ds[ar].rank++;
    }
  }
}