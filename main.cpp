#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>

std::vector<int> string2vec(std::string i) {
  std::vector<int> vec;
  for (auto it = i.rbegin(); it != i.rend(); it++) {
    vec.push_back(*it - '0');
  }
  return vec;
}

void outputVec(std::vector<int> vec) {
  for (auto it = vec.rbegin(); it != vec.rend(); it++) {
    std::cout << *it;
  }
}

int safeGet(std::vector<int> vec, size_t i) {
  return (i < vec.size()) ? vec[i] : 0;
}

std::vector<int> schoolAddition(std::vector<int> i1, std::vector<int> i2, int b) {
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
  if(!ans.empty() && ans.back() == 0) ans.pop_back();
  return ans;
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
  std::string i1, i2;
  int b;
  std::cin >> i1 >> i2 >> b;
  std::cout << i1 << " " << i2 <<  " " << b << std::endl;
  std::vector<int> vec1 = string2vec(i1);
  std::vector<int> vec2 = string2vec(i2);
  std::vector<int> sum = schoolAddition(vec1, vec2, b);
  // int product = karatsubaMultiplication(vec1, vec2, b);
  // int quotient = ratio(vec1, vec2, b);
  outputVec(sum);
  std::cout << " " << 0 << " " << 0 << std::endl;
  return 0;
}