#include "substring.h"

std::vector<int> SearchBoyerMoore(const std::string& haystack,
                                  const std::string& needle) {
  std::vector<int> occurrences;

  int n = static_cast<int>(haystack.length());
  int m = static_cast<int>(needle.length());

  if (m > n) {
    return occurrences;
  }

  std::vector<int> badChar(256, -1);
  for (int i = 0; i < m; i++) {
    badChar[static_cast<int>(needle[i])] = i;
  }

  int shift = 0;
  while (shift <= (n - m)) {
    int j = m - 1;

    while (j >= 0 && needle[j] == haystack[shift + j]) {
      j--;
    }

    if (j < 0) {
      occurrences.push_back(shift);
      if (shift + m < n) {
        shift += m - badChar[static_cast<int>(haystack[shift + m])];
      } else {
        shift += 1;
      }
    } else {
      shift += std::max(1, j - badChar[static_cast<int>(haystack[shift + j])]);
    }
  }

  return occurrences;
}

std::vector<int> SearchRabinKarp(const std::string& haystack,
                                 const std::string& needle) {
  std::vector<int> occurrences;

  int n = static_cast<int>(haystack.length());
  int m = static_cast<int>(needle.length());

  if (m > n) {
    return occurrences;
  }

  int needleHash = 0;
  int haystackHash = 0;
  int power = 1, prime = 101;

  for (int i = 0; i < m; i++) {
    needleHash = (needleHash + needle[i]) % prime;
    haystackHash = (haystackHash + haystack[i]) % prime;

    if (i != 0) {
      power = (power * 2) % prime;
    }
  }

  for (int i = 0; i <= n - m; i++) {
    if (needleHash == haystackHash) {
      int j;
      for (j = 0; j < m; j++) {
        if (haystack[i + j] != needle[j]) {
          break;
        }
      }

      if (j == m) {
        occurrences.push_back(i);
      }
    }

    if (i < n - m) {
      haystackHash =
          (prime + haystackHash - haystack[i] * power % prime) % prime;
      haystackHash = (haystackHash * 2 + haystack[i + m]) % prime;
      if (haystackHash < 0) {
        haystackHash += prime;
      }
    }
  }

  return occurrences;
}

std::vector<int> SearchKnuthMorrisPratt(const std::string& haystack,
                                        const std::string& needle) {
  std::vector<int> occurrences;

  int n = static_cast<int>(haystack.length());
  int m = static_cast<int>(needle.length());

  if (m > n) {
    return occurrences;
  }

  std::vector<int> failure(m, 0);
  int j = 0;
  for (int i = 1; i < m; i++) {
    if (needle[i] == needle[j]) {
      failure[i] = j + 1;
      j++;
    } else {
      if (j != 0) {
        j = failure[j - 1];
        i--;
      } else {
        failure[i] = 0;
      }
    }
  }

  int i = 0;
  j = 0;

  while (i < n) {
    if (haystack[i] == needle[j]) {
      i++, j++;
      if (j == m) {
        occurrences.push_back(i - m);
        j = failure[j - 1];
      }
    } else {
      if (j != 0) {
        j = failure[j - 1];
      } else {
        i++;
      }
    }
  }

  return occurrences;
}