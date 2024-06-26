class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> word_list_set(wordList.begin(), wordList.end());
        unordered_map<string, int> word_to_distance;
        for (string& word: wordList) {
            word_to_distance[word] = -1;
        }
        word_to_distance[beginWord] = 1;

        queue<string> word_to_visit;
        word_to_visit.emplace(beginWord);
        while (!word_to_visit.empty()) {
            string word = move(word_to_visit.front());
            word_to_visit.pop();
            for (int i = 0; i < word.size(); i++) {
                string next_word = word;
                for (char c = 'a'; c <= 'z'; c++) {
                    next_word[i] = c;
                    if (word_list_set.find(next_word) == word_list_set.end()) continue;
                    if (word_to_distance[next_word] != -1) continue;
                    word_to_distance[next_word] = word_to_distance[word] + 1;
                    word_to_visit.emplace(next_word);
                }
            }
        }
        return word_to_distance[endWord] == -1 ? 0 : word_to_distance[endWord];
    }
};
