#ifndef MONTY_H
#define MONTY_H

#define  _POSIX_C_SOURCE 200809L
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
* struct stack_s - doubly linked list representation of a stack (or queue)
* @n: integer
* @prev: points to the previous element of the stack (or queue)
* @next: points to the next element of the stack (or queue)
*
* Description: doubly linked list node structure
* for stack, queues, LIFO, FIFO
*/
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

/**
* struct instruction_s - opcode and its function
* @opcode: the opcode
* @f: function to handle the opcode
*
* Description: opcode and its function
* for stack, queues, LIFO, FIFO
*/
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

size_t total_tokens(char *str, char delim);
char **tokenize(char *str, char *delim);
void free_memory(char **mem);
void interprate(stack_t **stack, char **tokens, size_t line_no);
int count_array(char **arr);
void (*get_operations(char *opcode))(stack_t **stack, unsigned int line_number);
void stack_push(stack_t **stack, unsigned int line_number);
void stack_pall(stack_t **stack, unsigned int line_number);
void stack_pint(stack_t **stack, unsigned int line_number);
void stack_pop(stack_t **stack, unsigned int line_number);
void stack_swap(stack_t **stack, unsigned int line_number);
void stack_add(stack_t **stack, unsigned int line_number);
void stack_sub(stack_t **stack, unsigned int line_number);
void stack_div(stack_t **stack, unsigned int line_number);
void stack_mul(stack_t **stack, unsigned int line_number);
void stack_mod(stack_t **stack, unsigned int line_number);
void stack_nop(stack_t **stack, unsigned int line_number);
void stack_pchar(stack_t **stack, unsigned int line_number);
void stack_pstr(stack_t **stack, unsigned int line_number);
void stack_rotl(stack_t **stack, unsigned int line_number);
char *remove_newline(char *str);
int _isdigit(char *str);
int isnumber(int n);
int count_stack(stack_t *stack);

extern char *stack_value;
#endif
