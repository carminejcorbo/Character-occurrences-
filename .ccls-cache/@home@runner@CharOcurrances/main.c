#include <stdio.h>
#include <string.h>

int count_char_occurrences(char *str, char c) {
    int count = 0;
    char *ptr = strchr(str, c);
    while (ptr != NULL) {
        count++;
        ptr = strchr(ptr + 1, c);
    }
    return count;
}

int main() {
    char input[1000];
    char search_char;
    int total_occurrences = 0;

    // read lines of text until an empty line is entered
    printf("Enter some lines of text:\n");
    fgets(input, 1000, stdin);
    while (strcmp(input, "\n") != 0) {
        // remove newline character from input
        input[strcspn(input, "\n")] = '\0';

        // ask for search character
        printf("Enter a search character: ");
        scanf(" %c", &search_char);

        // count occurrences and print result
        int count = count_char_occurrences(input, search_char);
        printf("Total occurrences: %d\n", count);
        total_occurrences += count;

        // read next line of text
        fgets(input, 1000, stdin);
    }

    // print total occurrences across all lines of text
    printf("Total occurrences in all lines: %d\n", total_occurrences);

    return 0;
}
