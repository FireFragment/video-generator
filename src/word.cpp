#include "word.h"

void word::changeWord(string textOfWord)
{
	text = textOfWord;
}

word::word(string textOfWord) {
	text = textOfWord;
	changeWord(textOfWord);
}
