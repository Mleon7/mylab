# TODO
def main():
    height = get_height()
    for i in range(height):
        for j in range(height - 1, -1, -1):
            if (j <= i): print("#", end="")
            else: print(" ", end="")
        print("  ", end="")
        for j in range(height - 1, -1, -1):
            if (j <= i): print("#", end="")
            # else: print(" ", end="")
        print()


def get_height():
    while True:
        try:
            n = int(input("Height: "))
            if n >= 1 and n <= 8 :
                return n
            else:
                print("wrong number")
        except ValueError:
            print("Not an integer")


main()