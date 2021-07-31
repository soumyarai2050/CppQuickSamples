
#include <vector>

int main()
{
    vec1.push_back(1<<20);
    vec2.emplace_back(1<<20);
    return 0;
}

/*
The first line is quite straightforward: it adds the number 1048576 to the end of the vector.
 The second, however, is not so clear. Without knowing the type of the vector, we don’t know what constructor it’s invoking,
 so we can’t really say what that line is doing. For example, if vec2 is a std::vector<int>, that line merely adds 1048576 to the end, as with the first line,
 but if vec2 is a std::vector<std::vector<int>>, that second line constructs a vector of over a million elements, allocating several megabytes of memory in the process.
 */