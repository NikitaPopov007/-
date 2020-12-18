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
	char str[N]; //���������� �����
	char letter; //��������� �����

	char russian_letter[WORD] = { '�','�','�','�','�','�','�','�','�','�','�',
								  '�','�','�','�','�','�','�','�','�','�','�',
								  '�','�','�','�','�','�','�','�','�','�','�' };

	char english_letter[26] = { 'a','b','c','d','e','f','g','h','i','j','k','l','m',
							    'n','o','p','q','r','s','t','u','v','w','x','y','z' };
	
	char mas[WORD]; //������ ��������� ����
	char word_yes[WORD]; //������ ���������� ���� � �����
	char word_no[WORD];
	int kol; //���������� ���������� ���� � �����
	int num; //���������� ��������� ����
	int num1;
	
	int count; //���������� ���� � �����
	int mistake;

public:

	Interface();
	~Interface();
	void draw_Visel(Text text, int mistake); //������ ��������
	void OpenInterface(); //��������� ���� ����
	void game();
	void draw_Word(); //������ ������
	void draw_Theme(Text text, string theme, string theme1); //������ ����
	int if_Win(Text text, int cnt); //�������� �� ������
	void menu();
};