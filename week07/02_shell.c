#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// maximum string size (arbitrary)
#define SMAX 80

// display modes
#define MAXMODE 2
#define DECMODE 0
#define HEXMODE 1


// number of textual commands
// QUIT EXIT Q DEC HEX CLEAR CLR HELP NUM INPUT NOP INC ?
#define MAXCMDS 13
typedef struct ct {
  char cmdtext[SMAX];  // command text
  int cmdcode;         // associated command code
  char cmdhelp[SMAX];  // help string associated with command 
} command_t;

// valid unique commmands codes
#define CMDERROR -1
#define CMDQUIT 0
#define CMDDEC  1
#define CMDHEX  2
#define CMDCLR  3
#define CMDHELP 4
#define CMDNUM  5
#define CMDNOP  6
#define CMDINC  7


// states
#define S0 0
#define S1 1
#define S2 2
#define SFINAL -1


void printRegister(int mode, int r) {
  // prints value of register in correct display mode
   
  switch (mode) {
  case DECMODE:
    printf("r[dec]: %d\n", r);
    break;
    
  case HEXMODE:
    printf("r[hex]: 0x%x\n", r);
    break;

  default:
    printf("INVALID MODE\n");
    break;
  }

  return;
};


int readIntFromString(int mode, char* source){
  // reads value of integer from source string in correct display mode
  int intsFound;
  int result;

  switch (mode) {
  case DECMODE:
    intsFound = sscanf(source, "%d", &result);
    if (intsFound != 1) {
      printf("INVALID NUMBER - used 0 instead.\n");
      result = 0;
    }
    break;

  case HEXMODE:
    intsFound = sscanf(source, "%x", &result);
    if (intsFound != 1) {
      printf("INVALID NUMBER - used 0x0 instead.\n");
      result = 0;
    }
    break;
    
  default:
    printf("INVALID MODE ENCOUNTERED - used 0 instead.\n");
    result = 0;
    break;
  }
  
  return(result);
}


void stringUpper(char* s){
  // upper case the argument string
  int i = 0;

  while ((s[i] != '\0') && (i < SMAX)) {
    if (('a' <= s[i]) && (s[i] <= 'z')) {
      s[i] = s[i] - ('a' - 'A');
    }
    i++;
  }
}




// ============= MAIN PROGRAM ==============

