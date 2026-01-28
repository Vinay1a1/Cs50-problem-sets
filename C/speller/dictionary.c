// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#include "dictionary.h"
int word_count = 0;

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 26;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
        int index = hash(word);
        node *ptr = table[index];
        while (ptr != NULL)
        {
            if (strcasecmp(word, ptr->word) == 0)
            { return true;}
            ptr = ptr->next;
        }
        return false;

}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    return toupper(word[0]) - 'A';
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    // Use fopen to open a file
    // fscanf to read things into memory after malloc
    // use hash function to sort them
    FILE *source = fopen(dictionary, "r");
    if (source == NULL)
    return false;
    char word[LENGTH + 1];
    while (fscanf(source, "%s", word) != EOF)
    {
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {return false;}
        strcpy(n->word, word);
        int index = hash(word);
        n->next = table[index];
        table[index] = n;
        word_count++;
    }
    fclose(source);
    return true;


}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    return word_count;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    for (int i = 0; i < N; i++)
    {
    node *ptr = table[i];
    while (ptr != NULL)
    {
        node *next = ptr->next;
        free(ptr);
        ptr = next;
    }
    }
    return true;
}
