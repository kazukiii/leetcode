class Solution:
    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:
        LAND = 1
        WATER = 0
        n_row = len(grid)
        n_col = len(grid[0])
        visited = [[False] * n_col for _ in range(n_row)]

        def calculate_area(row: int, col: int) -> int:
            is_water = (
                not 0 <= row < n_row
                or not 0 <= col < n_col
                or grid[row][col] == WATER
            )
            if is_water or visited[row][col]:
                return 0

            visited[row][col] = True
            area = 1
            drow = (0, 1, 0, -1)
            dcol = (1, 0, -1, 0)
            for direction in range(4):
                area += calculate_area(row + drow[direction], col + dcol[direction])
            return area

        max_area = 0
        for i in range(n_row):
            for j in range(n_col):
                if grid[i][j] == WATER or visited[i][j]: continue
                max_area = max(max_area, calculate_area(i, j))
        return max_area
