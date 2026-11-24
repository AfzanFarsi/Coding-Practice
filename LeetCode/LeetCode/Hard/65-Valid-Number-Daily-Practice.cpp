class Solution {
public:
    bool isNumber(string s) {
        bool digit = false;
        bool dot = false;
        bool exponent = false;

        for (int i = 0; i < s.size(); i++) {

            if (isdigit(s[i])) {
                digit = true;
            }

            else if (s[i] == '+' || s[i] == '-') {
                if (i != 0 && s[i - 1] != 'e' && s[i - 1] != 'E') {
                    return false;
                }
            }

            else if (s[i] == '.') {
                if (dot || exponent) {
                    return false;
                }
                dot = true;
            }

            else if (s[i] == 'e' || s[i] == 'E') {
                if (exponent || !digit) {
                    return false;
                }
                exponent = true;
                digit = false;
            }

            else {
                return false;
            }
        }

        return digit;
    }
};
