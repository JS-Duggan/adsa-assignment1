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

std::vector<int> schoolSubtraction(std::vector<int> i1, std::vector<int> i2, int b) {
  size_t length = std::max(i1.size(), i2.size());
  int borrow = 0;
  std::vector<int> ans(length, 0);

  for (size_t i = 0; i < length; i++) {
    int t1 = safeGet(i1, i);
    int t2 = safeGet(i2, i);
    int diff = t1 - t2 - borrow;

    if (diff < 0) {
      diff += b;
      borrow = 1;
    } else {
      borrow = 0;
    }

    ans[i] = diff;
  }
  if(!ans.empty() && ans.back() == 0) ans.pop_back();
  return ans;
}

std::vector<int> schoolMultiplication(std::vector<int> i1, std::vector<int> i2, int b) {
  size_t length = std::max(i1.size(), i2.size());
  std::vector<int> ans(length + 1, 0);

  for (size_t i = 0; i < i1.size(); ++i) {
    int carry = 0;
    for (size_t j = 0; j < i2.size(); ++j) {
      int product = i1[i] * i2[j] + ans[i + j] + carry;
      ans[i + j] = product % b;
      carry = product / b;
    }
    if (carry > 0) {
      ans[i + i2.size()] += carry;
    }
  }

  if(!ans.empty() && ans.back() == 0) ans.pop_back();
  return ans;
}

std::vector<int> karatsubaMultiplication(std::vector<int> i1, std::vector<int> i2, int b) {
  if (i1.size() == 0 || i2.size() == 0) return {0};
  if (i1.size() == 1 || i2.size() == 1) return schoolMultiplication(i1, i2, b);

  // get value for m
  int m = std::max(i1.size(), i2.size());
  int m2 = floor(m / 2);

  // pad vectors
  i1.resize(m, 0);
  i2.resize(m, 0);

  // split vector in half
  std::vector<int> x0(i1.begin(), i1.begin() + m2);
  std::vector<int> x1(i1.begin() + m2, i1.end());

  std::vector<int> y0(i2.begin(), i2.begin() + m2);
  std::vector<int> y1(i2.begin() + m2, i2.end());

  // recursive call to calculate values
  std::vector<int> z0 = karatsubaMultiplication(x0, y0, b);
  std::vector<int> z2 = karatsubaMultiplication(x1, y1, b);
  std::vector<int> z1_intermediary = karatsubaMultiplication(schoolAddition(x0, x1, b), schoolAddition(y0, y1, b), b);
  std::vector<int> z1 = schoolSubtraction(schoolSubtraction(z1_intermediary, z0, b), z2, b);

  // right shift vectors
  z2.insert(z2.begin(), m2 * 2, 0);
  z1.insert(z1.begin(), m2, 0);

  // sum together
  std::vector<int> ans = schoolAddition(z2, schoolAddition(z1, z0, b), b);
  while (true) {
    if(!ans.empty() && ans.back() == 0) ans.pop_back();
    else break;
  }
  return ans;
}

int ratio(std::vector<int> i1, std::vector<int> i2, int b) {
  int quotient = 0;
  return quotient;
}

int main() {
  std::string i1, i2;
  int b;
  std::cin >> i1 >> i2 >> b;
  std::vector<int> vec1 = string2vec(i1);
  std::vector<int> vec2 = string2vec(i2);
  std::vector<int> sum = schoolAddition(vec1, vec2, b);
  std::vector<int> product = karatsubaMultiplication(vec1, vec2, b);
  // int quotient = ratio(vec1, vec2, b);
  outputVec(sum);
  std::cout << " ";
  outputVec(product);
  std::cout << " " << 0 << std::endl;
  return 0;
}