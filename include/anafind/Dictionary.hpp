
#ifndef INCLUDE_ANAFIND_DICTIONARY_HPP_
#define INCLUDE_ANAFIND_DICTIONARY_HPP_

#include <algorithm>
#include <fstream>
#include <string>
#include <set>
#include <unordered_map>

namespace anafind {

class Dictionary {
 private:
  // map letters and their frequencies to corresponding words
  std::unordered_map<std::string, std::set<std::string> > _words;

  // return a common identifier for anagrams (encodes chars and frequency)
  std::string wordKey(const std::string& word);

 public:
  // load dictionary (words separated by newline)
  void loadWords(const std::string& filename);
  void loadWords(std::ifstream& input);

  // insert word in dictionary
  void insertWord(const std::string& word);

  // return first (alphabetically) anagram of word present in dictionary
  std::string getFirstAnagramOf(const std::string& word);
};

}  // namespace anafind

#endif  // INCLUDE_ANAFIND_DICTIONARY_HPP_
