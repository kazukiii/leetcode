class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> word_list_set(wordList.begin(), wordList.end());
        unordered_map<string, int> word_to_distance;
        for (string& word: wordList) {
            word_to_distance[word] = numeric_limits<int>::max();
        }
        word_to_distance[beginWord] = 1;

        priority_queue<pair<int, string>, vector<pair<int, string>>, greater<pair<int, string>>> frontier;
        frontier.emplace(1, beginWord);
        while (!frontier.empty()) {
            auto [distance, word] = frontier.top();
            frontier.pop();
            if (distance > word_to_distance[word]) continue;

            for (int i = 0; i < word.size(); i++) {
                string next_word = word;
                for (char c = 'a'; c <= 'z'; c++) {
                    next_word[i] = c;
                    if (word_list_set.find(next_word) == word_list_set.end()) continue;
                    if (distance + 1 < word_to_distance[next_word]) {
                        word_to_distance[next_word] = distance + 1;
                        frontier.emplace(distance + 1, next_word);
                    }
                }
            }
        }
        return word_to_distance[endWord] == numeric_limits<int>::max() ? 0 : word_to_distance[endWord];
    }
};
