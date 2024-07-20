#ifndef boardclass_h
#define boardclass_h

#include <iostream>

class board  {
    public:
    // Each slot is empty originally
    int rocks [14]{};

    // Set-up the starting amount of rocks in each pile
    board() {
        for(int i{1}; i<7; i++){
            rocks[i] = 4;
        }
        for(int i{8}; i<14; i++){
            rocks[i] = 4;
        }
    }
    int getRockValue(int pile) {
        return rocks[pile];
    }
    void setRockValue(int pile, int value) {
        rocks[pile] = value;
    }
};

///////////////////////////////////////////////////
//   |    | 06 | 05 | 04 | 03 | 02 | 01 |    |   //
//   | 07 |-----------------------------| 00 |   //
//   |    | 08 | 09 | 10 | 11 | 12 | 13 |    |   //
///////////////////////////////////////////////////

#endif

