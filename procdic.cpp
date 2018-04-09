#include <iostream>
#include <fstream>
#include <string>
#include <regex>
#include <vector>
#include <algorithm>
using namespace std;

//Funcoes
void counter(int v[], int n, char c);
void printer(int qtd, int letter);
int main()
{
								vector<string> word;
								string file4read, file4write = "Output.txt", line;
								ifstream infile;
								ofstream outfile;
								char *tok = NULL, *write = NULL;
								int contador[26] = {0};
								regex reg ("[A-Z ;'-]+");
								regex reg2 (".+[-'].*");

								cout << "EXTRACTION OF WORD LIST FROM DICTIONARY" << endl;
								cout << "=======================================" << endl;
								cout << "\nDictionary file ? ";
								getline (cin,file4read);
								// cin >> file4read;
//Abertura de arquivos
								infile.open(file4read);
								outfile.open(file4write);
//Verificação de abertura
								if (infile.fail())
								{
																cerr << "Error opening file: " << file4read << endl;
																exit(1);
								}
								if (infile.fail())
								{
																cerr << "Error opening file: " << file4write << endl;
																exit(1);
								}

//Separação de headlines
								while(!infile.eof())
								{
																//Conversao para char* com o objetivo de utilizar strtok
																getline(infile, line);
																write = new char[line.length() + 1];
																strcpy(write, line.c_str());
																//Separação de palavras simples
																if (regex_match(write, reg))
																{
																								tok = strtok(write, " ;");
																								while (tok != NULL)
																								{
																																//cout << tok << endl;
																																if (!regex_match(tok, reg2))
																																{
																																								counter(contador, 25, tok[0]);
																																								//words.push_back(tok);
																																								outfile << tok << endl;
																																}
																																tok = strtok(NULL, " ;");
																								}
																}
								}
//Fechando os arquivos
								infile.close();
								outfile.close();
//ordenando o vetor
								//sort(words.begin(), words.end());

//Impressao da interface
								for (int i = 0; i < 26; i++)
								{
																if (contador[i] != 0)
																{
																								printer(contador[i], i);
																}
								}
								return 0;
}

void counter(int v[], int n, char c)
{
								switch (c)
								{
								case 'A':
																v[0] += 1;
																break;
								case 'B':
																v[1] += 1;
																break;
								case 'C':
																v[2] += 1;
																break;
								case 'D':
																v[3] += 1;
																break;
								case 'E':
																v[4] += 1;
																break;
								case 'F':
																v[5] += 1;
																break;
								case 'G':
																v[6] += 1;
																break;
								case 'H':
																v[7] += 1;
																break;
								case 'I':
																v[8] += 1;
																break;
								case 'J':
																v[9] += 1;
																break;
								case 'K':
																v[10] += 1;
																break;
								case 'L':
																v[11] += 1;
																break;
								case 'M':
																v[12] += 1;
																break;
								case 'N':
																v[13] += 1;
																break;
								case 'O':
																v[14] += 1;
																break;
								case 'P':
																v[15] += 1;
																break;
								case 'Q':
																v[16] += 1;
																break;
								case 'R':
																v[17] += 1;
																break;
								case 'S':
																v[18] += 1;
																break;
								case 'T':
																v[19] += 1;
																break;
								case 'U':
																v[20] += 1;
																break;
								case 'V':
																v[21] += 1;
																break;
								case 'W':
																v[22] += 1;
																break;
								case 'X':
																v[23] += 1;
																break;
								case 'Y':
																v[24] += 1;
																break;
								case 'Z':
																v[25] += 1;
																break;
								}
}

