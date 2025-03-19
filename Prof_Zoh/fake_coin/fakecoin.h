#define MAX_CNT 3
#include <stdio.h>
#include <stdlib.h>

int left[22]  = {0,};
int right[22] = {0,};

char input[23];
int  coins[22];

int balance_call_cnt = 0;

FILE* in;
FILE* out;

void load_coins() {
    in = fopen("C:\\Users\\USER\\local_repo\\Alogorithm-Practice\\Prof_Zoh\\fake_coin\\sample_data\\06.inp", "r");
    fscanf(in, "%22s", input);

    for (int i = 0; i < 22; i++) {
        coins[i] = input[i] - '0';
    }

    fclose(in);
}


void report_coin(int i) {
    out = fopen("C:\\Users\\USER\\local_repo\\Alogorithm-Practice\\Prof_Zoh\\fake_coin\\sample_data\\06.out", "w");
    fprintf(out, "%d", i);
    exit(0);
}


int balance(int left[], int right[]) {
    balance_call_cnt += 1;
    if (balance_call_cnt > MAX_CNT) {
        out = fopen("C:\\Users\\USER\\local_repo\\Alogorithm-Practice\\Prof_Zoh\\fake_coin\\sample_data\\06.out", "w");
        fprintf(out, "Function call limit over");
        exit(0);
    }

    int left_weight = 0, right_weight = 0;

    for (int i=1; i < 22; i++) {
        if (left[i] == 1 && right[i] == 1) {
            printf("둘 다 같음\n");
            return 999;
        }
        if (left[i] != 0 && left[i] != 1) {
            printf("더미 값 들어감\n");
            return 999;
        }
        if (right[i] != 0 && right[i] != 1) {
            printf("더미 값 들어감\n");
            return 999;
        }
        if (left[i] == 1) {
            left_weight += coins[i];
        }
        if (right[i] == 1) {
            right_weight += coins[i];
        }
    }

    if (left_weight < right_weight) { return 1; }
    else if (left_weight == right_weight) { return 0; }
    else if (left_weight > right_weight) { return -1; }
}