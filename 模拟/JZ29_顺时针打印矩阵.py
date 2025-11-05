# -*- coding:utf-8 -*-
def create_ones_matrix(inputs):
    rows = len(inputs)
    cols = len(inputs[0]) if rows > 0 else 0

    # 创建全1矩阵
    ones_matrix = [[1] * cols for _ in range(rows)]
    return ones_matrix


class Solution:
    # matrix类型为二维列表，需要返回列表
    def printMatrix(self, matrix):
        if not matrix or not matrix[0]:
            return []
        
        usage = create_ones_matrix(matrix)
        i, j = 0, 0
        res = []
        
        # 定义方向：右、下、左、上
        directions = [(0, 1), (1, 0), (0, -1), (-1, 0)]
        dir_idx = 0  # 当前方向索引
        
        for _ in range(len(matrix) * len(matrix[0])):
            res.append(matrix[i][j])
            usage[i][j] = 0
            
            # 尝试按照当前方向移动
            next_i = i + directions[dir_idx][0]
            next_j = j + directions[dir_idx][1]
            
            # 如果下一个位置无效，改变方向
            if (next_i < 0 or next_i >= len(matrix) or 
                next_j < 0 or next_j >= len(matrix[0]) or 
                usage[next_i][next_j] == 0):
                
                dir_idx = (dir_idx + 1) % 4  # 改变方向
                next_i = i + directions[dir_idx][0]
                next_j = j + directions[dir_idx][1]
            
            i, j = next_i, next_j
        
        return res