#ifndef NEURON_H
#define NEURON_H

#include "../utils/my_ptr.h"
#include <vector>

class Neuron{
public:
    Neuron();
    void set_randon_weight();
    void set_zero_weight();
    void connect_input(double_ptr in);
    void connect_output(double *out);
    double get_weight(int n);
    void set_weight(int n, double w);
    double get_bias();
    void set_bias(double b);
    int get_number_inputs();
    void work();
    double get_output_value();

private:
    double_ptr input;
    double *output;
    std::vector<double> weight;
    double bias;
};

#endif
