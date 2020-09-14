
#include <fstream>
#include <algorithm> // for remove
#include "files_handler.h"
#include "../exceptions/exceptions.h"


std::string read_from_file(std::string file_name)
{
    std::string path = "./data _files/";
    path += file_name;
    std::ifstream file(path.c_str());

    if (!file.is_open() || file.peek() == std::ifstream::traits_type::eof())
        throw UnableReadFromFile("Error");

    std::string content((std::istreambuf_iterator<char>(file)),(std::istreambuf_iterator<char>()));

    content.erase(std::remove(content.begin(), content.end(), '\n'), content.end());
    return content;
}

void write_into_file(std::string file_name, std::string data)
{
    std::string path = "./data _files/";
    path += file_name;
    std::ofstream file(path.c_str(), std::ios_base::app);

    if(!file.is_open())
        throw UnableWriteToFile("Error");
    file << data;
}