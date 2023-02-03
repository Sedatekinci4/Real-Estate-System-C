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

// This function initialize the hash table as all NULL values
bool hash_table_init(){
    for(int i = 0; i < TABLE_LENGTH; i++){
        hash_table[i] = NULL;
    }
}

// Print function for out program, prints the house table
void print_table(){
    printf("\n-------START-------\n");
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
            printf("\t%i\t%s\n",i, hash_table[i]->title);
        }
    }
    printf("-------END-------\n\n");
}

// main function that we will use
int main(){
    hash_table_init();
    print_table();

    return 0;
}
