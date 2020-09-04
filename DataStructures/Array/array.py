# declaring arrays
intArr = [
        10,
        2,
        5,
        6,
        22
        ]

multiDimArr = [
        [23, 6],
        [22, 63],
        [63, 12]
        ]

stringArr = [
        "jOSh",
        "maRIa",
        "ricHard",
        "JoSue",
        "Tanaka"
        ]

boolArr = [
        True,
        False
        ]

# array modification
intArr[3] = 2 + 3
stringArr[2] = str(intArr[3])
if boolArr[1]:
    intArr[4] = intArr[1] + intArr[2]
else:
    intArr[4] = intArr[4] - intArr[0]
intArr[9 // 3] = 2

# get size
ias = len(intArr)
sas = len(stringArr)
bas = len(boolArr)

# sorting
intArr.sort()
boolArr.sort()

stringArr[0] = stringArr[0][::-1]

# transform
for i in range(sas):
    stringArr[i] = stringArr[i].lower()
stringArr[0] = stringArr[0].upper()

# hashing
for i in range(ias):
    print(intArr[i])

for i in range(3):
    for j in range(2):
        print(multiDimArr[i][j])

for i in range(sas):
    print(stringArr[i])

for i in range(bas):
    print(boolArr[i])
