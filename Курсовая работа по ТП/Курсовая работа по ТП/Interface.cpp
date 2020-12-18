#include "Interface.h"

Interface::Interface()
{
	kol = 0;
	num = 0;
	num1 = 0;
	mistake = 0;
}

Interface::~Interface()
{

}


void Interface::OpenInterface()
{
	this->window = new RenderWindow(VideoMode(1580, 720), "HangMan");
	this->window->display();
}


void Interface::game()
{
	
	int choose_language;
	Font font_russian;
	Font font_english;

	try
	{
		if (!font_russian.loadFromFile("CyrilicOld.ttf"))
		{
			throw "Не удалось загрузить шрифт из файла";
		}
		if (!font_english.loadFromFile("arial.ttf"))
		{
			throw "Не удалось загрузить шрифт из файла";
		}
	}
	catch (const char* exc)
	{
		cout << exc << endl;
	}

	Texture texture1;
	Texture texture2;

	try
	{
		if (!texture1.loadFromFile("alphavit.png")) //загружаем текстуру из файла
		{
			throw "Не удалось загрузить текстуру из файла";
		}

		if (!texture2.loadFromFile("alphavit_English.png")) //загружаем текстуру из файла
		{
			throw "Не удалось загрузить текстуру из файла";
		}
	}
	catch (const char* exc)
	{
		cout << exc << endl;
	}
	
	//menu();
	//window->clear();

	bool FLAG = 0;

	bool isMove = false; //переменная для события
	int coordx, coordy; //координаты нажатия лкм
	int n = 0, Width = 80;

	Text text("", font_russian, 20);
	Text text1[WORD];

	string theme; //тема
	string theme1 = "Буквы, которых нет в слове";

	int obj = 0;
	int com[N]; //массив номера буквы в слове

	int kk = 0;
	int Xl = 600, Yl = 60, Xcoord = 35; //коордтнаты буквы
	int cnt = 0; //счетчик на проверку введенных букв с буквами в загаданном слове


	try
	{
		cout << "Выберете, на каком языке будет загадано слово (1. Русский, 2. Английский): ";
		cin >> choose_language;

		if (choose_language > 2) //если больше двух то исключение
		{
			throw "Вы не выбрали язык ввода";
		}
	}
	catch (const char *exc)
	{
		cout << exc << endl;
		cout << "Введите заново значение 1 или 2" << endl;

		cout << "Выберете, на каком языке будет загадано слово (1. Русский, 2. Английский): ";
		cin >> choose_language;
	}


	try
	{
		cout << "Введите слово: ";
		cin >> str;
		
		count = strlen(str); //определяем количество букв
		
		if (choose_language == 1)
		{
			for (int i = 0; i < count; i++)
			{
				if (str[i] >= 'а' && str[i] <= 'п' || str[i] >= 'р' && str[i] <= 'я') //если не все буквы русского языка, то исключение
				{
					n++;
				}
			}

			if (n != count)
			{
				throw 1;
			}

		}
		else if (choose_language == 2)
		{
			for (int i = 0; i < count; i++)
			{
				if (str[i] >= 'a' && str[i] <= 'z') //если не все буквы английского языка, то исключение
				{
					n++;
				}
			}

			if (n != count)
			{
				throw 1;
			}
			
		}
		
		cin.ignore(32676, '\n');

		if (cin.fail())
		{
			throw "Произошел некорректный ввод";
		}

	}
	catch (const char* exc)
	{
		cout << exc << endl;
		cin.clear();
		cin.ignore(32767, '\n');
	}
	catch (int err)
	{
		cout << "Введите слово заново на правильном языке" << endl;
		
		cout << "Введите слово: ";
		cin >> str;
	}

	
	try
	{
		cout << "Введите тему загаданного слова: ";
		getline(cin, theme);

		cin.ignore(32676, '\n');

		if (cin.fail())
		{
			throw "Произошел некорректный ввод";
		}
	}
	catch (const char* exc)
	{
		cout << exc << endl;
		cin.clear();
		cin.ignore(32767, '\n');
	}

	system("cls");

	for (int i = 0; i < count; i++)
	{
		for (int j = 0; j < kol; j++)
		{
			if (word_yes[j] == str[i])
			{
				FLAG = 1;
				break;
			}
		}

		if (FLAG == 1)
		{
			FLAG = 0;
		}
		else
		{
			word_yes[kol] = str[i];
			kol++;
		}
	}
	FLAG = 0;
	


	while (this->window->isOpen() && mistake < 10)
	{
		Event event;

		draw_Word(); //рисуем слово
		draw_Theme(text, theme, theme1); //рисуем тему

		Sprite sprite1[WORD];
		Sprite sprite2[26];
		
		n = 0;
		if (choose_language == 1)
		{

			for (int i = 0; i < 3; i++) //количество строк
			{
				for (int j = 0; j < 11; j++) //количество столбцов
				{
					sprite1[n].setTexture(texture1);
					sprite1[n].scale(0.9, 0.9); //уменьшаем текстуру
					sprite1[n].setTextureRect(IntRect(j*Width, i * Width, Width, Width)); //разделяем ее по буквам

					sprite1[n].setPosition(500 + j * Width, 300 + i * Width); //перемещаем в определенное место
					window->draw(sprite1[n]);
					n++;
				}
			}
		}
		else if(choose_language == 2)
		{ 
			for (int i = 0; i < 2; i++)
			{
				for (int j = 0; j < 13; j++)
				{
					sprite2[n].setTexture(texture2);
					sprite2[n].scale(0.9, 0.9); //уменьшаем текстуру
					sprite2[n].setTextureRect(IntRect(j * Width, i * Width, Width, Width)); //разделяем ее по буквам

					sprite2[n].setPosition(500 + j * Width, 300 + i * Width); //перемещаем в определенное место
					window->draw(sprite2[n]);
					n++;
				}
			}
		}
		
	
		n = 0;
		if (choose_language == 1)
		{
			for (int i = 0; i < 3; i++)
			{
				for (int j = 0; j < 11; j++)
				{
					if (IntRect(500 + j * Width, 300 + i * Width, Width, Width).contains(Mouse::getPosition(*window)))
					{
						sprite1[n].setColor(Color::Green);
						window->draw(sprite1[n]);

					}
					n++;
				}
			}
		}
		else if (choose_language == 2)
		{
			for (int i = 0; i < 2; i++)
			{
				for (int j = 0; j < 13; j++)
				{
					if (IntRect(500 + j * Width, 300 + i * Width, Width, Width).contains(Mouse::getPosition(*window)))
					{
						sprite2[n].setColor(Color::Green);
						window->draw(sprite2[n]);

					}
					n++;
				}
			}
		}



		while (this->window->pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				this->window->close();
			}


			if (event.type == Event::MouseButtonPressed)
			{
				if (event.mouseButton.button == Mouse::Left)
				{
					

					coordx = event.mouseButton.x;
					coordy = event.mouseButton.y;

					try
					{
						
							n = 0;
							isMove = true;

							if (choose_language == 1)
							{
								if (coordx < 500 || coordx > 500 + 11 * Width || coordy < 300 || coordy > 300 + 3 * Width)
								{
									throw "Неправильный ввод";
								}
								else
								{
									n = 0;
									isMove = true;

									for (int i = 0; i < 3; i++)
									{
										for (int j = 0; j < 11; j++)
										{

											if (coordx >= 500 + j * Width && coordx <= 500 + j * Width + Width && coordy >= 300 + i * Width && coordy <= 300 + i * Width + Width)
											{
												letter = russian_letter[n];
											}
											n++;
										}
									}
								}
							}
							else if (choose_language == 2)
							{
								if (coordx < 500 || coordx > 500 + 13 * Width || coordy < 300 || coordy > 300 + 2 * Width)
								{
									throw "Неправильный ввод";
								}
								else
								{
									n = 0;
									isMove = true;

									for (int i = 0; i < 2; i++)
									{
										for (int j = 0; j < 13; j++)
										{

											if (coordx >= 500 + j * Width && coordx <= 500 + j * Width + Width && coordy >= 300 + i * Width && coordy <= 300 + i * Width + Width)
											{
												letter = english_letter[n];
											}
											n++;
										}
									}
								}
							}
						
					}

					catch (const char* exc)
					{
						cout << exc << endl;
					}

				}
			}
		}
		

		if (isMove)
		{
			obj = 0;
			for (int i = 0; i < count; i++)
			{
				if (str[i] == letter)
				{
					obj++; //определяем количество этой буквы в слове
					com[kk] = i; //в массив кладем номер буквы
					kk++;
				}
			}

			for (int i = 0; i < kol; i++)
			{
				if (word_yes[i] == letter) //есть ли буква в массиве оригинальных букв в слове
				{
					FLAG = 1;
					for (int j = 0; j < obj; j++)
					{
						mas[num] = letter; //кладем все буквы по порядку введения, если 2 и больше, то подряд
						num++;
					}
					break;
				}
				else
				{
					FLAG = 0;
				}
			}

			for (int i = 0; i < num; i++) //рисуем букву угаданную
			{
				if (choose_language == 1)
				{
					text1[i].setFont(font_russian);
				}
				else if (choose_language == 2)
				{
					text1[i].setFont(font_english);
				}
				
				text1[i].setString(mas[i]);
				text1[i].setFillColor(Color::White);
				text1[i].setPosition(Xl + Xcoord * com[i], Yl);
				window->draw(text1[i]);
			}

			if (FLAG == 0) //если ошибка то рисуем висилицу
			{
				mistake++;
				draw_Visel(text, mistake);

				word_no[num1] = letter;
				num1++;
			}
			else
			{
				draw_Visel(text, mistake);
			}

			for (int i = 0; i < num1; i++) //рисуем букву угаданную
			{
				if (choose_language == 1)
				{
					text1[i].setFont(font_russian);
				}
				else if (choose_language == 2)
				{
					text1[i].setFont(font_english);
				}

				text1[i].setString(word_no[i]);
				text1[i].setFillColor(Color::Red);
				text1[i].setPosition(970 +40*i, 200 );
				window->draw(text1[i]);
			}

			isMove = false;

			if (if_Win(text, cnt) == 1) //если победа, то выход из цикла
				break;
		}

		this->window->display();
	}
}

