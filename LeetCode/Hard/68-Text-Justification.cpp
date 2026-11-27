class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> result;
        int n = words.size();
        int i = 0;

        while (i < n) {
            int j = i;
            int totalChars = 0;

            // Find the maximum number of words that fit
            while (j < n &&
                   totalChars + words[j].size() + (j - i) <= maxWidth) {
                totalChars += words[j].size();
                j++;
            }

            int numWords = j - i;
            int spaces = maxWidth - totalChars;

            string line = "";

            // Last line or line containing only one word
            if (j == n || numWords == 1) {
                for (int k = i; k < j; k++) {
                    line += words[k];

                    if (k < j - 1) {
                        line += " ";
                    }
                }

                line += string(maxWidth - line.size(), ' ');
            }
            else {
                // Fully justify the line
                int gaps = numWords - 1;
                int spacesPerGap = spaces / gaps;
                int extraSpaces = spaces % gaps;

                for (int k = i; k < j; k++) {
                    line += words[k];

                    if (k < j - 1) {
                        int count = spacesPerGap;

                        if (k - i < extraSpaces) {
                            count++;
                        }

                        line += string(count, ' ');
                    }
                }
            }

            result.push_back(line);
            i = j;
        }

        return result;
    }
};