void printer(int qtd, int letter)
{

								switch (letter)
								{
								case 0:
																cout << "A" << endl;
																for (int i = 0; i < qtd / 100; i++) {

																								cout << ".";

																}
																cout << endl;
																break;
								case 1:
																cout << "B" << endl;
																for (int i = 0; i < qtd / 100; i++) {

																								cout << ".";
																}
																cout << endl;
																break;
								case 2:
																cout << "C" << endl;
																for (int i = 0; i < qtd / 100; i++) {

																								cout << ".";
																}
																cout << endl;
																break;
								case 3:
																cout << "D" << endl;
																for (int i = 0; i < qtd / 100; i++) {

																								cout << ".";
																}
																cout << endl;
																break;
								case 4:
																cout << "E" << endl;
																for (int i = 0; i < qtd / 100; i++) {

																								cout << ".";
																}
																cout << endl;
																break;
								case 5:
																cout << "F" << endl;
																for (int i = 0; i < qtd / 100; i++) {

																								cout << ".";
																}
																cout << endl;
																break;
								case 6:
																cout << "G" << endl;
																for (int i = 0; i < qtd / 100; i++) {

																								cout << ".";
																}
																cout << endl;
																break;
								case 7:
																cout << "H" << endl;
																for (int i = 0; i < qtd / 100; i++) {

																								cout << ".";
																}
																cout << endl;
																break;
								case 8:
																cout << "I" << endl;
																for (int i = 0; i < qtd / 100; i++) {

																								cout << ".";
																}
																cout << endl;
																break;
								case 9:
																cout << "J" << endl;
																for (int i = 0; i < qtd / 100; i++) {

																								cout << ".";
																}
																cout << endl;
																break;
								case 10:
																cout << "K" << endl;
																for (int i = 0; i < qtd / 100; i++) {

																								cout << ".";
																}
																cout << endl;
																break;
								case 11:
																cout << "L" << endl;
																for (int i = 0; i < qtd / 100; i++) {

																								cout << ".";
																}
																cout << endl;
																break;
								case 12:
																cout << "M" << endl;
																for (int i = 0; i < qtd / 100; i++) {

																								cout << ".";
																}
																cout << endl;
																break;
								case 13:
																cout << "N" << endl;
																for (int i = 0; i < qtd / 100; i++) {

																								cout << ".";
																}
																cout << endl;
																break;
								case 14:
																cout << "O" << endl;
																for (int i = 0; i < qtd / 100; i++) {

																								cout << ".";
																}
																cout << endl;
																break;
								case 15:
																cout << "P" << endl;
																for (int i = 0; i < qtd / 100; i++) {

																								cout << ".";
																}
																cout << endl;
																break;
								case 16:
																cout << "Q" << endl;
																for (int i = 0; i < qtd / 100; i++) {

																								cout << ".";
																}
																cout << endl;
																break;
								case 17:
																cout << "R" << endl;
																for (int i = 0; i < qtd / 100; i++) {

																								cout << ".";
																}
																cout << endl;
																break;
								case 18:
																cout << "S" << endl;
																for (int i = 0; i < qtd / 100; i++) {

																								cout << ".";
																}
																cout << endl;
																break;
								case 19:
																cout << "T" << endl;
																for (int i = 0; i < qtd / 100; i++) {

																								cout << ".";
																}
																cout << endl;
																break;
								case 20:
																cout << "U" << endl;
																for (int i = 0; i < qtd / 100; i++) {

																								cout << ".";
																}
																cout << endl;

																break;
								case 21:
																cout << "V" << endl;
																for (int i = 0; i < qtd / 100; i++) {

																								cout << ".";
																}
																cout << endl;
																break;
								case 22:
																cout << "W" << endl;
																for (int i = 0; i < qtd / 100; i++) {

																								cout << ".";
																}
																cout << endl;

																break;
								case 23:
																cout << "X" << endl;
																for (int i = 0; i < qtd / 100; i++) {

																								cout << ".";
																}
																cout << endl;

																break;
								case 24:
																cout << "Y" << endl;
																for (int i = 0; i < qtd / 100; i++) {

																								cout << ".";
																}
																cout << endl;
																break;
								case 25:
																cout << "Z" << endl;
																for (int i = 0; i < qtd / 100; i++) {

																								cout << ".";

																}
																cout << endl;
																break;
								}
}
