import numpy as np
import matplotlib.pyplot as plt

def main():
    # Initializing the probabilites
    page_graph = np.array([
        [0  , 1/3 , 1/2 , 1/4 ,  0 ],
        [1/2,  0  ,  0  , 1/4 , 1/2],
        [0  , 1/3 ,  0  , 1/4 , 1/2],
        [1/2, 1/3 , 1/2 ,  0  ,  0 ],
        [0  ,  0  ,  0  , 1/4 ,  0 ]
    ])

    eig_val, eig_vec = np.linalg.eig(page_graph)
    order = np.absolute(eig_val).argsort()[::-1] # Orders them by their eigen values
    evals = eig_val[order]
    evecs = eig_vec[:,order]

    # r - principal eigen vector
    r = evecs[:, 0]

    # Multiplying it atleast 100 times for it to settle
    pagerank = 100 * np.real(r / np.sum(r))
    print(pagerank)

    fig = plt.figure()
    sites = ['Site-1', 'Site-2', 'Site-3', 'Site-4', 'Site-5']
    plt.bar(sites, pagerank)
    plt.show()

if __name__ == '__main__':
    main()
