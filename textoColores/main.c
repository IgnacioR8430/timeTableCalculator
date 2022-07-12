#include <stdio.h>
#include <windows.h>

int main(void)
{
    /* Point to our console */
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    int i = 0;

    /* Iterate through colors */
    for(; i < 255; i++)
    { /* i stands for color type: could refer to actual text color or background color of text */
        SetConsoleTextAttribute(hConsole, i);
        printf("Colorful text i = %d\n",i);
    }

    getchar();
    return 0;
}
