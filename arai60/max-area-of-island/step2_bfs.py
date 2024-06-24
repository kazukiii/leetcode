class Solution:
    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:
        LAND = 1
        WATER = 0
        n_row = len(grid)
        n_col = len(grid[0])
        visited = [[False] * n_col for _ in range(n_row)]

        def calculate_area(row: int, col: int) -> int:
            area = 0
            visited[row][col] = True
            node_que = deque([(row, col)])
            while node_que:
                current_row, current_col = node_que.pop()
                area += 1
                drow = (0, 1, 0, -1)
                dcol = (1, 0, -1, 0)
                for direction in range(4):
                    next_row = current_row + drow[direction]
                    next_col = current_col + dcol[direction]
                    is_land = (
                        0 <= next_row < n_row
                        and 0 <= next_col < n_col
                        and grid[next_row][next_col] == LAND
                    )
                    if is_land and not visited[next_row][next_col]:
                        visited[next_row][next_col] = True
                        node_que.append((next_row, next_col))
            return area

        max_area = 0
        for i in range(n_row):
            for j in range(n_col):
                if grid[i][j] == LAND and not visited[i][j]:
                    max_area = max(max_area, calculate_area(i, j))
        return max_area
