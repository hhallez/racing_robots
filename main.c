#include "robot_logic.h"
#include "racing_robots.h"
#include "dwengoConfig.h"


void _init() {
    // DO init here
    initBoard();
    initLCD();
    initSensorModule(); // initialiseren Sensor-module
    initMotor(); // inialiseren Motor-module
    
    
    init(); // Their init
}

int main () {
    // Call init
    _init();

    while (TRUE) {
        loop();
    }
}