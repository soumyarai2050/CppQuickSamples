#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <iomanip>

int main()
{
    //Write to file
    {
        std::ofstream fileWriter("F1.txt");
        std::stringstream str{"000223.txt"};
        int num1 = 5;
        std::string string1;
        str >> num1 >> string1;
        std::cout << "num1: " << num1 << " string1: " << string1 << std::endl;
        //std::endl will move further writes to next-line (i.e. \n separator will be inserted in the file
        fileWriter << "num1: " << num1 << " string1: " << string1 << std::endl;
        //Write high precision value:
        double highPrecisionVal = 27.5678923456765432;
        fileWriter << "highPrecisionVal: " << std::setprecision(20) << highPrecisionVal << std::endl;
    }
    //Read form file word by word
    {
        std::ifstream fileReader("F1.txt");
        int num2 = 0;
        std::string cString2, string2, string3, string4;
        double highPrecisionVal;
        fileReader >> cString2 >> num2 >> string2 >> string3 >> string4 >> highPrecisionVal;
        std::cout << "num2: " << num2 << " cString2: " << cString2 << " string2: " << string2 << " string3: "
        << string3 << " string4: " << string4 << " highPrecisionVal: " << std::setprecision(20) << highPrecisionVal << std::endl;
        //Later do an example of reading tabular data :
        //https://www.youtube.com/watch?v=8IHAwmbUuKU&list=PLgnQpQtFTOGRM59sr3nSL8BmeMZR9GCIA&index=11 time:22:11

    }
    //Read from file line by line
    {
        std::ifstream fileReader("F1.txt");
        std::string line;
        std::getline (fileReader , line);
        std::cout << "Line: " << line << std::endl;
        //Later do an example of reading tabular data :
        //https://www.youtube.com/watch?v=8IHAwmbUuKU&list=PLgnQpQtFTOGRM59sr3nSL8BmeMZR9GCIA&index=11 time:22:11

    }
    getchar();
    return 0;
}
