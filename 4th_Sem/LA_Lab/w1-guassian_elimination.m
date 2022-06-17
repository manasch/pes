%Gaussian Elimination

A = input("Enter the coefficient matrix: ");
B = input("Enter the source vector B: ");

N = length(B);

X = zeros(N,1); %N = rows to column 1
Aug= [A B]; % Augfmented matrix

for j=1:N-1 %1st colum to last comuln N-1
    for i=j+1:N %For column to row
        m=Aug(i,j)/Aug(j,j); %Finding the multiplier R2= R2-m*R1
        Aug(i,:)=Aug(i,:)-m*Aug(j,:); %Performing row operations to that row
    end
end

Aug;
X(N)=Aug(N, N+1)/Aug(N, N); %row and column size N, N=1=>a34 and N, N=>a33=>x4=a45/a44
for k=N-1:-1:1 %Backward Substitution
    X(k)= (Aug(k, N+1)-Aug(k, k+1:N)*X(k+1:N))/Aug(k,k);
end
X