% Computing eigenvalues and eigenvectors

A = [2, 2, 1; 1, 3, 1; 1, 2, 2]
e = eig(A)
[V, D] = eig(A)

A * V(:, 1)          % This command will give you first eigenvector
D(1, 1) * V(:, 1)    % First eigenvalue
% If you replace 2 or 3 in place of 1, that will create second or third eigenvalue  and eigenvectors respectively.