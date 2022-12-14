# Problem Set 2, hangman.py
# Name: 
# Collaborators:
# Time spent:

# Hangman Game
# -----------------------------------
# Helper code
# You don't need to understand this helper code,
# but you will have to know how to use the functions
# (so be sure to read the docstrings!)
import random
import string
import re
import subprocess as sp

WORDLIST_FILENAME = "words.txt"


def load_words():
    """
    Returns a list of valid words. Words are strings of lowercase letters.
    
    Depending on the size of the word list, this function may
    take a while to finish.
    """
    print("Loading word list from file...")
    # inFile: file
    inFile = open(WORDLIST_FILENAME, 'r')
    # line: string
    line = inFile.readline()
    # wordlist: list of strings
    wordlist = line.split()
    print("  ", len(wordlist), "words loaded.")
    return wordlist



def choose_word(wordlist):
    """
    wordlist (list): list of words (strings)
    
    Returns a word from wordlist at random
    """
    return random.choice(wordlist)

# end of helper code

# -----------------------------------

# Load the list of words into the variable wordlist
# so that it can be accessed from anywhere in the program
wordlist = load_words()


def is_word_guessed(secret_word, letters_guessed):
    '''
    secret_word: string, the word the user is guessing; assumes all letters are
      lowercase
    letters_guessed: list (of letters), which letters have been guessed so far;
      assumes that all letters are lowercase
    returns: boolean, True if all the letters of secret_word are in letters_guessed;
      False otherwise
    '''
    # FILL IN YOUR CODE HERE AND DELETE "pass"
    for word in secret_word:
      if word not in letters_guessed:
        return False

    return True


def get_guessed_word(secret_word, letters_guessed):
    '''
    secret_word: string, the word the user is guessing
    letters_guessed: list (of letters), which letters have been guessed so far
    returns: string, comprised of letters, underscores (_), and spaces that represents
      which letters in secret_word have been guessed so far.
    '''
    # FILL IN YOUR CODE HERE AND DELETE "pass"
    guessed_word_list=[ '_' for i in range(len(secret_word))]
    for i,letter in enumerate(letters_guessed):
      for j,char in enumerate(secret_word):
        if char == letter:
          guessed_word_list[j]=letter
    
    guessed_word=''
    for letter in guessed_word_list:
      guessed_word+=letter

    final_guessed_word='\'{guessed}\''.format(guessed=guessed_word)
    return final_guessed_word


def get_available_letters(letters_guessed):
    '''
    letters_guessed: list (of letters), which letters have been guessed so far
    returns: string (of letters), comprised of letters that represents which letters have not
      yet been guessed.
    '''
    # FILL IN YOUR CODE HERE AND DELETE "pass"
    
    available_letters_list=list(string.ascii_lowercase)
    index_letters_guessed=[]
    for letter in letters_guessed:
      index_letters=ord(letter)-97
      if index_letters<0 or index_letters>25:
        continue
      else:
        index_letters_guessed.append(index_letters)
    
    for index in index_letters_guessed:
      available_letters_list[index]=' '

    available_letters=''
    for letter in available_letters_list:
      available_letters+=letter

    return available_letters

def prompting_user(warning, guess, guessed_letter, secret_word):
  inform_guess='You have {num} guess left'.format(num=guess)
  inform_warning='You have {num} warning left'.format(num=warning)
  inform_available_letters='Available letters: \'{letters}\''.format(letters=get_available_letters(guessed_letter))
  print(inform_warning)
  print(inform_guess)
  print(inform_available_letters)
  print(get_guessed_word(secret_word,guessed_letter))
  please_guess='Please guess a letter: '
  print(please_guess, end='')


