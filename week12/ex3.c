#include <stdio.h>
#include <linux/input.h>
#include <stdlib.h>

#define bool int
#define true 1
#define false 0

FILE *out;

struct shortcut_unit
{
    uint code;
    bool is_pressed;
};

struct shortcut
{
    int len;
    struct shortcut_unit *units;
};

void init_shortcut(struct shortcut *s, int size, int *codes)
{
    s->len = size;
    s->units = malloc(sizeof(struct shortcut_unit) * size);
    for (int i = 0; i < size; i++)
    {
        s->units[i].code = codes[i];
        s->units[i].is_pressed = false;
    }
}

void update_shortcut(struct shortcut *s, struct input_event event)
{
    for (int i = 0; i < s->len; i++)
    {
        if (s->units[i].code == event.code)
        {
            if (event.value == 0)
            {
                // RELEASED
                s->units[i].is_pressed = false;
            }
            else if (event.value == 1)
            {
                // PRESSED
                s->units[i].is_pressed = true;
            }
        }
    }
}

bool is_active(struct shortcut *s)
{
    for (int i = 0; i < s->len; i++)
    {
        if (!s->units[i].is_pressed)
            return false;
    }
    return true;
}

void CAP_handling()
{
    fprintf(out, "Bring the cappucinio!\n");
    printf("Bring the cappucinio!\n");
    fflush(out);
}
void CJ_handling()
{
    fprintf(out, "Pram pam pam u drink Coca-Cola and write on Java! Press C+A+P!\n");
    printf("Pram pam pam u drink Coca-Cola and write on Java! Press C+A+P!\n");
    fflush(out);
}
void PE_handling(){
    fprintf(out, "I passed the Exam!\n");
    printf("I passed the Exam!\n");
    fflush(out);
}
void IL_handling()
{
    fprintf(out, "U are late, press C+A+P!\n");
    printf("U are late, press C+A+P!\n");
    fflush(out);
}

int main(int argc, char **argv)
{
    FILE *fp = fopen("/dev/input/by-path/platform-i8042-serio-0-event-kbd", "rb");

    out = fopen("ex3.txt", "wb");
    if (out == NULL)
    {
        fprintf(stderr, "\nError opening file\n");
        exit(1);
    }

    struct shortcut cap;
    struct shortcut cj;
    struct shortcut il;
    struct shortcut pe;

    int cap_codes[] = {46, 30, 25};
    init_shortcut(&cap, 3, cap_codes);
    int cj_codes[] = {46, 36};
    init_shortcut(&cj, 2, cj_codes);
    int il_codes[] = {23, 38};
    init_shortcut(&il, 2, il_codes);
    int pe_codes[] = {25, 18};
    init_shortcut(&pe, 2, pe_codes);

    while (1)
    {
        struct input_event event;
        fread(&event, sizeof(struct input_event), 1, fp);

        update_shortcut(&cap, event);
        update_shortcut(&cj, event);
        update_shortcut(&il, event);
        update_shortcut(&pe, event);

        if (is_active(&pe)){
            PE_handling();
        }
        if (is_active(&cap))
        {
            CAP_handling();
        }
        if (is_active(&cj))
        {
            CJ_handling();
        }
        if (is_active(&il))
        {
            IL_handling();
        }
    }
    fclose(fp);
    fclose(out);
    return 0;
}
