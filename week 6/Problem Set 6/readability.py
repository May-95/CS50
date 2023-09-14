def main():
    text = input("Text: ")
    letters = count_letters(text)
    words = len(text.split(" "))
    sentences = count_sentences(text)
    average_letters = letters / words * 100
    average_sentence = sentences / words * 100
    index = 0.0588 * average_letters - 0.296 * average_sentence - 15.8

    if index >= 16:
        print("Grade 16+")
    elif index < 1:
        print("Before Grade 1")
    else:
        print(f"Grade {round(index)}")


def count_letters(text):
    count = 0
    for letter in text:
        if letter.isalpha():
            count += 1
    return count


def count_sentences(text):
    count = 0
    for letter in text:
        if letter == "!" or letter == "." or letter == "?":
            count += 1
    return count


if __name__ == "__main__":
    main()
