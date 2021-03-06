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
}
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
// returns pointer to starting character
//traversimngs trough  delim characters   then returning &str it will produce a pointer to the entire str array.
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
 char *copy =    (char *)malloc(sizeof(char) * (len+1)); // create a block of memory
 for(i=0; i< len; i++) {
   copy[i] = inStr[i]; // adds each character to memory
 }
 copy[i] = '\0'; // ends the block will a zero terminator
 return copy;
}
// returns an array of words
char **tokenize(char *str) {
 int i;
 //gets the total count of all the words
 int tokens = count_tokens(str); 
 // creates a block or memory
 char **array = malloc(sizeof(char *) * (tokens)); 
 // gets the starting word
 char *start = word_start(str); 

 char *end = end_word(str); // gets the ending character
 //int word_len = end_word - start_word; // gets the length of the word

 for (i = 0; i < tokens; i++) {
   array[i] = copy_str(start, end-start); // creates a char "array" and stores it in postion i of array
   start = word_start(end); // gets the new starting word
   end = end_word(start); // gets the new ending word
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
  char** tokens = tokenize(inStr); // stores new strings and sequence of char*
  print_all_tokens(tokens);
  return 0;
}
