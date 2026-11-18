class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> numbers;

        int fact = 1;

        for (int i = 1; i <= n; i++) {
            numbers.push_back(i);
            fact *= i;
        }

        k--; // Convert to 0-based indexing

        string result;

        for (int i = n; i >= 1; i--) {
            fact /= i;

            int index = k / fact;

            result += to_string(numbers[index]);

            numbers.erase(numbers.begin() + index);

            k %= fact;
        }

        return result;
    }
};
