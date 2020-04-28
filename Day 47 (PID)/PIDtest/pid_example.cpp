#include "pid.h"
#include <stdio.h>
#include <unistd.h> //for sleep

int main() {

    PID pid = PID(0.1, 100, -100, 0.1, 0.001, 0.5);

    double out = 20;
    double i = 0.000000;
    while(true){
        i += 0.1;
        printf("Another one:\n");
        double speed = pid.calculate(5, out);
        printf("out:% 7.3f speed:% 7.3f time:% 7.3f", out, speed, i);
        out += speed;
        usleep(100000);
        printf("\n\n");
    }

    return 0;
}
