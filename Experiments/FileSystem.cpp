#include <iostream>
#include <string>
#include <fstream>
//C++17 and onwards
#include <filesystem>

//get alias to reduce code bloat
namespace fs = std::filesystem;

int main()
{
    fs::create_directories("newdir/a/b");
    std::ofstream ("newdir/F1.txt");
    std::ofstream ("newdir/F2.txt");
    for (auto & path : fs::directory_iterator("newdir"))
        std::cout << " path: " << path << " filename: " << fs::path(path).filename() << " extension: "
                  << fs::path(path).extension() << " stem: " << fs::path(path).stem() << std::endl;
    if (fs::exists("newdir/F1.txt"))
    {
        //Enable this to remove the above created dir and all files / contents inside of it
        //fs::remove_all("newdir");
    }

    return 0;
}
