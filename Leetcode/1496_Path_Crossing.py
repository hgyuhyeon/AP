class Solution:
    def isPathCrossing(self, path: str) -> bool:
        visited = [[0, 0]]
        x = 0
        y = 0
        for p in path:
            if p == 'N':
                y += 1
            elif p == 'E':
                x += 1
            elif p == 'S':
                y -= 1
            elif p == 'W':
                x -= 1
            
            if [x, y] in visited:
                return True
            else:
                visited.append([x, y])
            
        return False