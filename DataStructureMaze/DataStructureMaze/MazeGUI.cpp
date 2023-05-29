#include <SFML/Graphics.hpp>
#include <time.h>
#include<iostream>
#include <vector>
#include "Maze.h"
#include<fstream>
#include "StateSpaceTree.h"
#define N 10
using namespace sf;
using namespace std;
//int x=0.16,  x1=0.7;
void draw_text(bool i_black, unsigned short i_x, unsigned short i_y, const std::string& i_text, sf::RenderWindow& i_window)
{
    short character_x = i_x;
    short character_y = i_y;
    unsigned char character_width;
    sf::Sprite character_sprite;
    sf::Texture font_texture;
    font_texture.loadFromFile("images/Font.png");
    character_width = font_texture.getSize().x / 96;
    character_sprite.setTexture(font_texture);
    if (1 == i_black)
    {
        character_sprite.setColor(sf::Color(0, 0, 0));
    }
    for (const char a : i_text)
    {
        if ('\n' == a)
        {
            character_x = i_x;
            character_y += font_texture.getSize().y;
            continue;
        }
        character_sprite.setPosition(character_x, character_y);
        character_sprite.setTextureRect(sf::IntRect(character_width * (a - 32), 0, character_width, font_texture.getSize().y));
        character_x += character_width;
        i_window.draw(character_sprite);
    }
}
void solver(int grid3[10][10], int sgrid[12][12], int* start, int* end, string file, Sprite maze2[][N], Texture& brick,
    Texture& grass, Texture& grassRed, int x, int x1) {

    /*int length = 0;
    bool hasPath = false;*/
    
    Maze maze(start, end);

    //vector<vector<int>> grid3 = {};
   /* maze.findPath(grid4);*/
    maze.read(file);
    maze.findPath();

    //mesh mehtgaha delwa2ty
    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 10; j++)
        {
            grid3[i][j] = 0;
        }

    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 10; j++)
        {
            sgrid[i][j] = (maze.matrix)[i][j];
            if (sgrid[i][j] == 0) {
                maze2[i][j].setTexture(brick);
                maze2[i][j].setPosition(j * 100, i * 100);
                maze2[i][j].scale(0.16, 0.16);
            }
            else if (sgrid[i][j] == 1)
            {

                maze2[i][j].setTexture(grass);
                maze2[i][j].setPosition(j * 100, i * 100);
                maze2[i][j].scale(0.7, 0.7);
            }
           /* else
            {
                maze2[i][j].setTexture(grassRed);
                maze2[i][j].setPosition(j * 100, i * 100);
                maze2[i][j].scale(0.7, 0.7);

            }*/
        }



    }
    /*else
        cout << "file not found" << endl;*/
    //init player;
 /*   player.setTexture(playert);
    player.setPosition(playery * 100, playerx * 100);
    player.scale(0.2, 0.2);*/


