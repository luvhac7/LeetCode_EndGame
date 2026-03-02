#include <iostream>
#include <string>
#include <algorithm>
#include <limits> // Required for std::numeric_limits

class Solution {
public:
    int reverse(int x) {
        // Use long long to prevent intermediate overflow during string conversion 
        // and allow checking against int limits
        long long reversed_val;

        try {
            std::string r = std::to_string(x);
            // Handle negative sign: find the start of digits
            size_t first_digit_pos = 0;
            if (!r.empty() && r[0] == '-') {
                first_digit_pos = 1;
            }

            // Reverse only the digits portion
            std::reverse(r.begin() + first_digit_pos, r.end());

            // Convert the reversed string to a long long to safely check against int limits
            reversed_val = std::stoll(r); 
        } catch (const std::out_of_range& e) {
            // If stoll throws out_of_range, the value is outside even long long limits (unlikely for int input) or larger than int.
            return 0; // Return 0 as per typical problem constraints for overflow
        } catch (...) {
            // Handle other exceptions like invalid_argument
            return 0;
        }

        // Check if the reversed long long value is outside the range of a 32-bit signed integer
        if (reversed_val > std::numeric_limits<int>::max() || reversed_val < std::numeric_limits<int>::min()) {
            return 0;
        }

        // Cast back to int if within range
        return static_cast<int>(reversed_val);
    }
};
