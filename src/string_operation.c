//
// Created by Qui Tran on 10/4/23.
//

#include <string.h>
#include <stdio.h>
#include "string_operation.h"

char * string_concat(char *str1, char *str2){
    if (str1 == NULL || str2 == NULL){
        return NULL;
    }
    return strcat(str1, str2);
}

int string_compare(char *str1, char *str2){
    int result = strcmp(str1, str2);
    return result;
}