def hangman(secret_word):
    '''
    secret_word: string, the secret word to guess.
    
    Starts up an interactive game of Hangman.
    
    * At the start of the game, let the user know how many 
      letters the secret_word contains and how many guesses s/he starts with.
      
    * The user should start with 6 guesses

    * Before each round, you should display to the user how many guesses
      s/he has left and the letters that the user has not yet guessed.
    
    * Ask the user to supply one guess per round. Remember to make
      sure that the user puts in a letter!
    
    * The user should receive feedback immediately after each guess 
      about whether their guess appears in the computer's word.

    * After each guess, you should display to the user the 
      partially guessed word so far.
    
    Follows the other limitations detailed in the problem write-up.
    '''
    # FILL IN YOUR CODE HERE AND DELETE "pass"
    print("Welcome to the game Hangman!")
    word_length=len(secret_word)
    print('I am thinking of a word that is {word} letters long'.format(word=word_length))
    print('-------------')
    warning=3
    guess=6
    scoreMultiplier=0
    guessed_letter=[]
    prompting_user(warning, guess, guessed_letter, secret_word)

    #play
    while not (is_word_guessed(secret_word, guessed_letter) or guess<0):
      # sp.call('clear', shell=True)
      user_guess=input().lower()
      cek=re.findall('\w{1}',user_guess)

      if cek:
        if cek[0] in guessed_letter or (cek[0] in '1234567890'):
          if warning>0:
            warning-=1
          else:
            guess-=1

          if guess<=0:
            break
          else:
            print('===============')
            print('You have already input that')
            prompting_user(warning, guess, guessed_letter, secret_word)

        elif cek[0] in secret_word:
          scoreMultiplier+=1
          guessed_letter.append(cek[0])
          if is_word_guessed(secret_word, guessed_letter):
            break
          else:
            print('===============')
            guessed_letter.append(cek[0])
            print('Good guess: {word}'.format(word=get_guessed_word(secret_word,guessed_letter)))
            prompting_user(warning, guess, guessed_letter, secret_word)
            # print(get_available_letters(guessed_letter))
        elif cek[0] not in secret_word and cek[0] in 'aeiou':
          guess-=2

          if guess<=0:
            break
          else:
            print('===============')
            print('Oop! {letter} is not in my word'.format(letter=cek[0]))
            prompting_user(warning, guess, guessed_letter, secret_word)

        else:
          guess-=1

          if guess<=0:
            break
          else:
            print('===============')
            print('Oops! {letter} is not in my word'.format(letter=cek[0]))
            prompting_user(warning, guess, guessed_letter, secret_word)
        guessed_letter.append(cek[0])
      else:
        if warning>0:
          warning-=1
        elif warning==0:
          guess-=1

        if guess<=0:
          break
        else:
          print('===============')
          print('Oops! That is not a valid letter. You have {num} warning left: {word}'.format(num=warning,word=get_guessed_word(secret_word,guessed_letter)))
          prompting_user(warning, guess, guessed_letter, secret_word)
        
      # print(guessed_letter)

    if guess<=0:
      # sp.call('clear', shell=True)
      print('===============')
      # print('You lose')
      print('Sorry, you ran out of guesses. Secret word is \'{word}\''.format(word=secret_word))
      print(secret_word)
    else:
      # sp.call('clear', shell=True
      print('===============')
      print('Congratulation, You won!')
      print('Secret word is \'{word}\''.format(word=secret_word))
      print('Your total score for this game is: {scr}'.format(scr=scoreMultiplier*guess))
# When you've completed your hangman function, scroll down to the bottom
# of the file and uncomment the first two lines to test
#(hint: you might want to pick your own
# secret_word while you're doing your own testing)


# -----------------------------------



def match_with_gaps(my_word, other_word):
    '''
    my_word: string with _ characters, current guess of secret word
    other_word: string, regular English word
    returns: boolean, True if all the actual letters of my_word match the 
        corresponding letters of other_word, or the letter is the special symbol
        _ , and my_word and other_word are of the same length;
        False otherwise: 
    '''
    # FILL IN YOUR CODE HERE AND DELETE "pass"
    my_word_length=len(my_word)
    other_word_length=len(other_word)

    if my_word_length == other_word_length:
      for i in range(my_word_length):
        if my_word[i]!='_' and my_word[i].lower()!=other_word[i].lower():
          return False
    else:
      return False
    return True


def show_possible_matches(my_word):
    '''
    my_word: string with _ characters, current guess of secret word
    returns: nothing, but should print out every word in wordlist that matches my_word
             Keep in mind that in hangman when a letter is guessed, all the positions
             at which that letter occurs in the secret word are revealed.
             Therefore, the hidden letter(_ ) cannot be one of the letters in the word
             that has already been revealed.

    '''
    # FILL IN YOUR CODE HERE AND DELETE "pass"
    matched_list=[]
    for word in wordlist:
      if match_with_gaps(my_word,word):
        matched_list.append(word)

    if matched_list:
      matched_list=' '.join(matched_list)
      return matched_list
    else:
      return 'No matches found'

print(type(get_guessed_word('apple','abcel')[1:-1]))
print(show_possible_matches(get_guessed_word('apple','abcel')[1:-1]))