//рисует количество штрихов для букв
void Interface::draw_Word()
{
	int Xw = 600, Yw = 100;

	RectangleShape line_Word(Vector2f(3, 20));
	line_Word.setFillColor(Color::White);
	line_Word.rotate(-90);
	line_Word.move(Xw, Yw);
	this->window->draw(line_Word);

	for (int i = 0; i < count - 1; i++)
	{
		Xw += 35;
		line_Word.setPosition(Xw, Yw);
		this->window->draw(line_Word);
	}
}


//рисует тему слова
void Interface::draw_Theme(Text text, string theme, string theme1)
{
	int Xth = 50, Yth = 20;

	text.setString("ТЕМА: ");
	text.setCharacterSize(30); //увеличиваем размер текста в пикселях
	text.setPosition(Xth, Yth);
	window->draw(text);

	text.setString(theme);
	text.setCharacterSize(30);
	text.setPosition(Xth + 120, Yth);
	window->draw(text);

	text.setString(theme1);
	text.setCharacterSize(30);
	text.setPosition(600, 200);
	window->draw(text);
}


//проверка на победу в игре
int Interface::if_Win(Text text, int cnt)
{
	if (count == num) //если буквы в слове равны угаданным буквам
	{
		for (int i = 0; i < num; i++)
		{
			for (int j = 0; j < kol; j++)
			{
				if (mas[i] == word_yes[j])
				{
					cnt++;
				}
			}
		}
	}

	if (count == cnt)
	{
		text.setString("Y  O  U     W  I  N");
		text.setCharacterSize(100);
		text.setFillColor(Color::Red);
		text.setPosition(500, 550);
		window->draw(text);
		this->window->display();
		return 1;
	}
}

