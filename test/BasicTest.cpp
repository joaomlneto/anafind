
#include <fstream>

#include <anafind/Dictionary.hpp>

int main() {
  anafind::Dictionary d;
  d.loadWords("test/dictionaries/small.txt");
  printf("anagram of %s => %s\n", "lots", d.getFirstAnagramOf("lots").c_str());
  printf("anagram of %s => %s\n", "word", d.getFirstAnagramOf("word").c_str());
  printf("anagram of %s => %s\n", "abt", d.getFirstAnagramOf("abt").c_str());
  return 0;
}
