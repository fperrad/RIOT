/*
 * Copyright (C) 2025-2026 Francois Perrad
 *
 * This file is subject to the terms and conditions of the GNU Lesser
 * General Public License v2.1. See the file LICENSE in the top level
 * directory for more details.
 */

#include <stdlib.h>
#include "shell.h"
extern shell_command_handler_t find_handler(const shell_command_t *command_list, char *command);
extern void print_commands_json(const shell_command_t *cmd_list);
extern void print_help(const shell_command_t *command_list);

#include "picol_shell.h"

picolResult riot_picol_command_exec(struct picolInterp *i, int argc, const char *argv[], void *pd)
{
    int res = EXIT_SUCCESS;

    (void)i;

    shell_command_handler_t handler = find_handler(pd, (char *)argv[1]);
    if (handler != NULL) {
        if (IS_USED(MODULE_SHELL_HOOKS)) {
            shell_pre_command_hook(argc - 1, (char **)&argv[1]);
            res = handler(argc - 1, (char **)&argv[1]);
            shell_post_command_hook(res, argc - 1, (char **)&argv[1]);
        }
        else {
            res = handler(argc - 1, (char **)&argv[1]);
        }
    }
    else {
        if (strcmp("help", argv[1]) == 0) {
            print_help(pd);
        }
        else if (IS_USED(MODULE_SHELL_BUILTIN_CMD_HELP_JSON)
                 && !strcmp("help_json", argv[1])) {
            print_commands_json(pd);
        }
        else {
            printf("shell: command not found: %s\n", argv[1]);
            res = EXIT_FAILURE;
        }
    }

    return (res == EXIT_SUCCESS) ? PICOL_OK : PICOL_ERR;
}
