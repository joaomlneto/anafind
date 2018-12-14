
#include <assert.h>

#include <fstream>

#include <anafind/Dictionary.hpp>

int main() {
  anafind::Dictionary d;
  d.loadWords("test/dictionaries/small.txt");
  assert(d.getFirstAnagramOf("lots") == "lost");
  assert(d.getFirstAnagramOf("word") == "");
  assert(d.getFirstAnagramOf("abt") == "bat");
  return 0;
}
