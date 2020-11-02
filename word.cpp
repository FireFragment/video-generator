#include "word.h"

void word::changeWord(string textOfWord)
{
	text = textOfWord;

	//Checks, if word is in uppercase. If yes, sets accentutation to 3.
	accentutation = 3;
	for (size_t i = 0; i < textOfWord.length(); i++)
		if ((!isupper(static_cast<unsigned char>(textOfWord[i]))) && isalpha(static_cast<unsigned char>(textOfWord[i])))
			accentutation = 0;
}

word::word(string textOfWord) {
	text = textOfWord;
	changeWord(textOfWord);
}
