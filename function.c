# include <stdio.h>
# include <string.h>
# include "main.h"

//this hepl menu
void help_menu()
{
    printf("-----------------------------HELP MENU----------------------------------\n");
    printf("1. -v -> to view mp3 file contents\n");
    printf("2. -e -> to edit mp3 file contents\n");
    printf("\t 2.1. -t -> to edit song title\n \t 2.2. -a -> to edit artist name\n \t 2.3. -A -> to edit album name\n \t 2.4. -y -> to edit year\n \t 2.5. -m -> to edit content\n \t 2.1. -c -> to edit comment \n");
    printf("---------------------------------------------------------------------------\n");
}

// funtion to disply details of mp3
int view_details(char *buffer)
{
    char title[31], artist[31], album[31], year[5], genre[2], comment[31];
    strncpy(title, buffer + 3, 30);
    title[30] = '\0';
    strncpy(artist, buffer + 33, 30);
    artist[30] = '\0';
    strncpy(album, buffer + 63, 30);
    album[30] = '\0';
    strncpy(year, buffer + 93, 4);
    year[4] = '\0';
    strncpy(comment, buffer + 97, 30);
    comment[30] = '\0';
    strncpy(genre, buffer + 126, 1);
    genre[1] = '\0';
    
    printf("-------------------------SELECTED VIEW DETAILS--------------------------\n\n");
    printf("------------------------------------------------------------------------\n");
    printf("              MP3 TAG READER AND EDITOR FOR ID3v2\n");
    printf("-------------------------------------------------------------------------\n");
    printf("TITLE           :          %s \n", title);
    printf("ARTIST          :          %s \n", artist);
    printf("ALBUM           :          %s \n", album);
    printf("YEAR            :          %s \n", year);
    printf("COMMENT         :          %s \n", comment);
    printf("GENRE           :          %s \n", genre);
    printf("-------------------------------------------------------------------------\n\n");
    printf("-------------------DETAILS DISPLAYED SUCCESSFULLY------------------------\n");
}

// functiont to edit details of mp3
void edit_mp3_tag(char *mp3_file, char *content, char *to_edits)
{
    printf("------------------------SELECTED DETAILS EDIT-----------------------------\n");
    FILE *fp1 = fopen(mp3_file, "rb+");
    if(fp1 == NULL)
    {
        printf("File not found\n");
        return;
    }
    char buffer[30] = {0};
    fseek(fp1, -128, SEEK_END);
    if(strcmp(to_edits, "-t") == 0)
    {
        fseek(fp1, 3, SEEK_CUR);
        strncpy(buffer, content, 30);
        fwrite(buffer , 1, 30, fp1);
        printf("SUCESSFULLY EDIT TITLE\n");
    }
    else if(strcmp(to_edits, "-a") == 0)
    {
        fseek(fp1, 33, SEEK_CUR);
        strncpy(buffer, content, 30);
        fwrite(buffer , 1, 30, fp1);
        printf("SUCESSFULLY EDIT ARTIST\n");
    }
    else if(strcmp(to_edits, "-A") == 0)
    {
        fseek(fp1, 63, SEEK_CUR);
        strncpy(buffer, content, 30);
        fwrite(buffer , 1, 30, fp1);
        printf("SUCESSFULLY EDIT ALBUM\n");
    }
    else if(strcmp(to_edits, "-y") == 0)
    {
        fseek(fp1, 93, SEEK_CUR);
        strncpy(buffer, content, 30);
        fwrite(buffer , 1, 4, fp1);
        printf("SUCESSFULLY EDIT YEAR\n");
    }
    else if(strcmp(to_edits, "-c") == 0)
    {
        fseek(fp1, 97, SEEK_CUR);
        strncpy(buffer, content, 30);
        fwrite(buffer , 1, 30, fp1);
        printf("SUCESSFULLY EDIT COMMENT\n");
    }
    else if(strcmp(to_edits, "-g") == 0)
    {
        fseek(fp1, 126, SEEK_CUR);
        strncpy(buffer, content, 30);
        fwrite(buffer , 1, 1, fp1);
        printf("SUCESSFULLY EDIT GENRE\n\n");
    }
    fclose(fp1);
    printf("-------------------------------------------------------------------------\n"); 
}
    