#include <iostream>
#include <string>
#include <vector>

using namespace std;

// This function checks if the given word is in the dictionary.
bool isInDictionary(string word) {
  // Open the dictionary file.
  ifstream dictionary("dictionary.txt");

  // Check if the file exists.
  if (!dictionary) {
    cout << "Error: Dictionary file not found." << endl;
    return false;
  }

  // Iterate over the words in the dictionary.
  for (string line; getline(dictionary, line);) {
    // If the word is found in the dictionary, return true.
    if (line == word) {
      return true;
    }
  }

  // The word was not found in the dictionary.
  return false;
}

// This function suggests possible correct spellings for the given misspelled word.
vector<string> suggestCorrectSpellings(string word) {
  // Create a vector to store the suggested spellings.
  vector<string> suggestions;

  // Check if the word is in the dictionary.
  if (isInDictionary(word)) {
    // The word is spelled correctly.
    suggestions.push_back(word);
    return suggestions;
  }

  // The word is misspelled.
  // Try the following corrections:

  // 1. Remove a character.
  for (int i = 0; i < word.length(); i++) {
    string correctedWord = word.substr(0, i) + word.substr(i + 1);
    if (isInDictionary(correctedWord)) {
      suggestions.push_back(correctedWord);
    }
  }

  // 2. Add a character.
  for (char c = 'a'; c <= 'z'; c++) {
    string correctedWord = word + c;
    if (isInDictionary(correctedWord)) {
      suggestions.push_back(correctedWord);
    }
  }

  // 3. Replace a character.
  for (int i = 0; i < word.length(); i++) {
    for (char c = 'a'; c <= 'z'; c++) {
      string correctedWord = word.substr(0, i) + c + word.substr(i + 1);
      if (isInDictionary(correctedWord)) {
        suggestions.push_back(correctedWord);
      }
    }
  }

  // Return the vector of suggested spellings.
  return suggestions;
}

int main() {
  // Get the misspelled word from the user.
  cout << "Enter a misspelled word: ";
  string misspelledWord;
  cin >> misspelledWord;

  // Suggest possible correct spellings.
  vector<string> suggestions = suggestCorrectSpellings(misspelledWord);

  // Print the suggested spellings.
  cout << "Suggested spellings: ";
  for (string suggestion : suggestions) {
    cout << suggestion << " ";
  }
  cout << endl;

  return 0;
}
