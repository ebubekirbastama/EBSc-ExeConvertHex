#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>

int main()
{
    std::string exe_path;
    std::cout << "Lutfen exe dosyasinin yolunu girin: ";
    std::cin >> exe_path;

    std::ifstream file(exe_path, std::ios::binary | std::ios::ate);

    if (!file.is_open())
    {
        std::cerr << "Dosya acilamadi!" << std::endl;
        return 1;
    }

    std::streamsize size = file.tellg();
    std::vector<char> buffer(size);
    file.seekg(0, std::ios::beg);
    file.read(buffer.data(), size);

    std::string output_path;
    std::cout << "Kaydedilecek dosyanin adini girin: ";
    std::cin >> output_path;

    std::ofstream output(output_path, std::ios::out | std::ios::app);
    for (int i = 0; i < size; ++i)
    {
        output << std::setw(2) << std::setfill('0') << std::hex << (unsigned int)(unsigned char)buffer[i];
    }

    file.close();
    output.close();

    return 0;
}
