#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char* content;
    size_t length;
    size_t size;
} string;

string* strinit(char* context) {
    string* tmp = (string*) malloc(sizeof(string));
    if (!tmp) {
        fprintf(stderr, "ERROR 001: Failed to allocate memory for string");
        exit(EXIT_FAILURE);
    }

    tmp->size = strlen(context) + 1;
    tmp->length = strlen(context);

    tmp->content = (char*) malloc(sizeof(char) * tmp->size);
    if (!tmp->content) {
        fprintf(stderr, "ERROR 002: Failed to allocate memory for content");
        exit(EXIT_FAILURE);
    }

    strcpy(tmp->content, context);
    return tmp;
}

string* strassign(string* String, char* context) {
    size_t length = strlen(context);
    size_t size = length + 1;

    if (size > String->size) {
        char* tmp = (char*) realloc(String->content, sizeof(char) * size);
        if (!tmp) {
            fprintf(stderr, "ERROR 003: Failed to reallocate memory for content");
            exit(EXIT_FAILURE);
        }

        strcpy(tmp, context);
        String->content = tmp;
    }
    else {
        strcpy(String->content, context);
    }

    String->size = size;
    String->length = length;
    return String;
}

void strprint(string* String, bool newline) {
    if (newline) {
        printf("%s\n", String->content);
    }
    else {
        printf("%s", String->content);
    }
}

void strfree(string* String) {
    free(String->content);
    free(String);
}