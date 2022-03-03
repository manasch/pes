import numpy as np
from enum import Enum
from egcd import egcd

# The character set used: A-Z + '!@# - 29 set, hence a prime

'''
Key = [
    5, 15, 2
    6, 7, 8
    4, 9, 3
]
''' 
N = 3
KEY = 'FPCGHIEJD'
CHAR2ASC = {
    "A": 0, "B": 1, 
    "C": 2, "D": 3, 
    "E": 4, "F": 5, 
    "G": 6, "H": 7, 
    "I": 8, "J": 9, 
    "K": 10,"L": 11,
    "M": 12,"N": 13,
    "O": 14,"P": 15,
    "Q": 16,"R": 17,
    "S": 18,"T": 19,
    "U": 20,"V": 21,
    "W": 22,"X": 23,
    "Y": 24,"Z": 25,
    " ": 26,"@": 27,
    "#": 28
}
ASC2CHAR = {
    0: 'A', 1: 'B',
    2: 'C', 3: 'D',
    4: 'E', 5: 'F',
    6: 'G', 7: 'H',
    8: 'I', 9: 'J',
    10: 'K', 11: 'L',
    12: 'M', 13: 'N',
    14: 'O', 15: 'P',
    16: 'Q', 17: 'R',
    18: 'S', 19: 'T',
    20: 'U', 21: 'V', 
    22: 'W', 23: 'X',
    24: 'Y', 25: 'Z',
    26: ' ', 27: '@',
    28: '#'
    }
MODULUS = len(CHAR2ASC)

def formatMessage(msg):
    while len(msg) % 3 != 0:
        msg += 'Z'
    return msg

def keyToMatrix(msg):
    matrix = []
    row = []
    for i, ch in enumerate(msg):
        row.append(CHAR2ASC[ch])
        if i % N == N - 1:
            matrix.append(row)
            row = []

    return np.array(matrix)

def msgToMatrix(msg):
    matrix = []
    for ch in msg:
        matrix.append(CHAR2ASC[ch])
    
    transpose = np.transpose([matrix])
    return transpose

def displayCrypt(crypt):
    crypted = ''
    for chunk in crypt:
        for j in chunk:
            crypted += ASC2CHAR[int(j)]
    
    return crypted

def getInv(matrix):
    det = int(np.round(np.linalg.det(matrix)))
    inv_det = egcd(det, MODULUS)[1] % MODULUS
    return (inv_det * np.round(det * np.linalg.inv(matrix)).astype(int) % MODULUS) 

def encryptDecryptMessage(msg, key, ed):
    repeat = len(msg) // 3
    chunks = []
    for i in range(repeat):
        j = i * N
        chunks.append(msg[j : j + 3])
    
    result = []
    inverse = getInv(key)
    for chunk in chunks:
        k = msgToMatrix(chunk)
        if ed == 1:
            result.append(np.dot(key, k) % MODULUS)
        if ed == 0:
            result.append(np.dot(inverse.astype(int), k) % MODULUS)
    
    return displayCrypt(result)

def main():
    msg = (input('Enter the message: ')).strip().upper()
    msg = formatMessage(msg)
    print('\nFormatted message: ', msg)

    key = keyToMatrix(KEY)
    print(f'\nKey [{KEY}]:\n', key)
    print('\n------------------\nEncryption')
    crypted_msg = encryptDecryptMessage(msg, key, 1)
    print('\nEncrypted Message: ', crypted_msg)

    print('\n------------------\nDecryption')

    original_msg = encryptDecryptMessage(crypted_msg, key, 0)
    print('\nDecrypted Message: ', original_msg)


if __name__ == '__main__':
    main()
