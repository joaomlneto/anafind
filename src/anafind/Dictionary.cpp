
#include <iostream>
#include <fstream>
#include <map>

#include <anafind/Dictionary.hpp>

static const size_t NUM_LETTERS = 26;

namespace anafind {

std::string Dictionary::wordKey(const std::string& word) {
  // count the frequency of all characters in the word
  std::map<char, size_t> charCount;
  for (const char& c : word) {
    charCount[c]++;
  }
  // return a unique identifier based on the character count
  // FIXME(joaomlneto): using std::string for convenience; should be a map
  std::string summary;
  for (auto& [c, count] : charCount) {
    summary += c + std::to_string(count);
  }
  return summary;
}

void Dictionary::loadWords(const std::string& filename) {
  std::ifstream file(filename);
  loadWords(file);
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
  _words[wordKey(word)].insert(word);
}

std::string Dictionary::getFirstAnagramOf(const std::string& word) {
  // get set of anagrams for this word
  std::set<std::string> & anagrams = _words[wordKey(word)];
  // return the first (alphabetically) anagram string or empty string if none
  return (anagrams.size() > 0) ? *anagrams.begin() : "";
}

}  // namespace anafind
