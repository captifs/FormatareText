//Bejenaru Adrian 311 CB 

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// Am implimentat functia itoa ca sa o folosesc la liste
// Functia converteste int in string
void itoa(int n, char s[])
{ int i = 0;
  
  while(n)
  {
    s[i] = '0' + n % 10;
    n/=10;
    i++;
  }
  s[i] = '\0';
  char buf[10];
  int len = strlen(s);
  for(i = 0; i < len; i++)
  {
    buf[len - i - 1] = s[i];
  }
  buf[len] = '\0';
  strcpy(s,buf);
}
// Aceasta este o functie care gaseste linia de lungime maxima
int lungime_maxima(char original[1000][1000], int numar_linii) {
  int max = 0, i; 
  for (i = 0; i <= numar_linii; i++) {
    if (strlen(original[i]) > max ) 
      max = strlen(original[i]);
  }
  return max;
}
//Aliniaza textul la stanga
void align_left(char original[1000][1000], int inceput_linie,
                                           int final_linie )
{
  int i;
  for (i = inceput_linie; i <= final_linie; i++) {
  // Cat timp primul caracter din fiecare 
  //rand va fi spatiu , mutam textul in stanga
    while(original[i][0] == ' '){
      memmove(original[i],original[i]+1, strlen(original[i]));

    }
  }
// Daca prima linie coincide cu ultima ,
// mutam textul in stanga cand avem spatii 
  if (inceput_linie == final_linie) {
    while(original[final_linie][0] == ' '){
      memmove(original[final_linie],original[final_linie]+1,
                    strlen(original[final_linie]));

    }
    
  }
}
//Aliniaza textul la dreapta
void align_right(char original[1000][1000], int inceput_linie, int final_linie, 
                                int numar_linii) {
  int maxim = lungime_maxima(original, numar_linii);
  int i,j;
  for (i = inceput_linie; i <= final_linie; i++) {
// Daca primul caracter din fiecare linie nu e \n
    if(original[i][0] != '\n'){
    int lungimea_linie = strlen(original[i]);
// Mutam textul in dreapta cu diferenta intre 
    //lungimea randului maxim si lungimea liniei curente
    memmove(original[i]+(maxim - lungimea_linie),original[i],lungimea_linie);
    for (j = 0 ; j < (maxim - lungimea_linie); j++)
      // si pe locurile libere punem spatii 
      original[i][j] = ' ';
    }

  }
}
//Aliniaza textul in centru 
void align_center(char original[1000][1000], int inceput_linie,
            int final_linie, int numar_linii) {
  int maxim = lungime_maxima(original, numar_linii);
  int i,j;
  for (i = inceput_linie; i <= final_linie; i++) {
    if(original[i][0] != '\n'){
    int lungimea_linie = strlen(original[i]);
// Mutam textul la dreapta doar cu jumatate din
// lungimea randului maxim - lungimea liniei curente
    if ((maxim - lungimea_linie ) % 2 == 0 ){
    memmove(original[i]+(maxim - lungimea_linie)/2,original[i],lungimea_linie);
    for (j = 0 ; j < (maxim - lungimea_linie)/2; j++)
      original[i][j] = ' ';
      }
// Daca maxim-lungimea liniei e impara , 
      //mutam la fel, ajustand pentru paritate
    else {
      memmove(original[i]+(maxim - lungimea_linie)/2+1,original[i],
                                  lungimea_linie);
    for (j = 0 ; j < (maxim - lungimea_linie)/2+1; j++)
      original[i][j] = ' ';
      }

    }
  }
  
}

