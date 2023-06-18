#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <Windows.h>
#include <conio.h> // getch() 함수를 사용하기 위해 추가

#define UP 0
#define DOWN 1
#define ENTER 2
enum {
    black,
    blue,
    green,
    cyan,
    red,
    purple,
    brown,
    lightgray,
    darkgray,
    lightblue,
    lightgreen,
    lightcyan,
    lightred,
    lightpurple,
    yellow,
    white,
};

int Key();
int menu();
void gotoxy(int, int);
void gameinfo();
void setColor(int, int);


int menu() {
    setColor(yellow, black);
    int x = 24;
    int y = 12;
    gotoxy(x - 2, y);
    printf("> 시 작 하 기");
    gotoxy(x, y + 1);
    printf("게 임 설 명");
    gotoxy(x, y + 2);
    printf("종 료 하 기\n");
    while (1) {
        int n = Key();
        switch (n) {
        case UP: {
            if (y > 12) {
                gotoxy(x - 2, y);
                printf(" ");
                gotoxy(x - 2, y - 1);
                printf(">");
                y--;
            }
            break;
        }
        case DOWN: {
            if (y < 14) {
                gotoxy(x - 2, y);
                printf(" ");
                gotoxy(x - 2, y + 1);
                printf(">");
                y++;
            }
            break;
        }
        case ENTER: {
            return y - 12;
        }
        }
    }
}

void gotoxy(int x, int y) {
    COORD pos;
    pos.X = x;
    pos.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

int Key() {
    int key = _getch();

    if (key == 224) {
        switch (_getch()) {
        case 72: return UP;
        case 80: return DOWN;
        }
    }
    else if (key == 13) {
        return ENTER;
    }

    return -1;
}

void setColor(int foreground, int background) {
    int color = foreground + background * 16;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void gameinfo() {
    setColor(white, black);
    system("cls");
    printf("\n\n");
    printf("===============================================================   \n");
    setColor(yellow, black);
    printf("    ######   #######  ########  ########  #######  #######        \n");
    printf("    ##       ##   ##  ##        ##    ##  ##       ##             \n");
    printf("    ##       ##   ##  ##        ##    ##  ##       ##             \n");
    printf("    ######   ##   ##  ########  ##    ##  ##       #######        \n");
    printf("    ##       ##   ##  ##        ##    ##  ##       ##             \n");
    printf("    ##       ##   ##  ##        ##    ##  ##       ##             \n");
    printf("    ######   ##   ##  ##        ########  #######  #######        \n");
    setColor(white, black);
    printf("===============================================================   \n");
    printf("==================================\n");
    printf("장르 : 무기 강화 RPG\n");
    printf("제작 : YOON\n");
    printf("제작 기간 : 약 ㅇ일\n");
    printf("==================================\n");
    setColor(yellow, black);
    printf("엔터키를 누르면 메뉴로 돌아갑니다!\n");
    setColor(white, black);
    printf("==================================\n");
    while (1) {
        if (Key() == ENTER) {
            setColor(white, black);
            break;
        }
    }
}

void mainer() {
    system("mode con cols=68 lines=35 | title ENFORCE-MASTER");

    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(consoleHandle, &cursorInfo);
    cursorInfo.bVisible = FALSE;
    SetConsoleCursorInfo(consoleHandle, &cursorInfo);
}

void PrintingTitle() {
    printf("\n\n");
    setColor(white, black);
    printf("===============================================================\n");
    setColor(yellow, black);
    printf("    ######   #######  ########  ########  #######  #######          \n");
    printf("    ##       ##   ##  ##        ##    ##  ##       ##          \n");
    printf("    ##       ##   ##  ##        ##    ##  ##       ##          \n");
    printf("    ######   ##   ##  ########  ##    ##  ##       #######          \n");
    printf("    ##       ##   ##  ##        ##    ##  ##       ##          \n");
    printf("    ##       ##   ##  ##        ##    ##  ##       ##           \n");
    printf("    ######   ##   ##  ##        ########  #######  #######         \n");
    setColor(white, black);
    printf("===============================================================\n");
}

void StartGame() {
    setColor(white, black);
    system("cls");
    printf("\n");
    printf("");
    setColor(yellow, black);
    int x = 2;
    int y = 1;
    gotoxy(x - 2, y);
    printf("> 시 작 하 기");
    gotoxy(x, y + 1);
    printf("게 임 설 명");
    gotoxy(x, y + 2);
    printf("종 료 하 기\n");
    while (1) {
        int n = Key();
        switch (n) {
        case UP: {
            if (y > 1) {
                gotoxy(x - 2, y);
                printf(" ");
                gotoxy(x - 2, y - 1);
                printf(">");
                y--;
            }
            break;
        }
        case DOWN: {
            if (y < 3) {
                gotoxy(x - 2, y);
                printf(" ");
                gotoxy(x - 2, y + 1);
                printf(">");
                y++;
            }
            break;
        }
        case ENTER: {
            return y - 1;
        }
        }
    }
    int menuCode = menu();
    if (menuCode == 0) {
        StartGame();
    }
    else if (menuCode == 1) {
        gameinfo();
    }
    else if (menuCode == 2) {
        setColor(white, black);
        system("cls");
        return 0;
    }
    system("cls");

}

int main() {
    char start[20];

    mainer();
    while (1) {
        PrintingTitle();
        int menuCode = menu();
        if (menuCode == 0) {
            StartGame();
        }
        else if (menuCode == 1) {
            gameinfo();
        }
        else if (menuCode == 2) {
            setColor(white, black);
            system("cls");
            return 0;
        }
        system("cls");
    }
}
