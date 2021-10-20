#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

struct student
{
    int gpa;
    char name[20];
    struct student *next;
};

void print_student(struct student *j)
{
    printf("The student's name is %s and their gpa is %d.\n", j->name, j->gpa);
}

struct student *create_student(int gpa, char *name)
{
    struct student *k = malloc(sizeof(struct student));
    strncpy(k->name, name, strlen(name));
    k->gpa = gpa;
    k->next = NULL;
    return k;
}

void print_list(struct student *node)
{
    while (node)
    {
        print_student(node);
        node = node->next;
    }
}

struct student *insert_front(struct student *curr, int new_gpa, char *new_name)
{
    struct student *new_student = malloc(sizeof(struct student));
    strncpy(new_student->name, new_name, strlen(new_name));
    new_student->gpa = new_gpa;
    new_student->next = curr;
    return new_student;
}

struct student *free_list(struct student *k)
{
    struct student *front = k;
    struct student *temp;
    while (k != NULL)
    {
        temp = k;
        k = k->next;
        free(temp);
    }
    return front;
}

int main()
{
    struct student *a = create_student(100, "david wang");
    struct student *b = insert_front(a, 99, "mandy smith");
    print_list(b);
    free_list(b);
    return 0;
}