//
// Created by JoachimWagner on 31.03.2025.
//

#pragma once


    class State {
    public :

        virtual ~State()=default;
        virtual void drucken() = 0;

        virtual void changeToA() = 0;
        virtual void changeToB() = 0;
    };

