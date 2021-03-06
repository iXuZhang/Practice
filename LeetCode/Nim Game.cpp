// Nim Game
class Solution {
public:
    // Time: O(1), Space: O(1)
    // 1 win
    // 2 win
    // 3 win
    // 4 lose
    // 5 = 1 + 4 win
    // 6 = 2 + 4 win
    // 7 = 3 + 4 win
    // 8 lose
    bool canWinNim(int n) {
        if(n < 0) throw invalid_argument("the input is less than 0");
        return n%4;
    }
};