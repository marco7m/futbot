#include "csv.h"

#include <cstdlib>
#include <sstream>
#include <stdlib.h>

Csv::Csv(){
}

// OLD
std::vector<std::vector<std::string> > Csv::GetStringData(std::string name){
    std::ifstream file;
    std::vector<std::vector<std::string> > all_data;
    file.open(name.c_str());
    if(file.is_open()){
        // inicializa variáveis
        std::string data = " ";
        int w_dentro = 0;
        int w_fora = 0;
        // identifica o caractere separador
        char sc = file.get();

        while(data != "\neof"){
            w_fora ++;
            if(w_fora > 100000){
                std::cout << "Error: or CSV file is bad formatted or it has more than 100000 lines" << std::endl;
                exit(1);
            } 

            //cria um vetor de string para add ele no vetor de vetor de string
            std::vector<std::string> line_data;

            w_dentro = 0;
            while(data != "\n" && data != "\neof"){
                // coleta dado
                if(std::getline(file,data, sc)){
                    w_dentro ++;
                    if(w_dentro > 100000){
                        std::cout << "Error: or CSV file is bad formatted or it has a line larger than 100000 characteres" << std::endl;
                        exit(1);
                    } 
                    if(data != "\n" && data != "\neof"){
                        line_data.push_back(data);
                    }
                }
            }
            if(data != "\neof") data = " ";

            all_data.push_back(line_data);
        }
    file.close();
    } 
    else{
        std::cout << "ERROR: couldn't open file." << std::endl;
    }
    return all_data;
}

std::vector<std::vector<std::string> > Csv::get_string_data(std::string name, char sc){
    std::ifstream file;
    std::vector<std::vector<std::string> > all_data;
    file.open(name.c_str());
    if(file.is_open()){
        // inicializa variáveis
        std::string file_line_data;
        std::string file_line_data_word;
        std::vector<std::string> line_data;

        // enquanto não chegou no fim do arquivo
        while(std::getline(file,file_line_data)){
            for(int i = 0; i < (int)file_line_data.size() - 1; i++){
                if(file_line_data[i] != sc){
                    file_line_data_word.push_back(file_line_data[i]);
                }
                else{
                    line_data.push_back(file_line_data_word);
                    file_line_data_word.clear();
                }
            }
            line_data.push_back(file_line_data_word);
            file_line_data_word.clear();

            all_data.push_back(line_data);
            line_data.clear();
        }
    file.close();
    } 
    else{
        std::cout << "ERROR: couldn't open file." << std::endl;
    }
    return all_data;
}

std::vector<std::vector<double> > Csv::get_double_data(std::string name, char sc){
    std::ifstream file;
    std::vector<std::vector<double> > all_data;
    file.open(name.c_str());
    if(file.is_open()){
        // inicializa variáveis
        std::string file_line_data;
        std::string file_line_data_word;
        std::vector<double> line_data;
        double double_data_temp;

        // enquanto não chegou no fim do arquivo
        while(std::getline(file,file_line_data)){
            for(int i = 0; i < (int)file_line_data.size() - 1; i++){
                if(file_line_data[i] != sc){
                    file_line_data_word.push_back(file_line_data[i]);
                }
                else{
                    if((int)file_line_data_word.size() > 0){
                        std::stringstream ss(file_line_data_word);
                        ss >> double_data_temp;
                        line_data.push_back(double_data_temp);
                        file_line_data_word.clear();
                    }
                }
            }
            if((int)file_line_data_word.size() > 0){
                std::stringstream ss(file_line_data_word);
                ss >> double_data_temp;
                line_data.push_back(double_data_temp);
                file_line_data_word.clear();
            }

            all_data.push_back(line_data);
            line_data.clear();
        }
    file.close();
    } 
    else{
        std::cout << "ERROR: couldn't open file." << std::endl;
    }
    return all_data;
}


