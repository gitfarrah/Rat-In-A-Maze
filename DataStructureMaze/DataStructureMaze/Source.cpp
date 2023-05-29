//#include <iostream>
//#include <SFML/Graphics.hpp>
//#include <cmath>
//using namespace std;
//int main()
//{
//	sf::RenderWindow window(sf::VideoMode(600, 600), "game");
//	std::srand(std::sin(std::time(nullptr)) * 1000);
//	int framcount = 0;
//	bool updatepath = true;
//	int orderset[15 * 15];
//	int path[100];
//	int pathsize = 0;
//	int pathpos = 0;
//	sf::Vector2i  player = sf::Vector2i(13, 13);
//	sf::RectangleShape playerRect = sf::RectangleShape(sf::Vector2f(40.f, 40.f));
//	playerRect.setPosition(player.x * 40.f, player.y * 40.f);
//	playerRect.setFillColor(sf::Color(0, 100, 0));
//	playerRect.setOutlineThickness(1.f);
//	playerRect.setOutlineColor(sf::Color(0, 0, 0));
//
//	sf::Vector2i opponent = sf::Vector2i(1, 1);
//	sf::RectangleShape opponentRect = sf::RectangleShape(sf::Vector2f(40.f, 40.f));
//	opponentRect.setPosition(opponent.x * 40.f, opponent.y * 40.f);
//	opponentRect.setFillColor(sf::Color(190, 0, 0));
//	opponentRect.setOutlineThickness(1.f);
//	opponentRect.setOutlineColor(sf::Color(0, 0, 0));
//	int gameMap[15 * 15];
//	sf::RectangleShape displayRecte[15 * 15];
//	for (int i = 0; i < 15; i++)
//	{
//		for (int j = 0; j < 15; j++)
//		{
//			displayRecte[i + j * 15].setPosition(i * 40.f, j * 40.f);
//			displayRecte[i + j * 15].setSize(sf::Vector2f(40.f, 40.f));
//			displayRecte[i + j * 15].setOutlineThickness(1.f);
//			displayRecte[i + j * 15].setOutlineColor(sf::Color(0, 0, 0));
//			if (!(i == opponent.x && j == opponent.y && i == player.x && j == player.y))
//			{
//				if (std::rand() / (float)RAND_MAX < 0.22f || i == 0 || j == 0 || i == 14 || j == 14) // randomization to black and white cells
//				{
//					gameMap[i + j * 15] = 1;
//					displayRecte[i + j * 15].setFillColor(sf::Color(0, 0, 0));
//				}
//			}
//
//		}
//	}
//	while (window.isOpen())
//	{
//		sf::Event event;
//		while (window.pollEvent(event))
//		{
//			if (event.type == sf::Event::Closed)
//			{
//				window.close();
//			}
//			else if (event.type == sf::Event::KeyPressed)
//			{
//				switch (event.key.code)
//				{
//				case sf::Keyboard::Up:
//					if (gameMap[player.x + (player.y - 1) * 15] != 1)
//					{
//						player.y -= 1;
//						break;
//					}
//				case sf::Keyboard::Down:
//					if (gameMap[player.x + (player.y + 1) * 15] != 1)
//					{
//						player.y += 1;
//						break;
//					}
//				case sf::Keyboard::Left:
//					if (gameMap[(player.x - 1) + player.y * 15] != 1)
//					{
//						player.x -= 1;
//						break;
//					}
//				case sf::Keyboard::Right:
//					if (gameMap[(player.x + 1) + player.y * 15] != 1)
//					{
//						player.x += 1;
//						break;
//					}
//				}
//			}
//			updatepath = true;
//			pathsize = 0;
//			pathpos = 0;
//			playerRect.setPosition(player.x * 40.f, player.y * 40.f);
//		}
//		window.clear(sf::Color(255, 255, 255));
//		for (int i = 0; i < 15 * 15; i++)
//		{
//			window.draw(displayRecte[i]);
//		}
//		if (updatepath == true)
//		{
//			int counter = 0;
//			int fullset[2000];
//			int fullsetsize = 0;
//			int openset[100];
//			int opensetsize = 2;
//			openset[0] = player.x + player.y * 15;
//			openset[1] = counter;
//			int currentindex = player.x + player.y * 15;
//			while (currentindex != opponent.x + opponent.y * 15)
//			{
//				currentindex = openset[0];
//				counter = openset[1] + 1;
//				int neighbors[4];
//				neighbors[0] = currentindex - 1;
//				neighbors[1] = currentindex + 1;
//				neighbors[2] = currentindex - 15;
//				neighbors[3] = currentindex + 15;
//				for (int i = 0; i < 8; i += 2)
//				{
//					bool alreadyexists = false;
//					for (int j = 0; j < fullsetsize; j += 2)
//					{
//						if (neighbors[i / 2] == fullset[j])
//						{
//							alreadyexists = true;
//							break;
//						}
//					}
//					if (alreadyexists == false)
//					{
//						if (gameMap[neighbors[i / 2]] != 1)
//						{
//							fullset[fullsetsize] = neighbors[i / 2];
//							fullset[fullsetsize + 1] = counter;
//							fullsetsize += 2;
//
//							openset[opensetsize] = neighbors[i / 2];
//							openset[opensetsize + 1] = counter;
//							opensetsize += 2;
//						}
//						else
//						{
//							fullset[fullsetsize] = neighbors[i / 2];
//							fullset[fullsetsize + 1] = 100000;
//							fullsetsize += 2;
//						}
//					}
//				}
//				for (int i = 0; i < opensetsize; i++)
//				{
//					openset[i] = openset[i + 2];
//				}
//				opensetsize -= 2;
//			}
//			for (int i = 0; i < 15 * 15; i++)
//			{
//				orderset[i] = 100000;
//			}
//			for (int i = 0; i < fullsetsize; i += 2)
//			{
//				orderset[fullset[i]] = fullset[i + 1];
//			}
//			orderset[player.x + player.y * 15] = 0;
//			int pathindex = opponent.x + opponent.y * 15;
//			while (pathindex != player.x + player.y * 15)
//			{
//				int neighbors[4];
//				neighbors[0] = pathindex - 1;
//				neighbors[1] = pathindex + 1;
//				neighbors[2] = pathindex - 15;
//				neighbors[3] = pathindex + 15;
//
//				int lowest[2]{ 0,100000 };
//				for (int i = 0; i < 4; i++)
//				{
//					if (orderset[neighbors[i]] < lowest[1])
//					{
//						lowest[0] = i;
//						lowest[1] = orderset[neighbors[i]];
//
//					}
//				}
//				pathindex = neighbors[lowest[0]];
//				path[pathsize] = pathindex;
//				pathsize += 1;
//			}
//			updatepath = false;
//		}
//		if (framcount % 1000 == 0)
//		{
//			opponent.x = path[pathpos] % 15;
//			opponent.y = std::floor(path[pathpos] / 15);
//			opponentRect.setPosition(opponent.x * 40.f, opponent.y * 40.f);
//			pathpos += 1;
//		}
//		window.draw(playerRect);
//		window.draw(opponentRect);
//		window.display();
//		framcount += 1;
//	}
//	return 0;
//}