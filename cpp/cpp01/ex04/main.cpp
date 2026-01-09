// on ouvre filename et on copie filename dans un new file "filename" en replancant
// chaque occurence de s1 par s2
# include <string>
# include <iostream>
#include <fstream>

int main(int ac, char **av) {
    if (ac != 4)
        std::cerr << "Error: Expected 3 arguments: <filename> <s1> <s2>." << std::endl;
    
    (void)av;
    std::ifstream file(av[1]);
    if (!file.is_open()) {
        std::cerr << "Error: Can't open de file!" << std::endl;
    }
}