import math

def cross_length(a, b):
    qwe = []
    qwe.append(a[1] * b[2] - a[2] * b[1])
    qwe.append(a[2] * b[0] - a[0] * b[2])
    qwe.append(a[0] * b[1] - a[1] * b[0])
    print("cross length:", math.sqrt((qwe[0] ** 2) + (qwe[1] ** 2) + (qwe[2] ** 2)))
def inner_product(a, b):
    print("innerproduct:", (a[0] * b[0] + a[1] * b[1] + a[2] * b[2]))


def outer_product(a, b):
    qwe = []
    qwe.append(a[1] * b[2] - a[2] * b[1])
    qwe.append(a[2] * b[0] - a[0] * b[2])
    qwe.append(a[0] * b[1] - a[1] * b[0])
    print("out product:", qwe)


def ucgen_alani(a, b):
    qwe = []
    qwe.append(a[1] * b[2] - a[2] * b[1])
    qwe.append(a[2] * b[0] - a[0] * b[2])
    qwe.append(a[0] * b[1] - a[1] * b[0])
    k1 = math.sqrt((a[0] ** 2) + (a[1] ** 2) + (a[2] ** 2))
    k2 = math.sqrt((b[0] ** 2) + (b[1] ** 2) + (b[2] ** 2))
    k3 = math.sqrt((qwe[0] ** 2) + (qwe[1] ** 2) + (qwe[2] ** 2))
    c = (k1 + k2 + k3) / 2
    print("olusan ucgenin alani:", math.sqrt(c * (c - k1) * (c - k2) * (c - k3)))


def determinant(a, b):
    qwe = []
    qwe.append(a[1] * b[2] - a[2] * b[1])
    qwe.append(a[2] * b[0] - a[0] * b[2])
    qwe.append(a[0] * b[1] - a[1] * b[0])
    n1 = (a[0] * b[1]) - (b[0] * a[1])
    n2 = (a[0] * b[2]) - (b[0] * a[2])
    n3 = (a[0] * qwe[1]) - (a[1] * qwe[0])
    n4 = (a[0] * qwe[2]) - (qwe[0] * a[2])
    print("vektörlerin oluþturduðu matrisin determinantý:", ((n1 * n4) - (n2 * n3)) / a[0])

if __name__ == '__main__':
    vector1 = []
    vector2 = []
    x =input("vektörün katsayilarini giriniz: ")
    y =input("vektörün katsayilarini giriniz: ")
    a, b, c = x.split(",")
    vector1.append(int(a))
    vector1.append(int(b))
    vector1.append(int(c))
    a, b, c = y.split(",")
    vector2.append(int(a))
    vector2.append(int(b))
    vector2.append(int(c))
    inner_product(vector1,vector2)
    outer_product(vector1,vector2)
    cross_length(vector1,vector2)
    ucgen_alani(vector1,vector2)
    determinant(vector1,vector2)