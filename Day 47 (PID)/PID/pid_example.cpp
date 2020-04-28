#include "pid.h"
#include <stdio.h>
#include <unistd.h> //for sleep

int main() {

    PID pid = PID(0.1, 100, -100, 0.1, 0.01, 0.5);

    double out = 20;
    double i = 0.000000;
    while(true){
        i += 0.1;
        double inc = pid.calculate(5, out);
        printf("out:% 7.3f inc:% 7.3f time:% 7.3f\n", out, inc, i);
        out += inc;
        usleep(100000);
    }

    return 0;
}
