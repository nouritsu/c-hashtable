#define BASE_TABLE_SIZE 8
#define HT_PRIME1 151
#define HT_PRIME2 131

typedef struct {
    char *key, *value;
} HashItem;

typedef struct {
    int capacity, size;
    HashItem** items;
} HashTable;

HashTable* new_hash_table();
void ht_insert(HashTable*, const char*, const char*);
char* ht_search(HashTable*, const char*);
void ht_delete(HashTable*, const char*);
void delete_hash_table(HashTable*);
