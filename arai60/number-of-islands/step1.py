class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        m = len(grid)
        n = len(grid[0])
        visited = [[False] * n for _ in range(m)]

        def dfs(node: tuple):
            current_row, current_col = node
            visited[current_row][current_col] = True

            for next_node in get_neighbors(node):
                next_row, next_col = next_node
                if not visited[next_row][next_col]:
                    dfs(next_node)

        def get_neighbors(node: tuple):
            drow = (0, 1, 0, -1)
            dcol = (1, 0, -1, 0)
            neighbors = []
            for direction in range(4):
                next_row = node[0] + drow[direction]
                next_col = node[1] + dcol[direction]
                if 0 <= next_row < m and 0 <= next_col < n and grid[next_row][next_col] == '1':
                    neighbors.append((next_row, next_col))
            return neighbors

        total = 0
        for i in range(m):
            for j in range(n):
                if grid[i][j] == '1' and not visited[i][j]:
                    dfs((i, j))
                    total += 1

        return total
