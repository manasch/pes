import numpy as np


class KNN:
    """
    K Nearest Neighbours model
    Args:
        k_neigh: Number of neighbours to take for prediction
        weighted: Boolean flag to indicate if the nieghbours contribution
                  is weighted as an inverse of the distance measure
        p: Parameter of Minkowski distance
    """

    def __init__(self, k_neigh, weighted=False, p=2):

        self.weighted = weighted
        self.k_neigh = k_neigh
        self.p = p

    def fit(self, data, target):
        """
        Fit the model to the training dataset.
        Args:
            data: M x D Matrix( M data points with D attributes each)(float)
            target: Vector of length M (Target class for all the data points as int)
        Returns:
            The object itself
        """

        self.data = data
        self.target = target.astype(np.int64)

        return self

    def find_distance(self, x):
        """
        Find the Minkowski distance to all the points in the train dataset x
        Args:
            x: N x D Matrix (N inputs with D attributes each)(float)
        Returns:
            Distance between each input to every data point in the train dataset
            (N x M) Matrix (N Number of inputs, M number of samples in the train dataset)(float)
        """
        # TODO
        result = []
        # The number of dimensions of the dataset x
        dimensions = x.shape[1]

        for coord in x:
            minkowski_distance = []
            for point in self.data:
                dist = 0
                for dim in range(dimensions):
                    dist += (abs(coord[dim] - point[dim])) ** self.p
                minkowski_distance.append(dist ** (1 / self.p))
            result.append(minkowski_distance)
        
        return np.array(result)

    def k_neighbours(self, x):
        """
        Find K nearest neighbours of each point in train dataset x
        Note that the point itself is not to be included in the set of k Nearest Neighbours
        Args:
            x: N x D Matrix( N inputs with D attributes each)(float)
        Returns:
            k nearest neighbours as a list of (neigh_dists, idx_of_neigh)
            neigh_dists -> N x k Matrix(float) - Dist of all input points to its k closest neighbours.
            idx_of_neigh -> N x k Matrix(int) - The (row index in the dataset) of the k closest neighbours of each input

            Note that each row of both neigh_dists and idx_of_neigh must be SORTED in increasing order of distance
        """
        # TODO
        distances = self.find_distance(x)
        neigh_dists = []
        idx_of_neigh = []
        
        for dist in distances:
            sorted_dist = sorted(list(enumerate(dist)), key=lambda x: x[1])
            neigh_dists.append([x[1] for x in sorted_dist[:self.k_neigh]])
            idx_of_neigh.append([x[0] for x in sorted_dist[:self.k_neigh]])
        
        return (np.array(neigh_dists), np.array(idx_of_neigh))

    def predict(self, x):
        """
        Predict the target value of the inputs.
        Args:
            x: N x D Matrix( N inputs with D attributes each)(float)
        Returns:
            pred: Vector of length N (Predicted target value for each input)(int)
        """
        # TODO
        neigh_dists, idx_of_neigh = self.k_neighbours(x)
        pred = []

        if self.weighted:
            weighted_dists = 1 / neigh_dists
        
        for w, idxs in enumerate(idx_of_neigh):
            # Assigns count of all classes to 0
            classes = {x: 0 for x in set(self.target)}
            for indx, idx in enumerate(idxs):
                if self.weighted:
                    classes[self.target[idx]] += weighted_dists[w][indx]
                else:
                    classes[self.target[idx]] += 1
            classes = sorted(classes.items(), key=lambda x: x[1], reverse=True)
            pred.append(classes[0][0])

        return np.array(pred)

    def evaluate(self, x, y):
        """
        Evaluate Model on test data using 
            classification: accuracy metric
        Args:
            x: Test data (N x D) matrix(float)
            y: True target of test data(int)
        Returns:
            accuracy : (float.)
        """
        # TODO
        result = self.predict(x)
        # Accuracy = (True Positive + True Negative) / (True Positvie + True Negative + False Positive + False Negative)
        # list(np.logical_xor(result, y)).count(False) -> gives the number of correct predictions
        accuracy = list(np.logical_xor(np.array(result, dtype=int), np.array(y, dtype=int))).count(False) / len(result)
        return accuracy * 100
