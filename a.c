#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_SIZE 100

int main() {
    char input_str[MAX_SIZE];
    int char_count[26] = {0};  // アルファベットの数だけ要素を持つ配列を作成
    int pair_count[26][26] = {0};  // 二文字の組み合わせのカウント
    int space_count = 0;  // スペースの数をカウントする変数
    int total_char_count = 0;  // 全体の文字数をカウントする変数

    // 文字列を入力
    printf("文字列を入力してください: ");
    fgets(input_str, sizeof(input_str), stdin);

    // 文字列を小文字に変換
    for (int i = 0; input_str[i] != '\0'; i++) {
        input_str[i] = tolower(input_str[i]);
    }

    // 文字数をカウント
    for (int i = 0; input_str[i] != '\0'; i++) {
        if (isalpha(input_str[i])) {  // アルファベットのみをカウント
            char_count[input_str[i] - 'a']++;
            total_char_count++;  // アルファベットを見つけたら全体の文字数を増やす
            if (i > 0 && isalpha(input_str[i - 1])) {
                pair_count[input_str[i - 1] - 'a'][input_str[i] - 'a']++;
            }
        }
        // 記号やスペースをスペースとしてカウント
        else if (isspace(input_str[i]) || ispunct(input_str[i])) {
            space_count++;
        }
    }

    // 上位3つの組み合わせを表示
    printf("\n上位10の組み合わせ:\n");
    for (int k = 0; k < 10; k++) {
        double max_probability = -1.0;
        int max_i = -1, max_j = -1;
        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < 26; j++) {
                if (pair_count[i][j] > 0) {
                    double probability = (double)pair_count[i][j] / total_char_count;
                    if (probability > max_probability) {
                        max_probability = probability;
                        max_i = i;
                        max_j = j;
                    }
                }
            }
        }
        if (max_i >= 0 && max_j >= 0) {
            printf("%c%c: %.2f%% (占有率: %.2f%%)\n", 'a' + max_i, 'a' + max_j, max_probability * 100.0, max_probability * 100.0 / total_char_count);
            pair_count[max_i][max_j] = 0;  // 重複を避けるためにカウントをクリア
        }
    }

    return 0;
}

