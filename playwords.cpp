#include <iostream>
#include <string>
#include <regex>
#include <fstream>
#include <vector>
#include <ctime>
#include <random>
#include <chrono>
#include <cctype>

using namespace std;
using namespace std::regex_constants;

void strupper(string &s);
int playwords(string pattern);
bool checkWord(const string word, const vector<string> lista);
string guessWord(const vector<string> lista, const int num);
void searchWord(string letters, const vector<string> lista);
int main()
{
    int op, a, n, i = 3;
    vector<string> dic;
    string word, file4read, line, aux, aux2;
    ifstream infile;

    srand((unsigned int)time(0));
//Leitura do arquivo
    cout << "Input file name: " << endl;
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
    infile.close();

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
//limpando o buffer
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    switch (op)
    {
    case 1:
        getline(cin, word);
        strupper(word);
        if(checkWord(word, dic))
            cout << "Word exists!" << endl;
        else
            cout << "Word does not exists" << endl;
        break;
    case 2:
        n = rand () % dic.size();
        aux = guessWord(dic, n);
        aux2 = dic.at(n);
        cout << "Form a word with: "<< aux << endl;
        do
        {
            getline(cin, word);
            if(aux2 != word)
            {
                i--;
                cout << "Try Again(" << i << " chances left!)" << endl;
            }
            else
                break;
        }while(i > 0);

        if(aux2 == word)
            cout << "Winner Winner, Chicken Dinner!!!" << endl;
        else
            cout << "Better luck next time, Loser!" << endl;
        break;
    case 3:
        cout << "Provide the set of letters: ";
        getline(cin, word);
        searchWord(word, dic);
        break;
    // case 4:
    //     break;
    case 5:
        cout << "Insert Wildcard: ";
        //getline(cin, word);
        if((a = (playwords(word)) < 0))
            cout << "Error opening file" << endl;
        else if(a==0)
            cout << "No matching words" << endl;
        break;
    default:
        break;
    }

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

string guessWord(const vector<string> lista, const int num)
{
    string word;
    int seed;

    seed = chrono::system_clock::now().time_since_epoch().count();

    word = lista.at(num);

    shuffle(word.begin(), word.end(), default_random_engine(seed));

    return word;
}

void searchWord(string letters, const vector<string> lista)
{
    int flag;

    for (size_t i = 0; i < lista.size(); i++)
    {
        if (lista.at(i).size() >= letters.size())
        {
            for (size_t j = 0; j < lista.at(i).size(); j++) //verifica letras da palavra do vetor
            {
                for (size_t k = 0; k < letters.size(); k++) //verifica letras fornecidas
                {
                    if(letters.at(k)==lista.at(i).at(j))
                    {
                        flag = 1;
                        k = letters.size();
                    }
                    else
                        flag = 0;
                }
            }
        }
        if(flag==1)
            cout << lista.at(i) << endl;
    }
}

void strupper(string &s)
{

    for(size_t i; i < s.size(); i++)
    {
        if(s.at(i)<='z' && s.at(i)<='a')
            cout << s.at(i) - 32 << endl;
    }
}
