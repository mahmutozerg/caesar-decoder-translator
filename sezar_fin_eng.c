#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define LIMIT 26
int g_results[100];
void crt_new_alphabet(char original[], char encoded[], int shift)
{
    shift %= LIMIT;
    int move_dup = 0;// ı'll explain this at line 23
    for (int i = 0; i < LIMIT; ++i)
    {

        if (i < LIMIT - shift)// Reason for this if statement is when we shift  alphabet by a value our original alphabeth's shift th element will be
            // assigned to the new alphabet. Bc of thar encrypted alphabeth's las shift and original alphabeth's last shift element will be un assigned
        {
            encoded[i] = original[i + shift];
        }
        else if (move_dup < shift)// if we've reached to the last  shift th value of the original alphabet we have to reach it first  shift th value
            // thats why we are using a  another cursor for indexes
        {

            encoded[i] = original[move_dup];
            ++move_dup;
        }

    }


}
void encode(char original[], char encoded[], char string[], int shift)
{
    shift %= LIMIT;// no matter how big our shifting value is  it can be max 25  unit(26-1 in english alphabet)


    for (int i = 0; string[i] != '\0'; ++i)// We are moving in user input string
    {

        for (int j = 0; j < LIMIT; ++j)//moving in our alphabet
        {
            if (original[j] == string[i])// If the  current string is equal to any letter in our original alphabet we are going to change it with encoded alphabet
            {

                string[i] = encoded[j];
                break;
            }
        }

    }


}
void decode(char original[], char encoded[], char string[], int shift)
{
    shift %= LIMIT;

    //This function is same logic with the encode but this time we are changing letters with original alphabet

    for (int i = 0; string[i] != '\0'; ++i)
    {
        for (int j = 0; j < LIMIT; ++j)
        {
            if (encoded[j] == string[i])
            {
                string[i] = original[j];
                break;

            }
        }
    }

}
void print_alph(char alph[])
{
    for (int i = 0; i < LIMIT; ++i)
    {
        printf("%c ", alph[i]);

    }


}
void print_text(char text[])
{
    for (int j = 0; text[j] != '\0'; ++j)
    {
        printf("%c", text[j]);

    }

}

