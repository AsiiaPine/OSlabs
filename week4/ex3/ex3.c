#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>


int main() {

    /*короч, надо сначала выдать имя пользователя и путь, в котором он находится
     * Ждать  команду, записываемую во "что-то"
     *
     */
    char something[1024];
    while (1) {
        scanf(" %[^\n]",something);
        if ((strcmp(something, "q") == 0)||(strcmp(something, "exit") == 0))
            break;
        else {
            system(something);
        }
    }
    printf("See ya!\n");
    return 0;
}
