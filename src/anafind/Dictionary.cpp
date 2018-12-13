
#include <map>

#include <anafind/Dictionary.hpp>

static const size_t NUM_LETTERS = 26;

namespace anafind {

std::string Dictionary::wordKey(const std::string& word) {
  // printf("wordKey for word %s", word.c_str());
}

void Dictionary::loadWords(std::ifstream& input) {
  std::string word;
  while (std::getline(input, word)) {
    // convert word to all-lowercase
    std::transform(word.begin(), word.end(), word.begin(), ::tolower);
    insertWord(word);
  }
}

void Dictionary::insertWord(const std::string& word) {
  // // map letters to words composed by those letters
  // std::unordered_map<std::string, std::set<std::string> > _words;

  // count how many of each letter exists in the word
  std::map<char, size_t> charCount;
  for (const char& c : word) {
    charCount[c]++;
    printf("found a %c. counter is now %zu\n", c, charCount[c]);
  }
  printf("WORD: %s\n", word.c_str());
  for (auto& [char, count] : charCount) {
    printf("char %c -> %zu\n", char, count);
  }
  exit(0);
}

void Dictionary::print(void) {
  printf("DUMPING LIST");
}

}  // namespace anafind
