
#include <fstream>

#include <anafind/Dictionary.hpp>

int main() {
  printf("Hello world\n");
  anafind::Dictionary d;
  std::ifstream file("test/dictionaries/small.txt");
  d.loadWords(file);
  // d.insertWord("one");
  // d.insertWord("two");
  // d.insertWord("three");
  // d.print();
  return 0;
}
