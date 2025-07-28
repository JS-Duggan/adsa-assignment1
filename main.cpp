#include <iostream>
#include <vector>
#include <algorithm>

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

int schoolAddition(std::vector<int> i1, std::vector<int> i2, int b) {
  int sum;
  return sum;
}

int karatsubaMultiplication(std::vector<int> i1, std::vector<int> i2, int b) {
  int product;
  return product;
}

int ratio(std::vector<int> i1, std::vector<int> i2, int b) {
  int quotient;
  return quotient;
}

std::vector<int> int2vec(int i) {
  std::vector<int> vec;
  while (i > 0) {
    vec.push_back(i % 10);
    i /= 10;
  }
  std::reverse(vec.begin(), vec.end());
  return vec;
}