void paragraph(char original[1000][1000], int lungime_tab, int inceput_linie,
                            int final_linie) {
  int i,j;
    if(inceput_linie != 0)
    for (i = inceput_linie; i <= final_linie; i++) {
  // Linie dinainte sa fie un \n    
      if((original[i-1][0] == '\n')) {
        int lungimea_linie = strlen(original[i]);
  //  Mut inceputul liniei cu "lungime_tab" spatii mai incolo
        memmove(original[i] + lungime_tab,original[i],lungimea_linie);
    // In locul pozitiilor goale pun spatii     
        for (j = 0 ; j < lungime_tab; j++)
          original[i][j] = ' ';
    }
  }

  
  else
  //Fac paragraf pe prima linie 
    { int lungimea_linie = strlen(original[0]);
    memmove(original[0] + lungime_tab,original[0],lungimea_linie);
      for (j = 0 ; j < lungime_tab; j++)
        original[0][j] = ' ';

      for (i = inceput_linie + 1; i <= final_linie; i++) {
// Daca linia e goala , urmatoarea linie va fi paragraf     
        if((original[i-1][0] == '\n')) {
          int lungimea_linie = strlen(original[i]);
          memmove(original[i] + lungime_tab,original[i],lungimea_linie);
          for (j = 0 ; j < lungime_tab; j++)
            original[i][j] = ' ';
    }
    

}
}
}
void liste(char original[1000][1000], char tipul_listei, char caract_sp,
                                   int inceput_linie, int final_linie) {
  int i;

// lista bullet 
  if( tipul_listei == 'b')
  {
    for (i = inceput_linie; i <= final_linie; i++) {
      { int lungime_linie = strlen(original[i]);
        memmove(original[i]+2,original[i],lungime_linie);
        original[i][0] = caract_sp;
        original[i][1] = ' ';
      }
    }
  }
//lista alfabetica
  if( tipul_listei == 'a' || tipul_listei =='A')
  { char nr = tipul_listei;
    for (i = inceput_linie; i <= final_linie; i++) {
      { 
        int lungime_linie = strlen(original[i]);
// fac loc liber in fata liniei
        memmove(original[i]+3,original[i],lungime_linie);
    // primu caracter numar , apoi caracter special apoi spatiu 
       original[i][0] = nr;
        original[i][1] = caract_sp;
        original[i][2] = ' ';
        nr = nr + 1;
      }
    }
  }
  //lista numerotata
  if(tipul_listei == 'n')
  { int nr = 1;
    for (i = inceput_linie; i <= final_linie; i++) {
      { 
        
        char buf[1010];
        itoa(nr,buf); // face nr un sir de caractere 
        int lungime = strlen(buf);
        buf[lungime] = caract_sp; // urmatoru lucru un buffer va fi caract.sp.
        buf[lungime+1] = ' '; // apoi spatiu
        buf[lungime+2] = '\0'; // inchid buffer 
        strcat(buf, original[i]);
        strcpy(original[i],buf);
        nr++;

      }
    }
  }
}
void ordered_list(char original[][1000], char tipul_listei, 
          char caract_sp, char ordering, int inceput_linie, int sfarsit_linie)
{
char buffer[1000];
int inceput_linie_salvat = inceput_linie;
int var = inceput_linie;
while (inceput_linie < sfarsit_linie - 1) {
  while(var < sfarsit_linie - 1) {
    if (ordering == 'z' ) { // daca incepe cu z sorteaza invers 
      if (strcmp(original[var],original[var+1]) < 0 )  { 
        strcpy(buffer,original[var + 1]);
        strcpy(original[var+1],original [var]);
        strcpy(original[var],buffer);
      } 
    } else if (ordering == 'a') { // daca incepe cu a sorteaza alfabetic
      if (strcmp(original[var], original[var+1]) > 0 )  { 
        strcpy(buffer,original[var + 1]);
        strcpy(original[var+1],original [var]);
        strcpy(original[var],buffer);
      } 
    }
    var++;
  }
  var = inceput_linie_salvat;
  inceput_linie++;
  }
  liste(original,tipul_listei,caract_sp,inceput_linie_salvat, sfarsit_linie);
}

  // Functie care sterge spatiile 
