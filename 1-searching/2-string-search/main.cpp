#include <iostream>
#include <string>
#include <vector>

using namespace std;

int naiveSearch(const string &str, const string &needle) {
  for (int i = 0; i < str.length() - needle.length() + 1; ++i) {
    bool found = true;
    for (int j = 0; j < needle.length(); ++j) {
      if (str[i + j] != needle[j]) {
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

vector<int> getLPS(const string &s) {
  vector<int> lps(s.length());
  int j = 0;
  lps[0] = 0;
  for (int i = 1; i < s.length(); ++i) {
    if (s[i] == s[j]) {
      lps[i] = j + 1;
      ++j;
    } else {
      while (j != 0 && s[i] != s[j]) {
        j = lps[j - 1];
      }
      if (s[i] != s[j]) {
        lps[i] = 0;
      } else {
        lps[i] = j + 1;
      }
    }
  }

  return lps;
}

int kmpSearch(const string &s, const string &needle) {
  auto lps = getLPS(needle);

  int i = 0;
  int j = 0;
  while (i < s.length()) {
    if (s[i] == needle[j]) {
      ++i;
      ++j;
    }

    if (j == needle.length()) {
      return i - j;
    }

    if (i < s.length() && s[i] != needle[j]) {
      if (j != 0) {
        j = lps[j - 1];
      } else {
        i++;
      }
    }
  }
  return -1;
}

int main() {
  string s = "ABABDABACDABABCABAB";
  cout << s.find("ABABCABAB") << endl;
  cout << naiveSearch(s, "ABABCABAB") << endl;
  cout << kmpSearch(s, "ABABCABAB") << endl;

  cout << s.find("ABD") << endl;
  cout << naiveSearch(s, "ABD") << endl;
  cout << kmpSearch(s, "ABD") << endl;

  cout << s.find("ABDE") << endl;
  cout << naiveSearch(s, "ABDE") << endl;
  cout << kmpSearch(s, "ABDE") << endl;

  return 0;
}
