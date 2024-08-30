#include <iostream>
#include <cctype>
#include <string>

int main() {
    std::string input;
    std::cout << "Enter a lowercase string: ";
    std::cin >> input;

    for (char& c : input) {
        if (std::islower(c)) {
            c = std::toupper(c);
        }
    }

    std::cout << "Uppercase string: " << input << std::endl;

    return 0;
}
// #include <iostream>
// #include <iostream>
// #include <cctype>
// #include <string>

// int main() {
//     std::string input;
//     std::cout << "Enter a lowercase string: ";
//     std::cin >> input;

//     for (char& c : input) {
//         if (std::islower(c)) {
//             c = std::toupper(c);
//         }
//     }

//     std::cout << "Uppercase string: " << input << std::endl;

//     return 0;
// }