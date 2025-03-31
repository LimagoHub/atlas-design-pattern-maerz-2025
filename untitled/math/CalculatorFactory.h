//
// Created by JoachimWagner on 31.03.2025.
//

#pragma once
#include "CalculatorImpl.h"
#include "CalculatorLogger.h"
#include "CalculatorSecure.h"

using Calc_Pointer = std::unique_ptr<math::Calculator>;

namespace math {

    class CalculatorFactory {

    private:
        inline static bool logger{false};
        inline static bool secure{false};

    public:

        static bool isLogger() {
            return logger;
        }

        static void setLogger(bool logger) {
            CalculatorFactory::logger = logger;
        }

        static bool isSecure() {
            return secure;
        }

        static void setSecure(bool secure) {
            CalculatorFactory::secure = secure;
        }

        static Calc_Pointer create() {
            Calc_Pointer result;
            result = std::make_unique<CalculatorImpl>();
            if(logger) result =std::make_unique<CalculatorLogger>(std::move(result));
            if(secure) result =std::make_unique<CalculatorSecure>(std::move(result));
            return result;
        }

    };

} // math
