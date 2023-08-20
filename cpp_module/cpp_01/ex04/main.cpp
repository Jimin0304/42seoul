#include <iostream>
#include <fstream>

int main(int argc, char *argv[])
{
    if (argc != 4)
    {
        std::cout << "Wrong arguments: <program> <filename> <s1> <s2>" << std::endl;
        exit(1);
    }

    std::string s1 = argv[2];
    std::string s2 = argv[3];

    std::ifstream   ifs(argv[1]);
    if (ifs.fail())
    {
        std::cout << "Can't find the file..." << std::endl;
        exit(1);
    }
    std::ofstream   ofs(std::string(argv[1]) + ".replace");
    if (ofs.fail())
    {
        std::cout << "Failed to create output file..." << std::endl;
        ifs.close();
        exit(1);
    }

    size_t  s1_len = s1.length();
    size_t  s2_len = s2.length();
    size_t  pos = 0;
    std::string content;
    
    while (!ifs.eof())
    {
        std::getline(ifs, content);
        pos = 0;
        while (1)
        {
            pos = content.find(s1, pos);
            if (pos == std::string::npos)
                break ;
            content.erase(pos, s1_len);
            content.insert(pos, s2);
            pos += s2_len;
        }
        ofs << content;
        if (!ifs.eof())
            ofs << std::endl;
    }

    ifs.close();
    ofs.close();

    return (0);
}