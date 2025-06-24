class Solution {
public:
    bool possible(vector<int>& arr, int days, int weight) {
        int sum = 0;
        int day = 1;
        for (int i : arr) {
            if (sum + i > weight) { 
                sum = i;
                day++;
                if (day > days) return false;
            } else {
                sum += i;
            }
        }
        return true;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int left = INT_MIN;
        int right = 0;
        for (int i : weights) {
            right += i;
            left = max(left, i);  
        }

        while (left <= right) {
            int mid = (left + right) / 2;
            if (possible(weights, days, mid)) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return left;
    }
};
