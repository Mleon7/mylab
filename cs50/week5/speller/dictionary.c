// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>

// fopen, fclose, fscanf
#include <stdio.h>
// malloc, free
#include <stdlib.h>
// strcpy
#include <string.h>
// strcasecmp
#include <strings.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 26;
int dict_size = 0;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    int hash_value = hash(word);
    node *new = table[hash_value];

    while (new != NULL)
    {
        if(strcasecmp(word, new->word) == 0)
        {
            return true;
        }
        new = new->next;
    }

    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    // unsigned int hashValue = 0;

    // for (int i = 0; word[i] != '\0'; i++) {
    //     hashValue = (hashValue * 31 + word[i]) % N;
    // }

    // return hashValue;
    return toupper(word[0]) - 'A';
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    FILE *dict = fopen(dictionary, "r");
    if (dict == NULL)
    {
        printf("Error opening file: %s", dictionary);
        return false;
    }

    char word[LENGTH+1];
    while (fscanf(dict, "%s", word) != EOF)
    {
        node *new = malloc(sizeof(node));
        if(new == NULL)
        {
            return false;
        }
        strcpy(new->word, word);

        int hash_code = hash(word);
        new->next = table[hash_code];
        table[hash_code] = new;

        dict_size++;
    }

    fclose(dict);


    return true;
}

// Returns numtable[hash_code] = new dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return dict_size;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    for (int i = 0; i < N; i++)
    {
        node *cursor = table[i];
        while (cursor != NULL)
        {
            node *tmp = cursor;
            cursor = cursor->next;
            free(tmp);
        }

        if (i == N - 1 && cursor == NULL)
        {
            return true;
        }
    }
    return false;
}
