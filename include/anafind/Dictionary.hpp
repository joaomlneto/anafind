
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
  // map letters to words composed by those letters
  std::unordered_map<std::string, std::set<std::string> > _words;

  std::string wordKey(const std::string& word);

 public:
  void loadWords(std::ifstream& input);
  void insertWord(const std::string& word);
  void print(void);
};

}  // namespace anafind

#endif  // INCLUDE_ANAFIND_DICTIONARY_HPP_
