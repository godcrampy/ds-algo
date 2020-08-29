class Main {
  public static void main(String[] args) {
    DisjointSet ds = new DisjointSet(10);

    ds.join(2, 1);
    ds.join(4, 3);
    ds.join(8, 4);
    ds.join(9, 3);
    ds.join(6, 5);

    System.out.println(ds.find(9));
    System.out.println(ds.find(8));
    System.out.println(ds.find(2));
  }
}