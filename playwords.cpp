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
//Escopo das Funcoes
//================================================================
//Funcao que converte toda uma string para letras maiusculas
void strUpper(string &s);
//================================================================
//Funcao que procura palavras de acordo com a Wildcard
int playwords(string pattern, const vector<string> lista);
//================================================================
//Funcao que verifica a existencia de uma palavra no vetor
bool checkWord(const string word, const vector<string> lista);
//================================================================
//Funcao procura uma palavra aleatoria e embaralha suas letras
string guessWord(const vector<string> lista, const int num);
//================================================================
//Funcao que procura palavras a partir de um conjunto de letras
void searchWord(string letters, const vector<string> lista);

int main()
{
    int op, a, n1, n2, i = 3;
    vector<string> dic;
    string word, file4read, line, aux, aux2;
    ifstream infile;

//Leitura do arquivo
    cout << "Input file name: " << endl;
    getline(cin, file4read);
    infile.open(file4read);
    if (infile.fail())
	{
		cerr << "Error opening file: " << file4read << endl;
		exit(1);
	}
//Transferencia de dados para o vetor
    while(!infile.eof())
	{
        getline(infile, line);
        dic.push_back(line);
    }
    infile.close();

//Interface
    cout << "PLAYWORDS" << endl;
    cout << "=======================================" << endl;
    cout << "Choose your option: " << endl;
    cout << "Option 1: Check a word" << endl;
    cout << "Option 2: Guess a word" << endl;
    cout << "Option 3: Search a word by letters" << endl;
    cout << "Option 4: Build a word" << endl;
    cout << "Option 5: Wildcards!" << endl;

//Verificação do input das opcoes
    do
    {
        cin >> op;
        if(op>5 || op<1)
            cout << "Please enter a vaid option (between 1 and 5)" << endl;
    } while(op>5 || op<1);

//Limpa o buffer
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

//Seletor da operacao
    switch (op)
    {
    //Verifica se palavra existe
    case 1:
        getline(cin, word);
        strUpper(word);
        if(checkWord(word, dic))
            cout << "Word exists!" << endl;
        else
            cout << "Word does not exists" << endl;
        break;
    //Escolhe uma palavra aleatoria, embaralha as letras e pede ao usuario para adivinhar
    case 2:
        srand((unsigned int)time(0));
        n1 = rand () % dic.size();
        aux = guessWord(dic, n1);
        aux2 = dic.at(n1);
        cout << "Form a word with: "<< aux << endl;
        do
        {
            getline(cin, word);
            strUpper(word);
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
    //Apresentar palavras a partir de um conjunto de letras fornecidos pelo usuario
    case 3:
        cout << "Provide the set of letters: ";
        getline(cin, word);
        strUpper(word);
        searchWord(word, dic);
        break;
    //Gerar um conjunto de letras aleatorios e pedir ao usuario para formar uma palavra
    case 4:
        srand((unsigned int)time(0));
        n1 = rand () % dic.size();
        srand((unsigned int)time(0));
        n2 = rand () % dic.size() - 1;
        aux = guessWord(dic, n1);
        aux2 = guessWord(dic, n2);
        cout << "Build a word using: " << aux + aux2 << endl;
        getline(cin, word);
        strUpper(word);
        if(checkWord(word, dic))
            cout << "Word belongs!" << endl;
        else
            cout << "Word does not belong" << endl;
        break;
    //Ler e verificar Wildcards
    case 5:
        cout << "Insert Wildcard: ";
        getline(cin, word);
        a = playwords(word, dic);
        if(a==0)
            cout << "No matching words" << endl;
        break;
    default:
        break;
    }

    return 0;
}
//Funcoes
int playwords(string pattern, const vector<string> lista)
{
    string new_pattern = "^" + pattern + "$",
         line;
    regex reg;
    int flag = 0;
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

    for (size_t i = 0; i < lista.size(); i++)
    {
      line = lista.at(i);

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
    int flag = 0;
    vector<string> aux;

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
                if(flag == 0)
                {
                    j = lista.at(i).size();
                }
            }
            if(flag!=0)
            {
                aux.push_back(lista.at(i));
            }

        }
    }
    for (size_t i = 0; i < aux.size(); i++)
    {
        cout << aux.at(i) << endl;
    }
}

void strUpper(string &s)
{
    for(size_t i = 0; i < s.size(); i++)
    {
        if(islower(s.at(i)))
        {
            s.at(i) = toupper(s.at(i));
        }
    }
}
