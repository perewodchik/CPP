#include <iostream>
#include <string>
#include <locale>
#include <vector>
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
void input(vector<string> &words);

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	setlocale(LC_ALL,"");
	vector<string> words;
	input(words);
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

void input(vector<string> &words)
{
	string symbols;
	string word;
	while( cin >> symbols )
	{
		word = "";
		for(int i = 0; i < symbols.size(); i++)
			if( (int) symbols[i] >= '�' && (int) symbols[i] <= '�')
				word += symbols[i];
		if(word != "")
			words.push_back(word);
	}
}

bool same_words(vector<string> &words)
{
	for(int k = 0; k < words.size()-1; k++)
		for(int q = k+1; q < words.size(); q++)
			if(words[k] == words[q])
				return true;
	return false;
}

//������� ������� �� ����
void remove_vowels(vector<string> &words)
{
	const static char russian_vowels[RUSSIAN_VOWEL_QUANTITY] = {
		'�','�','�','�','�','�','�','�','�','�',
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

//��������� ������ ���������
void double_consonants(vector<string> &words)
{
	const static char russian_consonants[RUSSIAN_CONSONANTS] = {
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
		if(words[i] != "") 
			cout << words[i] << endl;
}

