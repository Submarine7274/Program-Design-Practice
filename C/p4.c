/*Modify the inventory. c program of Section lo.3 by adding a price member to the
part structure. The insert function should ask the user for the price of a new item. The
search and print functions should display the price. Add a new command that allows
the user to change the price of a part.
To illustrate how nested arrays and structures are used in practice, we’ll now
develop a fairly long program that maintains a database of information about parts
stored in a warehouse. The program is built around an array of structures, with
each structure containing information—part number, name, and quantity—about
one part. Our program will support the following operations:
■ Add a new part number, part name, and initial quantity on hand. The program
must print an error message if the part is already in the database or if the
database is full.
■ Given a part number, print the name of the part and the current quantity on
hand. The program must print an error message if the part number isn’t in the
database.
■ Given a part number, change the quantity on hand. The program must print
an error message if the part number isn’t in the database.
■ Print a table showing all information in the database. Parts must be displayed
in the order in which they were entered.
■ Terminate program execution.
C99
390 Chapter 16 Structures, Unions, and Enumerations
We’ll use the codes i (insert), s (search), u (update), p (print), and q (quit) to represent
these operations. A session with the program might look like this:
*/
#include <stdio.h>
#include"readline.h"

#define NAME_LEN 25
#define MAX_PARTS 100
struct{
    int number;
    char name[NAME_LEN+1];
    int on_hand;
    float price;
} inventory[MAX_PARTS];

int num_parts = 0;   /* number of parts currently stored */
int find_part(int number);
void insert(void);
void search(void);
void update(void);
void print(void);
void costupdate(void);
int main (void){
    char code;
    for (;;) {
    printf("Enter operation code: ");
    scanf(" %c", &code);
    while (getchar() != '\n')   /* skips to end of line */
      ;
    switch (code) {
        case 'i': insert();
                break;
        case 'c': costupdate();
            break;
        case 's': search();
                break;
        case 'u': update();
                break;
        case 'p': print();
                break;
        case 'q': return 0;
        default:  printf("Illegal code\n");
    }
    printf("\n");
  }
}
int find_part(int number)
{
  int i;

  for (i = 0; i < num_parts; i++)
    if (inventory[i].number == number)
      return i;
  return -1;
}
void insert(void){
    int part_number;

  if (num_parts == MAX_PARTS) {
    printf("Database is full; can't add more parts.\n");
    return;
  }

  printf("Enter part number: ");
  scanf("%d", &part_number);
  if (find_part(part_number) >= 0) {
    printf("Part already exists.\n");
    return;
  }

  inventory[num_parts].number = part_number;
  printf("Enter part name: ");
  read_line(inventory[num_parts].name, NAME_LEN);
  printf("Enter quantity on hand: ");
  scanf("%d", &inventory[num_parts].on_hand);
  printf("Enter price: ");
  scanf("%f", &inventory[num_parts].price);
  num_parts++;
}
void search(void)
{
  int i, number;

  printf("Enter part number: ");
  scanf("%d", &number);
  i = find_part(number);
  if (i >= 0) {
    printf("Part name: %s\n", inventory[i].name);
    printf("Quantity on hand: %d\n", inventory[i].on_hand);
    printf("Price : %.2f \n",inventory[i].price);
  } else
    printf("Part not found.\n");
}
void update(void)
{
  int i, number, change;

  printf("Enter part number: ");
  scanf("%d", &number);
  i = find_part(number);
  if (i >= 0) {
    printf("Enter change in quantity on hand: ");
    scanf("%d", &change);
    inventory[i].on_hand += change;
  } else
    printf("Part not found.\n");
}
void costupdate(void)
{
  int i, number;
    float change;
  printf("Enter part number: ");
  scanf("%d", &number);
  i = find_part(number);
  if (i >= 0) {
    printf("Enter change in price: ");
    scanf("%f", &change);
    inventory[i].price += change;
  } else
    printf("Part not found.\n");
}
void print(void)
{
  int i;

  printf("Part Number   Part Name                  ""Quantity on Hand  Price\n");
  for (i = 0; i < num_parts; i++)
    printf("%7d       %-27s%-18d$%-5.2f\n", inventory[i].number,
           inventory[i].name, inventory[i].on_hand, inventory[i].price);
}