void guesser(char string[], char alpha[])// this is for decoding input with out the shifting value with brute force
{
   
    char new_alphabet[LIMIT];
    int cr = 0;// index of copy string
    char strcp[100] = { 0 }; // copy of string
    int counter = 0;// how many letters are passed untill space
    int counter2 = 0;// counter for succesfull cracks
    

    const char two_letter[] = { 'o', 'f', 't', 'o', 'i', 'n', 'i', 't', 'i', 's', 'b', 'e', 'a', 's', 'a', 't', 's', 'o', 'w', 'e', 'h', 'e', 'b', 'y', 'o', 'r', 'o', 'n', 'd', 'o', 'i', 'f', 'm', 'e', 'm', 'y', 'u', 'p', 'a', 'n', 'g', 'o', 'n', 'o', 'u', 's', 'a', 'm', 'o', 'f', 't', 'o', 'i', 'n', 'i', 't', 'i', 's', 'b', 'e', 'a', 's', 'a', 't', 's', 'o', 'w', 'e', 'h', 'e', 'b', 'y', 'o', 'r', 'o', 'n', 'd', 'o', 'i', 'f', 'm', 'e', 'm', 'y', 'u', 'p', 'a', 'n', 'g', 'o', 'n', 'o', 'u', 's', 'a', 'm', 'o', 'f', 't', 'o', 'i', 'n', 'i', 't', 'i', 's', 'b', 'e', 'a', 's', 'a', 't', 's', 'o', 'w', 'e', 'h', 'e', 'b', 'y', 'o', 'r', 'o', 'n', 'd', 'o', 'i', 'f', 'm', 'e', 'm', 'y', 'u', 'p', 'a', 'n', 'g', 'o', 'n', 'o', 'u', 's', 'a', 'm',' ' };
    const char three_letter[] = { 't', 'h', 'e', 'a', 'n', 'd', 'f', 'o', 'r', 'a', 'r', 'e', 'b', 'u', 't', 'n', 'o', 't', 'y', 'o', 'u', 'a', 'l', 'l', 'a', 'n', 'y', 'c', 'a', 'n', 'h', 'a', 'd', 'h', 'e', 'r', 'w', 'a', 's', 'o', 'n', 'e', 'o', 'u', 'r', 'o', 'u', 't', 'd', 'a', 'y', 'g', 'e', 't', 'h', 'a', 's', 'h', 'i', 'm', 'h', 'i', 's', 'h', 'o', 'w', 'm', 'a', 'n', 'n', 'e', 'w', 'n', 'o', 'w', 'o', 'l', 'd', 's', 'e', 'e', 't', 'w', 'o', 'w', 'a', 'y', 'w', 'h', 'o', 'b', 'o', 'y', 'd', 'i', 'd', 'i', 't', 's', 'l', 'e', 't', 'p', 'u', 't', 's', 'a', 'y', 's', 'h', 'e', 't', 'o', 'o', 'u', 's', 'e',' ' };
    const char four_letter[] = { 't', 'h', 'a', 't', 'w', 'i', 't', 'h', 'h', 'a', 'v', 'e', 't', 'h', 'i', 's', 'w', 'i', 'l', 'l', 'y', 'o', 'u', 'r', 'f', 'r', 'o', 'm', 't', 'h', 'e', 'y', 'k', 'n', 'o', 'w', 'w', 'a', 'n', 't', 'b', 'e', 'e', 'n', 'g', 'o', 'o', 'd', 'm', 'u', 'c', 'h', 's', 'o', 'm', 'e', 't', 'i', 'm', 'e','a','b','o','u','t','l','i','k','e',' ' };
    // this 3 arrays are for brute force attack. They are our dict. We can expand our list for  more succesfull output

    for (int i = 0; string[i] != '\0'; ++i)//  moving in user input string
    {

        if (string[i] != ' ')// counting how many  letter passed until space is entered
        { 

            strcp[cr++] = string[i];
            ++counter;

        }
        else // if  we find space
        {

            cr = 0;// I am resetting the string copy's cursor. Because i don't want to get lost in the  array
            if (counter == 2)// if we caught two letter word
            {
                for (int j = 0; j < LIMIT; ++j) // Because there can only b [1,25] different shifting value we will try all of them
                {

                    crt_new_alphabet(alpha, new_alphabet, j); // Because i'll use new alphabet i have to create it
                    decode(new_alphabet, alpha, strcp, j);// i am trying to decode with the current lap 

                    for (int s = 0; two_letter[s] != ' '; s += 2) // we are going to move in the two letter word list
                    {

                        if (strcp[0] == two_letter[s] && strcp[1] == two_letter[s + 1])// if we can match the decoded string and word list
                        {
                            g_results[counter2++] = LIMIT - j;

                            break;// if we managed to  crack the  word doesn't try to crack it again. Some times it can cause problem

                        }
                    }

                    crt_new_alphabet(alpha, new_alphabet, LIMIT - j);// Now prev we changed the our encoded alphabet and our strcp
                    //we have take it back what've done
                    encode(alpha, new_alphabet, strcp, LIMIT - j);
                }


            }
            else if (counter == 3)// same thing
            {
                for (int j = 0; j < LIMIT; ++j)
                {
                    crt_new_alphabet(alpha, new_alphabet, j);
                    decode(new_alphabet, alpha, strcp, j);

                    for (int s = 0; three_letter[s] != ' '; s += 2)
                    {
                        if (strcp[0] == three_letter[s] && strcp[1] == three_letter[s + 1] && strcp[2] == three_letter[s + 2])
                        {
                            g_results[counter2++] = 26 - j;

                            break;

                        }
                    }


                    crt_new_alphabet(alpha, new_alphabet, LIMIT - j);
                    encode(alpha, new_alphabet, strcp, LIMIT - j);
                }

            }
            else if (counter == 4)// same thing
            {
                for (int j = 0; j < LIMIT; ++j)
                {

                    crt_new_alphabet(alpha, new_alphabet, j);
                    decode(new_alphabet, alpha, strcp, j);

                    for (int s = 0; four_letter[s] != ' '; s += 2)
                    {
                        if (strcp[0] == four_letter[s] && strcp[1] == four_letter[s + 1] && strcp[2] == four_letter[s + 2] && strcp[3] == four_letter[s + 3])
                        {
                            g_results[counter2++] = 26 - j;

                            break;



                        }
                    }
                    crt_new_alphabet(alpha, new_alphabet, LIMIT - j);
                    encode(alpha, new_alphabet, strcp, LIMIT - j);
                }
            }

            counter = 0; // reseting letter counter
        }


    }

    int size = sizeof(g_results) / sizeof(g_results[0]); // creating size value
    for (int i = 0; i < size; ++i)// basic removing duplicate  loop
    {
        for (int j = 1; j < size; ++j)
        {
            if (g_results[i] == g_results[j])
            {
                for (int k = j; k + 1 < size; ++k)
                {
                    g_results[k] = g_results[k + 1];
                }
            }
        }
    }

}
int main()
{
    int shift, choice;// user input shifting value and choice variable
    char new_alphabet[26]; //shifted alphabet
    char alphabet[LIMIT] = { 'a','b' ,'c' ,'d' ,'e' ,'f' ,'g' ,'h' ,'i' ,'j' ,'k' ,'l' ,'m' ,'n' ,'o' ,'p' ,'q' ,'r' ,'s' ,'t' ,'u' ,'v' ,'w' ,'x' ,'y' ,'z' };
    char text[1001];

    printf("1-> Decode\n2-> Encode \n3-> Make a guess\n");//prompting the user
    scanf("%d", &choice);

    if (choice == 1)
    {

        printf("Enter the text(max 1000 char)  ");// prompting
        scanf(" %1000[^\n]s", &text);//scaning the user input

        printf("Enter the shifting value ");
        scanf("%d", &shift);// scanning  shift value
        if (shift < 0)// if shifting value is  below zero 
        {
            shift = shift * -1;
        }

        crt_new_alphabet(alphabet, new_alphabet, shift);

        printf("\nDecoded text ");
        decode(alphabet, new_alphabet, text, shift);
        print_text(text);

    }
    else if (choice == 2)// same but for encoding
    {

        printf("Enter the text(max 1000 char) ");
        scanf(" %1000[^\n]s", &text);

        printf("Enter the shifting value ");
        scanf("%d", &shift);

        if (shift < 0)
        {
            shift = shift * -1;
        }


        crt_new_alphabet(alphabet, new_alphabet, shift);
        encode(alphabet, new_alphabet, text, shift);
        printf("\nEncoded text ");
        print_text(text);
    }
    else
    {

        printf("Enter the text(max 1000 char) please put blank line before pressing enter\n");
        scanf(" %1000[^\n]s", &text);

        for (int f = 0; text[f] != '\0'; ++f) // replacing upper case letters with lower case
        {

            for (int c = 65; c <= 90; ++c)
            {
                if ((int)text[f] == c)
                {
                    text[f] = (char)32 + c;
                }
            }

        }

        guesser(text, alphabet);// calling the funciton
        if (g_results[0] == NULL)
        {
            printf("We couldn't be able to crack the code\n");
        }
        else
        {
            printf("\nOur Gueses(s) are\n");
            for (int i = 0; g_results[i] != '\0'; ++i)// for printing the every result
            {
                crt_new_alphabet(alphabet, new_alphabet, 26 + g_results[i]);
                decode(alphabet, new_alphabet, text, 26 + g_results[i]);
                printf("\nDecrpyted text\n");
                print_text(text);
                printf("\n\nOur alphabet is\n");
                print_alph(new_alphabet);

                if (g_results[i] == 26)
                {
                    printf("\n\nA -> A  0\n");
                }
                else
                {

                    printf("\n\nA -> %c  %d\n", (65 + g_results[i] % 65), ((65 + g_results[i]) % 65));

                }
                printf("*********************************************************\n");
                encode(alphabet, new_alphabet, text, g_results[i]);
            }
        }
    }
    return 0;
}
