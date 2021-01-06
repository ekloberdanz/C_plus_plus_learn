#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <ctype.h>


void enter_number();
int add_numbers(int a, int b);
void word_count();

int main() {
    // enter_number();
    // std::cout << add_numbers(10, 15) << "\n";
    word_count();
    return 0;

}

void enter_number() {
    int number;
    std::cout << "Enter a number: ";
    std::cin >> number;
    std::cout << "Your number is " << number << "\n";
}

int add_numbers(int a, int b){
    int s;
    s = a + b;
    return s;
}

void word_count(){
    std::ifstream file("war_and_peace.txt");
    std::string str;
    std::map<std::string, int> mp;
    while (std::getline(file, str)) {
        std::string word = "";
        for (char character: str) {
            if (ispunct(character) == false && character != ' ') {
                word += character;
            }
            else {
                // std::cout << word << std::endl;        
                if (!mp.count(word)) {
                    mp.insert(make_pair(word, 1)); 
                }
                else {
                    mp[word]++;
                }
                word.clear();
            }
        }
    }
    file.close();
    for (const auto &word : mp) {
        std::cout << word.first << ": " << word.second << std::endl;
    }
}