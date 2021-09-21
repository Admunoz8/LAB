#include  <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#define max 1000
//checks if char is whitespace
//simple if statement that  returns true if char is a whitespace
bool delim_character(char c){
	if(c == '\t' || c == ' '){
		return true;
	}
	return false;
}//doome
/* Return true (non-zero) if c is a non-whitespace
   character (not tab or space).
   Zero terminators are not printable (therefore false) */
//if char is tab return flase if not return  not delim characters   
bool non_delim_character(char c){
	if(c == '\0'){
		return false;
	}
	return !delim_character(c);
}
// returning the  pointer to the starting character

//traversings trough  delim characters   then returning &str it will produce a pointer to the entire str array.
char *word_start(char *str){
 int i = 0;
 while(delim_character(str[i])) {
   i++;
 }
 return &str[i];
}
//retruns pointer to end character

//traversing non  delim  characters tto get  end character  and return  &str it will produce a pointer to the entire str array.
char *end_word(char *str) {
 str = word_start(str);
 int i =0;
 while(non_delim_character(str[i])){
   i++;
 }
 return &str[i];
}
//returns number of tokens by counting the end of word
int count_tokens(char *str) {
  //making  a counter
 int count;
 //loop that will count them all 
 for(count = 0; str != end_word(str); count++) {
   str = end_word(str);
 }
 return count;
}
// returns a array with a token in it
char *copy_str(char *inStr, short len) {
 int i;
 char *c = (char *)malloc(sizeof(char) * (len+1)); // create a block of memory
 // adds each character to memory
 for(i=0; i< len; i++) {
   c[i] = inStr[i]; 
 }
 // ends the block will a zero terminator
 c[i] = '\0'; 
 return c;
}
// returns an array of words
char **tokenize(char *str) {
 int i;
 //gets the total count of all the words
 int tok = count_tokens(str); 
 // creates a block or memory
 char **array = malloc(sizeof(char *) * (tok)); 
 // gets the start word
 char *s = word_start(str); 
// gets the end word
 char *e = end_word(str); 
// creates a char "array" and stores it in postion i of array
 for (i = 0; i < tok; i++) {
   array[i] = copy_str(s, e-s); 
   // gets the new starting word
   s = word_start(e); 
   // gets the new ending word
   e = end_word(s); 
 }
 array[i] = 0;
 return array;
}

//simply just printing the tokens
void print_all_tokens(char** tokens){
  int i = 0;
  while(tokens[i]) {
    printf("Tokens[%d]: = %s\n", i, tokens[i]);
    i++;
  }
  return;
}

//main to run tthe program
int main() {
  char inStr[max];
  printf("Please enter the input string: \n");
  fgets(inStr, max, stdin); //fgets also has a pointer
  printf("\n");
   // stores new strings and sequence of char*
  char** tokens = tokenize(inStr);
  print_all_tokens(tokens);
  return 0;
}
