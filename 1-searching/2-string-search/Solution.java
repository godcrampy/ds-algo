class Main {
  public static int naiveSearch(String s, String n) {
    for (int i = 0; i < s.length() - n.length() + 1; ++i) {
      boolean found = true;
      for (int j = 0; j < n.length(); ++j) {
        if (s.charAt(i + j) != n.charAt(j)) {
          found = false;
          break;
        }
      }
      if (found) {
        return i;
      }
    }
    return -1;
  }

  public static int[] getLPS(String s) {
    int[] lps = new int[s.length()];

    int j = 0;
    lps[0] = 0;

    for (int i = 1; i < lps.length; ++i) {
      if (s.charAt(i) == s.charAt(j)) {
        lps[i] = j + 1;
        ++j;
      } else {
        while (j > 0 && s.charAt(i) != s.charAt(i)) {
          j = lps[j - 1];
        }

        if (s.charAt(i) != s.charAt(i)) {
          lps[i] = 0;
        } else {
          lps[i] = j + 1;
        }
      }
    }
    return lps;
  }

  public static int KMPSearch(String s, String n) {
    int[] lps = getLPS(s);
    int i = 0;
    int j = 0;

    while (i < s.length()) {
      if (s.charAt(i) == n.charAt(j)) {
        ++i;
        ++j;
      }

      if (j == n.length()) {
        return i - j;
      }

      if (i < s.length() && s.charAt(i) != n.charAt(j)) {
        if (j != 0) {
          j = lps[j - 1];
        } else {
          i++;
        }
      }
    }

    return -1;
  }

  public static void main(String[] args) {
    String s = "ABABDABACDABABCABAB";

    System.out.println(s.indexOf("ABABCABAB"));
    System.out.println(naiveSearch(s, "ABABCABAB"));
    System.out.println(KMPSearch(s, "ABABCABAB"));
    System.out.println(s.indexOf("ABD"));
    System.out.println(naiveSearch(s, "ABD"));
    System.out.println(KMPSearch(s, "ABD"));
    System.out.println(s.indexOf("ABDE"));
    System.out.println(naiveSearch(s, "ABDE"));
    System.out.println(KMPSearch(s, "ABDE"));
  }
}
