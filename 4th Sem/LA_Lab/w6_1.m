% Computing determinant and trace

A = [1, 1, 3; 1, 5, 1; 3, 1, 1]
e = eig(A)
det(A)
prod(eig(A))
det(A) = prod(eig(A))
sum(eig(A))
trace(A)
[V, D] = eig(A)
A* V - V * D