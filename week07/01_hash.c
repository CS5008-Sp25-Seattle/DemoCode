#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

#define MAXSTRING 20
#define HASHSIZE 30
#define MAXENTRIES 40

#define MAXRANDCHAR 95 // 95 printing characters x20-x7E
#define CHAROFFSET 0x20 // 0x20 character offset
#define MAXRANDINT 1000 // range of random values for key value pairs

// ********** string manipulation ************
// return random character
char rand_char() {
    // 0 -> 0x20 -> ' '
    // 1 -> 0x21 -> '!'
    // ...
    // 94 -> 0x7E -> '~'
    // see https://ascii.cl
    return ((char)((rand() % MAXRANDCHAR)+CHAROFFSET));
}

// return random int
int rand_int() {
    return ((int)(rand() % MAXRANDINT));
}

// return random string length
int rand_str_length() {
    return ((int)(rand() % MAXSTRING));
}

// set s argument to random string
void rand_string(char* s) {
    int m;
    char c[2]; // convert character into string of len 1
    strcpy(s, ""); // start out with the null string
    m = rand_str_length(); // get a random string length
    c[1] = '\0'; // terminate the conversion string
    for (int i=0; i<m; ++i) {
        c[0] = rand_char();
	strcat(s, c); 
    }
    return;
}

// ********** key value pairs ************
typedef struct kv {
    char key[MAXSTRING];
    int value;
    struct kv* next;
} keyvalue_t;

// create new key value pair with key s and value i
keyvalue_t* new_key_value(char* s, int i) {
    keyvalue_t* t = (keyvalue_t*)malloc(sizeof(keyvalue_t));
    if (t != NULL) {
        strcpy(t->key, s);
	t->value = i;
	t->next = NULL;
    }
    return t;
}

// free a key value pair
void free_key_value(keyvalue_t* kvp) {
    if (kvp != NULL) {
        free(kvp);
    }
}

// ********** hash table manipulation ************
// hash 1 is just the length of the string
int hash1(char* s) {
    return (strlen(s) % HASHSIZE);
}

// hash 2 is the sum of the char codes of string
int hash2(char* s) {
    int sum_of_s = 0;
    for (int i=0; i<strlen(s); ++i) {
        sum_of_s += (int)s[i];
    }

    return (sum_of_s % HASHSIZE);
}

// add (key k, value v) to hashtable t at location loc
// note that t is an array of keyvalue pointers
// return true if successful, false if not
bool add_to_hash_table(keyvalue_t* t[], int loc, char* k, int v) {
    bool result = false;
    if ((0<=loc) && (loc<HASHSIZE)) {
	keyvalue_t* kv = new_key_value(k, v); // creat new kv pair
	//insert kv in front of linked list at location loc
	kv->next = t[loc];
	t[loc] = kv;
	result = true;
    } 
    return result;
}

// print the linked list pointed to by p
void print_hash_list(keyvalue_t* p) {
    while (p != NULL) {
        printf("key/value: [%s] / [%d]\n", p->key, p->value);
	p = p->next;
    }

    return;
}

// print the hash table t
void print_hash_table(keyvalue_t* t[]) {
    printf("=====================\n");
    for (int i=0; i<HASHSIZE; ++i) {
        printf("TABLE[%d]:\n", i);
	print_hash_list(t[i]);
	printf("\n");
    }
    printf("=====================\n");

    return;
}

// free the hash list in table ht location i
void free_hash_list(keyvalue_t* ht[], int i) {
    keyvalue_t* t;
    while (ht[i] != NULL) {
        t = ht[i];
	ht[i] = ht[i]->next;
	free_key_value(t);
    }

    return;
}

// free up kv pairs in hash table t
void free_hash_table(keyvalue_t* t[]) {
    for (int i=0; i<HASHSIZE; ++i) {
	free_hash_list(t, i);
    }

    return;
}

// return true if t is empty
bool is_hash_table_empty(keyvalue_t* t[]) {
    bool result = true;
    for (int i=0; i<HASHSIZE; ++i) {
        result = result && (t[i] == NULL);
    }
    return result;
}

int main() {
    // declare hash table as an array of pointers to kv pairs
    keyvalue_t* hashtable1[HASHSIZE];
    keyvalue_t* hashtable2[HASHSIZE];

    int i;              // iterator
    char k[MAXSTRING];  // temporary key
    int v;              // temporary value

    // seed random numbers
    srand((unsigned)time(NULL));

    // initialize the hash table entries to NULL
    for (i=0; i<HASHSIZE; ++i) {
        hashtable1[i] = NULL;
	hashtable2[i] = NULL;
    }

    // generate random strings and hash themL
    for (i=0; i<MAXENTRIES; ++i) {
        rand_string(k); // genrate random string and add to both tables
	v = rand_int(); // generate random int and add to both tables
      
        add_to_hash_table(hashtable1, hash1(k), k, v);
        add_to_hash_table(hashtable2, hash2(k), k, v);	
    }
    print_hash_table(hashtable1);
    print_hash_table(hashtable2);

    free_hash_table(hashtable1);
    free_hash_table(hashtable2);

    if (!is_hash_table_empty(hashtable1)) {
        printf("Hash table 1 is NOT empty\n");
    }
    if (!is_hash_table_empty(hashtable2)) {
        printf("Hash table 2 is NOT empty\n");
    }

    return 0;
}


