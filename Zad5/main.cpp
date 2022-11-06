#include <iostream>
#include <ranges>
#include <string>
#include <sstream>

std::string dec2bin(std::string dec);
std::string dec2hex(std::string dec);

std::string bin2dec(std::string bin);
std::string bin2hex(std::string bin);

std::string oct2bin(std::string oct);

int main()
{
    std::cout << "dec2bin: " << "44(10) = "    << dec2bin("44")     << "(2)\n";
    std::cout << "dec2hex: " << "44(10) = "    << dec2hex("44")     << "(16)\n";
    std::cout << "bin2dec: " << "101(2) = "    << bin2dec("101")      << "(10)\n";
    std::cout << "bin2hex: " << "101100(2) = " << bin2hex("101100") << "(16)\n";
    std::cout << "oct2bin: " << "115(8) = "    << oct2bin("115")    << "(2)\n";

    return 0;
}

std::string dec2bin(std::string dec)
{
    std::stringstream stream;
    int v = std::stoi(dec);
    do
    {
        stream << v % 2;
        v /= 2;
    } while (v != 0);

    std::string out = stream.str();
    return {out.rbegin(), out.rend()};
}


std::string dec2hex(std::string dec)
{
    std::stringstream stream;
    int v = std::stoi(dec);
    do
    {
        if(const int n = v % 16; n < 9)
            stream << n;
        else
            stream << static_cast<char>('A' + n - 10);
        v /= 16;
    } while (v != 0);

    std::string out = stream.str();
    return {out.rbegin(), out.rend()};
}


std::string bin2dec(std::string bin)
{
    int v = 0, i = 0;
    for (const char& c : bin | std::views::reverse)
        v += (c - '0') * static_cast<int>(std::pow(2, i++));
    
    return std::to_string(v);
}


std::string bin2hex(std::string bin)
{
    return dec2hex(bin2dec(bin));
}


std::string oct2bin(std::string oct)
{
    std::string out;
    for(const char& c : oct | std::views::reverse)
    {
        auto s = std::string_view(dec2bin(std::to_string(c + '0')));
        s = s.substr(s.length() - 3, 3);
        out.insert(0, s);
    }

    return out;
}