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

int equipmentweaponNum = 999;
int nomalstone = 10;
int colorfulstone = 10;
int equipmentweaponNumTemp;
int equipmentweaponNumTemp1;
int enforcepercent = 100;
int enforceLV;
int Gold = 1000;



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
int weaponinfo(int equipmentweaponNum);
void gatch();
void nomalgatch();
void colorfulgatch();
void enforcing();


void PrintingTitle() {
    printf("\n\n");
    setColor(white, black);
    printf("  ============================================================\n");
    setColor(yellow, black);
    printf("      ######   #######  #######  ########  #######  ######   \n");
    printf("      ##       ##   ##  ##       ##    ##  ##       ##       \n");
    printf("      ##       ##   ##  ##       ##    ##  ##       ##       \n");
    printf("      ######   ##   ##  #######  ##    ##  ##       ######   \n");
    printf("      ##       ##   ##  ##       ##    ##  ##       ##       \n");
    printf("      ##       ##   ##  ##       ##    ##  ##       ##       \n");
    printf("      ######   ##   ##  ##       ########  #######  ######   \n");
    setColor(white, black);
    printf("  ============================================================\n");
}

int menu() {
    setColor(yellow, black);
    int x = 23;
    int y = 12;
    gotoxy(x - 2, y);
    printf("▷ 시 작 하 기");
    gotoxy(x, y + 1);
    printf(" 게 임 설 명");
    gotoxy(x, y + 2);
    printf(" 종 료 하 기\n");
    while (1) {
        int n = Key();
        switch (n) {
        case UP: {
            if (y > 12) {
                gotoxy(x - 2, y);
                printf("  ");
                gotoxy(x - 2, y - 1);
                printf("▷ ");
                y--;
            }
            break;
        }
        case DOWN: {
            if (y < 14) {
                gotoxy(x - 2, y);
                printf("  ");
                gotoxy(x - 2, y + 1);
                printf("▷ ");
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
    system("cls");
    printf("\n\n");
    setColor(white, black);
    printf("  ============================================================\n");
    setColor(yellow, black);
    printf("      ######   #######  #######  ########  #######  ######   \n");
    printf("      ##       ##   ##  ##       ##    ##  ##       ##       \n");
    printf("      ##       ##   ##  ##       ##    ##  ##       ##       \n");
    printf("      ######   ##   ##  #######  ##    ##  ##       ######   \n");
    printf("      ##       ##   ##  ##       ##    ##  ##       ##       \n");
    printf("      ##       ##   ##  ##       ##    ##  ##       ##       \n");
    printf("      ######   ##   ##  ##       ########  #######  ######   \n");
    setColor(white, black);
    printf("  ============================================================\n");
    printf("==================================================================\n");
    printf("  장르 : 무기 강화 RPG\n");
    printf("  제작 : YOON\n");
    printf("  제작 기간 : 약 ㅇ일\n");
    printf("==================================================================\n");
    setColor(yellow, black);
    printf("  엔터키를 누르면 메뉴로 돌아갑니다!\n");
    setColor(white, black);
    printf("==================================================================\n");
    while (1) {
        if (Key() == ENTER) {
            setColor(white, black);
            break;
        }
    }
}

void mainer() {
    system("mode con cols=66 lines=35 | title ENFORCE-MASTER");

    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(consoleHandle, &cursorInfo);
    cursorInfo.bVisible = FALSE;
    SetConsoleCursorInfo(consoleHandle, &cursorInfo);
}



int StartGame() {
    setColor(white, black);
    system("cls");
    printf("\n");
    printf("");
    setColor(yellow, black);
    int x = 24;
    int y = 2;
    printf("==================================================================");
    gotoxy(x - 2, y);
    setColor(brown, black);
    printf("▷ 무 기 강 화 ");
    gotoxy(x, y + 1);
    printf(" 무 기 뽑 기");
    gotoxy(x, y + 2);
    printf(" 던 전 입 장\n"); 
    gotoxy(x, y + 3);
    printf(" 상 점 가 기\n");
    gotoxy(x, y + 4);
    printf(" 돌 아 가 기\n");
    setColor(yellow, black);
    printf("==================================================================");
    while (1) {
        int n = Key();
        switch (n) {
        case UP: {
            if (y > 2) {
                gotoxy(x - 2, y);
                printf("  ");
                gotoxy(x - 2, y - 1);
                printf("▷ ");
                y--;
            }
            break;
        }
        case DOWN: {
            if (y < 6) {
                gotoxy(x - 2, y);
                printf("  ");
                gotoxy(x - 2, y + 1);
                printf("▷ ");
                y++;
            }
            break;
        }
        case ENTER: {
            if (y == 2) {
                return 5;  // Option: 무 기 강 화
            }
            else if (y == 3) {
                return 6;  // Option: 무 기 뽑 기
            }
            else if (y == 4) {
                return 7;  // Option: 상 점 가 기
            }
            else if (y == 5) {
                system("cls");
                main();
            }
            else if (y == 6) {
                system("cls");
                main();
            }
        }
        }
    }
}


int Enforce() {
    srand(time(NULL));
    char Nowing[50];
    if (equipmentweaponNum == 100) strcpy_s(Nowing, sizeof(Nowing), "[N] 부러진 검");
    else if (equipmentweaponNum == 101) strcpy_s(Nowing, sizeof(Nowing), "[N] 세계수의 줄기");
    else if (equipmentweaponNum == 102) strcpy_s(Nowing, sizeof(Nowing), "[N] 세계수의 가지");
    else if (equipmentweaponNum == 103) strcpy_s(Nowing, sizeof(Nowing), "[N] 세계수의 뿌리");
    else if (equipmentweaponNum == 104) strcpy_s(Nowing, sizeof(Nowing), "[N] 쓸만한 조약돌");
    else if (equipmentweaponNum == 105) strcpy_s(Nowing, sizeof(Nowing), "[N] 피 묻은 짱돌");
    else if (equipmentweaponNum == 106) strcpy_s(Nowing, sizeof(Nowing), "[C] 강인한 철 검");
    else if (equipmentweaponNum == 107) strcpy_s(Nowing, sizeof(Nowing), "[C] 오만의 검");
    else if (equipmentweaponNum == 108) strcpy_s(Nowing, sizeof(Nowing), "[R] 녹슨 영웅의 검");
    else if (equipmentweaponNum == 109) strcpy_s(Nowing, sizeof(Nowing), "[R] 엄청난 것");
    else if (equipmentweaponNum == 110) strcpy_s(Nowing, sizeof(Nowing), "[R] 세계수 종합세트");
    else if (equipmentweaponNum == 111) strcpy_s(Nowing, sizeof(Nowing), "[R] 백년을 딛고 천년을 날자");
    else if (equipmentweaponNum == 112) strcpy_s(Nowing, sizeof(Nowing), "[SR] 잊힌 고대의 대검");
    else if (equipmentweaponNum == 113) strcpy_s(Nowing, sizeof(Nowing), "[SR] 몽상의 일태도");
    else if (equipmentweaponNum == 114) strcpy_s(Nowing, sizeof(Nowing), "[SR] 누군가의 이름의 무게");
    else if (equipmentweaponNum == 115) strcpy_s(Nowing, sizeof(Nowing), "[SSR] 세계수의 순수한 가지");
    else if (equipmentweaponNum == 116) strcpy_s(Nowing, sizeof(Nowing), "[SSR] 끝나지 않는 하나사토를 향한 의지");
    else if (equipmentweaponNum == 117) strcpy_s(Nowing, sizeof(Nowing), "[SSR] <한태규> 라는 이름의 무게");
    else if (equipmentweaponNum == 118) strcpy_s(Nowing, sizeof(Nowing), "[SSR] 오만의 검");
    else if (equipmentweaponNum == 119) strcpy_s(Nowing, sizeof(Nowing), "[L] 영원토록 타오르는 신염의 검");
    else if (equipmentweaponNum == 120) strcpy_s(Nowing, sizeof(Nowing), "[L] <김정우> 라는 이름의 무게");
    else if (equipmentweaponNum == 121) strcpy_s(Nowing, sizeof(Nowing), "[L] <문준서> 라는 이름의 무게");
    else if (equipmentweaponNum == 122) strcpy_s(Nowing, sizeof(Nowing), "[★★★★★★★] 七星死吏多");
    else if (equipmentweaponNum == 123) strcpy_s(Nowing, sizeof(Nowing), "[U] 재앙을 부르는 혼의 검");
    else if (equipmentweaponNum == 124) strcpy_s(Nowing, sizeof(Nowing), "[U] 타오르는 태양의 돌"); 
    else if (equipmentweaponNum == 125) strcpy_s(Nowing, sizeof(Nowing), "[U] 이름없는 가문의 가보"); 
    else if (equipmentweaponNum == 126) strcpy_s(Nowing, sizeof(Nowing), "[U] 하늘의 부름"); 
    else if (equipmentweaponNum == 127) strcpy_s(Nowing, sizeof(Nowing), "[Mythic] 허무의 열쇠"); 
    else if (equipmentweaponNum == 999) strcpy_s(Nowing, sizeof(Nowing), "[UNKNOWN] 시작의 돌 ");
    else if (equipmentweaponNum == 1000) strcpy_s(Nowing, sizeof(Nowing), "[ColorFul] 천공의 빛 - 세계의 끝, 종언의 검");
    system("cls");
    printf("\n");
    printf("");
    setColor(yellow, black);
    int x = 2;
    int y = 2;
    printf("==================================================================");
    gotoxy(x - 2, y);
    printf("▷ 현재 장착 무기 : %s", Nowing);
    gotoxy(x, y + 1);
    printf(" 강화 하기 ");
    gotoxy(x, y + 2);
    printf(" 돌아 가기\n");
    printf("==================================================================\n");
    setColor(white, black);
    printf("무기 정보 : +%d강 %s\n", enforceLV, Nowing);
    printf("소지금 : %dG\n", Gold);
    setColor(lightred, black);
    printf("강화 확률 : %d%%",enforcepercent);
    setColor(yellow, black);
    while (1) {
        int n = Key();
        switch (n) {
        case UP: {
            if (y > 2) {
                gotoxy(x - 2, y);
                printf("  ");
                gotoxy(x - 2, y - 1);
                printf("▷ ");
                y--;
            }
            break;
        }
        case DOWN: {
            if (y < 4) {
                gotoxy(x - 2, y);
                printf("  ");
                gotoxy(x - 2, y + 1);
                printf("▷ ");
                y++;
            }
            break;
        }
        case ENTER: {
            if (y == 2) {
                weaponinfo(equipmentweaponNum); break;
            }
            else if (y == 3) {
                enforcing();
            }
            else if (y == 4) {
                return 7;  // Option: 상 점 가 기
            }
            else if (y == 5) {
                system("cls");
                main();
            }
            break;
        }
        }
    }
}

int weaponinfo(int equipmentweaponNum) {
    setColor(yellow, black);
    if (equipmentweaponNum == 100) {
        system("cls");
        printf("==================================================================\n\n");
        printf("▷ 부러진 검, 형체를 알아볼 수 없다. 그냥 쓰자\n\n");
        printf("==================================================================\n");
        printf("\n");
        printf("엔터키를 누르면 뒤로 돌아갑니다.\n");
        while (1) {
            if (Key() == ENTER) {
                main();
                break;
            }
        }
    }
    else if (equipmentweaponNum == 101) {
        system("cls");
        printf("==================================================================\n\n");
        printf("▷ 신성한 세계수의 줄기, 신성한 느낌이 든다. \n\n");
        printf("==================================================================\n");
        printf("\n");
        printf("엔터키를 누르면 뒤로 돌아갑니다.\n");
        while (1) {
            if (Key() == ENTER) {
                main();
                break;
            }
        }
    }
    else if (equipmentweaponNum == 102) {
        system("cls");
        printf("==================================================================\n\n");
        printf("▷ 신성한 세계수의 가지, 신성한 느낌이 든다. \n\n");
        printf("==================================================================\n");
        printf("\n");
        printf("엔터키를 누르면 뒤로 돌아갑니다.\n");
        while (1) {
            if (Key() == ENTER) {
                main();
                break;
            }
        }
    }
    else if (equipmentweaponNum == 103) {
        system("cls");
        printf("==================================================================\n\n");
        printf("▷ 신성한 세계수의 뿌리, 신성한 느낌이 든다. \n\n");
        printf("==================================================================\n");
        printf("\n");
        printf("엔터키를 누르면 뒤로 돌아갑니다.\n");
        while (1) {
            if (Key() == ENTER) {
                main();
                break;
            }
        }
    }
    else if (equipmentweaponNum == 104) {
        system("cls");
        printf("==================================================================\n\n");
        printf("▷ 쓸만해 보이는 조약돌이다. 꽤나 날카로운데? \n\n");
        printf("==================================================================\n");
        printf("\n");
        printf("엔터키를 누르면 뒤로 돌아갑니다.\n");
        while (1) {
            if (Key() == ENTER) {
                main();
                break;
            }
        }
    }
    else if (equipmentweaponNum == 105) {
        system("cls");
        printf("==================================================================\n\n");
        printf("▷ 피가 묻어있네.. 신고가 우선이려나? \n\n");
        printf("==================================================================\n");
        printf("\n");
        printf("엔터키를 누르면 뒤로 돌아갑니다.\n");
        while (1) {
            if (Key() == ENTER) {
                main();
                break;
            }
        }
    }
    else if (equipmentweaponNum == 106) {
        system("cls");
        printf("==================================================================\n\n");
        printf("▷ 에라이.. '강인한'만 붙이면 다 쌘줄알아?? \n\n");
        printf("==================================================================\n");
        printf("\n");
        printf("엔터키를 누르면 뒤로 돌아갑니다.\n");
        while (1) {
            if (Key() == ENTER) {
                main();
                break;
            }
        }
    }
    else if (equipmentweaponNum == 107) {
        system("cls");
        printf("==================================================================\n\n");
        printf("▷ 얼룩이 있다.. 닦아보니 작은 글씨로 '원'이 적혀있다. 하, 사기당했네\n\n");
        printf("==================================================================\n");
        printf("\n");
        printf("엔터키를 누르면 뒤로 돌아갑니다.\n");
        while (1) {
            if (Key() == ENTER) {
                main();
                break;
            }
        }
    }
    else if (equipmentweaponNum == 108) {
        system("cls");
        printf("==================================================================\n\n");
        printf("▷ 녹슬었으면 버리지 이런걸 쓰라고..? 어라? 꽤 좋은걸? \n\n");
        printf("==================================================================\n");
        printf("\n");
        printf("엔터키를 누르면 뒤로 돌아갑니다.\n");
        while (1) {
            if (Key() == ENTER) {
                main();
                break;
            }
        }
    }
    else if (equipmentweaponNum == 109) {
        system("cls");
        printf("==================================================================\n\n");
        printf("▷ 엄청나다.. 크고, 길고, 단단한.. 그래서 어따쓰라고?\n\n");
        printf("==================================================================\n");
        printf("\n");
        printf("엔터키를 누르면 뒤로 돌아갑니다.\n");
        while (1) {
            if (Key() == ENTER) {
                main();
                break;
            }
        }
    }
    else if (equipmentweaponNum == 110) {
        system("cls");
        printf("==================================================================\n\n");
        printf("▷ 신성한 세계수의 잡것들을 엮어 만들었다.. 이게 뭔데 그래서..!! \n\n");
        printf("==================================================================\n");
        printf("\n");
        printf("엔터키를 누르면 뒤로 돌아갑니다.\n");
        while (1) {
            if (Key() == ENTER) {
                main();
                break;
            }
        }
    }
    else if (equipmentweaponNum == 111) {
        system("cls");
        printf("==================================================================\n\n");
        printf("▷ 백년을 딛었지만 천년까지는 무리같은데.. 아닙니다!! \n\n");
        printf("==================================================================\n");
        printf("\n");
        printf("엔터키를 누르면 뒤로 돌아갑니다.\n");
        while (1) {
            if (Key() == ENTER) {
                main();
                break;
            }
        }
    }
    else if (equipmentweaponNum == 112) {
        system("cls");
        printf("==================================================================\n\n");
        printf("▷ 잊혀졌었던 고대의 대검이다. 내가 알았으니 이제 그냥 고대의 대검이다. \n\n");
        printf("==================================================================\n");
        printf("\n");
        printf("엔터키를 누르면 뒤로 돌아갑니다.\n");
        while (1) {
            if (Key() == ENTER) {
                main();
                break;
            }
        }
    }
    else if (equipmentweaponNum == 113) {
        system("cls");
        printf("==================================================================\n\n");
        printf("▷ 야! 이거 표절아니..읍읍 \n\n");
        printf("==================================================================\n");
        printf("\n");
        printf("엔터키를 누르면 뒤로 돌아갑니다.\n");
        while (1) {
            if (Key() == ENTER) {
                main();
                break;
            }
        }
    }
    else if (equipmentweaponNum == 114) {
        system("cls");
        printf("==================================================================\n\n");
        printf("▷ 누군가의 이름은 참으로 무겁구나.. 어라? 나도 못드는데? \n\n");
        printf("==================================================================\n");
        printf("\n");
        printf("엔터키를 누르면 뒤로 돌아갑니다.\n");
        while (1) {
            if (Key() == ENTER) {
                main();
                break;
            }
        }
    }
    else if (equipmentweaponNum == 115) {
        system("cls");
        printf("==================================================================\n\n");
        setColor(lightgreen, black);
        printf("▷ 세계수의 가장 순수한 가지를 꺽어냈다. 순수함은 곧 힘이니.. \n\n");
        setColor(yellow, black);
        printf("==================================================================\n");
        printf("\n");
        printf("엔터키를 누르면 뒤로 돌아갑니다.\n");
        while (1) {
            if (Key() == ENTER) {
                main();
                break;
            }
        }
    }
    else if (equipmentweaponNum == 116) {
        system("cls");
        printf("==================================================================\n\n");
        setColor(red, black);
        printf("▷ 하나사토, 그녀만을 바라보고 달려왔다.. 내 의지는 끝나지 않으리! \n\n");
        setColor(yellow, black);
        printf("==================================================================\n");
        printf("\n");
        printf("엔터키를 누르면 뒤로 돌아갑니다.\n");
        while (1) {
            if (Key() == ENTER) {
                main();
                break;
            }
        }
    }
    else if (equipmentweaponNum == 117) {
        system("cls");
        printf("==================================================================\n\n");
        setColor(lightred, black);
        printf("▷ 그의 이름의 무게란, <광마> 그 자체와 같다.. \n\n");
        setColor(yellow, black);
        printf("==================================================================\n");
        printf("\n");
        printf("엔터키를 누르면 뒤로 돌아갑니다.\n");
        while (1) {
            if (Key() == ENTER) {
                main();
                break;
            }
        }
    }
    else if (equipmentweaponNum == 118) {
        system("cls");
        printf("==================================================================\n\n");
        setColor(white, black);
        printf("▷ 하, 이번엔 진짜네.. 그래 이 느낌이지!! 강력하고 간지나는!! \n\n");
        setColor(yellow, black);
        printf("==================================================================\n");
        printf("\n");
        printf("엔터키를 누르면 뒤로 돌아갑니다.\n");
        while (1) {
            if (Key() == ENTER) {
                main();
                break;
            }
        }
    }
    else if (equipmentweaponNum == 119) {
        system("cls");
        printf("==================================================================\n\n");
        setColor(lightred, black);
        printf("▷ 나, 키아나 세상이 아름답지 않더라도 이 불꽃으로 미래를 비추리.. \n\n");
        setColor(yellow, black);
        printf("==================================================================\n");
        printf("\n");
        printf("엔터키를 누르면 뒤로 돌아갑니다.\n");
        while (1) {
            if (Key() == ENTER) {
                main();
                break;
            }
        }
    }
    else if (equipmentweaponNum == 120) {
        system("cls");
        printf("==================================================================\n\n");
        setColor(lightcyan, black);
        printf("▷ 김정우라는 이름의 무게는.. 씹덕 오타쿠.. 그만, 그는 대단하다.. \n\n");
        setColor(yellow, black);
        printf("==================================================================\n");
        printf("\n");
        printf("엔터키를 누르면 뒤로 돌아갑니다.\n");
        while (1) {
            if (Key() == ENTER) {
                main();
                break;
            }
        }
    }
    else if (equipmentweaponNum == 121) {
        system("cls");
        printf("==================================================================\n\n");
        setColor(lightcyan, black);
        printf("▷ 그는, 자연과 어린 생명들을 사랑하는 자애로운 사람이다. (?) \n\n");
        setColor(yellow, black);
        printf("==================================================================\n");
        printf("\n");
        printf("엔터키를 누르면 뒤로 돌아갑니다.\n");
        while (1) {
            if (Key() == ENTER) {
                main();
                break;
            }
        }
    }
    else if (equipmentweaponNum == 122) {
        system("cls");
        printf("==================================================================\n\n");
        setColor(lightcyan, black);
        printf("▷ 일곱개의 별이..어.. 뭐야 칠성사이다?\n\n");
        setColor(yellow, black);
        printf("==================================================================\n");
        printf("\n");
        printf("엔터키를 누르면 뒤로 돌아갑니다.\n");
        while (1) {
            if (Key() == ENTER) {
                main();
                break;
            }
        }
    }
    else if (equipmentweaponNum == 123) {
        system("cls");
        printf("==================================================================\n\n");
        setColor(lightcyan, black);
        printf("▷ 문(家)에서 가장 훌륭한 이가 남긴 무언가, 함부로 쓰다간 재앙이 찾아올 것이다. 문(家)재앙..\n\n");
        setColor(yellow, black);
        printf("==================================================================\n");
        printf("\n");
        printf("엔터키를 누르면 뒤로 돌아갑니다.\n");
        while (1) {
            if (Key() == ENTER) {
                main();
                break;
            }
        }
    }
    else if (equipmentweaponNum == 124) {
        system("cls");
        printf("==================================================================\n\n");
        setColor(lightred, black);
        printf("▷ 윤(家)의 귀중한 보물, <石熱> 열기를 내뿜는 굉장한 붉은 돌이다. 조심하지 않으면 산불의 주 원인이 될지도? \n\n");
        setColor(yellow, black);
        printf("==================================================================\n");
        printf("\n");
        printf("엔터키를 누르면 뒤로 돌아갑니다.\n");
        while (1) {
            if (Key() == ENTER) {
                main();
                break;
            }
        }
    }
    else if (equipmentweaponNum == 125) {
        system("cls");
        printf("==================================================================\n\n");
        setColor(lightblue, black);
        printf("▷ 이(家)의 가보, 과거 벼슬에서 제명당한 이가 원한을 품고 날을 간 굉장한 가보, 明剝한 검이다.\n\n");
        setColor(yellow, black);
        printf("==================================================================\n");
        printf("\n");
        printf("엔터키를 누르면 뒤로 돌아갑니다.\n");
        while (1) {
            if (Key() == ENTER) {
                main();
                break;
            }
        }
    }
    else if (equipmentweaponNum == 126) {
        system("cls");
        printf("==================================================================\n\n");
        setColor(red, black);
        printf("▷ 단군의 후손, 그들은 홍익인간이라 불리운다. 그들의 뜻을 이은 검일지리.. 準表한 홍익이로다\n\n");
        setColor(yellow, black);
        printf("==================================================================\n");
        printf("\n");
        printf("엔터키를 누르면 뒤로 돌아갑니다.\n");
        while (1) {
            if (Key() == ENTER) {
                main();
                break;
            }
        }
    }
    else if (equipmentweaponNum == 127) {
        system("cls");
        printf("==================================================================\n\n");
        setColor(lightred, black);
        printf("▷ 인류의 최초이자 최후의 터전, 하늘궁.. 그곳으로 가는 마지막 열쇠이다. 輕浧을 뜻한다.\n\n");
        setColor(yellow, black);
        printf("==================================================================\n");
        printf("\n");
        printf("엔터키를 누르면 뒤로 돌아갑니다.\n");
        while (1) {
            if (Key() == ENTER) {
                main();
                break;
            }
        }
    }
    else if (equipmentweaponNum == 130) {
        system("cls");
        printf("==================================================================\n\n");
        setColor(lightblue, black);
        printf("▷ 천공이 갈라지고, 세상의 종말이 찾아오리, 종언의 순간 내가 있다.\n\n");
        setColor(yellow, black);
        printf("==================================================================\n");
        printf("\n");
        printf("엔터키를 누르면 뒤로 돌아갑니다.\n");
        while (1) {
            if (Key() == ENTER) {
                main();
                break;
            }
        }
        }
    else if (equipmentweaponNum == 999) {
        system("cls");
        printf("==================================================================\n\n");
        setColor(lightcyan, black);
        printf("▷ 모험가여, 검을 쥐고 나아가라! 그대의 길은 고되고 순탄치 않겠지만.. 미래를 향해 달려나가라! 결코 포기마라!!\n\n");
        setColor(yellow, black);
        printf("==================================================================\n");
        printf("\n");
        printf("엔터키를 누르면 뒤로 돌아갑니다.\n");
        while (1) {
            if (Key() == ENTER) {
                main();
                break;
            }
        }
    }
}

void enforcing() {
    system("cls");
    srand(time(NULL));
    if (enforcepercent == 0) {
        printf("강화 수치가 최대치입니다!");
        Sleep(1000);
        main();
    }
        printf("강화를 진행합니다!\n");
        Sleep(1500);
        int randoms = rand() % 100 + 1; //강화 확률 난수
        if (randoms <= enforcepercent) {
            printf("강화 성공!\n");
            enforceLV++;
            enforcepercent -= 10;
            Gold -= 100;
        }
        else {
            printf("강화 실패\n");
            Gold -= 100;
        }
        Sleep(1500);
        main();
}



void gatch() {
    setColor(white, black);
    system("cls");
    printf("\n");
    printf("");
    setColor(yellow, black);
    int x = 2;
    int y = 2;
    printf("==================================================================");
    gotoxy(x - 2, y);
    printf("▷ 일반 기원");
    gotoxy(x, y + 1);
    printf(" 한정 기원");
    gotoxy(x, y + 2);
    printf(" 돌아 가기");
    printf("\n=================================================================="); 
    setColor(cyan, black);
    printf("보유 중인 기원의 돌 : %d개\n",nomalstone);
    setColor(lightcyan, black);
    printf("보유 중인 서약의 돌 : %d개\n",colorfulstone);
    setColor(yellow, black);
    while (1) {
        int n = Key();
        switch (n) {
        case UP: {
            if (y > 2) {
                gotoxy(x - 2, y);
                printf("  ");
                gotoxy(x - 2, y - 1);
                printf("▷ ");
                y--;
            }
            break;
        }
        case DOWN: {
            if (y < 4) {
                gotoxy(x - 2, y);
                printf("  ");
                gotoxy(x - 2, y + 1);
                printf("▷ ");
                y++;
            }
            break;
        }
        case ENTER: {
            if (y == 2) {
                nomalgatch();
            }
            else if (y == 3) {
                colorfulgatch();
            }
            else if (y == 4) {
                main();
            }
        }
        }
    }
}

void nomalgatch() {
    char Nowing[50];
    int max = 127;
    int min = 100;
    setColor(yellow, black);
    system("cls");
    srand(time(NULL));
    if (nomalstone > 0) {
        int randomnumber = rand() % 1000;

        if (randomnumber <= 600 && randomnumber > 0) {
            equipmentweaponNumTemp = rand() % 8 + 100; // 100부터 107 사이의 임의의 숫자 선택 //60%
        }
        else if (randomnumber <= 850 && randomnumber > 600) {
            equipmentweaponNumTemp = rand() % 4 + 108; // 108부터 111 사이의 임의의 숫자 선택 // 25%
        }
        else if (randomnumber <= 950 && randomnumber > 850) {
            equipmentweaponNumTemp = rand() % 3 + 112; // 112부터 114 사이의 임의의 숫자 선택 // 10%
        }
        else if (randomnumber > 950 && randomnumber <= 989) {
            equipmentweaponNumTemp = rand() % 4 + 115; // 115부터 118 사이의 임의의 숫자 선택 //3%
        }
        else if (randomnumber <= 999 && randomnumber > 989) {
            equipmentweaponNumTemp = rand() % 4 + 119; // 119부터 122 사이의 임의의 숫자 선택 //2%
        }
        else {
            equipmentweaponNumTemp = rand() % 5 + 123; // 123부터 127 사이의 임의의 숫자 선택 //1%
        }
    }
    else {
        setColor(lightred, black);
        printf("기원의 돌 수량이 부족합니다!"); Sleep(2000);
        setColor(yellow, black);
        main();
    }
    if (equipmentweaponNumTemp == 100) strcpy_s(Nowing, sizeof(Nowing), "[N] 부러진 검");
    else if (equipmentweaponNumTemp == 101) strcpy_s(Nowing, sizeof(Nowing), "[N] 세계수의 줄기");
    else if (equipmentweaponNumTemp == 102) strcpy_s(Nowing, sizeof(Nowing), "[N] 세계수의 가지");
    else if (equipmentweaponNumTemp == 103) strcpy_s(Nowing, sizeof(Nowing), "[N] 세계수의 뿌리");
    else if (equipmentweaponNumTemp == 104) strcpy_s(Nowing, sizeof(Nowing), "[N] 쓸만한 조약돌");
    else if (equipmentweaponNumTemp == 105) strcpy_s(Nowing, sizeof(Nowing), "[N] 피 묻은 짱돌");
    else if (equipmentweaponNumTemp == 106) strcpy_s(Nowing, sizeof(Nowing), "[C] 강인한 철 검");
    else if (equipmentweaponNumTemp == 107) strcpy_s(Nowing, sizeof(Nowing), "[C] 오만의 검");
    else if (equipmentweaponNumTemp == 108) strcpy_s(Nowing, sizeof(Nowing), "[R] 녹슨 영웅의 검");
    else if (equipmentweaponNumTemp == 109) strcpy_s(Nowing, sizeof(Nowing), "[R] 엄청난 것");
    else if (equipmentweaponNumTemp == 110) strcpy_s(Nowing, sizeof(Nowing), "[R] 세계수 종합세트");
    else if (equipmentweaponNumTemp == 111) strcpy_s(Nowing, sizeof(Nowing), "[R] 백년을 딛고 천년을 날자");
    else if (equipmentweaponNumTemp == 112) strcpy_s(Nowing, sizeof(Nowing), "[SR] 잊힌 고대의 대검");
    else if (equipmentweaponNumTemp == 113) strcpy_s(Nowing, sizeof(Nowing), "[SR] 몽상의 일태도");
    else if (equipmentweaponNumTemp == 114) strcpy_s(Nowing, sizeof(Nowing), "[SR] 누군가의 이름의 무게");
    else if (equipmentweaponNumTemp == 115) strcpy_s(Nowing, sizeof(Nowing), "[SSR] 세계수의 순수한 가지");
    else if (equipmentweaponNumTemp == 116) strcpy_s(Nowing, sizeof(Nowing), "[SSR] 끝나지 않는 하나사토를 향한 의지");
    else if (equipmentweaponNumTemp == 117) strcpy_s(Nowing, sizeof(Nowing), "[SSR] <한태규> 라는 이름의 무게");
    else if (equipmentweaponNumTemp == 118) strcpy_s(Nowing, sizeof(Nowing), "[SSR] 오만의 검");
    else if (equipmentweaponNumTemp == 119) strcpy_s(Nowing, sizeof(Nowing), "[L] 영원토록 타오르는 신염의 검");
    else if (equipmentweaponNumTemp == 120) strcpy_s(Nowing, sizeof(Nowing), "[L] <김정우> 라는 이름의 무게");
    else if (equipmentweaponNumTemp == 121) strcpy_s(Nowing, sizeof(Nowing), "[L] <문준서> 라는 이름의 무게");
    else if (equipmentweaponNumTemp == 122) strcpy_s(Nowing, sizeof(Nowing), "[★★★★★★★] 七星死吏多");
    else if (equipmentweaponNumTemp == 123) strcpy_s(Nowing, sizeof(Nowing), "[U] 문씨 가문의 가보");
    else if (equipmentweaponNumTemp == 124) strcpy_s(Nowing, sizeof(Nowing), "[U] 윤씨 가문의 가보");
    else if (equipmentweaponNumTemp == 125) strcpy_s(Nowing, sizeof(Nowing), "[U] 이씨 가문의 가보");
    else if (equipmentweaponNumTemp == 126) strcpy_s(Nowing, sizeof(Nowing), "[U] 홍익의 뜻 - 단군의 후예");
    else if (equipmentweaponNumTemp == 127) strcpy_s(Nowing, sizeof(Nowing), "[Mythic] 하늘궁의 지배자 - 허의 열쇠");
    else if (equipmentweaponNumTemp == 999) strcpy_s(Nowing, sizeof(Nowing), "[UNKNOWN] 시작의 돌 ");
    Sleep(1500);    
    printf("기원 아이템 : %s\n", Nowing);    
    nomalstone--;
    printf("남은 기원의 돌 : %d개\n", nomalstone);

    int x = 2;
    int y = 3;
    gotoxy(x - 2, y);
    printf("▷ 아이템 흭득하기");
    gotoxy(x - 2, y + 1);
    printf("   아이템 버리기");
    gotoxy(x - 2, y + 2);
    printf("   연속해서 뽑기(아이템 버리기)");
    while (1) {
        int n = Key();
        switch (n) {
        case UP: {
            if (y > 3) {
                gotoxy(x - 2, y);
                printf("  ");
                gotoxy(x - 2, y - 1);
                printf("▷ ");
                y--;
            }
            break;
        }
        case DOWN: {
            if (y < 5) {
                gotoxy(x - 2, y);
                printf("  ");
                gotoxy(x - 2, y + 1);
                printf("▷ ");
                y++;
            }
            break;
        }
        case ENTER: {
            if (y == 3) {
                equipmentweaponNum = equipmentweaponNumTemp;
                main();
            }
            else if (y == 4) {
                main();
            }
            else if (y == 5) {
                nomalgatch();
            }
        }
        }
    }
}

void colorfulgatch() {
    char Nowing[50];
    int max = 127;
    int min = 100;
    setColor(yellow, black);
    system("cls");
    srand(time(NULL));
    if (nomalstone > 0) {
        int randomnumber1 = rand() % 1000;

        if (randomnumber1 <= 400 && randomnumber1 > 0) {
            equipmentweaponNumTemp1 = rand() % 8 + 100; // 100부터 107 사이의 임의의 숫자 선택 //40%
        }
        else if (randomnumber1 <= 700 && randomnumber1 > 400) {
            equipmentweaponNumTemp1 = rand() % 4 + 108; // 108부터 111 사이의 임의의 숫자 선택 // 30%
        }
        else if (randomnumber1 <= 850 && randomnumber1 > 700) {
            equipmentweaponNumTemp1 = rand() % 3 + 112; // 112부터 114 사이의 임의의 숫자 선택 // 15%
        }
        else if (randomnumber1 > 950 && randomnumber1 <= 850) {
            equipmentweaponNumTemp1 = rand() % 4 + 115; // 115부터 118 사이의 임의의 숫자 선택 //10%
        }
        else if (randomnumber1 <= 996 && randomnumber1 > 950) {
            equipmentweaponNumTemp1 = rand() % 4 + 119; // 119부터 122 사이의 임의의 숫자 선택 //4.6%
        }
        else if (randomnumber1 <= 998 && randomnumber1 > 996) {
            equipmentweaponNumTemp1 = rand() % 5 + 123; // 123부터 127 사이의 임의의 숫자 선택 //0.1%
        }
        else {
            equipmentweaponNumTemp1 == 130; //픽업 0.1%
        }
    }
    else {
        setColor(lightred, black);
        printf("서약의 돌 수량이 부족합니다!"); Sleep(2000);
        setColor(yellow, black);
        main();
    }
    if (equipmentweaponNumTemp1 == 100) strcpy_s(Nowing, sizeof(Nowing), "[N] 부러진 검");
    else if (equipmentweaponNumTemp1 == 101) strcpy_s(Nowing, sizeof(Nowing), "[N] 세계수의 줄기");
    else if (equipmentweaponNumTemp1 == 102) strcpy_s(Nowing, sizeof(Nowing), "[N] 세계수의 가지");
    else if (equipmentweaponNumTemp1 == 103) strcpy_s(Nowing, sizeof(Nowing), "[N] 세계수의 뿌리");
    else if (equipmentweaponNumTemp1 == 104) strcpy_s(Nowing, sizeof(Nowing), "[N] 쓸만한 조약돌");
    else if (equipmentweaponNumTemp1 == 105) strcpy_s(Nowing, sizeof(Nowing), "[N] 피 묻은 짱돌");
    else if (equipmentweaponNumTemp1 == 106) strcpy_s(Nowing, sizeof(Nowing), "[C] 강인한 철 검");
    else if (equipmentweaponNumTemp1 == 107) strcpy_s(Nowing, sizeof(Nowing), "[C] 오만의 검");
    else if (equipmentweaponNumTemp1 == 108) strcpy_s(Nowing, sizeof(Nowing), "[R] 녹슨 영웅의 검");
    else if (equipmentweaponNumTemp1 == 109) strcpy_s(Nowing, sizeof(Nowing), "[R] 엄청난 것");
    else if (equipmentweaponNumTemp1 == 110) strcpy_s(Nowing, sizeof(Nowing), "[R] 세계수 종합세트");
    else if (equipmentweaponNumTemp1 == 111) strcpy_s(Nowing, sizeof(Nowing), "[R] 백년을 딛고 천년을 날자");
    else if (equipmentweaponNumTemp1 == 112) strcpy_s(Nowing, sizeof(Nowing), "[SR] 잊힌 고대의 대검");
    else if (equipmentweaponNumTemp1 == 113) strcpy_s(Nowing, sizeof(Nowing), "[SR] 몽상의 일태도");
    else if (equipmentweaponNumTemp1 == 114) strcpy_s(Nowing, sizeof(Nowing), "[SR] 누군가의 이름의 무게");
    else if (equipmentweaponNumTemp1 == 115) strcpy_s(Nowing, sizeof(Nowing), "[SSR] 세계수의 순수한 가지");
    else if (equipmentweaponNumTemp1 == 116) strcpy_s(Nowing, sizeof(Nowing), "[SSR] 끝나지 않는 하나사토를 향한 의지");
    else if (equipmentweaponNumTemp1 == 117) strcpy_s(Nowing, sizeof(Nowing), "[SSR] <한태규> 라는 이름의 무게");
    else if (equipmentweaponNumTemp1 == 118) strcpy_s(Nowing, sizeof(Nowing), "[SSR] 오만의 검");
    else if (equipmentweaponNumTemp1 == 119) strcpy_s(Nowing, sizeof(Nowing), "[L] 영원토록 타오르는 신염의 검");
    else if (equipmentweaponNumTemp1 == 120) strcpy_s(Nowing, sizeof(Nowing), "[L] <김정우> 라는 이름의 무게");
    else if (equipmentweaponNumTemp1 == 121) strcpy_s(Nowing, sizeof(Nowing), "[L] <문준서> 라는 이름의 무게");
    else if (equipmentweaponNumTemp1 == 122) strcpy_s(Nowing, sizeof(Nowing), "[★★★★★★★] 七星死吏多");
    else if (equipmentweaponNumTemp1 == 123) strcpy_s(Nowing, sizeof(Nowing), "[U] 문씨 가문의 가보");
    else if (equipmentweaponNumTemp1 == 124) strcpy_s(Nowing, sizeof(Nowing), "[U] 윤씨 가문의 가보");
    else if (equipmentweaponNumTemp1 == 125) strcpy_s(Nowing, sizeof(Nowing), "[U] 이씨 가문의 가보");
    else if (equipmentweaponNumTemp1 == 126) strcpy_s(Nowing, sizeof(Nowing), "[U] 홍익의 뜻 - 단군의 후예");
    else if (equipmentweaponNumTemp1 == 127) strcpy_s(Nowing, sizeof(Nowing), "[Mythic] 하늘궁의 지배자 - 허의 열쇠");
    else if (equipmentweaponNumTemp1 == 999) strcpy_s(Nowing, sizeof(Nowing), "[UNKNOWN] 시작의 돌 ");    
    else if (equipmentweaponNumTemp1 == 1000) strcpy_s(Nowing, sizeof(Nowing), "[ColorFul] 천공의 빛 - 세계의 끝, 종언의 검");
    Sleep(1500);
    printf("기원 아이템 : %s\n", Nowing);
    colorfulstone--;
    printf("남은 서약의 돌 : %d개\n", colorfulstone);

    int x = 2;
    int y = 3;
    gotoxy(x - 2, y);
    printf("▷ 아이템 흭득하기");
    gotoxy(x - 2, y + 1);
    printf("   아이템 버리기");
    gotoxy(x - 2, y + 2);
    printf("   연속해서 뽑기(아이템 버리기)");
    while (1) {
        int n = Key();
        switch (n) {
        case UP: {
            if (y > 3) {
                gotoxy(x - 2, y);
                printf("  ");
                gotoxy(x - 2, y - 1);
                printf("▷ ");
                y--;
            }
            break;
        }
        case DOWN: {
            if (y < 5) {
                gotoxy(x - 2, y);
                printf("  ");
                gotoxy(x - 2, y + 1);
                printf("▷ ");
                y++;
            }
            break;
        }
        case ENTER: {
            if (y == 3) {
                equipmentweaponNum = equipmentweaponNumTemp1;
                main();
            }
            else if (y == 4) {
                main();
            }
            else if (y == 5) {
                colorfulgatch();
            }
        }
        }
    }
}



    int main() {
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
                    system("cls");
                    gatch();
                }
                else if (startCode == 7) {
                    system("cls");
                    menu();
                }
                else if (startCode == 8) {
                    system("cls");
                    menu();
                }
            }
            else if (menuCode == 1) {
                gameinfo();
            }
            else if (menuCode == 2) {
                system("cls");
                exit(0);
            }
            system("cls");
        }
    }

