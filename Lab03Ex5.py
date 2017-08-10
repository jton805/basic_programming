"""
Lab 3 Ex 5
Author: Jodie Tong

"""

def main():
    sentence = get_sentence_from_user()
    count = count_words(sentence)
    print_number_of_words(sentence, count)
    

def get_sentence_from_user():
    sentence = input("Enter a sentence: ")
    return sentence

def count_words(sentence):
    if len(sentence) == 0:
        return 0
    count = 1
    for letter in sentence:
        if letter == " ": #number of spaces determine number of words
            count += 1
    return count

def print_number_of_words(words, number_of_words):
    print("There are " + str(number_of_words)
          + " words in the sentence '" + words + "'.")

main()


