#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <queue>
#include <vector>
#include <cctype>

struct CompareWords {
    bool operator()(const std::pair<std::string, int>& a, const std::pair<std::string, int>& b) {
        if (a.second != b.second) {
            return a.second < b.second;
        }
        return a.first > b.first;
    }
};

int main() {
    std::ifstream file("input.txt");
    if (!file.is_open()) {
        std::cerr << "Error: Could not open file 'input.txt'\n";
        return 1;
    }

    std::stringstream buffer;
    buffer << file.rdbuf();
    std::string phrase = buffer.str();
    file.close();

    std::string separators = " ,?!.";
    std::map<std::string, int> wordCountMap;

    size_t start = phrase.find_first_not_of(separators);

    while (start != std::string::npos) {
        size_t end = phrase.find_first_of(separators, start);
        std::string word = phrase.substr(start, end - start);

        for (char& c : word) {
            c = std::tolower(c);
        }

        wordCountMap[word]++;
        start = phrase.find_first_not_of(separators, end);
    }

    std::priority_queue<
        std::pair<std::string, int>,
        std::vector<std::pair<std::string, int>>,
        CompareWords
    > pq;

    for (const auto& pair : wordCountMap) {
        pq.push(pair);
    }

    while (!pq.empty()) {
        std::pair<std::string, int> topElement = pq.top();
        std::cout << topElement.first << " => " << topElement.second << "\n";
        pq.pop();
    }

    return 0;
}