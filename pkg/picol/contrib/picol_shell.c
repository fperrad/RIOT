/*
 * Copyright (C) 2025-2026 Francois Perrad
 *
 * This file is subject to the terms and conditions of the GNU Lesser
 * General Public License v2.1. See the file LICENSE in the top level
 * directory for more details.
 */

#include <stdio.h>
#include "modules.h"
#include "periph/pm.h"
#include "picol_shell.h"

static inline void print_prompt(void)
{
    putchar('.');
    putchar(' ');
    fflush(stdout);
}

void riot_picol_shell_run(struct picolInterp *i)
{
    for (;;) {
        char buffer[PICOL_DEFAULT_BUFSIZE];
        int retcode;
        print_prompt();
        if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
            break;
        }
        retcode = picolEval(i, buffer);
        if (i->result[0] != '\0') {
            printf("[%d] %s\n", retcode, i->result);
        }
    }

    if (IS_ACTIVE(CONFIG_SHELL_SHUTDOWN_ON_EXIT)) {
        pm_off();
    }
}
