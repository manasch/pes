import numpy as np


class KMeansClustering:
    """
    K-Means Clustering Model

    Args:
        n_clusters: Number of clusters(int)
    """

    def __init__(self, n_clusters, n_init=10, max_iter=1000, delta=0.001):

        self.n_cluster = n_clusters
        self.n_init = n_init
        self.max_iter = max_iter
        self.delta = delta
    
    def euclidian_distance(self, x, y, dim):
        dist = 0
        for i in range(dim):
            dist += (x[i] - y[i]) ** 2
        
        return dist ** 0.5
    
    def find_cluster_freq(self, clusters):
        freq = {}
        for c in clusters:
            if c not in freq:
                freq[c] = 1
            else:
                freq[c] += 1
        
        return freq
    
    def init_centroids(self, data):
        idx = np.random.choice(
            data.shape[0], size=self.n_cluster, replace=False)
        self.centroids = np.copy(data[idx, :])

    def fit(self, data):
        """
        Fit the model to the training dataset.
        Args:
            data: M x D Matrix(M data points with D attributes each)(numpy float)
        Returns:
            The object itself
        """
        if data.shape[0] < self.n_cluster:
            raise ValueError(
                'Number of clusters is grater than number of datapoints')

        best_centroids = None
        m_score = float('inf')

        for _ in range(self.n_init):
            self.init_centroids(data)

            for _ in range(self.max_iter):
                cluster_assign = self.e_step(data)
                old_centroid = np.copy(self.centroids)
                self.m_step(data, cluster_assign)

                if np.abs(old_centroid - self.centroids).sum() < self.delta:
                    break

            cur_score = self.evaluate(data)

            if cur_score < m_score:
                m_score = cur_score
                best_centroids = np.copy(self.centroids)

        self.centroids = best_centroids

        return self

    def e_step(self, data):
        """
        Expectation Step.
        Finding the cluster assignments of all the points in the data passed
        based on the current centroids
        Args:
            data: M x D Matrix (M training samples with D attributes each)(numpy float)
        Returns:
            Cluster assignment of all the samples in the training data
            (M) Vector (M number of samples in the train dataset)(numpy int)
        """
        #TODO
        ans = []
        num_data = data.shape[0]
        dim = self.centroids.shape[1]

        for i in range(data.shape[0]):
            dists = []
            for j in range(self.n_cluster):
                dists.append(self.euclidian_distance(data[i], self.centroids[j], dim))
            
            ans.append(np.argmin(dists))

        return np.array(ans)

    def m_step(self, data, cluster_assgn):
        """
        Maximization Step.
        Compute the centroids
        Args:
            data: M x D Matrix(M training samples with D attributes each)(numpy float)
        Change self.centroids
        """
        #TODO
        freq = self.find_cluster_freq(cluster_assgn)
        new_centroids = np.zeros((len(freq), len(data[0])))

        for idx, point in enumerate(data):
            c = cluster_assgn[idx]
            new_centroids[c] += point
        
        for idx, centroid in enumerate(new_centroids):
            new_centroids[idx] = centroid / freq[idx]
        
        self.centroids = new_centroids

    def evaluate(self, data):
        """
        K-Means Objective
        Args:
            data: Test data (M x D) matrix (numpy float)
        Returns:
            metric : (float.)
        """
        #TODO
        metric = 0
        dim = self.centroids.shape[1]
        
        for c in range(len(self.centroids)):
            for d in range(len(data)):
                metric += np.sum(self.euclidian_distance(data[c], data[d], dim) ** 2)
        
        return metric
