# TODO
from cs50 import get_string

def count_letters(text):
    cnt = 0
    for i in range(len(text)):
        if (text[i].isalnum()):
            cnt += 1
    return cnt


def count_words(text):
    cnt = 1
    for i in range(len(text)):
        if (text[i].isspace()):
            cnt += 1
    return cnt

def count_sentences(text):
    cnt = 0
    for i in range(0, len(text)):
        if text[i] == '.' or text[i] == '!' or text[i] == '?':
            cnt += 1
    return cnt

def main():
    text = get_string("Text: ")

    letters = count_letters(text)
    words = count_words(text)
    sentences = count_sentences(text)

    L = (letters / words) * 100
    S = (sentences / words) * 100

    index = round(0.0588 * L - 0.296 * S - 15.8)

    if index <= 1:
        print("Before Grade 1")
    elif index <= 15:
        print(f"Grade {index}")
    elif index >= 16:
        print("Grade 16+")
    else:
        print("Error")

if __name__ == "__main__":
    main()