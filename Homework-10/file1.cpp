#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <cctype>

// Function to remove punctuation marks from the beginning and end of a word
std::string cleanword(const std::string& word) 
{
    size_t start = 0, end = word.size();

    while (start < end && ispunct(word[start])) ++start;
    while (end > start && ispunct(word[end - 1])) --end;

    return word.substr(start, end - start);
}

int main() 
{
    std::string text;
    std::cout << "Please, enter a text that ends with a dot:\n";
    std::getline(std::cin, text);

    if (text.empty() || text.back() != '.') 
    {
        std::cerr << "Error: text must end with a dot.\n";
        return 1;
    }

    int n;
    std::cout << "Enter the length of the words (n): ";
    std::cin >> n;

    // Removing the last dot
    text.pop_back();

    std::istringstream iss(text);
    std::string word;
    std::vector<std::string> result;

    while (iss >> word) 
    {
        std::string cleaned = cleanword(word);
        if (cleaned.length() == n) 
        {
            result.push_back(cleaned);
        }
    }

    std::cout << "Here are words with the length of " << n << " letters:\n";
    for (const auto& w : result) 
    {
        std::cout << w << '\n';
    }

    return 0;
}
