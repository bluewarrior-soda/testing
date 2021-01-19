#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student
{
    char ID[30];
    char name[50];
    struct Student *prev, *next;
} *head, *tail, *curr;

struct Student *create_student (const char *ID, const char *name)
{
    struct Student *new_student = (struct Student*)malloc(sizeof(struct Student));
    strcpy(new_student->ID, ID);
    strcpy(new_student->name, name);
    new_student->prev = new_student->next = NULL;
    return new_student;
}

void push_head (const char *ID, const char *name)
{
    struct Student *temp = create_student(ID, name);
    if (!head)
    {
        head = tail = temp;
    }
    else
    {
        temp->next = head;
        head->prev = temp;
        head = temp;   
    }
}

void push_tail (const char *ID, const char *name)
{
    struct Student *temp = create_student(ID, name);
    if (!tail)
    {
        head = tail = temp;
    }
    else
    {
        tail->next = temp;
        temp->prev = tail;
        tail = temp;   
    }
}

void push_mid (const char *ID, const char *name)
{
    struct Student *temp = create_student(ID, name);
    if (!head)
    {
        head = tail = temp;
    }
    else if (strcmp(ID, head->ID) < 0)
    {
        push_head(ID, name);
    }
    else if (strcmp(ID, tail->ID) > 0)
    {
        push_tail(ID, name);
    }
    else
    {
        curr = head;
        while (curr && strcmp(curr->ID, ID) < 0)
        {
            curr = curr->next;
        }

        temp->prev = curr->prev;
        temp->next = curr;

        curr->prev->next = temp->next;
        curr->prev = temp;
    }   
}

void print_list ()
{
    curr = head;
    while (curr)
    {
        printf("%s %s\n", curr->ID, curr->name);
        curr = curr->next;
    }
}

const char* search_list (const char *ID)
{
    curr = head;
    while (curr)
    {
        if (strcmp(curr->ID, ID) == 0)
        {
            return curr->name;
        }
        curr = curr->next;
    }

    return "N/A";
}

int main()
{
    FILE *in = fopen("testdata.in", "r");
    int n;
    fscanf(in, "%d\n", &n);

    struct Student *student = (struct Student*)malloc(sizeof(struct Student) * n);
    for (int i = 0; i < n; i++)
    {
        fscanf(in, "%s %s\n", student[i].ID, student[i].name);
        push_mid(student[i].ID, student[i].name);
    }

    // print_list();

    int t;
    fscanf(in, "%d\n", &t);

    for (int c = 1; c <= t; c++)
    {
        char target[30];
        fscanf(in, "%s\n", target);
        char output[1000];
        strcpy(output, search_list(target));
        printf("Case #%d: %s\n", c, output);
    }

    fclose(in);

    return 0;
}