void Interface::menu()
{
	Texture tex_new_game, tex_rule_game, tex_exit_game, rule, background;
	tex_new_game.loadFromFile("menu1.png");
	tex_rule_game.loadFromFile("menu2.png");
	tex_exit_game.loadFromFile("menu3.png");
	rule.loadFromFile("rules.png");
	background.loadFromFile("заставка.jpg", IntRect(0, 0, 1580, 720));

	Sprite menu1(tex_new_game), menu2(tex_rule_game), menu3(tex_exit_game), menu2_rule(rule), menu_background(background);


	bool isMenu = 1;
	int menuNum = 0;

	menu_background.setPosition(150, 50);
	menu1.setPosition(700, 480);
	menu2.setPosition(700, 540);
	menu3.setPosition(700, 600);
	menu2_rule.setPosition(300, 100);

	
	while (isMenu)
	{
		menu1.setColor(Color::White);
		menu2.setColor(Color::White);
		menu3.setColor(Color::White);
		menuNum = 0;
		window->clear(Color(158, 158, 158, 5));

		if (IntRect(700, 480, 300, 50).contains(Mouse::getPosition(*window))) { menu1.setColor(Color::Black); menuNum = 1; }
		if (IntRect(700, 540, 300, 50).contains(Mouse::getPosition(*window))) { menu2.setColor(Color::Black); menuNum = 2; }
		if (IntRect(700, 600, 300, 50).contains(Mouse::getPosition(*window))) { menu3.setColor(Color::Black); menuNum = 3; }

		if (Mouse::isButtonPressed(Mouse::Left))
		{
			if (menuNum == 1)
			{
				isMenu = false;//если нажали первую кнопку, то выходим из меню 
				window->clear();
			}
			if (menuNum == 2) 
			{ 
				window->clear(Color::Black);
				window->draw(menu2_rule);
				window->display(); 

				while (!Keyboard::isKeyPressed(Keyboard::Escape)); 
			}
			if (menuNum == 3) 
			{ 
				window->close(); 
				isMenu = false; 
			}

		}

		window->draw(menu_background);
		window->draw(menu1);
		window->draw(menu2);
		window->draw(menu3);

		window->display();
	}
}


//рисует висилицу
void Interface::draw_Visel(Text text, int mistake)
{
	int radius = 30;
	int X0 = 200, Y0 = 300;
	int X1 = X0 + radius, Y1 = Y0 + 2 * radius; //координаты начала туловища и рук
	int Xlose = 500, Ylose = 550;

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
		

		text.setString("G  A  M  E     O  V  E  R");
		text.setCharacterSize(100);
		text.setFillColor(Color::Red);
		text.setPosition(Xlose, Ylose);
		window->draw(text);
	}
}
