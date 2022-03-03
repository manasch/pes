P = [0.8, -0.4; -0.4, 0.2]
Pu = P * u;
x = Pu(1, :)
y = Pu(2, :)
hold on
plot(x, y, 'ro')