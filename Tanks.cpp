#include <iostream>
#include <vector>
#include <string>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>
#include <ctime>
#include "Maps.h" 


struct Point {
    int x;
    int y;
};

struct Player {
    Point tankPos;
    bool tankAlive = true;
    bool baseAlive = true;
    Point spawnPos;
};



// std::vector<std::vector<std::string>> render(20, std::vector<std::string>(20, ".."));
std::string render[20][20];

// тыкает курсором в консоле (для графики*)
void gotoxy(int xpos, int ypos) {
    COORD scrn;
    HANDLE hOuput = GetStdHandle(STD_OUTPUT_HANDLE);
    scrn.X = 2*xpos; scrn.Y = ypos;
    SetConsoleCursorPosition(hOuput, scrn);
}

// отрисовывает игровое поле
void rendering(std::string(*render)[20]) {
    gotoxy(0, 0);
    for (int i = 0; i < 20; ++i) {
        for (int j = 0; j < 20; j++) {
            std::cout << render[i][j];
        }
        std::cout << std::endl;
    }
    gotoxy(0, 0);
}

void tankRender(Player& p) {
    std::string test = render[p.tankPos.x][p.tankPos.y];
    if (render[p.tankPos.x][p.tankPos.y] != "░░") {
        std::cout << "[" << "]";
    }
}

void spawn(Player & p) {
    p.tankPos.x = p.spawnPos.x;
    p.tankPos.y = p.spawnPos.y;
    gotoxy(p.tankPos.x, p.tankPos.y);
    tankRender(p);
    gotoxy(0, 0);
}

void up(Player & p) {
    if(p.tankPos.y > 0) {
            if( render[p.tankPos.x][p.tankPos.y - 1] != "▓▓" &&
                render[p.tankPos.x][p.tankPos.y - 1] != "~~" &&
                render[p.tankPos.x][p.tankPos.y - 1] != "&1" &&
                render[p.tankPos.x][p.tankPos.y - 1] != "&2" &&
                render[p.tankPos.x][p.tankPos.y - 1] != "<>" &&
                render[p.tankPos.x][p.tankPos.y - 1] != "{}" &&
                render[p.tankPos.x][p.tankPos.y - 1] != "[]" &&
                render[p.tankPos.x][p.tankPos.y - 1] != "██" ) {
                gotoxy(p.tankPos.x,p.tankPos.y);
                if(map2[p.tankPos.y][p.tankPos.x] == "░░") {
                    std::cout << "░░";
                    render[p.tankPos.x][p.tankPos.y] = "░░";
                }
                else {
                    std::cout << "..";
                    render[p.tankPos.x][p.tankPos.y] = "..";
                }
                p.tankPos.y -= 1;
                gotoxy(p.tankPos.x,p.tankPos.y);
                tankRender(p);
            }
    }
}

void down(Player & p) {
    if(p.tankPos.y < 19) {
        if( render[p.tankPos.x][p.tankPos.y + 1] != "▓▓" &&
            render[p.tankPos.x][p.tankPos.y + 1] != "~~" &&
            render[p.tankPos.x][p.tankPos.y + 1] != "&1" &&
            render[p.tankPos.x][p.tankPos.y + 1] != "&2" &&
            render[p.tankPos.x][p.tankPos.y + 1] != "<>" &&
            render[p.tankPos.x][p.tankPos.y + 1] != "{}" &&
            render[p.tankPos.x][p.tankPos.y + 1] != "[]" &&
            render[p.tankPos.x][p.tankPos.y + 1] != "██" ) {
            gotoxy(p.tankPos.x,p.tankPos.y);
            if(map2[p.tankPos.y][p.tankPos.x] == "░░") {
                std::cout << "░░";
                render[p.tankPos.x][p.tankPos.y] = "░░";
            }
            else {
                std::cout << "..";
                render[p.tankPos.x][p.tankPos.y] = "..";
            }
            p.tankPos.y += 1;
            gotoxy(p.tankPos.x,p.tankPos.y);
            tankRender(p);
        }
    }
}

void right(Player & p) {
    if(p.tankPos.x < 19) {
        if( render[p.tankPos.x + 1][p.tankPos.y] != "▓▓" &&
            render[p.tankPos.x + 1][p.tankPos.y] != "~~" &&
            render[p.tankPos.x + 1][p.tankPos.y] != "&1" &&
            render[p.tankPos.x + 1][p.tankPos.y] != "&2" &&
            render[p.tankPos.x + 1][p.tankPos.y] != "<>" &&
            render[p.tankPos.x + 1][p.tankPos.y] != "{}" &&
            render[p.tankPos.x + 1][p.tankPos.y] != "[]" &&
            render[p.tankPos.x + 1][p.tankPos.y] != "██" ) {
            gotoxy(p.tankPos.x,p.tankPos.y);
            if(map2[p.tankPos.y][p.tankPos.x] == "░░") {
                std::cout << "░░";
                render[p.tankPos.x][p.tankPos.y] = "░░";
            }
            else {
                std::cout << "..";
                render[p.tankPos.x][p.tankPos.y] = "..";
            }
            p.tankPos.x += 1;
            gotoxy(p.tankPos.x,p.tankPos.y);
            tankRender(p);
        }
    }
}

void left(Player & p) {
    if(p.tankPos.x > 0) {
        if( render[p.tankPos.x - 1][p.tankPos.y] != "▓▓" &&
            render[p.tankPos.x - 1][p.tankPos.y] != "~~" &&
            render[p.tankPos.x - 1][p.tankPos.y] != "&1" &&
            render[p.tankPos.x - 1][p.tankPos.y] != "&2" &&
            render[p.tankPos.x - 1][p.tankPos.y] != "<>" &&
            render[p.tankPos.x - 1][p.tankPos.y] != "{}" &&
            render[p.tankPos.x - 1][p.tankPos.y] != "[]" &&
            render[p.tankPos.x - 1][p.tankPos.y] != "██" ) {
            gotoxy(p.tankPos.x,p.tankPos.y);
            if(map2[p.tankPos.y][p.tankPos.x] == "░░") {
                std::cout << "░░";
                render[p.tankPos.x][p.tankPos.y] = "░░";
            }
            else {
                std::cout << "..";
                render[p.tankPos.x][p.tankPos.y] = "..";
            }
            p.tankPos.x -= 1;
            gotoxy(p.tankPos.x,p.tankPos.y);
            tankRender(p);
            }
    }
}




int main() {
    // Состояние игры - если true тогда игра идет, если false игра заканчивается и выводится game over
    bool game = true;

    Player p1;
    p1.spawnPos.x = 11;
    p1.spawnPos.y = 18;

   SetConsoleOutputCP(CP_UTF8);

   for (int i = 0; i < 20; i++) {
       for (int j = 0; j < 20; j++) {
           render[i][j] = map2[j][i];
       }
   }

    rendering(map2); 
    spawn(p1);
     
    while (game) {
        clock_t start_time = clock(); // задержка падения кубика

        if (_kbhit()) {
            int a, b;
            b = _getch();
            a = _getch();
            if (b == 224) {
                if (a == 77) {
                    right(p1);
                }
                if (a == 75) {
                    left(p1);
                }
                if (a == 80) {
                    down(p1);
                }
                if (a == 72) {
                    up(p1);
                }
            }
        }

        while ((clock() - start_time) / CLOCKS_PER_SEC < 0.02) {}


    }

    return 0;
}
