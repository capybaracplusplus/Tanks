
#include <iostream>
#include <vector>
#include <string>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>
#include <ctime>
#include <thread>
#include "Maps.h" 




struct Point
{
    int x;
    int y;

};

struct Player
{
    Point tankPos;
    bool baseAlive = true;
    Point spawnPos;
};


std::vector<std::vector<std::string>> render(20, std::vector<std::string>(20, "..")); 

// тыкает курсором в консоле (для графики*)
void gotoxy(int xpos, int ypos)
{
    COORD scrn;
    HANDLE hOuput = GetStdHandle(STD_OUTPUT_HANDLE);
    scrn.X = 2*xpos; scrn.Y = ypos;
    SetConsoleCursorPosition(hOuput, scrn);
}


void rendering(std::string(*render)[20]) // отрисовывает игровое поле
{

    gotoxy(0, 0);
    for (int i = 0; i < 20; ++i)
    {
        for (int j = 0; j < 20; j++)
        {
            std::cout << render[i][j];
        }
        std::cout << std::endl;
    }
    gotoxy(0, 0);
}

void look(std::string** render) // ставит "render[x][y]" на выбранное место
{
    gotoxy(13, 14);
    std::cout << render[13][14];
    gotoxy(0, 0);
}

void spawnRender()
{
    std::cout << "[" << "]";
}

void spawn(Player & p)
{
    p.tankPos.x = p.spawnPos.x;
    p.tankPos.y = p.spawnPos.y;
    gotoxy(p.tankPos.x, p.tankPos.y);
    spawnRender();
}



int main()
{   
    // Состояние игры - если true тогда игра идет, если false игра заканчивается и выводится game over
    bool game = true;

    Player p1;
    p1.spawnPos.x = 11;
    p1.spawnPos.y = 18;

   SetConsoleOutputCP(CP_UTF8);
   for (int i = 0; i < 20; i++)
   {
       for (int j = 0; j < 20; j++)
       {
           render[i][j] = map2[i][j];
       }
   }

    rendering(map2); 
    spawn(p1);
     
    while (game)
    {
        clock_t start_time = clock(); // задержка падения кубика


        if (_kbhit())
        {
            int a, b;
            b = _getch();
            a = _getch();

            if (b == 224)
            {
                if (a == 77)
                {
                    //right();
                }

                if (a == 75)
                {
                    //left();
                }

                if (a == 80)
                {
                    //down();
                }
                if (a == 72)
                {
                    //up();
                }
            }
        }

        while ((clock() - start_time) / CLOCKS_PER_SEC < 0.02) {}


    }

    return 0;
}
