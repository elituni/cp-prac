import numpy as np
import copy

def load_chars(filename):
    with open(filename, 'r') as f:
        data = f.read().splitlines() 
    return np.array([list(line) for line in data])  

data = load_chars('./in-out/in.txt')
print(data)


def get_guard_loc(data):
    rows = data.shape[0]
    cols = data.shape[1]
    for x in range(0, rows):
        for y in range(0, cols):
            if data[x][y] == '^':
                return (x,y)


def simulate(data, i, j):
    if data[i][j] == '.': data[i][j] = '#'
    else: return False
    infi = False
    orientation = 0
    (x,y) = get_guard_loc(data)
    visited = {(-1, -1, -1)}
    while x > 0:
        if data[x-1][y] == '#':
            data = np.rot90(data)
            orientation = (orientation + 1) % 4
            temp = x
            x = len(data[0])-y-1
            y = temp
        else: x -= 1
        if (x, y, orientation) in visited:
            infi = True
            break
        visited.add((x, y, orientation))
    return infi



possible_obstacles = 0
saved_data = copy.deepcopy(data)
rows = data.shape[0]
cols = data.shape[1]
for i in range(0, rows):
    for j in range(0, cols):
        if simulate(data, i, j):
            possible_obstacles += 1
        data = saved_data
        saved_data = copy.deepcopy(data)
        print((i,j))

print(possible_obstacles)