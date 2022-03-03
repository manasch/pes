%LU Fact
A = input("Enter the coefficient Matrix A: ");
N = length(A);
L = zeros(N, N); % Lower triangular matrix
U = zeros(N, N); % Upper triangular matrix

for a = 1: N
    L(a, a) = 1;
end

U(1, :) = A(1, :); % First column of upper triangular matrix
L(:, 1) = A(:, 1) / U(1, 1); % First column of lower triangular matrix

for i = 2:N % 2 to N columns
    for j = i:N % compute U columns
        U(i, j) = A(i, j) - L(i, 1:i-1) * U(1: i - 1, j)
    end
    for k = i + 1:N % compute L columns, i => column and k = row
        L(k, i) = (A(k, i) - L(k, 1:i-1) * U(1: i-1, i)) / U(i, i);
    end
end
L, U