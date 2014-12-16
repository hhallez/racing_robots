#include "robot_logic.h"
#include "racing_robots.h"

void _init() {
    // DO init here


    init(); // Their init
}

int main () {
    // Call init
    _init();

    while (1) {
        loop();
    }
}