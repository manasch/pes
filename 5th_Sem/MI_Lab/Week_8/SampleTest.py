import sys
import importlib
import argparse
import numpy as np


parser = argparse.ArgumentParser()
parser.add_argument('--SRN', required=True)

args = parser.parse_args()
subname = args.SRN


try:
    mymodule = importlib.import_module(subname)
except Exception as e:
    print(e)
    print("Rename your written program as YOUR_SRN.py and run python3.7 SampleTest.py --SRN YOUR_SRN ")
    sys.exit()

HMM = mymodule.HMM


def test_1():
    '''
    Bob's observed mood (Happy or Grumpy) 
    can be modelled with the weather (Sunny, Rainy)
    '''
    A = np.array([
        [0.8, 0.2],
        [0.4, 0.6]
    ])

    HS = ['Sunny', 'Rainy']
    O = ["Happy", 'Grumpy']
    priors = [2/3, 1/3]

    B = np.array([
        [0.8, 0.2],
        [0.4, 0.6]
    ])

    ES = ["Happy", "Grumpy", "Happy"]
    model = HMM(A, HS, O, priors, B)
    seq = model.viterbi_algorithm(ES)
    assert (seq == ['Sunny', 'Sunny', 'Sunny'])


def test_2():
    A = np.array([
        [0.2, 0.8],
        [0.7, 0.3]
    ])

    HS = ['A', 'B']
    O = ['x', 'y']
    priors = [0.7, 0.3]
    B = np.array([
        [0.4, 0.6],
        [0.3, 0.7]
    ])
    ES = ['x', 'y', 'y']
    model = HMM(A, HS, O, priors, B)
    seq = model.viterbi_algorithm(ES)
    assert(seq == ['A', 'B', 'A'])

# Custom test case
def test_3():
    A = np.array([
        [0.4, 0.6],
        [0.7, 0.3]
    ])

    HS = ['S1', 'S2']
    O = ['V1', 'V2', 'V3']
    priors = [0.2, 0.8]
    B = np.array([
        [0.1, 0.4, 0.5],
        [0.3, 0.5, 0.2]
    ])
    ES = ['V1', 'V3', 'V2']
    model = HMM(A, HS, O, priors, B)
    seq = model.viterbi_algorithm(ES)
    assert(seq == ['S1', 'S1', 'S2'])

if __name__ == "__main__":
    try:
        test_1()
        print("Test case 1 for Viterbi Algorithm passed!")
    except Exception as e:
        print(f"Test case 1 for Viterbi Algorithm failed!\n{e}")

    try:
        test_2()
        print("Test case 2 for Viterbi Algorithm passed!")
    except Exception as e:
        print(f"Test case 2 for Viterbi Algorithm failed!\n{e}")
    
    # Custom test case
    try:
        test_3()
        print("Test case 3 for Viterbi Algorithm passed!")
    except Exception as e:
        print(f"Test case 3 for Viterbi Algorithm failed!\n{e}")
