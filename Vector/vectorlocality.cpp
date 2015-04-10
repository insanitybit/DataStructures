#include <vector>
#include <chrono>
#include <iostream>
#include <stdlib.h>
#include <algorithm>

using namespace std;

#define size 50000

int main() {
  std::chrono::time_point<std::chrono::steady_clock> start, end;
  std::chrono::duration<double> elapsed_seconds;

  vector<size_t> v(size);

  // worst case loop
  // for (size_t i = 0; i < size; i++) {
  //   v[i] = i;
  // }

  // general case

  srand(50);

  size_t val = 0;
  for (size_t i = 0; i < size; i++) {
    val = (rand() % size);
    v[i] = val;
  }


  auto beg = v.begin();
  auto endi = v.end();

  sort(beg,endi);
  cout << "built structure\n";
  start = std::chrono::steady_clock::now();

  auto found = find(beg, endi, size);
  // bool found = binary_search(beg, endi, size);

  end = std::chrono::steady_clock::now();
  elapsed_seconds = end-start;
  cout << "Search for item took ::  " << elapsed_seconds.count() * 1000 << "ms\n";
  // cout << boolalpha << found << "\n";
  cout << *found  << "\n";
  return 0;
}
