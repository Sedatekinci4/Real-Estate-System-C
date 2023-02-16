#include <stdio.h>
#include <stdbool.h>

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
    printf("\n       START ---------- FOR WHO ------ ROOM COUNT \n\n");
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
            printf("\t%i\t%s\t%s\t\t%d\n",i, hash_table[i]->title, hash_table[i]->for_who, hash_table[i]->room_count);
        }
    }
    printf("-------END-------\n\n");
}

hash_table_insert(house *p){
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

// main function that we will use
int main(){
    int num = 0;
    hash_table_init();
    print_table();

    house first = {.title = "First", .for_who = "FAMILY", .face = "EAST", .room_count = 3, .bath_count = 2, .balcony_count = 2, .price = 60050,50};
    house second = {.title = "Second", .for_who = "SINGLE", .face = "WEST", .room_count = 1, .bath_count = 1, .balcony_count = 1, .price = 25050,50};
    house third = {.title = "Third", .for_who = "BOTH", .face = "SOUTH", .room_count = 2, .bath_count = 1, .balcony_count = 1, .price = 45050,00};
    house fourth = {.title = "Fourth", .for_who = "FAMILY", .face = "SOUTH", .room_count = 4, .bath_count = 2, .balcony_count = 1, .price = 55050,00};
    hash_table_insert(&first);
    hash_table_insert(&second);
    hash_table_insert(&third);
    hash_table_insert(&fourth);
    print_table();
    return 0;
}
