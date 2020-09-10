height = 0;
while(height < 1 or height > 8):
    height = int(input("Positive integer between 1 and 8: "))

space = height - 1

i = 1
while(i <= height):
    for j in range(space):
        print(" ", end="")

    for j in range(i):
        print("#" , end="")

    print("  ", end="")

    for j in range(i):
        print("#", end="")
    print("")
    i += 1
    space -= 1
