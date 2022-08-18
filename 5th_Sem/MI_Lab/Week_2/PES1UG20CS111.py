"""
You can create any other helper funtions.
Do not modify the given functions
"""

def find_cost_of_path(cost, path, heuristic):
    path_cost = 0
    for i in range(len(path) - 1):
        path_cost += cost[path[i]][path[i + 1]]
    path_cost += heuristic[path[-1]]

    return path_cost

def A_star_Traversal_Helper(node_no, cost, goals, paths, current_path, heuristic):
    if node_no in goals and not paths:
        return current_path
    
    for i in range(1, len(cost[node_no])):
        if cost[node_no][i] not in [0, -1] and i not in current_path:
            temp_path = [x for x in current_path]
            temp_path.append(i)
            cost_of_path = find_cost_of_path(cost, temp_path, heuristic)
            paths.append([temp_path, cost_of_path])
    
    # Assigning it the first element
    min_cost_path = paths[0]
    
    for i in paths:
        if i[1] <= min_cost_path[1]:
            min_cost_path = i
    
    current_path = paths.pop(paths.index(min_cost_path))[0]

    # Checking the last node of the path
    if current_path[-1] in goals:
        return current_path

    return A_star_Traversal_Helper(current_path[-1], cost, goals, paths, current_path, heuristic)

def DFS_Traversal_Helper(node_no, cost, visited, goals, path):
    visited.append(node_no)
    path.append(node_no)

    if node_no in goals:
        return path

    shortest_node = -1
    for i in range(1, len(cost[node_no])):
        if i not in visited and cost[node_no][i] > 0:
            if shortest_node == -1 or cost[node_no][i] < cost[node_no][shortest_node]:
                shortest_node = i
    
    if shortest_node > 0:
        return DFS_Traversal_Helper(shortest_node, cost, visited, goals, path)
    else:
        path.pop()
        return DFS_Traversal_Helper(path[-1], cost, visited, goals, path)

def A_star_Traversal(cost, heuristic, start_point, goals):
    """
    Perform A* Traversal and find the optimal path 
    Args:
        cost: cost matrix (list of floats/int)
        heuristic: heuristics for A* (list of floats/int)
        start_point: Staring node (int)
        goals: Goal states (list of ints)
    Returns:
        path: path to goal state obtained from A*(list of ints)
    """
    path = []
    # TODO
    
    current_path = [start_point]
    paths = []
    path = A_star_Traversal_Helper(start_point, cost, goals, paths, current_path, heuristic)
    return path


def DFS_Traversal(cost, start_point, goals):
    """
    Perform DFS Traversal and find the optimal path 
        cost: cost matrix (list of floats/int)
        start_point: Staring node (int)
        goals: Goal states (list of ints)
    Returns:
        path: path to goal state obtained from DFS(list of ints)
    """
    path = []
    # TODO

    visited = []
    path = DFS_Traversal_Helper(start_point, cost, visited, goals, path)

    return path