void remove_spaces(char original[1000][1000], int linii_matrice) {
  int i,j;
  for (i = 0; i <= linii_matrice; i++) {
    for (j = strlen(original[i])-1; j >= 0; j--)
      if (strchr(" \n\t", original[i][j]) == 0) {
        original[i][j+1] = '\n';
        original[i][j+2] = '\0';
        break;
      }
  }
}
void justify(char original[1000][1000], int inceput, int final, int nr_linii)
{ 
  align_left(original,inceput,final);
  int i,j,max = 0, paragraph = 0;
  for(i = 0; i < nr_linii; i++)
    if(strlen(original[i]) > max)
      max = strlen(original[i]);
    for(i = inceput; i < final; i++)
    { int spatii = 1; paragraph = 0;
      if(strlen(original[i]) > 1)
      while(strlen(original[i]) < max)
      { //cat timp linia e mai scurta decat maximul
        for(j = 0; j < strlen(original[i]); j++)
        {//parcurgem linia
          if(strlen(original[i]) == max)
            break; // daca am adaugat prea multe spatii, ne oprim
          else if(strcmp(original[i+1], "\n") == 0 || i == nr_linii -1)
            {paragraph = 1; break;}//daca am dat de un paragraf, 
          //sarim peste el
          else
          if(original[i][j] == ' ')
          { //daca am gasit un spatiu
            char space[1000] = {' '};
            strcat(space,original[i] + j);//il adaugam in linie        
            strcpy(original[i] +j, space);
            
            
            
            j+=spatii;//si dupa sarim peste toate 
            //spatiile pe care le-am adaugat
          }
          
        }
        spatii++;//cand am terminat de adaugat cate un spatiu, 
        //incrementam contorul pentru a putea sari peste 
        //toate spatiile, la pasii urmatori
        if(paragraph == 1)
          break;
       
      }
      
    }
    
}

