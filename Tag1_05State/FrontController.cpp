//
// Created by JoachimWagner on 31.03.2025.
//

#include "FrontController.h"
#include "state/StateA.h"
#include "state/StateB.h"

FrontController::FrontController()
    :stateA{std::make_shared<StateA>(this)},
     stateB{std::make_shared<StateB>(this)},
     current(stateA){

}
