"""
You can create any other helper funtions.
Do not modify the given functions
"""

def find_cost_of_path(cost, path, heuristic):
    path_cost = 0
    index = 0
    while index < len(path) - 1:
        path_cost += cost[path[index]][path[index + 1]]
        index += 1
    path_cost += heuristic[path[-1]]

    return path_cost

def path_to_string(path):
    string_path = " ".join(f"{x}" for x in path)
    return string_path

def string_to_path_list(path_string):
    path = [int(x) for x in path_string.split(" ")]
    return path

def helper_A_star_Traversal(node_no, cost, goals, paths, current_path, heuristic):
    '''
    Arguements:
        node_no: The current node number that is being visited
        paths: A dictionary which has the path mapped to their cost (path cost + heuristic)
        current_path: The current path
    Returns:
        min_cost_path: Returns the quickest path that reaches the goal
    '''
    if node_no in goals and not paths:
        return current_path
    
    index = 1

    while index < len(cost[node_no]):
        if cost[node_no][index] not in [0, -1] and index not in current_path:
            temp_path = [x for x in current_path]
            temp_path.append(index)
            cost_of_path = find_cost_of_path(cost, temp_path, heuristic)
            # paths.append([temp_path, cost_of_path])
            paths[path_to_string(temp_path)] = cost_of_path
        
        index += 1
    
    # Assigning it the first element
    min_cost_path = list(paths.items())[0]
    
    # Finding the minimum cost path out of all the available paths
    for p in list(paths.items()):
        if p[1] < min_cost_path[1]:
            min_cost_path = p
    
    current_path = string_to_path_list(min_cost_path[0])
    del paths[min_cost_path[0]]

    # Checking the last node of the path
    if current_path[-1] in goals:
        return current_path

    return helper_A_star_Traversal(current_path[-1], cost, goals, paths, current_path, heuristic)

def helper_DFS_Traversal(node_no, cost, visited, goals, path):
    '''
    Arugements:
        node_no: The current node being visited
        visited: A list of nodes that have been visited
    Returns:
        path: Returns a path that will reach a goal first by dfs
    '''
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
        return helper_DFS_Traversal(shortest_node, cost, visited, goals, path)
    else:
        path.pop()
        return helper_DFS_Traversal(path[-1], cost, visited, goals, path)

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
    paths = {}
    path = helper_A_star_Traversal(start_point, cost, goals, paths, current_path, heuristic)
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
    path = helper_DFS_Traversal(start_point, cost, visited, goals, path)

    return path
