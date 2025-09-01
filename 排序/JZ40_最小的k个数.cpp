class Solution {
  public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
    vector<int> vec;
    if (input.size() < k || k == 0) return vec;

    priority_queue<int> maxHeap;  // 大根堆
    for (int i = 0; i < input.size(); ++i) {
        if (maxHeap.size() < k) {
            maxHeap.push(input[i]);
        } else if (input[i] < maxHeap.top()) {
            maxHeap.pop();
            maxHeap.push(input[i]);
        }
    }

    while (!maxHeap.empty()) {
        vec.push_back(maxHeap.top());
        maxHeap.pop();
    }

    reverse(vec.begin(), vec.end()); // 从小到大
    return vec;
}

};