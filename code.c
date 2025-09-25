#include <stdio.h>
#include <stdlib.h>

/*Rock Paper Scissors game by Heer 
 *
 What this game does:
- You play R/P/S against the computer for 5 rounds (or until you quit, you can quit before 5 rounds).
- Input one letter each round:R, P, S (or Q to quit).
- Counts how many rounds you win and show the final total.

*/


int cpuMove(void);
int readMove(void);
int playRound(void);
int judge(int human, int cpu);
void printScore(void);


int wins = 0;

//0=Rock, 1=Paper, 2=Scissors
int cpuMove(void) {
    return rand() % 3;
}


int readMove(void) {
    char ch;
    printf("Your move (R/P/S, Q to quit): ");
    if (scanf(" %c", &ch) != 1){ return -1;}   // this is so it skips over spaces 
    if (ch=='q'||ch=='Q'){ return -1;}   //this is for quit
    if (ch=='r'||ch=='R'){ return 0;}  //this is for rock 
    if (ch=='p'||ch=='P'){ return 1;}  //this is for paper
    if (ch=='s'||ch=='S'){ return 2;} // this is for scissors 
    printf("Invalid. Try again.\n");  //invalid 
    return readMove();
}

// -1 = lose, 0 = tie, 1 = win (kinda used this format so its easy to keep track of) 
int judge(int human, int cpu) {
    if (human == cpu) return 0;    // so tie if both equal ofc
    if ((human == 0 && cpu == 2) || (human == 1 && cpu == 0) || (human == 2 && cpu == 1)){
	    return 1;} // this is when user wins
    return -1; // otherwise computer wins and user lose
}

void printScore(void) {
    printf("Wins: %d\n", wins); //just prints the number of times user wins
}


// rounds left for this game  
int playRound(void) {
    static int gamesLeft = 5;          
    if (gamesLeft <= 0) { printf("No rounds left.\n"); return 0; }

    int h = readMove();
    if (h == -1) return 0;  // quit 
    int c = cpuMove();

    const char *names[3] = {"Rock","Paper","Scissors"}; // use of array since we learning it in class right now :)
    printf("You: %s  |  CPU: %s\n", names[h], names[c]); //I wanted to stick to some sort of format so here it is

    int r = judge(h, c);
    if (r > 0) { wins++; printf("You win this round!\n"); }
    else if (r < 0) { printf("You lose this round.\n"); }
    else { printf("Tie.\n"); }

    gamesLeft--;
    printScore();


    return gamesLeft > 0;
}
//main method to make it all work altogether
int main(void) {
    printf("Rock–Paper–Scissors (best of 5)\n");
    while (playRound()) { }
    printf("Final wins: %d\n", wins);
    return 0;
}
