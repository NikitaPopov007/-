#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstring>
#include <Windows.h>
#define N 50
#define WORD 33
#include "Interface.h"

using namespace sf;
using namespace std;

void draw_Visel(RenderWindow* window, int mistake)
{
	//int mistake = 1;
	int radius = 30;
	int X0 = 300, Y0 = 300;
	int X1 = X0 + radius, Y1 = Y0 + 2 * radius; //координаты начала туловища и рук

	int leng_body = 100, leng_arm_leg = 50; //длина туловища, рук, ног
	int leng_kanat = 100; //длина каната
	int leng_osn = leng_kanat + leng_body + 2 * radius + 2 * leng_arm_leg + 100; //длина основания 

	if (mistake >= 1)
	{
		RectangleShape line_with_thickness5(Vector2f(1, leng_osn)); //вертикальная линия
		line_with_thickness5.setFillColor(Color::White); //установка цвета
		line_with_thickness5.move(X0 - 150, Y0 - leng_kanat);
		window->draw(line_with_thickness5);
	}	
	if (mistake >= 2)
	{
		RectangleShape line_with_thickness6(Vector2f(1, 300)); //горизонтальная линия
		line_with_thickness6.setFillColor(Color::White);
		line_with_thickness6.rotate(-90);
		line_with_thickness6.move(X0 - 150, Y0 - leng_kanat); 
		window->draw(line_with_thickness6);
	}
	if (mistake >= 3)
	{
		RectangleShape line_with_thickness7(Vector2f(1, 70)); //диагольная линия
		line_with_thickness7.setFillColor(Color::White);
		line_with_thickness7.rotate(45);
		line_with_thickness7.move(X0 - 100, Y0 - leng_kanat); 
		window->draw(line_with_thickness7);
	}
	if (mistake >= 4)
	{
		RectangleShape line_with_thickness8(Vector2f(1, 100)); //канат
		line_with_thickness8.setFillColor(Color::White);
		line_with_thickness8.move(X1, Y0 - leng_kanat); 
		window->draw(line_with_thickness8);
	}
	if (mistake >= 5)
	{
		CircleShape circle(radius); //рисуем круг с радиусом 20
		circle.setFillColor(Color::Black); //цвет заливки круга
		circle.setOutlineThickness(1);  //ширина контура
		circle.setOutlineColor(Color::White); // цвет контура
		circle.move(X0, Y0); //перемещаем круг на х, y координату
		window->draw(circle);
	}
	if (mistake >= 6)
	{
		RectangleShape line_with_thickness(Vector2f(1, leng_body)); //туловище
		line_with_thickness.setFillColor(Color::White);
		line_with_thickness.move(X1, Y1); 
		window->draw(line_with_thickness);
	}
	if (mistake >= 7)
	{
		RectangleShape line_with_thickness1(Vector2f(1, leng_arm_leg)); //левая рука
		line_with_thickness1.setFillColor(Color::White);
		line_with_thickness1.rotate(45);
		line_with_thickness1.move(X1, Y1); 
		window->draw(line_with_thickness1);
	}
	if (mistake >= 8)
	{
		RectangleShape line_with_thickness2(Vector2f(1, leng_arm_leg)); //правая рука
		line_with_thickness2.setFillColor(Color::White);
		line_with_thickness2.rotate(-45);
		line_with_thickness2.move(X1, Y1);
		window->draw(line_with_thickness2);
	}
	if (mistake >= 9)
	{
		RectangleShape line_with_thickness3(Vector2f(1, leng_arm_leg)); //левая нога
		line_with_thickness3.setFillColor(Color::White);
		line_with_thickness3.rotate(45);
		line_with_thickness3.move(X1, Y1 + leng_body);
		window->draw(line_with_thickness3);
	}
	if (mistake >= 10)
	{
		RectangleShape line_with_thickness4(Vector2f(1, leng_arm_leg)); //правая нога
		line_with_thickness4.setFillColor(Color::White);
		line_with_thickness4.rotate(-45);
		line_with_thickness4.move(X1, Y1 + leng_body);
		window->draw(line_with_thickness4);
	}
}


