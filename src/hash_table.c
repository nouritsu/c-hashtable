#include "./hash_table.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "./prime.h"

// Static Declarations
static HashTable* new_hash_table_sized(const int size);
static void ht_resize(HashTable* ht, const int new_size);
static void ht_resize_up(HashTable* ht);
static void ht_resize_down(HashTable* ht);
static HashItem* new_hash_item(const char*, const char*);
static void delete_hash_item(HashItem*);
static int get_hash(const char*, const int, const int);
static int hash(const char*, const int, const int);

// Deleted Item Bucket
static HashItem HT_DELETED_ITEM = {NULL, NULL};

HashTable* new_hash_table() { return new_hash_table_sized(HT_BASE_CAPACITY); }

static HashTable* new_hash_table_sized(const int init_size) {
    HashTable* ht = malloc(sizeof(HashTable));
    ht->base_capacity = init_size;
    ht->capacity = next_prime(ht->base_capacity);
    ht->size = 0;
    ht->items = calloc(ht->capacity, sizeof(HashItem));
    return ht;
}

static void ht_resize_up(HashTable* ht) {
    ht_resize(ht, ht->base_capacity * 2);
};
static void ht_resize_down(HashTable* ht) {
    ht_resize(ht, ht->base_capacity / 2);
};

static void ht_resize(HashTable* ht, const int new_size) {
    if (new_size < HT_BASE_CAPACITY) {
        return;
    }

    HashTable* new_ht = new_hash_table_sized(new_size);
    for (int i = 0; i < ht->size; i++) {
        HashItem* h = ht->items[i];
        if (h != NULL && h != &HT_DELETED_ITEM) {
            ht_insert(new_ht, h->key, h->value);
        }
    }

    // Swap stats of new and old table, then delete new table
    ht->base_capacity = new_ht->base_capacity;
    ht->size = new_ht->size;

    const int tmp_capacity = ht->capacity;
    ht->capacity = new_ht->capacity;
    new_ht->capacity = tmp_capacity;

    HashItem** tmp_items = ht->items;
    ht->items = new_ht->items;
    new_ht->items = tmp_items;

    delete_hash_table(new_ht);
}

void ht_insert(HashTable* ht, const char* k, const char* v) {
    const int load = ht->size * 100 / ht->capacity;
    if (load > HT_UPSIZE_LOAD) {
        ht_resize_up(ht);
    }

    HashItem* h = new_hash_item(k, v);

    int idx = get_hash(h->key, ht->capacity, 0);
    HashItem* curr = ht->items[idx];

    for (int i = 1; curr != NULL && curr != &HT_DELETED_ITEM; i++) {
        idx = get_hash(k, ht->capacity, i);
        curr = ht->items[idx];
    }

    ht->items[idx] = h;
    ht->size++;
}

char* ht_search(HashTable* ht, const char* k) {
    int idx = get_hash(k, ht->capacity, 0);
    HashItem* curr = ht->items[idx];

    for (int i = 1; curr != NULL; i++) {
        if (curr != &HT_DELETED_ITEM && strcmp(k, curr->key) == 0) {
            return curr->value;
        }
        idx = get_hash(k, ht->capacity, i);
        curr = ht->items[idx];
    }

    return NULL;
}

void ht_delete(HashTable* ht, const char* k) {
    const int load = ht->size * 100 / ht->capacity;
    if (load < HT_DOWNSIZE_LOAD) {
        ht_resize_down(ht);
    }

    int idx = get_hash(k, ht->capacity, 0);
    HashItem* curr = ht->items[idx];

    for (int i = 1; curr != NULL; i++) {
        if (curr != &HT_DELETED_ITEM && strcmp(k, curr->key) == 0) {
            delete_hash_item(curr);
            ht->items[idx] = &HT_DELETED_ITEM;
            ht->size--;
            return;
        }
        idx = get_hash(k, ht->capacity, i);
        curr = ht->items[idx];
    }
}

void ht_print(HashTable* ht, const int show_empty) {
    printf("{\n");
    for (int i = 0; i < ht->capacity; i++) {
        HashItem* h = ht->items[i];
        if ((h == NULL || h == &HT_DELETED_ITEM) && show_empty) {
            printf("\t(null) : (null),\n");
        } else if (h != NULL && h != &HT_DELETED_ITEM) {
            printf("\t%s : %s,\n", h->key, h->value);
        }
    }
    printf("}\n");
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

// Get rid of collisions
static int get_hash(const char* s, const int bucket_count, const int attempt) {
    const int h1 = hash(s, HT_PRIME1, bucket_count);
    const int h2 = hash(s, HT_PRIME2, bucket_count);
    return (h1 + (attempt * (h2 + 1))) % bucket_count;
}

static int hash(const char* s, const int a, const int m) {
    long hash = 0;
    const int len = strlen(s);
    for (int i = 0; i < len; i++) {
        hash += (unsigned long)pow(a, len - (i + 1)) * s[i];
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