class Solution {
public:
    int largestAltitude(vector<int>& gain) {
       int max = 0;

       for (int i = 0; i < gain.size(); ++i) {
           gain[i] = gain[i - 1] + gain[i];
           max = (gain[i] > max) ? gain[i] : max;
       }

       return max; 
    }
};
