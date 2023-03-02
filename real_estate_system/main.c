#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define TABLE_LENGTH 25 // how many element does this table has
#define MAX_STR 128 // max string length
#define DELETED_NODE (house*)(0xFFFFFFFFFFFFFFFFUL) // macro for deleting the value

typedef struct{
    char title[MAX_STR]; // short introduction about house
    char for_who[8]; // is it better for single person, family or both
    char face[8]; // Which face the house is looking(north, south, east, west)
    int room_count; // room count of the house
    int bath_count; // bath count of the house
    int balcony_count; // balcony count of the house
    float price; // price of the house
}house;

house *hash_table[TABLE_LENGTH];

unsigned int hash(int *title)
{
    int length = strnlen(title, MAX_STR);
    unsigned int hash_value = 0;
    for(int i = 0; i < length ; i++)
    {
        hash_value += title[i];
        hash_value = hash_value* title[i];
    }
    return hash_value % TABLE_LENGTH;
}

// This function initialize the hash table as all NULL values
bool hash_table_init(){
    for(int i = 0; i < TABLE_LENGTH; i++){
        hash_table[i] = NULL;
    }
}

// Print function for out program, prints the house table
void print_table(){
    printf("\n       START ---------- FOR WHO ------ FACE ------ ROOM COUNT --------- PRICE -- \n\n");
    for(int i = 0; i < TABLE_LENGTH; i++)
    {
        if(hash_table[i] == NULL)
        {
            printf("\t%i\t-----\n", i);
        }
        else if(hash_table[i]== DELETED_NODE)
        {
            printf("\t%i\t-----deleted\n", i);
        }
        else
        {
            printf("\t%i\t%s\t%s\t%s\t%d\t%.2f\n",i, hash_table[i]->title, hash_table[i]->for_who, hash_table[i]->face, hash_table[i]->room_count, hash_table[i]->price);
        }
    }
    printf("-------END-------\n\n");
}

bool hash_table_insert(house *p){
    if(p == NULL) return false;
    int index = hash(p->title);
    for(int i = 0; i < TABLE_LENGTH; i++)
    {
        int try = (i + index) % TABLE_LENGTH;
        if(hash_table[try] == NULL ||
           hash_table[try] == DELETED_NODE)
        {
            hash_table[try] = p;
            return true;
        }
    }
    return false;
}

int main_menu(){
    int choice;
    printf("-------------- WELCOME TO THE REAL ESTATE SYSTEM --------------\n");
    printf("Please select the operation you want to make...\n\n");
    printf("1- Show available houses\n");
    printf("0- Exit\n");
    printf("Your choice:\t");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        print_table();
        break;
    case 0:
        printf("Have a good day...\n");
        return 1;
    default:
        printf("Please enter one choice from available options!!!!\n");
        break;
    }

}

// main function that we will use
int main(){
    int num = 0;
    int choice = 1;
    hash_table_init();
    house first = {.title = "First", .for_who = "FAMILY", .face = "EAST", .room_count = 3, .bath_count = 2, .balcony_count = 2, .price = 60050.50};
    house second = {.title = "Second", .for_who = "SINGLE", .face = "WEST", .room_count = 1, .bath_count = 1, .balcony_count = 1, .price = 25050.50};
    house third = {.title = "Third", .for_who = "BOTH", .face = "SOUTH", .room_count = 2, .bath_count = 1, .balcony_count = 1, .price = 45050.00};
    house fourth = {.title = "Fourth", .for_who = "FAMILY", .face = "SOUTH", .room_count = 4, .bath_count = 2, .balcony_count = 1, .price = 55050.00};
    hash_table_insert(&first);
    hash_table_insert(&second);
    hash_table_insert(&third);
    hash_table_insert(&fourth);
    print_table();
    /*while(choice != 0){
        choice = main_menu();
    }*/
    
    return 0;
}
