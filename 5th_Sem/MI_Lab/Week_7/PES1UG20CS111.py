import numpy as np
from sklearn.tree import DecisionTreeClassifier

"""
Use DecisionTreeClassifier to represent a stump.
------------------------------------------------
DecisionTreeClassifier Params:
    critereon -> entropy
    max_depth -> 1
    max_leaf_nodes -> 2
Use the same parameters
"""
# REFER THE INSTRUCTION PDF FOR THE FORMULA TO BE USED 

class AdaBoost:

    """
    AdaBoost Model Class
    Args:
        n_stumps: Number of stumps (int.)
    """

    def __init__(self, n_stumps=20):

        self.n_stumps = n_stumps
        self.stumps = []

    def fit(self, X, y):
        """
        Fitting the adaboost model
        Args:
            X: M x D Matrix(M data points with D attributes each)(numpy float)
            y: M Vector(Class target for all the data points as int.)
        Returns:
            the object itself
        """
        self.alphas = []

        sample_weights = np.ones_like(y) / len(y)
        for _ in range(self.n_stumps):

            st = DecisionTreeClassifier(
                criterion='entropy', max_depth=1, max_leaf_nodes=2)
            st.fit(X, y, sample_weights)
            y_pred = st.predict(X)

            self.stumps.append(st)

            error = self.stump_error(y, y_pred, sample_weights=sample_weights)
            alpha = self.compute_alpha(error)
            self.alphas.append(alpha)
            sample_weights = self.update_weights(
                y, y_pred, sample_weights, alpha)

        return self

    def stump_error(self, y, y_pred, sample_weights):
        """
        Calculating the stump error
        Args:
            y: M Vector(Class target for all the data points as int.)
            y_pred: M Vector(Class target predicted for all the data points as int.)
            sample_weights: M Vector(Weight of each sample float.)
        Returns:
            The error in the stump(float.)
        """

        # Alternative Method:
        # indices = np.where(y != y_pred)[0]
        # error = np.sum(sample_weights[indices]) or np.sum(sample_weights)
        # return error

        # TODO
        err = 0.0

        for index, (yi, yp) in enumerate(zip(y, y_pred)):
            if yi != yp:
                err += sample_weights[index]

        return err

    def compute_alpha(self, error):
        """
        Computing alpha
        The weight the stump has in the final prediction
        Use eps = 1e-9 for numerical stabilty.
        Args:
            error:The stump error(float.)
        Returns:
            The alpha value(float.)
        """
        eps = 1e-9
        # TODO

        # For numerical stability, in the case error is 0
        alpha = 0.5 * np.log((1 - (error + eps)) / (error + eps))

        return alpha

    def update_weights(self, y, y_pred, sample_weights, alpha):
        """
        Updating Weights of the samples based on error of current stump
        The weight returned is normalized
        Args:
            y: M Vector(Class target for all the data points as int.)
            y_pred: M Vector(Class target predicted for all the data points as int.)
            sample_weights: M Vector(Weight of each sample float.)
            alpha: The stump weight(float.)
        Returns:
            new_sample_weights:  M Vector(new Weight of each sample float.)
        """

        # Alternative Method:
        # indeq = ( y == y_pred )
        # indne = ( y != y_pred )

        # sample_weights[indeq] = sample_weights[indeq] * (np.e ** (-alpha))
        # sample_weights[indne] = sample_weights[indne] * (np.e ** (alpha))

        # sample_weights = (sample_weights / np.sum(sample_weights))

        # TODO
        for index, (yi, yp, wi) in enumerate(zip(y, y_pred, sample_weights)):
            if yi == yp:
                sample_weights[index] = sample_weights[index] * np.exp(-alpha)
            else:
                sample_weights[index] = sample_weights[index] * np.exp(alpha)
        
        ns = np.sum(sample_weights)
        return [x / ns for x in sample_weights]

        # sample_weights = list(map(lambda x: x / ns, sample_weights))
        # return sample_weights

    def predict(self, X):
        """
        Predicting using AdaBoost model with all the decision stumps.
        Decison stump predictions are weighted.
        Args:
            X: N x D Matrix(N data points with D attributes each)(numpy float)
        Returns:
            pred: N Vector(Class target predicted for all the inputs as int.)
        """
        # TODO
        preds = []
        final = []
        for stump in self.stumps:
            preds.append(stump.predict(X))
        
        for index in range(len(X)):
            weight_preds = {}

            for stump_no in range(self.n_stumps):
                key = preds[stump_no][index]
                if key in weight_preds:
                    weight_preds[key] += self.alphas[stump_no]
                else:
                    weight_preds[key] = self.alphas[stump_no]
            
            final.append(max(weight_preds, key=weight_preds.get))
        
        return final

    def evaluate(self, X, y):
        """
        Evaluate Model on test data using
            classification: accuracy metric
        Args:
            x: Test data (N x D) matrix
            y: True target of test data
        Returns:
            accuracy : (float.)
        """
        pred = self.predict(X)
        # find correct predictions
        correct = (pred == y)

        accuracy = np.mean(correct) * 100  # accuracy calculation
        return accuracy