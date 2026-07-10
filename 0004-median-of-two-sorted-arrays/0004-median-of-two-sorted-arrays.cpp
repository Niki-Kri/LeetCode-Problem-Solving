#include <vector>
#include <algorithm>
#include <climits>
#include <stdexcept>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& A, vector<int>& B) {
        if (A.size() > B.size()) {
            return findMedianSortedArrays(B, A);
        }
        int m = A.size();
        int n = B.size();
        int lo = 0;
        int hi = m;
        while (lo <= hi) {
            int i = lo + (hi - lo) / 2;
            int j = (m + n + 1) / 2 - i;
            int l1 = (i == 0) ? INT_MIN : A[i - 1];
            int r1 = (i == m) ? INT_MAX : A[i];
            int l2 = (j == 0) ? INT_MIN : B[j - 1];
            int r2 = (j == n) ? INT_MAX : B[j];
            if (l1 <= r2 && l2 <= r1) {
                if ((m + n) % 2 == 0) {
                    return (max(l1, l2) + min(r1, r2)) / 2.0;
                } else {
                    return max(l1, l2);
                }
            } else if (l1 > r2) {
                hi = i - 1;
            } else {
                lo = i + 1;
            }
        }
        throw invalid_argument("Invalid input");
    }
};