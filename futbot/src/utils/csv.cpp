#include "csv.h"

#include <cstdlib>

Csv::Csv(){
}

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
                        line_data.push_back(std::stod(data.c_str()));
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

void Csv::SaveData(std::vector<std::vector<double> > all_data,std::string name, char sc){
    std::ofstream file;
    file.open(name.c_str());
    if(file.is_open()){
        file << sc;
        for(int i = 0; i < (int)all_data.size(); i++){
            for(int j = 0; j < (int)all_data[i].size(); j++){
                file << all_data[i][j] << sc;
            }
            if(i+1 < all_data.size()) file << "\n" << sc;
        }
        file << "\n" << "eof" << sc;
    file.close();
    }
    else{
        std::cout << "ERROR: couldn't open file." << std::endl;
    }
}
