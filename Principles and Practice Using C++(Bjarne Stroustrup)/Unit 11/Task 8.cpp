//8. Используйте программу из предыдущего упражнения для создания словаря(в качестве альтернативы подходу.
//описанному в разделе 1 1 .7).Примените ее к многостраничному текстовому файлу.проанализируйте результат и подумайте,
//можно ли улучшить эту программу.чтобы получить более качественный словарь.

#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>
#include <set>

void add_symb_to_space(std::string s, std::vector<char>& vec)
{
    for (char ch : s)
        vec.push_back(ch);
}

void conversion(std::ifstream& ifst, const std::vector<char>& vec, std::set<std::string>& st)
{
    bool flag;
    std::string word, line;
    while (std::getline(ifst,line))
    {
        std::istringstream is;
        is.str(line);
        while (is >> word)
        {
            flag = true;
            std::string new_word;
            for (char& ch : word)
                ch = tolower(ch);
            if (word == "don't") { new_word = "do not"; flag = false; }
            else if (word == "can't") { new_word = "can not"; flag = false; }
            else if (word == "could't") { new_word = "could not"; flag = false; }
            else if (word == "won't") { new_word = "will not"; flag = false; }

            if (flag)
            {
                for (int i = 0; i < word.length(); i++)
                {
                    if (std::find(vec.begin(), vec.end(), word[i]) != vec.end())
                    {
                        if (i > 0 && word[i] == '-' && word[i - 1] >= 'a' && word[i + 1] <= 'z') continue;
                        word[i] = ' ';
                    }
                }
                new_word = word;
            }

            st.insert(new_word);
        }
    }
}

void print_dictionary(const std::set<std::string>& st, std::ofstream& ofst)
{
    for (auto i : st)
        ofst << i << std::endl;
}

int main()
{
    std::vector<char> vec{ '.',';',',','-','?',39};
    std::set<std::string> dictionary;
    std::ifstream ifst;
    std::ofstream ofst;
    std::string file_name;

    std::cout << "Enter the file name for reading: ";
    std::getline(std::cin, file_name);
    
    ifst.open(file_name);
    if (!ifst.is_open())
    {
        std::cerr << "File " << file_name << " can't be open!" << std::endl;
        return 1;
    }

    file_name.clear();
    std::cout << "Enter the file name for writing the dictionary: ";
    std::getline(std::cin, file_name);

    ofst.open(file_name);
    if (!ifst.is_open())
    {
        std::cerr << "File " << file_name << " can't be opened or created!" << std::endl;
        return 1;
    }
    
    conversion(ifst, vec, dictionary);

    std::cout << "Result:" << std::endl;
    print_dictionary(dictionary, ofst);

    return 0;
}