#include "getbperror.h"

GetBPError::GetBPError(){

    data_input = Csv::GetDoubleData("data/data_input.csv");
    data_output = Csv::GetDoubleData("data/data_output.csv");

    // itera entre os dados da tabela, mantendo tudo em sincronia
    for(int i = 0; i < data_input[0].size(); i++){
        for(int j = 0; j < 26; j++){
            input.ptr[j] = data_input[j][i]/1000;
        }
        neural_network.DoTheJobOnce();
        error_0.push_back(output.ptr[0]*10 - data_output[0][i]);
        error_1.push_back(output.ptr[1]*10 - data_output[1][i]);

        std::cout << "output = " << output.ptr[0] * 1000 << std::endl;
        std::cout << "data_output = " << data_output[0][i] << std::endl;
        std::cout << "" << std::endl;
    }
    std::cout << "acabou" << std::endl;

//    for(int i = 0; i < error_0.size(); i++){
//        std::cout << "error_0 = " << error_0[i] << std::endl;
//    }

}

