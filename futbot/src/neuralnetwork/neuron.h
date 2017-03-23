#ifndef NEURON_H
#define NEURON_H

#include "../utils/my_ptr.h"
#include <vector>

class Neuron{
public:
    Neuron();
    Neuron(std::vector<double> w);
    void set_randon_weight();
    void set_uni_weight();
    void set_zero_weight();
    void connect_input(double_ptr in);
    void connect_output(double *out);
    double get_weight(int n);
    void set_weight(int n, double w);
    int get_number_inputs();
    void work();
    double get_output_value();

private:
    double_ptr input;
    double *output;
    std::vector<double> weight;
};

#endif