//}
//class player {
//private:
//    Texture t;
//    int playeri, playerj;
//    Sprite myPlayer;
//public:
//    player(int x, int y) {
//        playeri = x;
//        playerj = y;
//        t.loadFromFile("C:\\Users\\a\source\\repos\\test\\test\\image\\Rat-removebg-previeww.png");
//        myPlayer.setTexture(t);
//        myPlayer.setPosition(playerj * 100, playeri * 100);
//        myPlayer.scale(0.2, 0.2);
//    }
//};
int main()
{
    /*Texture startMaze;
    startMaze.loadFromFile("C:\\Users\\farah\\source\\repos\\DataStructureMaze\\DataStructureMaze\\startMaze.png");
    Sprite startMazex;
    startMazex.setTexture(startMaze);*/
    bool running = true;
    int start[] = { 0, 0 };
    int end[] = { N - 1, N - 1 };
    int w = 32;
    int grid[12][12];
    int sgrid[12][12];
    int grid3[N][N];
    string file = "C:\\Users\\farah\\source\\repos\\DataStructureMaze\\DataStructureMaze\\maze.txt";
    //player p1(0, 0);
    Sprite maze2[N][N];
    

    Texture brick;
    brick.loadFromFile("C:\\Users\\farah\\source\\repos\\DataStructureMaze\\DataStructureMaze\\brick.png");
    //Sprite s(brick);
    Texture grass;
    grass.loadFromFile("C:\\Users\\farah\\source\\repos\\DataStructureMaze\\DataStructureMaze\\grass.jpg");
    Texture grassRed;
    grassRed.loadFromFile("C:\\Users\\farah\\source\\repos\\DataStructureMaze\\DataStructureMaze\\grassRed.jpeg");
    //Sprite s2(grass);
   /* x = 0.16;
    x1 = 0.7;*/
    solver(grid3, sgrid, start, end, file, maze2, brick, grass, grassRed, 0.16, 0.7);
    RenderWindow app(VideoMode(1000, 1000), "Rat in Maze");

    while (app.isOpen())
    {

        Vector2i pos = Mouse::getPosition(app);
        int x = pos.x / w;
        int y = pos.y / w;

        Event e;
        while (app.pollEvent(e))
        {
            switch (e.type) {
            case Event::KeyPressed:
                switch (e.key.code)
                {
                case Keyboard::Enter:



                    running = false;

                    break;
                    //app.close();
                    app.display();

                }


                switch (e.key.code) {
                case Keyboard::Num1:
                    running = false;
                    int num = 3;
                    start[0] = { N - num };
                    start[1] = { N - num };
                    end[0] = { N - 1 };
                    end[1] = { N - 1 };
                    file = "C:\\Users\\farah\\source\\repos\\DataStructureMaze\\DataStructureMaze\\easy.txt";
                    /*x = 0.5;
                    x1 = 1.2;*/
                    solver(grid3, sgrid, start, end, file,maze2,brick,grass, grassRed,0.9,1.9);
                    running = true;

                    break;
                } switch (e.key.code) {
                case Keyboard::Num2:
                    running = false;
                    int num = 10;
                    start[0] = { N - num };
                    start[1] = { N - num };
                    end[0] = { N - 1 };
                    end[1] = { N - 1 };
                    file = "C:\\Users\\farah\\source\\repos\\DataStructureMaze\\DataStructureMaze\\maze.txt";
                    /*x = 0.16;
                    x1 = 0.7;*/
                    solver(grid3, sgrid, start, end, file,maze2,brick,grass, grassRed,0.16,0.7);
                    running = true;
                    break;
                }

                break;
            }
            if (e.type == Event::Closed)
                app.close();
        }
        if (running)
        {
            app.clear(Color::White);

            /*for (int i = 1; i <= 10; i++)
                for (int j = 1; j <= 10; j++)
                {*/
                    /*s.setTextureRect(IntRect(sgrid[i][j] * w, 0, w, w));
                    s.setPosition(i * w, j * w);
                    app.draw(s);*/
                    for (int i = 0; i < N; i++)
                    {
                        for (int j = 0; j < N; j++)
                        {
                            app.draw(maze2[i][j]);
                        }

                    }
               /* }*/
        }


        else
        {


            app.clear(Color::White);
            ifstream inFile("C:\\Users\\farah\\source\\repos\\DataStructureMaze\\DataStructureMaze\\display.txt");



            for (int i = 0; i < 10; i++)
                for (int j = 0; j < 10; j++)
                {
                    inFile >> grid[j][i];
                    if (grid[j][i] == 0) {
                        maze2[i][j].setTexture(brick);
                        maze2[i][j].setPosition(j * 100, i * 100);
                        maze2[i][j].scale(0.16, 0.16);
                    }
                    else if (grid[j][i] != 2)
                    {

                        maze2[i][j].setTexture(grassRed);
                        maze2[i][j].setPosition(j * 100, i * 100);
                        maze2[i][j].scale(0.7, 0.7);
                    }
                    
                    

                }

            inFile.close();


            app.clear(Color::White);

            for (int i = 0; i <N; i++)
                for (int j = 0; j <N; j++)
                {
                    /*if (grid[j][i] == 0) {
                        maze2[i][j].setTexture(brick);
                        maze2[i][j].setPosition(j * 100, i * 100);
                        maze2[i][j].scale(0.16, 0.16);
                    }
                    else if (grid[i][j] == 1)
                    {

                        maze2[i][j].setTexture(grassRed);
                        maze2[i][j].setPosition(j * 100, i * 100);
                        maze2[i][j].scale(0.7, 0.7);
                    }*/
                    /*else
                    {
                        maze2[i][j].setTexture(grass);
                        maze2[i][j].setPosition(j * 100, i * 100);
                        maze2[i][j].scale(0.7, 0.7);

                    }   */
                    
                }
            for (int i = 0; i < N; i++)
                for (int j = 0; j < N; j++)
                {
                    app.draw(maze2[i][j]);

                }

        }
        //app.draw(startMazex);
        app.display();
    }
    return 0;
}
