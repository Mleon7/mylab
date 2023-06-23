import sys
import random
from pyfiglet import Figlet

def print_usage():
    print("Invalid usage")
    sys.exit(1)

def choose_random_font():
    figlet = Figlet()
    fonts = figlet.getFonts()
    return random.choice(fonts)

def main():
    if len(sys.argv) not in (1, 3):
        print_usage()
        return

    if len(sys.argv) == 3:
        if sys.argv[1] not in ("-f", "--font"):
            print_usage()
        else:
            font = sys.argv[2]
            figlet = Figlet()
            if font not in figlet.getFonts():
                print_usage()
    else:
        font = choose_random_font()

    figlet = Figlet(font=font)
    text = input("Enter text: ")
    print(figlet.renderText(text))

if __name__ == "__main__":
    main()