#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

std::vector<int> int2vec(int i) {
  std::vector<int> vec;
  while (i > 0) {
    vec.push_back(i % 10);
    i /= 10;
  }
  return vec;
}

int vec2int(std::vector<int> vec) {
  int i = 0;
  for (size_t j = 0; j < vec.size(); j++) {
    i += vec[j] * pow(10, j);
  }
  return i;
}

int safeGet(std::vector<int> vec, size_t i) {
  return (i < vec.size()) ? vec[i] : 0;
}

int schoolAddition(std::vector<int> i1, std::vector<int> i2, int b) {
  size_t length = std::max(i1.size(), i2.size());
  int carry = 0;
  std::vector<int> ans(length + 1, 0);
  for (size_t i = 0; i < length + 1; i++) {
    int t1 = safeGet(i1, i);
    int t2 = safeGet(i2, i);
    int sum = t1 + t2 + carry;
    if (sum >= b) {
      carry = 1;
      sum = sum - b;
    } else {
      carry = 0;
    }
    ans[i] = sum;
  }
  return vec2int(ans);
}

int karatsubaMultiplication(std::vector<int> i1, std::vector<int> i2, int b) {
  int product = 0;
  return product;
}

int ratio(std::vector<int> i1, std::vector<int> i2, int b) {
  int quotient = 0;
  return quotient;
}

int main() {
  int i1, i2, b;
  std::cin >> i1 >> i2 >> b;
  std::vector<int> vec1 = int2vec(i1);
  std::vector<int> vec2 = int2vec(i2);
  int sum = schoolAddition(vec1, vec2, b);
  int product = karatsubaMultiplication(vec1, vec2, b);
  int quotient = ratio(vec1, vec2, b);
  std::cout << sum << " " << product << " " << quotient << std::endl;
  return 0;
}