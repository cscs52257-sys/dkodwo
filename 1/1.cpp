#include <iostream>
#include <string>
using namespace std;
void prntm(int matrix[7][7], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout.width(4);
            cout << matrix[i][j];
        }
        cout << endl;
    }
}
int main() {
    cout << "1) \n";
    setlocale(LC_ALL, "ru");
    const int ROWS = 7;
    const int COLS = 7;
    int matrix[ROWS][COLS] = {
        {1, -4, 8, -2, 5, -9, 3},
        {2, 7, -1, 6, -3, 0, 4},
        {3, -5, 2, -8, 9, 1, -6},
        {4, 0, -7, 3, -1, 5, 8},
        {5, -2, 6, -4, 7, -3, 9},
        {6, 9, -5, 1, -8, 2, -4},
        {7, -3, 0, -6, 4, -1, 5}
    };

    int K;
    cout << "Исходная матрица:" << endl;
    prntm(matrix, ROWS, COLS);

    cout << "Введите номер строки K (из первого столбца) для сортировки: ";
    cin >> K;
    int Row_id = -1;
    for (int i = 0; i < ROWS; i++) {
        if (matrix[i][0] == K) {
            Row_id = i;
            break;
        }
    }

    try {
        if (Row_id == -1) {
            throw runtime_error("Ошибка: Cтрока с таким номером не найдена в первом столбце");
        }
    }
    catch (const runtime_error& err) {
        cout << err.what() << endl;
        return -1;
    }

    for (int i = 1; i < COLS - 1; i++) {
        for (int j = 1; j < COLS - i; j++) {
            if (matrix[Row_id][j] > matrix[Row_id][j + 1]) {
                for (int r = 0; r < ROWS; r++) {
                    int temp = matrix[r][j];
                    matrix[r][j] = matrix[r][j + 1];
                    matrix[r][j + 1] = temp;
                }
            }
        }
    }
    cout << "Матрица после сортировки по строке K = " << K << ":" << endl;
    prntm(matrix, ROWS, COLS);

    cout << "2) \n";
    int N;
    string s;
    cout << "Введите длину слов N: ";
    if (!(cin >> N)) {
        cout << "Ошибка: введите целое число" << endl;
        return -1;
    }
    cin.ignore(1000, '\n');
    cout << "Введите строку (любые слова через пробел): ";
    getline(cin, s);
    int count = 0;
    int wordLen = 0;
    string S = s + " ";
    for (int i = 0; i < S.length(); i++) {
        if (S[i] != ' ' && S[i] != ',' && S[i] != '.' && S[i] != '!') {
            wordLen++;
        }
        else {
            if (wordLen > 0) {
                if (wordLen != N) {
                    count++;
                }
                wordLen = 0;
            }
        }
    }
    cout << "Количество слов с длиной не равной " << N << ": " << count << endl;

    return 0;
}

    cout << "Количество слов с длиной не равной " << N << ": " << count << endl;

    return 0;
}
}
