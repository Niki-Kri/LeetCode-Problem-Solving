class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        if (n <= 2) return n;
        int max_pts = 0;
        for (int i = 0; i < n; i++) {
            unordered_map<double, int> counts;
            for (int j = i + 1; j < n; j++) {
                double slope;
                if (points[i][0] == points[j][0]) {
                    slope = numeric_limits<double>::infinity();
                } else {
                    slope = (double)(points[j][1] - points[i][1]) / (points[j][0] - points[i][0]);
                    if (slope == -0.0) slope = 0.0;
                }
                counts[slope]++;
                max_pts = max(max_pts, counts[slope]);
            }
        }
        return max_pts + 1;
    }
};