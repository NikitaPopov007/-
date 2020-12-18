#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstring>
#include <Windows.h>
#include <string>
#define N 50
#define WORD 33

using namespace sf;
using namespace std;

class Interface
{
private:

	RenderWindow* window;
	char str[N]; //загаданное слово
	char letter; //введенная буква

	char russian_letter[WORD] = { 'а','б','в','г','д','е','ё','ж','з','и','й',
								  'к','л','м','н','о','п','р','с','т','у','ф',
								  'х','ц','ч','ш','щ','ъ','ы','ь','э','ю','я' };

	char english_letter[26] = { 'a','b','c','d','e','f','g','h','i','j','k','l','m',
							    'n','o','p','q','r','s','t','u','v','w','x','y','z' };
	
	char mas[WORD]; //массив угаданных букв
	char word_yes[WORD]; //массив уникальных букв в слове
	char word_no[WORD];
	int kol; //количество уникальных букв в слове
	int num; //количество угаданных букв
	int num1;
	
	int count; //количество букв в слове
	int mistake;

public:

	Interface();
	~Interface();
	void draw_Visel(Text text, int mistake); //рисуем виселицу
	void OpenInterface(); //открываем граф окно
	void game();
	void draw_Word(); //рисуем штрихи
	void draw_Theme(Text text, string theme, string theme1); //рисуем тему
	int if_Win(Text text, int cnt); //проверка на победу
	void menu();
};