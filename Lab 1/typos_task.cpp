#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

// Задание 17
bool checkWordsAreSimilar(const string word1, const string word2) {
    int len1 = word1.size();
    int len2 = word2.size();

    if (abs(len1 - len2) > 1) return false;

    for (int i = -1; i < len1; ++i) { 
        string w1 = word1;
        if (i >= 0) w1.erase(i, 1);

        for (int j = -1; j < len2; ++j) { 
            string w2 = word2;
            if (j >= 0) w2.erase(j, 1);

            if (w1 == w2) return true;
        }
    }

    return false;
}

int main() {
    ifstream inputFile("src/input.txt");
    ofstream outputFile("src/output.txt");

    if (!inputFile.is_open()) {
        cerr << "Ошибка открытия файла input.txt" << endl;
        return 1;
    }

    int N, M;
    inputFile >> N >> M;

    vector<string> dictionary(N);
    for (int i = 0; i < N; ++i) {
        inputFile >> dictionary[i];
    }

    vector<string> text(M);
    for (int i = 0; i < M; ++i) {
        inputFile >> text[i];
    }

    for (string word : text) {
        vector<string> similarWords;

        for (string dictWord : dictionary) {
            if (checkWordsAreSimilar(word, dictWord)) {
                similarWords.push_back(dictWord);
            }
        }

        outputFile << word << " " << similarWords.size();
        if (similarWords.size() == 1) {
            outputFile << " " << similarWords[0];
        }
        outputFile << "\n";
    }

    inputFile.close();
    outputFile.close();

    return 0;
}
