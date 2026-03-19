#include <iostream>
#include <string>
using namespace std;

int main() {
    setlocale(LC_ALL, "ru");
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