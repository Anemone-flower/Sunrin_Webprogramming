#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <Windows.h>
#include <conio.h> // getch() 함수를 사용하기 위해 추가

#define UP 0
#define DOWN 1
#define ENTER 2
#define woodensword 99
#define stonesword 100
#define ironsword 101

typedef struct {
    int enforcelv;
    char name[20];
} Weapon;


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
int Enforce();

int menu() {
    setColor(yellow, black);
    int x = 25;
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
    printf("  =============================================================\n");
    setColor(yellow, black);
    printf("      ######   #######  ########  ########  #######  ######   \n");
    printf("      ##       ##   ##  ##        ##    ##  ##       ##       \n");
    printf("      ##       ##   ##  ##        ##    ##  ##       ##       \n");
    printf("      ######   ##   ##  ########  ##    ##  ##       ######   \n");
    printf("      ##       ##   ##  ##        ##    ##  ##       ##       \n");
    printf("      ##       ##   ##  ##        ##    ##  ##       ##       \n");
    printf("      ######   ##   ##  ##        ########  #######  ######   \n");
    setColor(white, black);
    printf("  =============================================================\n");
    printf("  ==================================\n");
    printf("  장르 : 무기 강화 RPG\n");
    printf("  제작 : YOON\n");
    printf("  제작 기간 : 약 ㅇ일\n");
        printf("  ==================================\n");
    setColor(yellow, black);
    printf("  엔터키를 누르면 메뉴로 돌아갑니다!\n");
    setColor(white, black);
    printf("  ==================================\n");
    while (1) {
        if (Key() == ENTER) {
            setColor(white, black);
            break;
        }
    }
}

void mainer() {
    system("mode con cols=67 lines=35 | title ENFORCE-MASTER");

    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(consoleHandle, &cursorInfo);
    cursorInfo.bVisible = FALSE;
    SetConsoleCursorInfo(consoleHandle, &cursorInfo);
}

void PrintingTitle() {
    printf("\n\n");
    setColor(white, black);
    printf("  =============================================================\n");
    setColor(yellow, black);
    printf("      ######   #######  ########  ########  #######  ######   \n");
    printf("      ##       ##   ##  ##        ##    ##  ##       ##       \n");
    printf("      ##       ##   ##  ##        ##    ##  ##       ##       \n");
    printf("      ######   ##   ##  ########  ##    ##  ##       ######   \n");
    printf("      ##       ##   ##  ##        ##    ##  ##       ##       \n");
    printf("      ##       ##   ##  ##        ##    ##  ##       ##       \n");
    printf("      ######   ##   ##  ##        ########  #######  ######   \n");
    setColor(white, black);
    printf("  =============================================================\n");
}

int StartGame() {
    setColor(white, black);
    system("cls");
    printf("\n");
    printf("");
    setColor(yellow, black);
    int x = 2;
    int y = 1;
    gotoxy(x - 2, y);
    printf("> 무 기 강 화 ");
    gotoxy(x, y + 1);
    printf("무 기 뽑 기");
    gotoxy(x, y + 2);
    printf("상 점 가 기\n");
    gotoxy(x, y + 3);
    printf("돌 아 가 기\n");
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
            if (y < 4) {
                gotoxy(x - 2, y);
                printf(" ");
                gotoxy(x - 2, y + 1);
                printf(">");
                y++;
            }
            break;
        }
        case ENTER: {
            if (y == 1) {
                return 5;  // Option: 무 기 강 화
            }
            else if (y == 2) {
                return 6;  // Option: 무 기 뽑 기
            }
            else if (y == 3) {
                return 7;  // Option: 상 점 가 기
            }
            else if (y == 4) {
                return 8;  // Option: 돌 아 가 기
            }
        }
        }
    }
}


int Enforce() {
    srand(time(NULL));
    int equipmentweaponNum = 0;
    equipmentweaponNum = rand() %2 + 99;
    Weapon equipweapon;
    if (equipmentweaponNum == 99) strcpy_s(equipweapon.name, sizeof(equipweapon.name), "평범한 김정우의 검");
    else if (equipmentweaponNum == 100) strcpy_s(equipweapon.name, sizeof(equipweapon.name), "견고한 돌 검");
    else if (equipmentweaponNum == 999) strcpy_s(equipweapon.name, sizeof(equipweapon.name), "순수지경 - 자아무결");
    equipweapon.enforcelv = 0;
    setColor(white, black);
    system("cls");
    printf("\n");
    printf("");
    setColor(yellow, black);
    int x = 2;
    int y = 2;
    printf("==============================================");
    gotoxy(x - 2, y);
    printf("> 현재 장착 무기 : %s", equipweapon.name);
    gotoxy(x, y + 1);
    printf("강화 확률 : ");
    gotoxy(x, y + 2);
    printf("상 점 가 기\n");
    gotoxy(x, y + 3);
    printf("돌 아 가 기\n");
    printf("==============================================");
    while (1) {
        int n = Key();
        switch (n) {
        case UP: {
            if (y > 2) {
                gotoxy(x - 2, y);
                printf(" ");
                gotoxy(x - 2, y - 1);
                printf(">");
                y--;
            }
            break;
        }
        case DOWN: {
            if (y < 5) {
                gotoxy(x - 2, y);
                printf(" ");
                gotoxy(x - 2, y + 1);
                printf(">");
                y++;
            }
            break;
        }
        case ENTER: {
            if (y == 3) {
                return 5;  // Option: 무 기 강 화
            }
            else if (y == 4) {
                return 6;  // Option: 무 기 뽑 기
            }
            else if (y == 5) {
                return 7;  // Option: 상 점 가 기
            }
            else if (y == 6) {
                return 8;  // Option: 돌 아 가 기
            }
        }
        }
    }
}

int main() {
    int weaponnum = 99;
    mainer();
    while (1) {
        PrintingTitle();
        int menuCode = menu();
        if (menuCode == 0) {
            int startCode = StartGame();
            if (startCode == 5) {
                system("cls");
                Enforce();
            }
            else if (startCode == 6) {
                Enforce();
            }
            else if (startCode == 7) {
                Enforce();
                system("cls");
            }
            else if (startCode == 8) {
                // Handle the "돌 아 가 기" option
            }
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
