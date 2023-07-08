class Solution {
public:
  long long putMarbles(vector<int>& weights, int k) {
    if (k <= 1) {
      return 0;
    }
    --k;
    for (int i = 1; i < weights.size(); ++i) {
      weights[i - 1] += weights[i];
    }
    weights.pop_back();

    if (k * 2 > weights.size()) {
      k = weights.size() - k;
    }
    std::nth_element(weights.begin(), weights.begin() + k, weights.end());
    int64_t small = std::accumulate(weights.begin(), weights.begin() + k, int64_t(0));
    std::nth_element(weights.begin() + k, weights.end() - k, weights.end());
    int64_t large = std::accumulate(weights.end() - k, weights.end(), int64_t(0));
    return large - small;
  }
};