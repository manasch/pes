import random
import numpy as np

TRANSITION_PROB = np.array([[.2, .7], [.8, .3]])

def init():
    arr = []
    for i in range(len(TRANSITION_PROB)):
        arr.append(random.randint(1, 10000))

    return np.array(arr)

def mapState(n, states, population):
    mapped = dict(zip(states, population))
    print(f'Year {n}:', mapped)

def findNState(matrix1, matrix2, n):
    temp1 = matrix1
    temp2 = matrix2
    transpose_transition = np.transpose(TRANSITION_PROB)
    for i in range(n):
        temp2 = np.dot(temp2, transpose_transition).astype(int)
        mapState(i + 1, temp1, temp2)
    
    return [temp1, temp2]

def main():
    population = init()
    states = ['State-1', 'State-2']

    # Population distribution generated randomly using init() function
    print(f'\nPopulation state initially: ')
    for i in range(len(population)):
        print(f'{states[i]}: {population[i]}')

    num = int(input('\nNumber years to predict population : '))
    states_after_N, population_after_N = findNState(states, population, num)


    print(f'\nThe population distribution after {num} years: ')
    for i in range(len(population)):
        print(f'{states_after_N[i]}: {population_after_N[i]}')
    

if __name__ == '__main__':
    main()
