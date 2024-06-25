class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        LAND = '1'
        WATER = '0'
        n_row = len(grid)
        n_col = len(grid[0])
        visited = [[False] * n_col for _ in range(n_row)]

        def explore_island(node: tuple):
            que = deque()
            que.append(node)
            while que:
                current_node = que.popleft()
                current_row, current_col = current_node
                visited[current_row][current_col] = True
                for next_node in get_neighbors(current_node):
                    next_row, next_col = next_node
                    if not visited[next_row][next_col]:
                        que.append(next_node)
                        visited[next_row][next_col] = True

        def get_neighbors(node: tuple):
            drow = (0, 1, 0, -1)
            dcol = (1, 0, -1, 0)
            neighbors = []
            for direction in range(4):
                next_row = node[0] + drow[direction]
                next_col = node[1] + dcol[direction]
                if 0 <= next_row < n_row and 0 <= next_col < n_col and grid[next_row][next_col] == LAND:
                    neighbors.append((next_row, next_col))
            return neighbors

        total = 0
        for i in range(n_row):
            for j in range(n_col):
                if grid[i][j] == LAND and not visited[i][j]:
                    explore_island((i, j))
                    total += 1

        return total
