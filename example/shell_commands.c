#include "shell.h"
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof(arr[0]))

static bool kv_store_write(const char *key, const void *val, size_t len) {
    (void)key;
    (void)val;
    (void)len;
    // Stub
    return true;
}

static int cli_cmd_kv_write(int argc, char *argv[]) {
    // We expect 3 arguments:
    // 1. Command name
    // 2. Key
    // 3. Value
    if (argc != 3) {
        shell_put_line("> FAIL,1");
        return 1;
    }

    const char *key = argv[1];
    const char *value = argv[2];

    bool result = kv_store_write(key, value, strlen(value));
    if (!result) {
        shell_put_line("> FAIL,2");
        return 1;
    }
    shell_put_line("> OK");
    return 0;
}

static int cli_cmd_hello(int argc, char *argv[]) {
    (void)argc;
    (void)argv;
    shell_put_line("Hello World!");
    return 0;
}

static const sShellCommand s_shell_commands[] = {
    {"kv_write", cli_cmd_kv_write, "Write a Key/Value pair"},
    {"hello", cli_cmd_hello, "Say hello"},
    {"help", shell_help_handler, "Lists all commands"},
};

const sShellCommand *const g_shell_commands = s_shell_commands;
const size_t g_num_shell_commands = ARRAY_SIZE(s_shell_commands);