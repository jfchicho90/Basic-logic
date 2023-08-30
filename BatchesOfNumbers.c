 #include <stdio.h>

 typedef char txt[45];

 int readValueInRange(txt cad1, int num_initial, int num_final);
 int validateRange(int value, int num_initial, int num_final);
 int readValue(txt cad2);

 int main() {

   txt cad1 = "How many numbers?: ";
   txt cad2 = "Enter a number: ";
   int lim_inferior = 3;
   int lim_superior = 21;
   int group_Counter = 0;
   int numbers_Counter = 0;
   int winningGroup;
   float max_Average = -99.0;
   float partial_Average;
   int acum_Values = 0;
   
   int LIM = readValueInRange(cad1, lim_inferior, lim_superior);

   for (int i = 0; i < LIM; i++) {
     int value = readValue(cad2);
     if (value != 0) {
       acum_Values += value;
       numbers_Counter++;
     } else {
       partial_Average = acum_Values / (1.0 * numbers_Counter);
       printf("Group closure. Partial average: %f\n", partial_Average);
       group_Counter++;
       numbers_Counter = 0;
       acum_Values = 0;
     }

     if (max_Average < partial_Average) {
       max_Average = partial_Average;
       winningGroup = group_Counter;
     }
   }
   printf("The maximum average is %f ", max_Average);
   printf("winning Group: %d", winningGroup);
   return 0;
 }

 int readValue(txt cad2) {
   printf("%s", cad2);
   int n;
   scanf("%d", & n);
   fflush(stdin);
   while (n < 0) {
     printf("Error. Please enter positive numbers: ");
     scanf("%d", & n);
     fflush(stdin);
   }
   return n;
 }

  int readValueInRange(txt cad1, int num_initial, int num_final) {
   printf("%s", cad1);
   int dim;
   scanf("%d", & dim);
   fflush(stdin);
   while (!validateRange(dim, num_initial, num_final)) {
     printf("Error. Dimension must be in range\n");
     scanf("%d", & dim);
     fflush(stdin);
   }
   return dim;
 }

 int validateRange(int value, int num_initial, int num_final){
   return value >= num_initial && value <= num_final;
 }
