#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 1000


//struct albero cars (albero normale)
typedef struct NodeCar 
{
    int id;
    struct NodeCar *left;
    struct NodeCar *right;
} NodeCar;
typedef NodeCar *Ptr_node_car;


//struct albero
typedef struct Node 
{
    int id;
    struct NodeCar *carsTree ;
    struct Node *left;
    struct Node *right;
} Node;
typedef Node *Ptr_node;






//struct hash table
typedef struct {
    int key;
    Ptr_node node;
} Entry;

typedef struct {
    Entry *entries[TABLE_SIZE];
} HashTable;





//root del bst
Ptr_node root;
//hashtable
HashTable *hashTable ;



HashTable *createHashTable() {
    HashTable *hashTable = malloc(sizeof(HashTable));
    for (int i = 0; i < TABLE_SIZE; i++) {
        hashTable->entries[i] = NULL;
    }
    return hashTable;
}

unsigned int hash(int key) {
    return key % TABLE_SIZE;
}

void insertHT(int key, Ptr_node value) {
    unsigned int index = hash(key);
    Entry *entry = malloc(sizeof(Entry));
    entry->key = key;
    entry->node = value;
    hashTable->entries[index] = entry;
}

Entry *search(HashTable *hashTable, int key) {
    unsigned int index = hash(key);
    return hashTable->entries[index];
}

void destroyHashTable(HashTable *hashTable) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        Entry *entry = hashTable->entries[i];
        if (entry != NULL) {
            free(entry);
        }
    }
    free(hashTable);
}

void printTable(HashTable *hashTable){
    for(int i=0;i<TABLE_SIZE;i++){
    if(hashTable->entries[i]==NULL){
        printf("null \n");
    }
    else{
        printf("value %d \n",hashTable->entries[i]->node->id);
    }
      
}
}




/*
//codice per linked list

//struct lista
typedef struct ListNode {
    int val;
    struct ListNode* next;
} ListNode;




ListNode* createNode(int val) {
    ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

void insertTail(ListNode** carsTree, int val) {
    ListNode* newNode = createNode(val);

    if (*carsTree == NULL) {
        *carsTree = newNode;
        return;
    }

    ListNode* curr = *carsTree;
    while (curr->next != NULL) {
        curr = curr->next;
    }

    curr->next = newNode;
}

void printList(ListNode* carsTree) {
    ListNode* curr = carsTree;
    while (curr != NULL) {
        printf("%d ", curr->val);
        curr = curr->next;
    }
    printf("\n");
}

void freeList(ListNode* carsTree) {
    ListNode* curr = carsTree;
    while (curr != NULL) {
        ListNode* temp = curr;
        curr = curr->next;
        free(temp);
    }
}
*/




//codice per albero delle macchine
//crea nodo nell'albero e inserisce il suo puntatore nella hash table
Ptr_node_car new_node_car(int id)
{
    Ptr_node_car p;
    p = malloc(sizeof( Node));
    p->id = id;
    p->left = NULL;
    p->right = NULL;
    return p;
}

Ptr_node_car insertTreeCar(NodeCar *root, int id)
{
    if (root == NULL)
        return new_node_car(id);
    else if (root->id < id)
        root->right = insertTreeCar(root->right, id);
    else
        root->left = insertTreeCar(root->left, id);
    return root;
}

Ptr_node_car findMinCar(Ptr_node_car node) {
    if (node == NULL)
        return NULL;
    while (node->left != NULL)
        node = node->left;
    return node;
}

void deleteTreeCar(Ptr_node_car root)
{
    if (root == NULL)
        return;
    deleteTreeCar(root->left);
    deleteTreeCar(root->right);
    free(root);

    return;
}

Ptr_node_car removeNodeCar(Ptr_node_car root, int id) {
    if (root == NULL)
        return root;

    if (id < root->id)
        root->left = removeNodeCar(root->left, id);
    else if (id > root->id)
        root->right = removeNodeCar(root->right, id);
    else {
        // Case 1: No children or Case 2: One child
        if (root->left == NULL) {
            Ptr_node_car temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            Ptr_node_car temp = root->left;
            free(root);
            return temp;
        }

        // Case 3: Two children
        Ptr_node_car temp = findMinCar(root->right);
        root->id = temp->id;
        root->right = removeNodeCar(root->right, temp->id);
    }
    return root;
}

void inorderCar(Ptr_node_car root)
{
    if (root != NULL) // checking if the root is not null
    {
        inorderCar(root->left);        // visiting left child
        printf(" %d ", root->id); // printing data at root
        inorderCar(root->right);       // visiting right child
    }
}







//codice per albero


//crea nodo nell'albero e inserisce il suo puntatore nella hash table
Ptr_node new_node(int id)
{
    Ptr_node p;
    p = malloc(sizeof( Node));
    p->id = id;
    p->carsTree=NULL; 
    p->left = NULL;
    p->right = NULL;

    insertHT( id,p);
    return p;
}

