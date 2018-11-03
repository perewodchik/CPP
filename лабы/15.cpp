#include <iostream>
#include <string>
#include <locale>
#include <vector>
#include <windows.h>
#include <algorithm>
#define RUSSIAN_VOWEL_QUANTITY 20
#define RUSSIAN_CONSONANTS 10
using namespace std;

/*
#19. �� ������� ����� ������� ������� �����, ���������� �� ����� 1000 ����. 
���� � ������ ��� ���� ���������� ����, �� ������� ����� ������ � �������, 
�������� � �����������, � ��������� ������ ������� �� ���� ������ �������, 
�p������p����� ������ ��������� ����� � ������������� �����. 
������ ���������: ����������. ����� ������� �� ������ � ������.
*/

bool same_words(vector<string> &words);
void remove_vowels(vector<string> &words);
void shift_right(string &word, int &index);
void double_consonants(vector<string> &words);
void reverse_words(vector<string> &words);
void output(const vector<string> &words);


int main()
{
	freopen("input.txt", "r", stdin);
	setlocale(LC_ALL,"");
	vector<string> words;
	string input;
	while(cin >> input)
		words.push_back(input);
	if(!same_words(words))
		sort(words.rbegin(), words.rend());
	else
	{
		remove_vowels(words);
		double_consonants(words);
		reverse_words(words);
	}
	output(words);
	
	return 0;
}

bool same_words(vector<string> &words)
{
	for(int k = 0; k < words.size()-1; k++)
		for(int q = k+1; q < words.size(); q++)
			if(words[k] == words[q])
				return true;
	return false;
}

void remove_vowels(vector<string> &words)
{
	const static char russian_vowels[RUSSIAN_VOWEL_QUANTITY] = {
		'A','�','�','�','�','�','�','�','�','�',
		'�','�','�','�','�','�','�','�','�','�'
	};
	
	for(int q = 0; q < words.size(); q++)
		for(int i = 0; i < words[q].size(); i++)
			for(int k = 0; k < RUSSIAN_VOWEL_QUANTITY; k++)
				if(russian_vowels[k] == words[q][i])
				{
					words[q].erase(i,1);
					//k-- �� ������ ��������� ������� �������
					k--;
				}
}

void shift_right(string &word, int &index)
{
	word.push_back(word.back());
	for(int k = word.size()-1; k > index; k--)
		word[k] = word[k-1];
	//����������� ������ �������� ���������� ��� ����, 
	//����� �� ������������ ���������������� ������
	index++;
}

void double_consonants(vector<string> &words)
{
	const static char russian_consonants[] = {
		'�','�','�','�','�','�','�','�','�','�'
	};
	for(int q = 0; q < words.size(); q++)
		for(int i = 0; i < words[q].size(); i++)
			for(int k = 0; k < RUSSIAN_CONSONANTS; k++)
				if(russian_consonants[k] == words[q][i])
					shift_right(words[q], i);
}

void reverse_words(vector<string> &words)
{
	for(int i = 0; i < words.size(); i++)
		reverse(words[i].begin(), words[i].end());
}

void output(const vector<string> &words)
{
	for(int i = 0; i < words.size(); i++)
		cout << words[i] << endl;
}