std::vector<std::vector<double> > Csv::GetDoubleData(std::string name){
    std::ifstream file;
    std::vector<std::vector<double> > all_data;
    file.open(name.c_str());
    if(file.is_open()){
        // inicializa variáveis
        std::string data = " ";
        int w_dentro = 0;
        int w_fora = 0;
        // identifica o caractere separador
        char sc = file.get();

        while(data != "\neof"){
            w_fora ++;
            if(w_fora > 100000){
                std::cout << "Error: or CSV file is bad formatted or it has more than 100000 lines" << std::endl;
                exit(1);
            } 

            //cria um vetor de string para add ele no vetor de vetor de string
            std::vector<double> line_data;

            w_dentro = 0;
            while(data != "\n" && data != "\neof"){
                // coleta dado
                if(std::getline(file,data, sc)){
                    w_dentro ++;
                    if(w_dentro > 100000){
                        std::cout << "Error: or CSV file is bad formatted or it has a line larger than 100000 characteres" << std::endl;
                        exit(1);
                    } 
                    if(data != "\n" && data != "\neof"){
                        std::stringstream ss(data);
                        double double_data;
                        ss >> double_data;
                        line_data.push_back(double_data);
                    }
                }
            }
            if(data != "\neof") data = " ";

            all_data.push_back(line_data);
        }
    file.close();
    } 
    else{
        std::cout << "ERROR: couldn't open file." << std::endl;
    }
    return all_data;
}

void Csv::SaveData(std::vector<std::vector<std::string> > all_data,std::string name, char sc){
    std::ofstream file;
    file.open(name.c_str());
    if(file.is_open()){
        file << sc;
        for(int i = 0; i < (int)all_data.size(); i++){
            for(int j = 0; j < (int)all_data[i].size(); j++){
                file << all_data[i][j] << sc;
            }
            if(i+1 < (int)all_data.size()) file << "\n" << sc;
        }
        file << "\n" << "eof" << sc;
    file.close();
    }
    else{
        std::cout << "ERROR: couldn't open file." << std::endl;
    }
}

void Csv::save_data(std::vector<std::vector<std::string> > all_data,std::string name, char sc){
    std::ofstream file;
    file.open(name.c_str());
    if(file.is_open()){
        for(int i = 0; i < (int)all_data.size(); i++){
            for(int j = 0; j < (int)all_data[i].size(); j++){
                file << all_data[i][j];
                if(j < all_data[i].size() - 1) file << sc;
            }
            if(i+1 < (int)all_data.size()) file << "\n";
        }
    file.close();
    }
    else{
        std::cout << "ERROR: couldn't open file." << std::endl;
    }
}

void Csv::save_data(std::vector<std::vector<double> > all_data,std::string name, char sc){
    std::ofstream file;
    file.open(name.c_str());
    if(file.is_open()){
        for(int i = 0; i < (int)all_data.size(); i++){
            for(int j = 0; j < (int)all_data[i].size(); j++){
                file << all_data[i][j];
                if(j < all_data[i].size() - 1) file << sc;
            }
            if(i+1 < (int)all_data.size()) file << "\n";
        }
    file.close();
    }
    else{
        std::cout << "ERROR: couldn't open file." << std::endl;
    }
}

void Csv::SaveData(std::vector<std::vector<double> > all_data,std::string name, char sc){
    std::ofstream file;
    file.open(name.c_str());
    if(file.is_open()){
        file << sc;
        for(int i = 0; i < (int)all_data.size(); i++){
            for(int j = 0; j < (int)all_data[i].size(); j++){
                file << all_data[i][j] << sc;
            }
            if(i+1 < (int)all_data.size()) file << "\n" << sc;
        }
        file << "\n" << "eof" << sc;
    file.close();
    }
    else{
        std::cout << "ERROR: couldn't open file." << std::endl;
    }
}


void Csv::print_data(std::vector<std::vector<std::string> > data){
    for(int i = 0; i < (int)data.size(); i++){
        for(int j = 0; j < (int)data[i].size(); j++){
            std::cout << data[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void Csv::print_data(std::vector<std::vector<double> > data){
    for(int i = 0; i < (int)data.size(); i++){
        for(int j = 0; j < (int)data[i].size(); j++){
            std::cout << data[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

std::vector<std::vector<double> > Csv::transpose(std::vector<std::vector<double> > data){
    // check if data is square and can be transposed
    for(int i = 0, s = (int)data[0].size(); i < (int)data.size(); i++){
        if(data[i].size() != s){
            std::cout << "DATA CAN NOT BE TRANSPOSED BY THIS FUNCTION!!!" << std::endl;
            exit(EXIT_FAILURE);
        }
    }
    std::vector<std::vector<double> > outtrans(data[0].size(), std::vector<double>(data.size()));
    for(size_t i = 0; i < data.size(); ++i)
        for(size_t j = 0; j < data[0].size(); ++j)
            outtrans[j][i] = data[i][j]; 
    return outtrans;
}
