/* Classe criada com o intuito de facilitar a manupulação de dados do tipo CSV.
 * o caractere separador é o primeiro caractere do arquivo, e o arquivo deve terminar com a string "eof," sozinho (se o caracter separador for diferente de ",", no lugar da virgula do "eof," virá o caractere separador) na ultima linha do arquivo.
 *
 *
 * Exemplo:
 * ,1,2,3,4,
 * ,5,6,7,
 * ,5,4,34,
 * eof,
 *
 *
 * data 17/02/2017
 *
 * autor: Marco Aurélio Martins Mijam
 */

#ifndef CSV_H
#define CSV_H

#include <fstream>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <vector>

class Csv{
public:
    Csv(std::string name);
    std::vector<std::vector<std::string> > GetData();
    void SaveData(std::vector<std::vector<std::string> > all_data, char sc);
    void SaveData(std::vector<std::vector<double> > all_data, char sc);
    void ChangeFile(std::string new_name);
    std::string GetFileName();

private:
    std::string name;


};

#endif 
