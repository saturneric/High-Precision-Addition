//
//  main.c
//  Long_number_count
//
//  Created by Eric on 15-8-14.
//  Copyright (c) 2015年 Bakantu Eric. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

char *add_count(char const *front, char const *last);

int main(int argc, const char * argv[]) {
    long number_long_max = 0;
    printf("NUMBER_LONG: ");
    scanf("%ld",&number_long_max);
    
    char *front = (char *)malloc(sizeof(char)*number_long_max), *p_front = front;
    char *last = (char *)malloc(sizeof(char)*number_long_max), *p_last= last;
    
    for (int i = 0; i < number_long_max; i++) {
        *p_front++ = 48;
        *p_last++ = 48;
    }

    printf("INPUT: ");
    scanf("%s",front);
    
    
    printf("INPUT: ");
    scanf("%s",last);
    
    char *final = add_count(front,last);
    if (final == NULL){
        return -1;
    }
    char *p_final = final;
    
    while (*p_final++ != '\0') printf("%c",*p_final);
    printf("\n");
    free(final);
    free(front);
    free(last);
    
    return 0;
}

char *add_count(char const *front, char const *last){
    char *p_front = front, *p_last = last;
    int string_long_front = 0 ,string_long_max;
    
    while (*p_front++ != '\0') string_long_max++;
    
    /*while (*p_front++ != '\0') string_long_front++;
    while (*p_last++ != '\0') string_long_last++;
    if (string_long_last >= string_long_front) string_long_final = string_long_last;
    else string_long_final = string_long_front;*/
    
    char *final = (char *)malloc(sizeof(char)*(string_long_max+3)), *p_final = final;
    for (int i = 0; i < string_long_max; i++) {
        *p_final++ = 48;
    }
    
    if (final == NULL) {
        printf("Error in get the memory!");
        return NULL;
    }
    
    int n_final, n1_final;
    p_final = final;
    p_front--; p_last--;
    p_front--; p_last--;
    *p_final = '\0';p_final--;
    while (*p_front != '\0' || *p_last != '\0'){
        *p_final += (((((int)*p_front) - 48) +(((int)*p_last) - 48)) % 10);
        n_final = (*p_final - 48) / 10;
        n1_final = ((int)(((((int)*p_front) - 48) +(((int)*p_last) - 48)) / 10));
        *(++p_final) += (n_final+n1_final);
        p_front--; p_last--;
    }
    
    return final;
    
}