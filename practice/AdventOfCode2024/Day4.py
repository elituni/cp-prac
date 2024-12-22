import numpy as np

def load_chars(filename):
    with open(filename, 'r') as f:
        data = f.read().splitlines() 
    return np.array([list(line) for line in data])  

data = load_chars('./in-out/in.txt')
# print(data[0][0])

def count_xmas_directions(grid, row, col):
    # Define the eight directions: (dx, dy)
    directions = [
        (-1, 0),  # Up
        (1, 0),   # Down
        (0, -1),  # Left
        (0, 1),   # Right
        (-1, -1), # Up-Left
        (-1, 1),  # Up-Right
        (1, -1),  # Down-Left
        (1, 1)    # Down-Right
    ]
    
    target = "XMAS"
    count = 0
    
    for dx, dy in directions:
        match = True
        for i in range(len(target)):
            new_row, new_col = row + i * dx, col + i * dy
            
            # Check if the position is within bounds
            if (0 <= new_row < grid.shape[0]) and (0 <= new_col < grid.shape[1]):
                if grid[new_row, new_col] != target[i]:
                    match = False
                    break
            else:
                match = False
                break
        
        if match:
            count += 1
            
    return count

tot = 0
for row in range(1, data.shape[0] - 1):
    for col in range(1, data.shape[1] - 1):
        if data[row][col] == 'A' and data[row-1][col-1] == 'M' and data[row+1][col-1] == 'M' and data[row+1][col+1] == 'S' and data[row-1][col+1] == 'S':
            tot += 1
        elif data[row][col] == 'A' and data[row+1][col-1] == 'M' and data[row+1][col+1] == 'M' and data[row-1][col-1] == 'S' and data[row-1][col+1] == 'S':
            tot += 1
        elif data[row][col] == 'A' and data[row+1][col+1] == 'M' and data[row-1][col+1] == 'M' and data[row-1][col-1] == 'S' and data[row+1][col-1] == 'S':
            tot += 1
        elif data[row][col] == 'A' and data[row-1][col+1] == 'M' and data[row-1][col-1] == 'M' and data[row+1][col-1] == 'S' and data[row+1][col+1] == 'S':
            tot += 1

        
print(tot)
