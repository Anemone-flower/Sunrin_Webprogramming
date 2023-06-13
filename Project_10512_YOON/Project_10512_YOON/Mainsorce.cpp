#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <Windows.h>

void playGuessingGame() {
    srand(time(0));
    int targetNumber = rand() % 100 + 1;
    int guess;
    int attempts = 0;

    printf("1부터 100 사이의 숫자를 추측해보세요.\n");

    while (1) {
        printf("추측한 숫자를 입력하세요: ");
        scanf_s("%d", &guess);

        attempts++;

        if (guess == targetNumber) {
            printf("축하합니다! 숫자를 맞췄습니다!\n");
            printf("시도한 횟수: %d\n", attempts);
            break;
        }
        else if (guess < targetNumber) {
            printf("더 큰 숫자를 입력하세요.\n");
        }
        else {
            printf("더 작은 숫자를 입력하세요.\n");
        }
    }
}

int main() {
	char start[10];
	char ptr;
    char loader[5] = { '@', '!', '?', '*','#'};
    char reloader[4] = { '|', '/', '-', '\\' };


	printf("★☆★☆★☆ 정말 대충 만든 제로픈의 게임 ★☆★☆★☆\n");
	Sleep(2000);
	printf("★☆★☆ 게임을 시작하시려면 [게임 시작] 을 입력해주세요! ★☆★☆\n");
    fgets(start, sizeof(start), stdin);

    start[strcspn(start, "\n")] = '\0';

    if (strcmp(start, "게임 시작") == 0) {
        Sleep(1500);
        printf("★☆★☆ 좋습니다! 게임을 시작해볼까요? ★☆★☆.\n");
        Sleep(1500);
        for (int road = 0; road < 10; road++) {
            printf("로딩 중 %c\r", loader[road % 5]);
            fflush(stdout);
            Sleep(1000);
        }
        printf("로드 실패!\n");
        printf("로딩을 다시 시작합니다!\n");
        Sleep(1000);
        for (int reroad = 0; reroad < 10; reroad++) {
            printf("Game.exe %c\r", reloader[reroad % 4]);
            fflush(stdout);
            Sleep(1000);
        }
        printf("로딩 성공!\n");
        playGuessingGame();
}
    else {
        printf("Error, GameEnd.exe\n");
        Sleep(1500);
        printf("ErrorErrorErrorErrorErrorErrorErrorErrorErrorErrorErrorErrorErrorErrorErrorErrorErrorErrorErrorErrorErrorErrorErrorErrorErrorErrorErrorErrorErrorErrorErrorErrorErrorErrorErrorErrorErrorErrorErrorErrorErrorErrorErrorErrorErrorErrorErrorErrorErrorErrorErrorErrorErrorErrorErrorErrorErrorErrorErrorErrorErrorErrorErrorErrorErrorErrorError\n");
        Sleep(1500);
        printf("(●'◡'●)(●'◡'●)(●'◡'●)(●'◡'●)(●'◡'●)(●'◡'●)(●'◡'●)(●'◡'●)(●'◡'●)(●'◡'●)(●'◡'●)(●'◡'●)(●'◡'●)(●'◡'●)(●'◡'●)(●'◡'●)(●'◡'●)(●'◡'●)(●'◡'●)(●'◡'●)(●'◡'●)(●'◡'●)(●'◡'●)(●'◡'●)(●'◡'●)(●'◡'●)(●'◡'●)(●'◡'●)(●'◡'●)(●'◡'●)(●'◡'●)(●'◡'●)(●'◡'●)(●'◡'●)(●'◡'●)(●'◡'●)(●'◡'●)(●'◡'●)(●'◡'●)(●'◡'●)(●'◡'●)(●'◡'●)(●'◡'●)(●'◡'●)(●'◡'●)\n");
        Sleep(1500);
        playGuessingGame();
        return 0;
    }

}