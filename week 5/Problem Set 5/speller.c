// Implements a dictionary's functionality
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

const unsigned int N = 801;
int count = 0;

// Hash table
node *table[N] = {NULL};

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    int hash_index = hash(word);
    node *cursor = table[hash_index];

    while (cursor != NULL)
    {
        if (strcasecmp(cursor->word, word) == 0)
        {
            return true;
        }
        cursor = cursor->next;
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    int word1 = toupper(word[0]);
    int word2 = toupper(word[1]);
    return (word1 * word2) / 10;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    char words[255];
    FILE *file = fopen(dictionary, "r");
    while (fscanf(file, "%s", words) != EOF)
    {
        // Create a new node for the word.
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            fclose(file);
            return false;
        }
        strcpy(n->word, words);
        int hash_num = hash(words);

        // If the linked list in that index is null, we add it in. If there is another node already there,
        // we copy the pointer and point to the new node's next and insert the new node.
        if (table[hash_num] == NULL)
        {
            table[hash_num] = n;
            n->next = NULL;
        }
        else
        {
            n->next = table[hash_num];
            table[hash_num] = n;
        }
        count++;
    }
    fclose(file);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    return count;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    for (int i = 0; i < N; i++)
    {
        node *cursor = table[i];
        while (cursor != NULL)
        {
            node *temp = cursor;
            cursor = cursor->next;
            free(temp);
        }
    }
    return true;
}
