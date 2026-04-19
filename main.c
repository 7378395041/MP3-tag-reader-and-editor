/*Authu Name : akash mahajan
project name : MP3 tag reader and editor
description : Implemented a C program that reads and edits MP3 metadata stored in ID3v1 format.
used file handling functions to access the last 128 bytes and modify specific fields without
corrupting the audio file.”*/

# include <stdio.h>
# include <string.h>
# include "main.h"

int main(int argc, char *argv[])
{

    if(argc > 1)
    {
        char *str = argv[1];
        printf("%s\n",str);

        if(strcmp(str, "--help") == 0)
        {
            help_menu();
        }
        else if(strcmp(str, "-v") == 0)
        {
            char *mp3_file = argv[2];
            FILE *fp = fopen(mp3_file, "rb+");
            if(fp == NULL)
            { 
                printf("file not created");
            }
            fseek(fp, -128, SEEK_END);
            char buffer[128];
            fread(buffer, 1, 128, fp);
            //check this is mp3
           if(strncmp(buffer, "TAG", 3) == 0)
            {
                view_details(buffer);
            }
           else
            {
                printf("ID3 INVALID\n");
            }
        }
       
        else if(strcmp(str, "-e") == 0)
        {
           
            char *to_edit = argv[2];
            char *content = argv[3];
            char *mp3_file = argv[4];
            edit_mp3_tag(mp3_file, content, to_edit);
        }
    }
    else
    {
        printf("----------------------------------------------------------------------\n");
        printf("ERROR: ./a.out : INVALID ARGUMENT\n");
        printf("USAGE : \nTO view please pass like: ./a.out -v mp3filename\nTO edit please pass like: ./a.out -e -t/-a/-A/-m/-y/-c chaging_text mp3file\n");
        printf("TO get help pass like : ./a.out --help\n");
        printf("----------------------------------------------------------------------\n");
    }
}
