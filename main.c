#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"

#define CASE_NUMBER 3
#define MAX_BUFFER 100

Node *head, *tail;

int main() {
    FILE *stream;
    char command[10], output[MAX_BUFFER] = {0, }, answer[MAX_BUFFER] = {0, };
    int param[2];
    int buffer_index, length;
    char file_name[25], file_number[CASE_NUMBER][2] = {"1", "2", "3"};
    for (int i = 0; i < CASE_NUMBER; i++) {
        strcpy(file_name, "testcase/input_");
        strcat(file_name, file_number[i]);
        strcat(file_name, ".txt");
        stream = fopen(file_name, "r");
        buffer_index = 0;
        head = tail = NULL;
        while (fscanf(stream, "%s", command) != EOF) {
            if (!strcmp(command, "insert")) {
                fscanf(stream, "%d %d\n", &param[0], &param[1]);
                insert(param[0], param[1]);
            } else if (!strcmp(command, "delete")) {
                fscanf(stream, "%d\n", &param[0]);
                delete(param[0]);
            } else if (!strcmp(command, "append")) {
                fscanf(stream, "%d\n", &param[0]);
                append(param[0]);
            } else if (!strcmp(command, "get")) {
                fscanf(stream, "%d\n", &param[0]);
                get(param[0]);
            } else if (!strcmp(command, "clear")) {
                clear();
            } else if (!strcmp(command, "print")) {
                print(output, &buffer_index);
            }
        }
        fclose(stream);
        strcpy(file_name, "testcase/output_");
        strcat(file_name, file_number[i]);
        strcat(file_name, ".txt");
        stream = fopen(file_name, "r");
        length = fread(answer, 1, MAX_BUFFER, stream);
        fclose(stream);
        if (!strncmp(output, answer, length)) {
            printf("Testcase %d [correct]\n\n", i + 1);
        } else {
            printf("Testcase %d [incorrect]\n", i + 1);
            printf("[Answer]\n%.*s\n", length, answer);
            printf("[Your output]\n%.*s\n\n", buffer_index, output);
        }
    }
}
