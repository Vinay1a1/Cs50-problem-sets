while (True):
    try:

        text = input("Text: ")
        if len(text) > 0:
            break
    except ValueError:
        continue

letters = sum(char.isalpha() for char in text)

# words
words = len(text.split())

# Sentences
sentences = sum(char in [".", "!", "?"] for char in text)

L = letters*100/words
S = sentences*100/words
index = round((0.0588 * L) - (0.296 * S) - (15.8))

if (index < 1):
    print("Before Grade 1")
elif (index > 16):
    print("Grade 16+")
else:
    print(f"Grade {index}")
