#include <iostream>
#include <vector>
#include <string>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>
#include <ctime>
#include <thread>

// идея танчики на 2-х в консоле
 
 
// временное объявление функций
void gotoxy(int xpos, int ypos);
void rendering();
void right();
void left();
void down();
void up();
void look();

/*   как выглядит функция перемещения:
void right() 
{
    gotoxy(x, y);
    cout << 0;
    if (x + 1 < v.size() && v[x + 1][y] != 1)
    {
        x += 1;
    }
    look();       --- надо переписать!!!
    gotoxy(0, 0);
}


*/




/* 
     элемент           обозначение       номер в векторе      char
0) просто поле           .                       0          46    46
1) танк                 []                     11 12        133  135
2) танк противника      {}                     21 22        123  125
3) разрушаемая стена    ::                     3  3         58    58
4) река                 ~~                     4 4          126  126
5) куст                 ??                     5 5          63    63

*/




// Состояние игры - если true тогда игра идет, если false игра заканчивается и выводится game over
bool game = true;


// tex (бэк) вектор с чиселками
std::vector<std::vector<int>> tex(20, std::vector<int>(40, 0));


// rendor вектор (графическая часть которую видел игрок)
std::vector<std::vector<char>> render(20, std::vector<char>(40, 46));


// тыкает курсором в консоле (для графики*)
void gotoxy(int xpos, int ypos) 
{
    COORD scrn;
    HANDLE hOuput = GetStdHandle(STD_OUTPUT_HANDLE);
    scrn.X = xpos; scrn.Y = ypos;
    SetConsoleCursorPosition(hOuput, scrn);
}


void rendering() // отрисовывает игровое поле
{

    gotoxy(0, 0);
    for (int i = 0; i < 20; ++i)
    {
        for (int j = 0; j < 40; j++)
        {
            std::cout << render[i][j];
        }
        std::cout << std::endl;
    }
    gotoxy(0, 0);
}

void look() // ставит "render[x][y]" на выбранное место
{
    gotoxy(33, 34);
    std::cout << render[33][34];
    gotoxy(0, 0);
}

int main()
{   
    look();
   // render[8][38] = '[';
   // render[8][39] = ']';
   // tex[8][38] = 11;
   // tex[8][39] = 12;
    rendering(); 
    std::thread th1([]() {
        while (game) 
        {
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
                }
            }
        }


        });


    while (game == true)
    {
        clock_t start_time = clock(); // задержка падения кубика
        while ((clock() - start_time) / CLOCKS_PER_SEC < 0.02) {}

        gotoxy(0, 0);

    }

    return 0;
}
