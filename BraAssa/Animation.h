#pragma once
#include "Win.h"

class Animation
{
public:
   
    Win* winPtr = nullptr;
    Animation(Win* win) {
        winPtr = win;
    };

};


