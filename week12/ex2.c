#include <stdio.h>
#include <linux/input.h>

int main(int argc, char **argv)
{
    FILE *fp = fopen("/dev/input/by-path/platform-i8042-serio-0-event-kbd", "rb");
    FILE *out = fopen("ex2.txt", "wb");
    if (out == NULL)
    {
        fprintf(stderr, "\nError opening file\n");
        exit(1);
    }
    while (1)
    {
        struct input_event event;
        fread(&event, sizeof(struct input_event), 1, fp);
        if (event.value == 1)
        {
            fprintf(out, "PRESSED 0x%.4x (%d)\n", event.code, event.code);
            fflush(out);

        }
        else if (event.value == 0)
        {
            fprintf(out, "RELEASED 0x%.4x (%d)\n", event.code, event.code);
            fflush(out);

        }
    }
    fclose(fp);
    fclose(out);
    return 0;
}