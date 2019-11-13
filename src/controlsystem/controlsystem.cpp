#include "controlsystem.h"

ControlSystem::ControlSystem(){
    EvolutionControl ec{};
    ec.create_random_population(100);
    ec.train_the_guys(20000);
}

ControlSystem::~ControlSystem(){
}