Ptr_node insertTree(Node *root, int id)
{

    if (root == NULL)
        return new_node(id);
    else if (root->id < id)
        root->right = insertTree(root->right, id);
    else
        root->left = insertTree(root->left, id);
    return root;
}

Ptr_node findMin(Ptr_node node) {
    if (node == NULL)
        return NULL;
    while (node->left != NULL)
        node = node->left;
    return node;
}

void deleteTree(Ptr_node root)
{
    if (root == NULL)
        return;
    deleteTree(root->left);
    deleteTree(root->right);
    deleteTreeCar(root->carsTree);
    free(root);

    return;
}

Ptr_node removeNode(Ptr_node root, int id) {
    if (root == NULL)
        return root;

    if (id < root->id)
        root->left = removeNode(root->left, id);
    else if (id > root->id)
        root->right = removeNode(root->right, id);
    else {
        // Case 1: No children or Case 2: One child
        if (root->left == NULL) {
            Ptr_node temp = root->right;
            deleteTreeCar(root->carsTree);
            free(root);
            return temp;
        } else if (root->right == NULL) {
            Ptr_node temp = root->left;
            deleteTreeCar(root->carsTree);
            free(root);
            return temp;
        }

        // Case 3: Two children
        Ptr_node temp = findMin(root->right);
        root->id = temp->id;
        root->right = removeNode(root->right, temp->id);
    }
    return root;
}

void inorder(Ptr_node root)
{
    if (root != NULL) // checking if the root is not null
    {
        inorder(root->left);        // visiting left child
        printf("la stazione %d  ha le macchine", root->id); // printing data at root
        inorderCar(root->carsTree);
        printf("\n");
        inorder(root->right);       // visiting right child
    }
}



void command(char* line){
    char* part= strtok(line," ");

    if (strcmp(part, "aggiungi-stazione") == 0) {
        
        int id = atoi(strtok(NULL," "));
        int n = atoi(strtok(NULL," "));


        if(search(hashTable, id)!=NULL && search(hashTable,id)->node->id==id ){
            printf("non aggiunta\n");
        }
        else{

            root = insertTree(root,id);
            

            Ptr_node_car nodo = search(hashTable,id)->node->carsTree;

            for(int i=0;i<n;i++){
                part = strtok(NULL," ");
                nodo = insertTreeCar(nodo,atoi(part));
                 
            }
            search(hashTable,id)->node->carsTree=nodo;
            printf("aggiunta\n");
        }
        return;
    } 
    else if (strcmp(part, "demolisci-stazione") == 0) {


        int id= atoi(strtok(NULL," "));
        Entry *entry=search(hashTable,id);


        if(entry==NULL){
            printf("non demolita\n");
            return;
        }


        if(entry->node->id!=id){
            printf("non demolita\n");
        }
        else{
            //da migliorare usando il puntatore a nodo con hash table
            removeNode(root,id);
            printf("demolita\n");
        }
        





    } 
    else if (strcmp(part, "aggiungi-auto") == 0) {
        int id= atoi(strtok(NULL," "));
        Entry *entry=search(hashTable,id);
        if(entry !=NULL&&entry->node->id==id){
            Ptr_node_car nodo = entry->node->carsTree;
            nodo = insertTreeCar(nodo,atoi(strtok(NULL," ")));
            printf("aggiunta\n");      
        }
        else{
            printf("non aggiunta\n");
        }
    } else if (strcmp(part, "rottama-auto") == 0) {
        int id= atoi(strtok(NULL," "));
        int car= atoi(strtok(NULL," "));
        Entry *entry=search(hashTable,id);
        NodeCar *nodo = entry->node->carsTree;
        nodo = removeNodeCar(nodo,car);
        
        
    } else if (strcmp(part, "pianifica-percorso") == 0) {
       printf("Pianifica percorso selected.\n");
       
    } else {
        printf("Invalid option selected.\n");
    }
  
}









int main(){
//per hash table    
hashTable = createHashTable();
//root del bst
root=NULL;
char input[100];



char line[] = "aggiungi-stazione 3 2 1 2";
command(line);
char line1[] = "aggiungi-stazione 5 2 44 45";
command(line1);
char line2[] = "aggiungi-stazione 3434 2 56 577";
command(line2);
char line3[] = "aggiungi-stazione 1 0";
command(line3);
char line4[] = "aggiungi-stazione 23 2 93 99";
command(line4);
char line5[] = "aggiungi-auto 1 105";
command(line5);


/*
printTable(hashTable);
printf("\n \n \n");
inorder(root);
*/

/*
    while (!feof(stdin))
    { // finchè non finisce l'input legge i comandi e esegue le partite

        fgets(input, sizeof(input), stdin);
        command(input);
    }
*/

//printTable(hashTable);
printf("\n \n \n");
inorder(root);


destroyHashTable(hashTable);
deleteTree(root);
return 0;
}