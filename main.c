#include <stdio.h>
#define MAX_SIZE 128

//struct for product
typedef struct{
  char name[MAX_SIZE];
  int total;
}PRODUCT;

//function for creating product
void createProduct(PRODUCT *prod, PRODUCT products[MAX_SIZE], FILE *fp, int *total){
  while(getchar() != '\n');
  fp = fopen("products.dat", "a+");
  printf("Product Name: ");
  fgets(prod->name, MAX_SIZE, stdin);
  printf("Product Total: ");
  scanf("%d", &prod->total);
  printf("Product Added!\n");
  fwrite(prod, sizeof(PRODUCT), 1, fp);
  products[*total] = *prod;
  *total+=1;
  fclose(fp);
}

//function for listing recently added products
void listAllRecent(PRODUCT arr[MAX_SIZE], int total){
  printf("\n");
  for(int i = 0; i < total; i++){
    printf("%s", arr[i].name);
    printf("%d\n", arr[i].total);
    printf("\n");
  }
}

//function for listing all products using file i/o
void listAll(PRODUCT *prod, FILE *fp){
  printf("\n");
  fp = fopen("products.dat", "r");
  while(fread(prod, sizeof(PRODUCT), 1, fp)){
    printf("%s", prod->name);
    printf("%d\n", prod->total);
    printf("\n");
  }
  printf("\n");
  fclose(fp);
}

int main(int argc, char **argv){
  FILE *f1;
  PRODUCT products[MAX_SIZE] = { 0 };
  PRODUCT p;
  int size = 0;
  int opt = 0;
  //menu loop
  while(opt != 5){
    printf("1. Add Product\n");
    printf("2. List All Recent\n");
    printf("3. List All\n");
    printf("4. Clear File\n");
    printf("5. EXIT\n");
    scanf("%d", &opt);
    if(opt == 1){
      createProduct(&p, products, f1, &size);
      printf("\n");
      while(getchar() != '\n');
    }
    if(opt == 2){
      listAllRecent(products, size);
      printf("\n");
    }
    if(opt == 3){
      listAll(&p, f1);
    }
    if(opt == 4){
      f1 = fopen("products.dat", "w");
      fclose(f1);
      printf("\n");
    }
    printf("\n");
  }
  printf("EXITING...\n");
}
