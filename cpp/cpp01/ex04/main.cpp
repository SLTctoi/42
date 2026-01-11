#include <string>
#include <iostream>
#include <fstream>

int main(int ac, char **av) {
    if (ac != 4) {
        std::cerr << "Error: Expected 3 arguments: <filename> <s1> <s2>" << std::endl;
        return 1;
    }

    std::string filename = av[1];
    std::string s1 = av[2];
    std::string s2 = av[3];

    if (s1.empty()) {
        std::cerr << "Error: s1 cannot be empty" << std::endl;
        return 1;
    }

    std::ifstream infile(filename.c_str());
    if (!infile.is_open()) {
        std::cerr << "Error: Cannot open file '" << filename << "'" << std::endl;
        return 1;
    }

    std::string outfilename = filename + ".replace";
    std::ofstream outfile(outfilename.c_str());
    if (!outfile.is_open()) {
        std::cerr << "Error: Cannot create file '" << outfilename << "'" << std::endl;
        infile.close();
        return 1;
    }

    std::string line;
    while (std::getline(infile, line)) {
        std::string result;
        size_t pos = 0;
        size_t found;

        while ((found = line.find(s1, pos)) != std::string::npos) {
            result += line.substr(pos, found - pos);
            result += s2;
            pos = found + s1.length();
        }
        result += line.substr(pos);
        
        outfile << result;
        if (!infile.eof())
            outfile << std::endl;
    }

    infile.close();
    outfile.close();
    
    std::cout << "File created: " << outfilename << std::endl;
    return 0;
}