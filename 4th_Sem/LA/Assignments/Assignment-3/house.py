def setup():
    size(400, 100)
    background(255)
    for i in xrange(10, 350, 50):
        house(i, 20)

def house(x, y):
    triangle(x + 15, y, x, y + 15, x + 30, y + 15)
    rect(x, y + 15, 30, 30)
    rect(x + 12, y + 30, 10, 15)