int main () {
  // register to hold user input number - initially 0
  int reg = 0;

  // loop variable
  int i;

  
  // ====== USER INPUT =====
  // cmd input string
  char cmd_input[SMAX];

  // cmd portion of input (1st word)
  char cmd[SMAX];

  // number words found in input
  int wordsFound;


  // ===== STATES =====
  int currentState;

  

  // ===== DATA MODES =====
  int currentMode;


  // ===== COMMANDS =====
  // translate textual commands to command codes
  // QUIT EXIT Q DEC HEX CLEAR CLR HELP NOP INC NUM INPUT
  int currentCommand = CMDNOP;

  command_t cmdtable[MAXCMDS];

  strcpy(cmdtable[0].cmdtext, "QUIT");
  cmdtable[0].cmdcode = CMDQUIT;
  strcpy(cmdtable[0].cmdhelp, "end the program");

  strcpy(cmdtable[1].cmdtext, "EXIT");
  cmdtable[1].cmdcode = CMDQUIT;
  strcpy(cmdtable[1].cmdhelp, "end the program");

  strcpy(cmdtable[2].cmdtext, "Q");
  cmdtable[2].cmdcode = CMDQUIT;
  strcpy(cmdtable[2].cmdhelp, "end the program");

  strcpy(cmdtable[3].cmdtext, "DEC");
  cmdtable[3].cmdcode = CMDDEC;
  strcpy(cmdtable[3].cmdhelp, "switch data mode to decimal");

  strcpy(cmdtable[4].cmdtext, "HEX");
  cmdtable[4].cmdcode = CMDHEX;
  strcpy(cmdtable[4].cmdhelp, "switch data mode to hexadecimal");

  strcpy(cmdtable[5].cmdtext, "CLEAR");
  cmdtable[5].cmdcode = CMDCLR;
  strcpy(cmdtable[5].cmdhelp, "clear the register");

  strcpy(cmdtable[6].cmdtext, "CLR");
  cmdtable[6].cmdcode = CMDCLR;
  strcpy(cmdtable[6].cmdhelp, "clear the register");

  strcpy(cmdtable[7].cmdtext, "HELP");
  cmdtable[7].cmdcode = CMDHELP;
  strcpy(cmdtable[7].cmdhelp, "print out this help message");

  strcpy(cmdtable[8].cmdtext, "?");
  cmdtable[8].cmdcode = CMDHELP;
  strcpy(cmdtable[8].cmdhelp, "print out this help message");
  
  strcpy(cmdtable[9].cmdtext, "NOP");
  cmdtable[9].cmdcode = CMDNOP;
  strcpy(cmdtable[9].cmdhelp, "do nothing");

  strcpy(cmdtable[10].cmdtext, "INC");
  cmdtable[10].cmdcode = CMDINC;
  strcpy(cmdtable[10].cmdhelp, "increment the register");

  strcpy(cmdtable[11].cmdtext, "NUM");
  cmdtable[11].cmdcode = CMDNUM;
  strcpy(cmdtable[11].cmdhelp, "enter a number in the current format");

  strcpy(cmdtable[12].cmdtext, "INPUT");
  cmdtable[12].cmdcode = CMDNUM;
  strcpy(cmdtable[12].cmdhelp, "enter a number in the current format");




  // ===== START EXECUTION =====
  currentState = S0;
  currentMode = DECMODE;
  printf("\nWelcome to the command shell (? for help).\n");

  
  // ===== MAIN FSM LOOP =====
  while (currentState != SFINAL) {
    switch (currentState) {
      
    case S0: // TEXTUAL COMMAND STATE
      
      // PROMPT FOR COMMAND 
      // show current status and value of register
      printRegister(currentMode, reg);

      //prompt for input and read input string
      printf("> ");

      // get input line
      fgets(cmd_input, SMAX, stdin);

      // eliminate \n at end of string
      if (strlen(cmd_input) > 0) {
	cmd_input[strlen(cmd_input)-1] = '\0';
      }

      
      // SCAN COMMAND LINE (just get first word)
      // break the input string into cmd and junk
      wordsFound = sscanf(cmd_input, "%s %*s", cmd);

      // uppercase cmd to standard format
      stringUpper(cmd);

      // handle error inputs
      if (wordsFound <= 0) {
	// no command found, substitute NOP
	printf("No input found.\n");
	strcpy(cmd, "NOP");
      }


    
      // PARSE input for a textual command
      currentCommand = CMDERROR;
    
      for (i = 0; i < MAXCMDS; i++) {
	if (strcmp(cmd, cmdtable[i].cmdtext) == 0) {
	  currentCommand = cmdtable[i].cmdcode;
	}
      }


      // TAKE action based on command found
      switch (currentCommand) {

      case CMDERROR:
	printf("BAD INPUT |%s|\n", cmd_input);
	currentState = S0;
	break;

      case CMDQUIT:
	printf("Program terminated.\n");
	currentState = SFINAL;
	break;

      case CMDDEC:
	printf("Mode is now decimal.\n");
	currentMode = DECMODE;
	currentState = S0;
	break;

      case CMDHEX:
	printf("Mode is now hexadecimal.\n");
	currentMode = HEXMODE;
	currentState = S0;
	break;

      case CMDCLR:
	printf("Register cleared.\n");
	reg = 0;
	currentState = S0;
	break;

      case CMDHELP:
	printf("Valid commands are:\n");
	for (i = 0; i < MAXCMDS; i++) {
	  printf("%s - %s\n",cmdtable[i].cmdtext, cmdtable[i].cmdhelp);
	}
	printf("\n");
	currentState = S0;
	break;

      case CMDNUM:
	printf("Input new value for register.\n");
	currentState = S1;
	break;

      case CMDNOP:
	printf("No op.\n");
	currentState = S0;
	break;

      case CMDINC:
	printf("Register incremented.\n");
	reg++;
	currentState = S0;
	break;

      default:
	printf("UNEXPECTED INPUT |%s|\n", cmd_input);
	printf("Program Terminated.");
	currentState = SFINAL;
	break;

     
      }
      break;

    case S1: // NUMBER INPUT STATE
      // PROMPT FOR NUMBER 

      //prompt for input and read input string
      printf("INPUT NUMBER: ");

      // get input line
      fgets(cmd_input, SMAX, stdin);

      
      // SCAN COMMAND LINE (just get first word)
      // break the input string into number and junk
      wordsFound = sscanf(cmd_input, "%s %*s", cmd);

      // uppercase cmd to standard format
      stringUpper(cmd);

      // handle error input
      if (wordsFound <= 0) {
	// no number found
	printf("No number found. 0 used instead.\n");
	reg = 0;
      } else {
	reg = readIntFromString(currentMode, cmd);
      }
      
      currentState = S0;
      break;

    default:
      printf("UNKNOWN STATE ENCOUNTERED.\n");
      printf("PROGRAM TERMINATED.\n");
      currentState = SFINAL;
      break;
    }
    
  }

  printf("\nEnd Program.\n\n");
  return(0);

}

