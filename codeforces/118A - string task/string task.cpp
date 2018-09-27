#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
	string word;
	string new_word;
	cin >> word;
	
	transform(word.begin(), word.end(), word.begin(), ::tolower);
	for(int i = 0; i < word.length(); i++)
	{
		if(   !(word[i] == 'a' ||
				word[i] == 'o' ||
				word[i] == 'y' ||
				word[i] == 'e' ||
				word[i] == 'u' ||
				word[i] == 'i' ))
		{
			new_word = new_word + "." + word[i];
		}

	}
	cout << new_word;
}
