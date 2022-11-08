import numpy as np


class HMM:
    """
    HMM model class
    Args:
        A: State transition matrix
        states: list of states
        emissions: list of observations
        B: Emmision probabilites
    """

    def __init__(self, A, states, emissions, pi, B):
        self.A = A
        self.B = B
        self.states = states
        self.emissions = emissions
        self.pi = pi
        self.N = len(states)
        self.M = len(emissions)
        self.make_states_dict()

    def make_states_dict(self):
        """
        Make dictionary mapping between states and indexes
        """
        self.states_dict = dict(zip(self.states, list(range(self.N))))
        self.emissions_dict = dict(
            zip(self.emissions, list(range(self.M))))

    def viterbi_algorithm(self, seq):
        """
        Function implementing the Viterbi algorithm
        Args:
            seq: Observation sequence (list of observations. must be in the emmissions dict)
        Returns:
            nu: Porbability of the hidden state at time t given an obeservation sequence
            hidden_states_sequence: Most likely state sequence 
        """
        # TODO
        s = len(seq)
        viterbi_matrix = np.zeros((self.N, s))
        hidden_states = np.zeros(s, dtype=int)

        for i in range(s):
            if i == 0:
                viterbi_matrix[:, 0] = self.pi * self.B[:, self.emissions_dict[seq[0]]]
            else:
                for j in range(self.N):
                    viterbi_matrix[j, i] = np.max(viterbi_matrix[:, i - 1] * self.A[:, j]) * self.B[j, self.emissions_dict[seq[i]]]
                    hidden_states[i] = np.argmax(viterbi_matrix[:, i])
        
        return [self.states[x] for x in hidden_states]
