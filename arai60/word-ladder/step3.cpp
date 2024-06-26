class Solution {
public:
    int ladderLength(string begin_word, string end_word, vector<string>& word_list) {
        unordered_set<string> word_list_set(word_list.begin(), word_list.end());
        unordered_map<string, int> word_to_distance;
        for (const auto& word : word_list) {
            word_to_distance[word] = -1;
        }
        word_to_distance[begin_word] = 1;

        queue<string> word_to_visit;
        word_to_visit.emplace(begin_word);
        while (!word_to_visit.empty()) {
            string word = move(word_to_visit.front());
            word_to_visit.pop();

            for (int i = 0; i < word.size(); i++) {
                string next_word = word;
                for (char c = 'a'; c <= 'z'; c++) {
                    next_word[i] = c;
                    if (next_word == word) continue;
                    if (word_list_set.find(next_word) == word_list_set.end()) continue;
                    if (word_to_distance[next_word] != -1) continue;

                    if (next_word == end_word) return word_to_distance[word] + 1;
                    word_to_distance[next_word] = word_to_distance[word] + 1;
                    word_to_visit.emplace(next_word);
                }
            }
        }
        return 0;
    }
};
