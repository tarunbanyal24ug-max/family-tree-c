#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Person {
    char name[50];
    int age;
    struct Person *father;
    struct Person *mother;
} Person;

Person* create_person(const char *name, int age) {
    Person *p = malloc(sizeof(Person));
    strcpy(p->name, name);
    p->age = age;
    p->father = NULL;
    p->mother = NULL;
    return p;
}

void read_person_info(const char *role, char *name_out, int *age_out) {
    printf("Enter name and age for %s\n", role);
    printf("  Name: ");
    fgets(name_out, 50, stdin);
    name_out[strcspn(name_out, "\n")] = '\0';
    printf("  Age: ");
    scanf("%d", age_out);
    getchar();
}

int main() {
    char *roles[7] = {
        "Paternal Grandfather", "Paternal Grandmother",
        "Maternal Grandfather", "Maternal Grandmother",
        "Father", "Mother", "Yourself"
    };

    Person *people[7];
    char name[50];
    int age;

    for (int i = 0; i < 7; i++) {
        read_person_info(roles[i], name, &age);
        people[i] = create_person(name, age);
    }

    return 0;
}