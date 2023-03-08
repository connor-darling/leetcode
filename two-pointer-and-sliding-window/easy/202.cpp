class Solution {
public:
    bool isHappy(int n) {
        map<int, int> m;
        if (n == 1) return true;
        while (true) {
            int total = 0;
            while (n > 0) {
                total += pow(n % 10, 2);
                n /= 10;
            }

            if (total == 1) {
                return true;
            } 
            ++m[total];
            if (m[total] > 1) break;
            n = total;
        }
        return false;
    }
}
