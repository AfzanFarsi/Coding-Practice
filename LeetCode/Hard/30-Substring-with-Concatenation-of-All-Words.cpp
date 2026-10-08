class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result;

        int wordLen = words[0].length();
        int wordCount = words.size();
        int totalLen = wordLen * wordCount;

        if (s.length() < totalLen)
            return result;

        unordered_map<string, int> required;

        for (string word : words) {
            required[word]++;
        }

        for (int start = 0; start < wordLen; start++) {
            int left = start;
            int count = 0;

            unordered_map<string, int> current;

            for (int right = start; right + wordLen <= s.length(); right += wordLen) {
                string word = s.substr(right, wordLen);

                if (required.find(word) == required.end()) {
                    current.clear();
                    count = 0;
                    left = right + wordLen;
                    continue;
                }

                current[word]++;
                count++;

                while (current[word] > required[word]) {
                    string leftWord = s.substr(left, wordLen);
                    current[leftWord]--;
                    count--;
                    left += wordLen;
                }

                if (count == wordCount) {
                    result.push_back(left);

                    string leftWord = s.substr(left, wordLen);
                    current[leftWord]--;
                    count--;
                    left += wordLen;
                }
            }
        }

        return result;
    }
};
