from sklearn.svm import SVC
from sklearn.pipeline import Pipeline
from sklearn.preprocessing import *
import pandas as pd
import numpy as np


class SVM:

    def __init__(self, dataset_path):

        self.dataset_path = dataset_path
        data = pd.read_csv(self.dataset_path)

        # X-> Contains the features
        self.X = data.iloc[:, 0:-1]
        # y-> Contains all the targets
        self.y = data.iloc[:, -1]

    def solve(self):
        """
        Build an SVM model and fit on the training data
        The data has already been loaded in from the dataset_path

        Refrain to using SVC only (with any kernel of your choice)

        You are free to use any any pre-processing you wish to use
        Note: Use sklearn Pipeline to add the pre-processing as a step in the model pipeline
        Refrain to using sklearn Pipeline only not any other custom Pipeline if you are adding preprocessing

        Returns:
            Return the model itself or the pipeline(if using preprocessing)
        """

        # TODO
        scale = ('scaler', StandardScaler())
        nr = ('normalizer', Normalizer())
        svc = ('svc', SVC(gamma='scale', C=2.5))

        pipeline = Pipeline([scale, nr, svc])

        model = pipeline.fit(self.X, self.y)
        return model