int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Interface* inter = new Interface();

	inter->OpenInterface();
	inter->game();

	delete inter;

	system("pause");
	return 0;
	//RenderWindow* window;
	//window = new RenderWindow(VideoMode(1580, 720), "HangMan");
	//window->display();

	//char letter[WORD] = { 'а','б','в','г','д','е','ё','ж','з','и','й',
	//					  'к','л','м','н','о','п','р','с','т','у','ф',
	//					  'х','ц','ч','ш','щ','ъ','ы','ь','э','ю','я' };

	//Text text2[WORD];

	//bool isMove = false;
	//int z = -1;

	//char s[N];
	//char str; //символ выбранный
	//

	//float m = 500;

	//int a;
	//int mistake = 0;
	//int flag = 0, flag_g = 0;
	//char word_yes[WORD];
	//char word[N];

	//int k = 0;
	//int num = 0;

	//int X = 500; //координата первой буквы
	//int coord = 35;
	//int kk = 0;

	//char mas[N] = {};//массив угаданных букв
	//int obj = 0;
	//int com[WORD] = { 0 }; //массив номера буквы в слове

	//int coordx, coordy;

	//cout << "Введите: ";
	//cin >> s;
	//a = strlen(s);

	//for (int i = 0; i < a; i++)
	//{
	//	word[i] = s[i];
	//	for (int j = 0; j < k; j++)
	//	{
	//		if (word_yes[j] == s[i])
	//		{
	//			flag = 1;
	//			break;
	//		}
	//	}

	//	if (flag == 1)
	//	{
	//		flag = 0;
	//	}
	//	else
	//	{
	//		word_yes[k] = s[i];
	//		k++;
	//	}
	//}

	//for (int f = 0; f < k; f++)
	//{
	//	cout << word_yes[f] << " ";
	//}

	//cout << "\n\n\n\n";

	//
	//flag = 0;

	//while (window->isOpen())
	//{
	//	Event event;

	//	while (window->pollEvent(event))
	//	{
	//		if (event.type == Event::Closed)
	//		{
	//			window->close();
	//		}
	//	}


	//	int m = 500;

	//	RectangleShape line_word(Vector2f(3, 20));
	//	line_word.setFillColor(Color::White);
	//	line_word.rotate(-90);
	//	line_word.move(m, 150);
	//	window->draw(line_word);


	//	for (int i = 0; i < a - 1; i++)
	//	{

	//		m += 35;
	//		line_word.setPosition(m, 150);
	//		window->draw(line_word);

	//	}

	//	Font font;
	//	font.loadFromFile("CyrilicOld.ttf");

	//	Text text("", font, 20);
	//	text.setString("ТЕМА: ");
	//	text.setPosition(20, 20);
	//	window->draw(text);

	//	text.setString(s);
	//	text.setPosition(120, 20);
	//	window->draw(text);


	//	Texture texture;
	//	texture.loadFromFile("alphavit.png");
	//	Sprite sprite[33];
	//	 
	//	int n = 0;
	//	int Width = 80;
	//	for (int i = 0; i < 3; i++)
	//	{
	//		for (int j = 0; j < 11; j++)
	//		{
	//			sprite[n].setTexture(texture);
	//			sprite[n].scale(0.9, 0.9);
	//			sprite[n].setTextureRect(IntRect(j*Width, i*Width, Width, Width));

	//			sprite[n].setPosition(500 + j * Width, 300 + i * Width);
	//			window->draw(sprite[n]);
	//			n++;
	//		}
	//	}
	//	n = 0;
	//	


	//	for (int i = 0; i < 3; i++)
	//	{
	//		for (int j = 0; j < 11; j++)
	//		{
	//			if (IntRect(500 + j * Width, 300 + i * Width, Width, Width).contains(Mouse::getPosition(*window)))
	//			{
	//				sprite[n].setColor(Color::Green);
	//				window->draw(sprite[n]);

	//			}
	//			n++;
	//		}
	//	}

	//	//n = 0;
	//	while (window->pollEvent(event))
	//	{
	//		if (event.type == Event::Closed)
	//		{
	//			window->close();
	//		}

	//		if (event.type == Event::MouseButtonPressed)
	//		{
	//			if (event.mouseButton.button == Mouse::Left)
	//			{
	//				isMove = true;

	//				//Vector2i cordMouse = Mouse::getPosition(*window);
	//				//coordx = cordMouse.x;
	//				//coordy = cordMouse.y;

	//				
	//				coordx = event.mouseButton.x;
	//				coordy = event.mouseButton.y;
	//				cout << coordx << endl;
	//				cout << coordy << endl;


	//				if (coordx < 500 && coordx > 500 + 11 * Width && coordy < 300 && coordy > 300 + 3 * Width)
	//				{
	//					cout << "Неправильный ввод" << endl;
	//				}
	//				else
	//				{
	//					n = 0;
	//					for (int i = 0; i < 3; i++)
	//					{
	//						for (int j = 0; j < 11; j++)
	//						{

	//							if (coordx >= 500 + j * Width && coordx <= 500 + j * Width + Width && coordy >= 300 + i * Width && coordy <= 300 + i * Width + Width)
	//							{
	//								sprite[n].setColor(Color::Red);
	//								window->draw(sprite[n]);
	//								str = letter[n];
	//								
	//							}
	//							n++;
	//						}

	//					}

	//				}
	//			}


	//		}
	//	}

	//		
	//	if (isMove)
	//	{

	//			obj = 0;
	//			for (int i = 0; i < a; i++) //определяем количество этой буквы в слове
	//			{
	//				if (s[i] == str)
	//				{
	//					obj++;
	//					com[kk] = i;
	//					kk++;
	//				}
	//			}

	//			for (int i = 0; i < k; i++)
	//			{
	//				if (word_yes[i] == str) //есть ли буква в массиве оригинальных букв в слове
	//				{
	//					flag = 1;
	//					for (int j = 0; j < obj; j++)
	//					{
	//						mas[num] = str;
	//						num++;
	//					}

	//					break;
	//				}
	//				else
	//				{
	//					flag = 0;
	//				}
	//			}



	//			if (flag == 0)
	//			{
	//				mistake++;
	//				draw_Visel(window, mistake);
	//			}
	//			else
	//			{
	//				draw_Visel(window, mistake);
	//			}

	//			for (int i = 0; i < num; i++)
	//			{
	//				text2[i].setFont(font);
	//				text2[i].setString(mas[i]);
	//				text2[i].setPosition(X + coord * com[i], 110);
	//				window->draw(text2[i]);
	//			}
	//			isMove = false;
	//	}


	//	window->display();
	//}


	////}
	//system("pause");
	//return 0;
}