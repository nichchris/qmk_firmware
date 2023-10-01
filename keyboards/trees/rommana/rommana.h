#include "quantum.h"

// readability
#define ___ KC_NO

#define LAYOUT_23332( \
         L00, L01, L02, L03, L04,    R00, R01, R02, R03, R04, \
         L10, L11, L12, L13, L14,    R10, R11, R12, R13, R14, \
              L21, L22, L23,              R21, R22, R23,      \
                        L24, L20,    R20, R24                 \
    ) \
    { \
        { L04,   L03,   L02,   L01,   L00 }, \
        { L14,   L13,   L12,   L11,   L10 }, \
        { L20,   L23,   L22,   L21,   L24 }, \
        { R00,   R01,   R02,   R03,   R04 }, \
        { R10,   R11,   R12,   R13,   R14 }, \
        { R20,   R21,   R22,   R23,   R24 }, \
    }
