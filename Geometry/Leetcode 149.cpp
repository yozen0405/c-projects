class Solution {
public:
    struct pair_hash {
        std::size_t operator()(const std::pair<int, int> &p) const {
            return ((long long)p.first * (100000) + p.second) % 1000000007;
        }
    };

    pair<int, int> slope (vector<int> pt, vector<int> A) {
        pt[0] -= A[0];
        pt[1] -= A[1];
        if (pt[0] == 0 && pt[1] == 0) return {0, 0};
        else if (pt[0] == 0 && pt[1] < 0) return {0, -1};
        else if (pt[0] == 0 && pt[1] > 0) return {0, 1};
        else if (pt[1] == 0 && pt[0] < 0) return {-1, 0};
        else if (pt[1] == 0 && pt[0] > 0) return {1, 0};
        else {
            int gcd = __gcd (pt[0], pt[1]);
            pt[0] /= gcd;
            pt[1] /= gcd;
        }
        return make_pair (pt[0], pt[1]);
    }
    
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size ();
        unordered_map <pair<int, int>, int, pair_hash> mp;

        int mx = 0, A = 0;
        pair<int, int> r;
        for (int i = 0; i < n; i++) {
            mp.clear ();
            for (int j = 0; j < n; j++) {
                if (j == i) continue;
                pair<int, int> tmp = slope (points[j], points[i]);
                mp[tmp]++;

                if (mp[tmp] > mx) {
                    mx = mp[tmp];
                    r = tmp;
                    A = i;
                }
            }
        }

        int res = 1;
        for (int i = A, j = 0; j < n; j++) {
            if (j == i) continue;
            pair<int, int> tmp = slope (points[j], points[i]);

            if (tmp == r) res++;
        }
        return res;
    }
};
