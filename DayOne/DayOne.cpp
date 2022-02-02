#include <iostream>
#include <fstream>
#include <string>
#include <list>


int push(int* mas, int v)
{
    mas[0] = mas[1];
    mas[1] = mas[2];
    mas[2] = v;
    return *mas;
}

int sum(int* mas)
{
    return mas[0] + mas[1] + mas[2];
}


int main()
{
    std::string path("C:/Users/Maksym/source/repos/Adventofcode/Adventofcode/inputOne.txt");

    std::string line;

    std::ifstream in(path);

    int count1 = 0;
    int count2 = 0;
    std::list<std::string> input;

    if (in.is_open())
    {
        while (getline(in, line))
        {
            input.push_back(line);
        }
    }
    else std::cout << "File not found";
    in.close();

    auto iter = input.begin();
    while (iter != std::prev(input.end()))
    {
        int var1 = stoi(*iter);
        int var2 = stoi(*(++iter));

        if (var1 < var2)
            count1++;
    }

    {
        int win[3];
        iter = input.begin();
        win[0] = stoi(*iter);
        win[1] = stoi(*(++iter));
        win[2] = stoi(*(++iter));
        while (iter != std::prev(input.end()))
        {
            int var1 = sum(win);
            push(win, stoi(*(++iter)));
            int var2 = sum(win);

            if (var1 < var2)
                count2++;
        }
    }

    std::cout << count1 << "\n";
    std::cout << count2 << "\n";
    system("pause");
    return 0;
}

