#include <stdio.h>
#include <stdlib.h>
#include<string.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
/*
 * author Mehmet 
 */

struct CELL {
    char *anahtar;
    struct CELL *next;
};

int lookup(char *anahtar, struct CELL *l){
    if(l==NULL) return 0;
    else if(!strcmp(anahtar,l->anahtar)) return 1;
    else return lookup(anahtar,l->next);
}

int insert(char *anahtar, struct CELL **l){
    if(*l==NULL){
        *l=(struct CELL *)malloc(sizeof(struct CELL));
        (*l)->anahtar = (char *)malloc((strlen(anahtar)+1)*sizeof(char));
        strcpy((*l)->anahtar,anahtar);
        (*l)->next=NULL;
        return 1;
    }
    else if(strcmp(anahtar,(*l)->anahtar)) return insert(anahtar,&((*l)->next));
    else return 0;
}

void liste_yaz(struct CELL *l){
    if(l!=NULL){
        printf("%s ",l->anahtar);
        liste_yaz(l->next);
    }
}

struct table_node{
    int count;
    struct CELL *header;
};

struct hash_tablosu{
    struct table_node *tablo_basi;
    int tablo_uzunlugu;
    int multiplier;
};

#define TABLE_SIZE 11
#define MULTIPLIER 3
unsigned hash(char *s){
    int i=0;
    unsigned int value =0;
    while(s[i] != '\0'){
        value=(s[i]+MULTIPLIER*value) % TABLE_SIZE;
        i++;
    }
    return value;
}

unsigned hash1(char *s, int multiplier, int table_size){
    int i=0;
    unsigned int value =0;
    while(s[i] != '\0'){
        value=(s[i]+multiplier*value) % table_size;
        i++;
    }
    return value;
}


struct table_node* initialize_hash_table(){
    int i;
    struct table_node *hash_table;
    hash_table = (struct table_node*)malloc(TABLE_SIZE*sizeof(struct table_node));
    if(hash_table==NULL){
        printf("Hash hablosu icin gerekli yer ayrilamadi. Hata...");
        exit(1);
    }
    for(i=0; i<TABLE_SIZE; i++){
        (hash_table+i)->count=0;
        (hash_table+i)->header=NULL;
    }
    return hash_table;
}

void ekle_hash(struct table_node *hash_table, char *anahtar){
    insert(anahtar,&(hash_table+hash(anahtar))->header);
    hash_table[hash(anahtar)].count++;
}

void hash_table_print(struct table_node *hash_table){
    if(hash_table!=NULL){
        int i;
        for(i=0; i<TABLE_SIZE; i++){
            printf("%5d : (%2d)",i,(hash_table+i)->count);
            liste_yaz((hash_table+i)->header);
            printf("\n");
        }
    }
}

void initialize_hash_table1(struct hash_tablosu **hash_table,int multiplier,int tablo_uzunlugu){
    int i;
    
    *hash_table=(struct hash_tablosu*)malloc(sizeof(struct hash_tablosu));
   // *hash_table = (struct table_node*)malloc(TABLE_SIZE*sizeof(struct table_node));
    if(*hash_table==NULL){
        printf("Hash hablosu icin gerekli yer ayrilamadi. Hata...");
        exit(1);
    } 
    (*hash_table)->tablo_basi = (struct table_node*)malloc(tablo_uzunlugu*sizeof(struct table_node));
    if((*hash_table)->tablo_basi==NULL){
        printf("Hash hablosu icin gerekli yer ayrilamadi. Hata...");
        exit(1);
    }
    (*hash_table)->tablo_uzunlugu = tablo_uzunlugu;
    (*hash_table)->multiplier = multiplier;
    
    for(i=0; i<tablo_uzunlugu; i++){
        (((*hash_table)->tablo_basi)+i)->count=0;
       (((*hash_table)->tablo_basi)+i)->header=NULL;
    }
}

void ekle_hash1(struct hash_tablosu *hash_table, char *anahtar){
    int yerles;
    yerles=insert(anahtar, &((hash_table->tablo_basi+hash1(anahtar,hash_table->multiplier,hash_table->tablo_uzunlugu))->header));
     if(yerles) (hash_table->tablo_basi+
           hash1(anahtar,hash_table->multiplier,hash_table->tablo_uzunlugu))->count++;
}

void hash_table_print1(struct hash_tablosu *hash_table){
    if(hash_table!=NULL){
        int i;
        printf("---- Hash Table icerigi----\n");
        for(i=0; i<hash_table->tablo_uzunlugu; i++){
            printf("%5d : (%2d) ",i,(hash_table->tablo_basi+i)->count);
            liste_yaz((hash_table->tablo_basi+i)->header);
            printf("\n");
        }
    }
    else printf("\nHash table bos...\n");
}

void liste_yok_et(struct CELL **liste_basi){
    if(*liste_basi!=NULL) {
        struct CELL *gecici=*liste_basi;
        *liste_basi=(*liste_basi)->next;
        free(gecici->anahtar);
        free(gecici);
    }
}

void liste_yok_et_recursive(struct CELL **liste_basi){
    if(*liste_basi!=NULL){
       liste_yok_et_recursive(&(*liste_basi)->next);
       free((*liste_basi)->anahtar);
       free(*liste_basi);
    }
    *liste_basi=NULL;
}

void hash_table_yok_et(struct hash_tablosu **hash_table){
    int i;
    if(*hash_table!=NULL){
       for(i=0; i <(*hash_table)->tablo_uzunlugu; i++)
           liste_yok_et(&((*hash_table)->tablo_basi+i)->header);
    
       free((*hash_table)->tablo_basi);  
   }
   *hash_table=NULL; 
}    


 struct hash_tablosu* hash_tablosu_buyut(struct hash_tablosu **htable1,
     int multiplier,int tablo_uzunlugu){
     
     int i;
     struct CELL *liste_basi;
     struct hash_tablosu *htable2;
     if(*htable1==NULL) return NULL;
     initialize_hash_table1(&htable2,multiplier,tablo_uzunlugu);
     for(i=0; i<(*htable1)->tablo_uzunlugu; i++){
         liste_basi=((*htable1)->tablo_basi+i)->header;
         while(liste_basi!=NULL){
            ekle_hash1(htable2, liste_basi->anahtar);
            liste_basi=liste_basi->next;
         }
     }
     hash_table_yok_et(htable1);
     return htable2;
}

int main(int argc, char *argv[]) {
	struct hash_tablosu *htable=NULL;
    
    initialize_hash_table1(&htable,3,11);
    
    ekle_hash1(htable,"amasya");
    ekle_hash1(htable,"batman");
    ekle_hash1(htable,"urfa");
    ekle_hash1(htable,"kayseri");
    ekle_hash1(htable,"adana");
    ekle_hash1(htable,"mus");
    ekle_hash1(htable,"kayseri");
 	ekle_hash1(htable,"canakkale");
    ekle_hash1(htable,"nigde");
    ekle_hash1(htable,"giresun");
    ekle_hash1(htable,"balikesir");
    ekle_hash1(htable,"batman");
	ekle_hash1(htable,"bursa");
    ekle_hash1(htable,"konya");
    ekle_hash1(htable,"ordu");
    ekle_hash1(htable,"rize");
    ekle_hash1(htable,"zonguldak");
    ekle_hash1(htable,"kocaeli");

    
    
    hash_table_print1(htable);
    htable=hash_tablosu_buyut(&htable,7,23);    
    hash_table_print1(htable);    
    htable=hash_tablosu_buyut(&htable,89,101);
    hash_table_print1(htable);    
	return 0;
}
