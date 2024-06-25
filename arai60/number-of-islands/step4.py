class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        LAND = '1'
        WATER = '0'
        num_rows = len(grid)
        num_cols = len(grid[0])
        visited = [[False] * num_cols for _ in range(num_rows)]

        def explore_island(row, col):
            visited[row][col] = True
            directions = [(0, 1), (1, 0), (-1, 0), (0, -1)]
            for delta_row, delta_col in directions:
                next_row = row + delta_row
                next_col = col + delta_col
                if not (0 <= next_row < num_rows and 0 <= next_col < num_cols): continue
                if grid[next_row][next_col] == WATER: continue
                if visited[next_row][next_col]: continue
                explore_island(next_row, next_col)

        total = 0
        for i in range(num_rows):
            for j in range(num_cols):
                if grid[i][j] == LAND and not visited[i][j]:
                    explore_island(i, j)
                    total += 1
        return total
