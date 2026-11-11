#include <iostream>
#include <cstdlib>
#include <ctime>

// Project 3 — Johan Zuniga
// CIS 5 Week 12 · Fifty students
// Do not edit the boilerplate. It randomly generates 50 scores.
// Do not type scores or names into this file.

void countGrades(const int scores[], int n,
                 int& a, int& b, int& c, int& d, int& failing) {
  a = 0;
  b = 0;
  c = 0;z
  d = 0;
  failing = 0;

  if (n <= 0 || scores == nullptr) return;

  for (int i = 0; i < n; ++i) {
    if (scores[i] >= 90) {
      ++a;
    } else if (scores[i] >= 80) {
      ++b;
    } else if (scores[i] >= 70) {
      ++c;
    } else if (scores[i] >= 60) {
      ++d;
    } else {
      ++failing;
    }
  }
}

double average(const int scores[], int n) {
  if (n <= 0 || scores == nullptr) return 0.0;

  int sum = 0;
  for (int i = 0; i < n; ++i) {
    sum += scores[i];
  }

  return sum * 1.0 / n;
}

void officeHours(const int scores[], int n, int* failingCount) {
  int i = 0;
  int linesPrinted = 0;

  if (scores != nullptr) {
    while (i < n) {
      if (scores[i] < 60) {
        std::cout << "Student at index " << i
                  << " needs to come to office hours.\n";
        ++linesPrinted;
      }
      ++i;
    }
  }

  if (failingCount != nullptr) {
    *failingCount = linesPrinted;
  }
}

int main() {
  const int N = 50;
  int scores[N];

  // Do not edit this boilerplate. It randomly generates 50 scores.
  srand(static_cast<unsigned>(time(nullptr)));
  for (int i = 0; i < N; ++i) {
    scores[i] = rand() % 100;
  }

  for (int i = 0; i < N; ++i) {
    std::cout << "[" << i << "] " << scores[i] << "\n";
  }

  int a = 0;
  int b = 0;
  int c = 0;
  int d = 0;
  int failing = 0;
  countGrades(scores, N, a, b, c, d, failing);

  std::cout << "A: " << a << "\n";
  std::cout << "B: " << b << "\n";
  std::cout << "C: " << c << "\n";
  std::cout << "D: " << d << "\n";
  std::cout << "Failing: " << failing << "\n";
  std::cout << "Average: " << average(scores, N) << "\n";

  int lines = 0;
  officeHours(scores, N, &lines);
  std::cout << "Office hours: " << lines << "\n";

  return 0;
}
