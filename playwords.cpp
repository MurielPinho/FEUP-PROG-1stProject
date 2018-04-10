#include <iostream>
#include <string>
#include <regex>
#include <fstream>
#include <vector>
#include <ctime>
#include <random>
#include <chrono>

using namespace std;
using namespace std::regex_constants;

int playwords(string pattern);
bool checkWord(const string word, const vector<string> lista);
string guessWord(const vector<string> lista);
int main()
{
        int op;
        vector<string> dic;
        string word, file4read, line;
        ifstream infile;

        srand((unsigned int)time(0));
//Leitura do arquivo
        getline(cin, file4read);
        infile.open(file4read);
        if (infile.fail())
        {
                cerr << "Error opening file: " << file4read << endl;
                exit(1);
        }
//Transferencia para o vetor
        while(!infile.eof())
        {
                getline(infile, line);
                dic.push_back(line);
        }
        cout << "PLAYWORDS" << endl;
        cout << "=======================================" << endl;
        cout << "Choose your option: " << endl;
        cout << "Option 1: Check a word" << endl;
        cout << "Option 2: Guess a word" << endl;
        cout << "Option 3: Search a word by letters" << endl;
        cout << "Option 4: Build a word" << endl;
        cout << "Option 5: Wildcards!" << endl;

        do
        {
                cin >> op;
                if(op>5 || op<1)
                        cout << "Please enter a vaid option (between 1 and 5)" << endl;
        } while(op>5 || op<1);

        switch (op) {
        case 1:
                getline(cin, word);
                if(checkWord(word, dic))
                        cout << "Word exists!" << endl;
                else
                        cout << "Word does not exists" << endl;
                break;
        case 2:
                string aux;
                int i = 3;
                aux = guessWord(dic);
                do
                {
                        getine(cin, word);
                        if(aux != word)
                        {
                                i--;
                                cout << "Try Again(" << i << " chances left!)" << endl;
                        }
                } while(aux != word || i != 0);

                break;
        // case 3:
        //     break;
        // case 4:
        //     break;
        case 5:
                int aux;
                cout << "Insert Wildcard: ";
                getline(cin, word);
                if((aux = (playwords(word)) < 0))
                        cout << "Error opening file" << endl;
                else if(aux==0)
                        cout << "No matching words" << endl;
                break;
        default:
                break;

        }

        infile.close();
        return 0;
}
//Funcoes
int playwords(string pattern)
{
        string new_pattern = "^" + pattern + "$",
               line;
        regex reg;
        ifstream file;
        int flag;
        for (size_t i = 0; i < new_pattern.length(); i++)
        {
                if (new_pattern.at(i) == '?')
                {
                        new_pattern.replace(i, 1, ".");
                }
                else if(new_pattern.at(i) == '*')
                {
                        new_pattern.replace(i, 1, ".*");
                        i++;
                }
        }
        reg.assign(new_pattern, icase);

        file.open("Output.txt");
        if(file.fail())
                return -1;

        while (!file.eof())
        {
                getline(file, line);

                if(regex_match(line, reg))
                {
                        cout << line << endl;
                        flag++;
                }
        }
        return flag;
}

bool checkWord(const string word, const vector<string> lista)
{
        for (size_t i = 0; i < lista.size(); i++)
        {
                if (lista.at(i)==word)
                        return true;
        }
        return false;
}

string guessWord(const vector<string> lista)
{
        string word;
        int seed, n;

        n = rand () % lista.size();
        seed = chrono::system_clock::now().time_since_epoch().count();

        word = lista.at(n);

        shuffle(word.begin(), word.end(), default_random_engine(seed));

        return word;
}
