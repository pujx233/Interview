package lc695;

class Solution {
  public int maxAreaOfIsland(int[][] grid) {
    if (grid == null || grid.length == 0) {
      return 0;
    }

    int maxArea = 0;
    // 遍历整个网格
    for (int i = 0; i < grid.length; i++) {
      for (int j = 0; j < grid[0].length; j++) {
        // 如果发现一个岛屿，就计算其面积并更新最大面积
        if (grid[i][j] == 1) {
          int currentArea = dfs(grid, i, j);
          maxArea = Math.max(maxArea, currentArea);
        }
      }
    }
    return maxArea;
  }

  /**
   * 深度优先搜索，计算从 (r, c) 开始的岛屿面积
   * @return 返回岛屿面积
   */
  private int dfs(int[][] grid, int r, int c) {
    // 1. 递归终止条件：越界或遇到水
    if (r < 0 || r >= grid.length || c < 0 || c >= grid[0].length || grid[r][c] == 0) {
      return 0;
    }

    // 2. 核心操作：沉岛，将陆地变为水，避免重复计算
    grid[r][c] = 0;

    // 3. 当前单元格的面积为 1
    int area = 1;

    // 4. 递归探索四个方向的邻居
    area += dfs(grid, r + 1, c); // 下
    area += dfs(grid, r - 1, c); // 上
    area += dfs(grid, r, c + 1); // 右
    area += dfs(grid, r, c - 1); // 左

    // 5. 返回总面积
    return area;
  }
}

public class maxAreaOfIsland {
  public static void main(String[] args) {
    Solution s = new Solution();
    s.maxAreaOfIsland(new int[][]{{0,0,0,0,0,0,0,0}});
  }
}
