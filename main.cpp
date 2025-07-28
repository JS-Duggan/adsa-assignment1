#include <iostream>

int main() {
  int i1, i2, b;
  std::cin >> i1 >> i2 >> b;
  int sum = schoolAddition(i1, i2, b);
  int product = karatsubaMultiplication(i1, i2, b);
  int quotient = ratio(i1, i2, b);
  std::cout << sum << " " << product << " " << quotient << std::endl;
  return 0;
}

int schoolAddition(int i1, int i2, int b) {
  int sum;
  return sum;
}

int karatsubaMultiplication(int i1, int i2, int b) {
  int product;
  return product;
}

int ratio(int i1, int i2, int b) {
  int quotient;
  return quotient;
}