int main(int argc, char *argv[]) {
  char buf[1000],               // buffer used for reading from the file
      original[1000][1000],     // original text, line by line
      result[1000][1000],       // text obtained after applying operations
      comanda[30][30],      // matrice de comenzi si parametri
      copie[1000][1000];    //copie in caz de eroare
  int original_line_count = 0,  // number of lines in the input file
      result_line_count = 0,    // number of lines in the output file
      i;

  if (argc != 4) {  // invalid number of arguments
    fprintf(stderr,
            "Usage: %s operations_string input_file output_file\n",
            argv[0]);
    return -1;
  }

  // Open input file for reading
  FILE *input_file = fopen(argv[2], "r");

  if (input_file == NULL) {
    fprintf(stderr, "File \"%s\" not found\n", argv[2]);
    return -2;
  }

  // Read data in file line by line
  while (fgets(buf, 1000, input_file)) {
    strcpy(original[original_line_count], buf);
    strcpy(copie[original_line_count],buf);
    original_line_count++;
  }

  fclose(input_file);
  char *arg = strtok(argv[1],",");
  i = 0;
  while(arg)
  {
    strcpy(comanda[i],arg);
    i++;
    arg = strtok(NULL, ",");
  }
  int nr_comenzi = i;
  for(i = 1; i < nr_comenzi; i++)
  {
    memmove(comanda[i],comanda[i]+1, strlen(comanda[i]));
  }
  char error = 'N';
  for(i = 0 ; i < nr_comenzi; i++)
  {
    //tratez fiecare operatie in parte 
    switch (comanda[i][0])
    {
    case 'w' : ;
    case 'W':
    {
    char *arg = strtok(comanda[i], " ");
      arg = strtok(NULL, " "); 
    int arg_i = 0;
    if(atoi(arg))
    arg_i = atoi(arg);
    else 
     {
      error ='Y';
        printf("Invalid operation!\n");
        break;
     }
    arg = strtok(comanda[i]," ");
    if(arg)
    {
     error ='Y';
       printf("Invalid operation!\n");
       break;
    }
    }
      case 'l' : ;
      case 'L' : 
      {
        char *arg = strtok(comanda[i], " ");
        arg = strtok(NULL, " "); 
        int arg_i[2] ={ 0, original_line_count},i = 0;

        while(arg)
        {
         if(atoi(arg) != 0 || arg[0] =='0')
         {
          arg_i[i] = atoi(arg);
          i++;
         }
         else
         {
          error ='Y';
          printf("Invalid operation!\n");
          break;
         }
         arg = strtok(NULL, " ");
      if(arg && i > 1)
       {
          error ='Y';
          printf("Invalid operation!\n");
          break;
         }
        }
        
      if(arg_i[1] < 0 || arg_i[0] < 0 || arg_i[0] > arg_i[1])
      {
          error ='Y';
          printf("Invalid operation!\n");
          break;
         }
      if(error == 'Y')
         break;
        else align_left(original, arg_i[0],arg_i[1]);
        break;
      }
      case 'r' : ;
      case 'R' : 
      {
        char *arg = strtok(comanda[i], " ");
        arg = strtok(NULL, " "); 
        int arg_i[2] ={ 0, original_line_count},i = 0;

        while(arg)
        {
         if(atoi(arg) != 0 || arg[0] =='0')
         {
          arg_i[i] = atoi(arg);
          i++;
         }
         else
         {
          error ='Y';
          printf("Invalid operation!\n");
          break;
         }
         arg = strtok(NULL, " ");
       if(arg && i > 1)
       {
          error ='Y';
          printf("Invalid operation!\n");
          break;
         }
 
        }
      if(arg_i[1] < 0 || arg_i[0] < 0 || arg_i[0] > arg_i[1])
      {
          error ='Y';
          printf("Invalid operation!\n");
          break;
         }
        if(error == 'Y')
         break;
        else align_right(original, arg_i[0],arg_i[1],original_line_count);
        break;
      }
      case 'c' : ;
      case 'C' : 
      {
        char *arg = strtok(comanda[i], " ");
        arg = strtok(NULL, " "); 
        int arg_i[2] ={ 0, original_line_count},i = 0;

        while(arg)
        {
         if(atoi(arg) != 0 || arg[0] =='0')
         {
          arg_i[i] = atoi(arg);
          i++;
         }
         else
         {
          error ='Y';
          printf("Invalid operation!\n");
          break;
         }
         arg = strtok(NULL, " ");
       if(arg && i > 1)
       {
          error ='Y';
          printf("Invalid operation!\n");
          break;
         }
        }
      if(arg_i[1] < 0 || arg_i[0] < 0 || arg_i[0] > arg_i[1])
      {
          error ='Y';
          printf("Invalid operation!\n");
          break;
         }
        if(error == 'Y')
         break;
        else align_center(original, arg_i[0],arg_i[1],original_line_count);
        break;
      }
      case 'p' : ;
      case 'P' : 
      {
        char *arg = strtok(comanda[i], " ");
        arg = strtok(NULL, " "); 
        int arg_i[3] ={-1, 0, original_line_count},i = 0;

        while(arg)
        {
         if(atoi(arg) != 0 || arg[0] =='0')
         {
          arg_i[i] = atoi(arg);
          i++;
         }
         else
         {
          error ='Y';
          printf("Invalid operation!\n");
          break;
         }
         arg = strtok(NULL, " ");
       if(arg && i > 2)
       {
          error ='Y';
          printf("Invalid operation!\n");
          break;
         }
        }
      if(arg_i[2] < 0 || arg_i[1] < 0 || arg_i[1] > arg_i[2])
      {
          error ='Y';
          printf("Invalid operation!\n");
          break;
         }
        if(error == 'Y')
         break;
        if(arg_i[0] == -1)
        {
          error ='Y';
          printf("Invalid operation!\n");
          break;
        }
        else paragraph(original, arg_i[0],arg_i[1],arg_i[2]);
        break;
      }

      case 'i' : ;
      case 'I' : {
        char *arg = strtok(comanda[i], " ");
        arg = strtok(NULL, " "); 
        int ctr = 0;
        int arg_i[2] = {0, original_line_count};
        char arg1[2]="``", arg2[2]="``";
        while(arg)
        {
          if(ctr == 0)
          {
            strcpy(arg1, arg);
          }
          else if (ctr == 1)
          {
            strcpy(arg2, arg);
          }
          else if (ctr == 2)
          {
            if(atoi(arg) != 0 || arg[0] == '0')
            {
              arg_i[ctr - 2] = atoi(arg); 
            }
            
          }
          else if (ctr == 3)
          {
            if(atoi(arg) != 0 || arg[0] == '0')
            {
              arg_i[ctr - 2] = atoi(arg); 
            }
            
          }
          arg = strtok(NULL," ");
          ctr++;
        }
          if(arg1[0] == '`' || arg2[0] == '`')
          { 
            error ='Y';
            printf("Invalid operation!\n");
            break;
          }
          else liste(original, arg1[0],arg2[0],arg_i[0],arg_i[1]);
          break;
      }

      case 'o' : ;
      case 'O' : {
        char *arg = strtok(comanda[i], " ");
        arg = strtok(NULL, " "); 
        int ctr = 0;
        int arg_i[2] = {0, original_line_count};
        char arg1[2]="``", arg2[2]="``", arg3[2]="``";
        while(arg)
        {
          if(ctr == 0)
          {
            strcpy(arg1, arg);
          }
          else if (ctr == 1)
          {
            strcpy(arg2, arg);
          }
        else if (ctr == 2)
          {
            strcpy(arg3, arg);
            
          }
          else if (ctr == 3)
          {
            if(atoi(arg) != 0 || arg[0] == '0')
            {
              arg_i[ctr - 3] = atoi(arg); 
            }
            
          }
          else if (ctr == 4)
          {
            if(atoi(arg) != 0 || arg[0] == '0')
            {
              arg_i[ctr - 3] = atoi(arg); 
            }
            
          }
          arg = strtok(NULL," ");
          ctr++;
        }
          if(arg1[0] == '`' || arg2[0] == '`')
          { 
            error ='Y';
            printf("Invalid operation!\n");
            break;
          }
        else {ordered_list(original, arg1[0],arg2[0],arg3[0],arg_i[0],arg_i[1])
               ;break;}
      }
      case 'J':
  {
char *arg = strtok(comanda[i], " ");
        arg = strtok(NULL, " "); 
        int arg_i[2] ={ 0, original_line_count},i = 0;

        while(arg)
        {
         if(atoi(arg) != 0 || arg[0] =='0')
         {
          arg_i[i] = atoi(arg);
          i++;
         }
         else
         {
          error ='Y';
          printf("Invalid operation!\n");
          break;
         }
         arg = strtok(NULL, " ");
        }
        if(error == 'Y')
         break;
        else justify(original, arg_i[0],arg_i[1],original_line_count);
        break;
}

      if(error == 'Y')
        break;
    }
  }

  //if(error == 'N') 
    remove_spaces(original,original_line_count);
  for (i = 0; i < original_line_count; i++) {
    strcpy(result[i], original[i]);
  }
   if(error == 'Y')
  for( i = 0; i < original_line_count; i++)
     strcpy(result[i],copie[i]);
  result_line_count = original_line_count;

  // Open output file for writing
  FILE *output_file = fopen(argv[3], "w");

  if (output_file == NULL) {
    fprintf(stderr, "Could not open or create file \"%s\"\n", argv[3]);
    return -2;
  }

  // Write result in output file
  for (i = 0; i < result_line_count; i++) {
    fputs(result[i], output_file);
  }

  fclose(output_file);
  return 0;
}