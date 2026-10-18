class Solution {
public:
    string countAndSay(int n) {
        string result = "1";

        for (int i = 2; i <= n; i++) {
            string next = "";
            int j = 0;

            while (j < result.length()) {
                int count = 1;

                while (j + 1 < result.length() &&
                       result[j] == result[j + 1]) {
                    count++;
                    j++;
                }

                next += to_string(count);
                next += result[j];
                j++;
            }

            result = next;
        }

        return result;
    }
};
