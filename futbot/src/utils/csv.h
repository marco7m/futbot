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
    Csv();
    static std::vector<std::vector<std::string> > GetStringData(std::string name);
    static std::vector<std::vector<std::string> > get_string_data(std::string name, char sc);
    static std::vector<std::vector<double> > get_double_data(std::string name, char sc);
    static std::vector<std::vector<double> > GetDoubleData(std::string name);
    static void SaveData(std::vector<std::vector<std::string> > all_data, std::string name, char sc);
    static void save_data(std::vector<std::vector<std::string> > all_data, std::string name, char sc);
    static void save_data(std::vector<std::vector<double> > all_data, std::string name, char sc);
    static void SaveData(std::vector<std::vector<double> > all_data, std::string name, char sc);
    static void print_data(std::vector<std::vector<std::string> > data);
    static void print_data(std::vector<std::vector<double> > data);

};

#endif 