def hangman_with_hints(secret_word):
    '''
    secret_word: string, the secret word to guess.
    
    Starts up an interactive game of Hangman.
    
    * At the start of the game, let the user know how many 
      letters the secret_word contains and how many guesses s/he starts with.
      
    * The user should start with 6 guesses
    
    * Before each round, you should display to the user how many guesses
      s/he has left and the letters that the user has not yet guessed.
    
    * Ask the user to supply one guess per round. Make sure to check that the user guesses a letter
      
    * The user should receive feedback immediately after each guess 
      about whether their guess appears in the computer's word.

    * After each guess, you should display to the user the 
      partially guessed word so far.
      
    * If the guess is the symbol *, print out all words in wordlist that
      matches the current guessed word. 
    
    Follows the other limitations detailed in the problem write-up.
    '''
    # FILL IN YOUR CODE HERE AND DELETE "pass"
    print("Welcome to the game Hangman!")
    word_length=len(secret_word)
    print('I am thinking of a word that is {word} letters long'.format(word=word_length))
    print('-------------')
    warning=3
    guess=6
    scoreMultiplier=0
    guessed_letter=[]
    prompting_user(warning, guess, guessed_letter, secret_word)

    #play
    while not (is_word_guessed(secret_word, guessed_letter) or guess<0):
      # sp.call('clear', shell=True)
      user_guess=input().lower()
      if user_guess=='*':
        print('=============')
        print('Your suggestion words')
        print(show_possible_matches(get_guessed_word(secret_word, guessed_letter)[1:-1]))
        prompting_user(warning, guess, guessed_letter, secret_word)
      else:
        cek=re.findall('\w{1}',user_guess)

        if cek:
          if cek[0] in guessed_letter or (cek[0] in '1234567890'):
            if warning>0:
              warning-=1
            else:
              guess-=1

            if guess<=0:
              break
            else:
              print('===============')
              print('You have already input that')
              prompting_user(warning, guess, guessed_letter, secret_word)

          elif cek[0] in secret_word:
            scoreMultiplier+=1
            guessed_letter.append(cek[0])
            if is_word_guessed(secret_word, guessed_letter):
              break
            else:
              print('===============')
              guessed_letter.append(cek[0])
              print('Good guess: {word}'.format(word=get_guessed_word(secret_word,guessed_letter)))
              prompting_user(warning, guess, guessed_letter, secret_word)
              # print(get_available_letters(guessed_letter))
          elif cek[0] not in secret_word and cek[0] in 'aeiou':
            guess-=2

            if guess<=0:
              break
            else:
              print('===============')
              print('Oop! {letter} is not in my word'.format(letter=cek[0]))
              prompting_user(warning, guess, guessed_letter, secret_word)

          else:
            guess-=1

            if guess<=0:
              break
            else:
              print('===============')
              print('Oops! {letter} is not in my word'.format(letter=cek[0]))
              prompting_user(warning, guess, guessed_letter, secret_word)
          guessed_letter.append(cek[0])
        else:
          if warning>0:
            warning-=1
          elif warning==0:
            guess-=1

          if guess<=0:
            break
          else:
            print('===============')
            print('Oops! That is not a valid letter. You have {num} warning left: {word}'.format(num=warning,word=get_guessed_word(secret_word,guessed_letter)))
            prompting_user(warning, guess, guessed_letter, secret_word)
        
      # print(guessed_letter)

    if guess<=0:
      # sp.call('clear', shell=True)
      print('===============')
      # print('You lose')
      print('Sorry, you ran out of guesses. Secret word is \'{word}\''.format(word=secret_word))
      print(secret_word)
    else:
      # sp.call('clear', shell=True
      print('===============')
      print('Congratulation, You won!')
      print('Secret word is \'{word}\''.format(word=secret_word))
      print('Your total score for this game is: {scr}'.format(scr=scoreMultiplier*guess))



# When you've completed your hangman_with_hint function, comment the two similar
# lines above that were used to run the hangman function, and then uncomment
# these two lines and run this file to test!
# Hint: You might want to pick your own secret_word while you're testing.


if __name__ == "__main__":
    # pass

    # To test part 2, comment out the pass line above and
    # uncomment the following two lines.
    
    # secret_word = choose_word(wordlist)
    # hangman(secret_word)

###############
    
    # To test part 3 re-comment out the above lines and 
    # uncomment the following two lines. 
    
    secret_word = choose_word(wordlist)
    hangman_with_hints('apple')