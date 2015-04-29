#include <iostream>
#include <fstream>
#include <cstdlib>

void bestbuzz(std::ostream& os, const int& num) {
    os << "#include <iostream>\nint main() {\n\tfor (int i = 1; i <= " << num << "; ++i) {\n";
    for (int i = 1; i <= num; ++i) {
        bool fizz = i%3 == 0;
        bool buzz = i%5 == 0;
        os << "\t\tif (i==" << i << ") {\n";
        if (fizz && buzz)
            os << "\t\t\tstd::cout << \"fizzbuzz\" << std::endl;";
        else if (fizz)
            os << "\t\t\tstd::cout << \"fizz\" << std::endl;";
        else if (buzz)
            os << "\t\t\tstd::cout << \"buzz\" << std::endl;";
        else
            os << "\t\t\tstd::cout << " << i << " << std::endl;";
        os << "\n\t\t}\n";
    }
    os << "\t}\n\treturn 0;\n}";
}

int main(int argc, char *argv[]) {
    if (argc == 3) {
        std::ofstream file;
        file.open(argv[1]);
        int upto = atoi(argv[2]);
        bestbuzz(file, upto);
        file.close();
    } else {
        bestbuzz(std::cout, 100);
    }
    return 0;
}
