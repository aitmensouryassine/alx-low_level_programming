#!/usr/bin/python3
"""Island Perimeter module"""


def island_perimeter(grid):
    """Calculates Island Perimeter"""
    perim = 0

    for row in range(len(grid)):
        for col in range(len(grid)):
            if grid[row][col] == 1:
                if grid[row][col - 1] == 0:
                    perim += 1
                if grid[row][col + 1] == 0:
                    perim += 1
                if grid[row - 1][col] == 0:
                    perim += 1
                if grid[row + 1][col] == 0:
                    perim += 1

    return perim
