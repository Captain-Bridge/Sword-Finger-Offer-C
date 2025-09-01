class Solution {
  public:
    int movingCount(int threshold, int rows, int cols) {
        row = rows;
        col = cols;
        ts = threshold;
        visited = vector<vector<bool>>(row, vector<bool>(col, false));
        moving(0, 0);
        return ans;
    }
  private:
    int row;
    int col;
    int ts;
    int ans = 0;
    vector<vector<bool>> visited;

    void moving(int x, int y) {
        if (x < 0 || x >= row || y < 0 || y >= col || visited[x][y]) return;

        int nums = 0, tx = x, ty = y;
        while (tx > 0) {
            nums += tx % 10;
            tx /= 10;
        }
        while (ty > 0) {
            nums += ty % 10;
            ty /= 10;
        }
        if (nums > ts) return;

        visited[x][y] = true;
        ans += 1;

        moving(x + 1, y);
        moving(x, y + 1);
    }
};
