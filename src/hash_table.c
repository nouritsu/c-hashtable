#include "./hash_table.h"

#include <math.h>
#include <stdlib.h>
#include <string.h>

// Static Declarations
static HashItem* new_hash_item(const char*, const char*);
static void delete_hash_item(HashItem*);
static int get_hash(const char*, const int, const int);
static int hash(const char*, const int, const int);

HashTable* new_hash_table() {
    HashTable* ht = malloc(sizeof(HashTable));
    ht->capacity = BASE_TABLE_SIZE;
    ht->size = 0;
    ht->items = calloc(ht->capacity, sizeof(HashItem));
    return ht;
}

void delete_hash_table(HashTable* ht) {
    for (int i = 0; i < ht->capacity; i++) {
        HashItem* h = ht->items[i];
        if (h != NULL) {
            delete_hash_item(h);
        }
    }
    free(ht->items);
    free(ht);
}

// Used to deal with collisions
static int get_hash(const char* s, const int bucket_count, const int attempt) {
    const int h1 = hash(s, HT_PRIME1, bucket_count);
    const int h2 = hash(s, HT_PRIME2, bucket_count);
    return (h1 + (attempt * (h2 + 1))) % bucket_count;
}

static int hash(const char* s, const int a, const int m) {
    long hash = 0;
    const int len = strlen(s);
    for (int i = 0; i < len; i++) {
        hash += (long)pow(a, len - (i + 1)) * s[i];
        hash = hash % m;  // make hash a number between 0...(m-1)
    }
    return (int)hash;
}

static HashItem* new_hash_item(const char* k, const char* v) {
    HashItem* h = malloc(sizeof(HashItem));
    h->key = strdup(k);
    h->value = strdup(v);
    return h;
}

static void delete_hash_item(HashItem* h) {
    free(h->key);
    free(h->value);
    free(h);
}