#include<stdio.h>
#include<stdlib.h>

#define MAX_STR_LEN 1024
#define BLACK_LIST_SIZE 10

int find_substring(char source_string[MAX_STR_LEN], char query[MAX_STR_LEN])
{
   // This function determines whether a query string is present anywhere within
   // the source_string. If the query string is found, it returns 1, otherwise it
   // returns 0

   int length = 0;
   int email_length = 0;
   int found = 0;
   
   if (query[0] == '\0') return 0;
   
   // Length of query
   while (query[length] != '\0')
   {
	   length++;
   }
   // length of source_string
   while (source_string[email_length] != '\0')
   {
	   
	   email_length++;
   }
   // check each letter of source_string
   for (int i = 0; i < email_length-length+1; i++)
   {
	   // If the first letter is the same
	   if (source_string[i] == query[0])
	   {
		   found = 1;
		   // Check the next few letters (up to length)
		   for (int j = 0; j < length; j++)
		   {
			   // If one letter is not the same 
			   if (source_string[i+j] != query[j])
			   {
				   found = 0;
				   break;
			   }
		   }
		   if (found)
			   break;
	   }
   }
   return found;
}

int filter_message(char message_header[MAX_STR_LEN], char black_list[BLACK_LIST_SIZE][MAX_STR_LEN])
{
   // This function takes the header of an incoming email, and uses a black list to
   // determine whether to accept or reject the email. A message is rejected if any
   // of the black-listed keywords appear in the header.
   // The function returns 1 if the message should be rejected,
   //                      0 if the message should be accepted.
  
  for (int i = 0; i < BLACK_LIST_SIZE; i++){
	  if (find_substring(message_header, black_list[i])){
		  return 1;
	  }
  }
  return 0;
}

#ifndef __testing

int main()
{
    // Initialize black-list - normally, we'd read it from file but we haven't
    // done files in C yet! keep in mind we will  test your program on a different
    // black list, so test carefully!
    char black_list[BLACK_LIST_SIZE][MAX_STR_LEN]={"IMPORTANT",\
						   "ad",\
						   "online",\
						   "scam",\
						   "password",\
						   "account",\
						   "free",\
						   "profile",\
						   "dating",\
						   "prescription"
    };
    
    if (filter_message("This is a harmless email",black_list))
    {
        printf("Rejected!\n");
    }
    else
    {
        printf("Accepted\n");
    }

    if (filter_message("This is a scam! please send me to the inbox!",black_list))
    {
        printf("Rejected!\n");
    }
    else
    {
        printf("Accepted\n");
    }
    if (filter_message("How about some free online prescriptions?",black_list))
    {
        printf("Rejected!\n");
    }
    else
    {
        printf("Accepted\n");
    }
    if (filter_message("Give us your password!",black_list))
    {
        printf("Rejected!\n");
    }
    else
    {
        printf("Accepted\n");
    }
    if (filter_message("A48 assignment IMPORTANT! PLEASE READ! ",black_list))
    {
        printf("Rejected!\n");
    }
    else
    {
        printf("Accepted\n");
    }
    if (filter_message("Some funny pictures of cats",black_list))
    {
        printf("Rejected!\n");
    }
    else
    {
        printf("Accepted\n");
    }
    if (filter_message("Your bank account statement is ready",black_list))
    {
        printf("Rejected!\n");
    }
    else
    {
        printf("Accepted\n");
    }
    return 0;
}
#endif
