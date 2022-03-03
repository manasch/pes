import random
import numpy as np

TRANSITION_PROB = np.array([[.5, .4, .3], [.2, .4, .4], [.3, .2, .3]])

def init():
    arr = []
    for i in range(len(TRANSITION_PROB)):
        arr.append(random.randint(1, 100000))

    return np.array(arr)

def mapState(n, parties, voters):
    mapped = dict(zip(parties, voters))
    print(f'Year {n}', mapped)

def findNState(matrix1, matrix2, n):
    temp1 = matrix1
    temp2 = matrix2
    transpose_transition = np.transpose(TRANSITION_PROB)
    for i in range(n):
        temp2 = np.dot(temp2, transpose_transition).astype(int)
        mapState(i + 1, temp1, temp2)
    
    return [temp1, temp2]

def main():
    voters = init()
    parties_present = ['Congress', 'BJP', 'AAP']

    # Voters are generated randomly
    print(f'\nNo. of voters initially: ')
    for i in range(len(voters)):
        print(f'{parties_present[i]}: {voters[i]}')

    num = int(input('\nEnter the number of years to predict the voters: '))
    parties_after_N, voters_after_N = findNState(parties_present, voters, num)


    print(f'\nNo. of voters for the respective parties after {num} years: ')
    for i in range(len(voters)):
        print(f'{parties_after_N[i]}: {voters_after_N[i]}')
    

if __name__ == '__main__':
    main()
