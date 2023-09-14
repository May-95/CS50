height = 0

while height < 1 or height > 8:
    height = input("Height: ")
    isNum = height.isdigit()
    if not isNum:
        height = 0
    height = int(height)

count = 0
space = height - 1
# for each row
for x in range(height):
    count += 1
    # create the space before the hashes
    for x in range(space):
        print(" ", end="")
    # print the hashes
    for x in range(count * 2):
        half = (count * 2) / 2
        # adds the space for the halfway mark
        if x == half:
            print("  ", end="")
        print("#", end="")
    print("")
    space -= 1
