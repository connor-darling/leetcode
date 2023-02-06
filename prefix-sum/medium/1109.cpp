class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        std::vector<int> allReservations(n, 0);
        for (int i = 0; i < bookings.size(); ++i) {
            allReservations[bookings[i][0] - 1] += bookings[i][2];
            if (bookings[i][1] < n) {
                allReservations[bookings[i][1]] -= bookings[i][2];
            }
        }

        for (int i = 1; i < allReservations.size(); ++i) {
            allReservations[i] += allReservations[i - 1];
        }

        return allReservations;
    }
};
