class UnionFind:
    def __init__(self, n):
        self.parent_size = [-1] * n

    def find(self, a):
        if self.parent_size[a] < 0:
            return a
        self.parent_size[a] = self.find(self.parent_size[a])
        return self.parent_size[a]

    def unite(self, a, b):
        x = self.find(a)
        y = self.find(b)
        if x == y:
            return
        if abs(self.parent_size[x]) < abs(self.parent_size[y]):
            x, y = y, x
        self.parent_size[x] += self.parent_size[y]
        self.parent_size[y] = x

    def size(self, a):
        return abs(self.parent_size[self.find(a)])

class Solution:
    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:
        LAND = 1
        WATER = 0
        n_row, n_col = len(grid), len(grid[0])
        uf = UnionFind(n_row * n_col)

        def index(row, col):
            return row * n_col + col

        for row in range(n_row):
            for col in range(n_col):
                if grid[row][col] == WATER: continue
                drow = (0, 1, 0, -1)
                dcol = (1, 0, -1, 0)
                for direction in range(4):
                    next_row = row + drow[direction]
                    next_col = col + dcol[direction]
                    is_land = (
                        0 <= next_row < n_row
                        and 0 <= next_col < n_col
                        and grid[next_row][next_col] == LAND
                    )
                    if is_land:
                        uf.unite(index(row, col), index(next_row, next_col))

        max_area = 0
        for row in range(n_row):
            for col in range(n_col):
                if grid[row][col] == LAND:
                    max_area = max(max_area, uf.size(index(row, col)))
        return max_area
