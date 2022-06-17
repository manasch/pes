A = [0, 1, 1; 1, 1, 0; 1, -1, 2; 1, 0, -1]
Q = zeros(4, 3)
R = zeros(3)
for j=1:3 
	v=A(: , j);
for i=1:j-1
	R(i,j)=Q(:,i)'*A(:,j) 
	v=v-R(i,j)*Q(:,i) 
end 
	R(j,j)=norm(v)
	Q(:,j)=v/R(j,j)
end
