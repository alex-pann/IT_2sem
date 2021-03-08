#include <filesystem>
#include <fstream>
#include <iostream>
#include <string>
#include <cctype>

int main() {
    std::filesystem::path text{"text.txt"};
    std::filesystem::path out{"out.txt"};
    std::filesystem::path c{"c.txt"};
    std::filesystem::path even{"even.txt"};
    std::filesystem::path odd{"odd.txt"};
    std::filesystem::path parent_directory{".."};

    std::ifstream file_in(text); //читаем текст из файла
    std::vector<std::string> words;
    unsigned int n = 0;
    for (std::string word; file_in >> word;) {
        words.push_back(std::move(word));
    }

    std::vector<std::string> words_c;
    std::vector<std::string> words_even;
    std::vector<std::string> words_odd;

    for (auto& word : words) {
        unsigned int n = word.size();
        bool is_c = false;

        for (unsigned int i = 0; i < n; i++) { //переводим все в нижний регистр
            if (!islower(word[i])) {
                word[i] = tolower(word[i]);
            }

            if (word[i] == 'c') { //проверяем, есть ли в слове с
                word[i] = toupper(word[i]);
                is_c = true;
            }
        }

        if (is_c) {
            words_c.push_back(word);
        } else {
            if (n%2 == 0) {
                words_even.push_back(word);
            } else {
                words_odd.push_back(word);
            }
        }
    }

    std::ofstream file_out_c(c);//запись в файлы
    for (auto& word : words_c) {
        file_out_c << word << "_" << std::endl;
    }
    file_out_c.close();

    std::ofstream file_out_even(even);
    for (auto& word : words_even) {
        file_out_even << word << "_" << std::endl;
    }
    file_out_even.close();

    std::ofstream file_out_odd(odd);
    for (auto& word : words_odd) {
        file_out_odd << word << "_" << std::endl;
    }
    file_out_odd.close();
    return 0;
}
