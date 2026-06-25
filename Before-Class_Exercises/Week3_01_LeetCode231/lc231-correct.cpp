class Solution {
public:
    bool isPowerOfTwo(int n) {
        // power of two: positive AND has exactly one '1' bit
        // n & (n - 1) clears the lowest set bit; if the result is 0,
        // there was only one bit -> n is a power of two
        return n > 0 && (n & (n - 1)) == 0;
    }
};
