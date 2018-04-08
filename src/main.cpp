#include <stdio.h>
#include <stdint.h>

#include "config.h"

#include "types.h"
#include "cpu_model.h"
#include "instructions.h"
#include "cpu_operator.h"
#include "loggers.h"

void run() {

    bool flag = false;

    while (PERMANENTLY_EXECUTE or !flag) {
        execute_program();
        ic = 0;
        flag = true;
    }

}

int main() {

    init_control_unit();
    run();
    return 0;

}