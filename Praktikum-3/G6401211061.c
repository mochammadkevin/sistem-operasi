/*
Shell
=====
Shell adalah program yang membuat proses child untuk menjalankan string perintah yang diberikan.
Shell berupa infinite looping yang berisi siklus fork--exec--wait.
Lengkapilah kode berikut ini untuk membuat program shell sederhana!
Contoh masukan dan keluaran
---------------------------
    $ date
    Tue Dec  9 13:34:17 WIB 2014
    $ whoami
    auriza
    $ exit
*/

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

// pecah string per kata
void split_words(char *string, char **words)
{
    int i;
    words[0] = strtok(string, " \n");
    for (i = 0; words[i]; i++)
        words[i+1] = strtok(NULL, " \n");
}

int main()
{
    char cmd[80];                           
    char *args[20];                         

    while (1)
    {
        printf("$ ");                       //  cetak prompt "$ "
        
        fgets(cmd, 80, stdin);              //  baca string perintah
        
        split_words(cmd, args);             //  pecah string perintah per argumen
         
        if (strcmp(args[0], "exit") == 0)   //  jika perintah = "exit"
            break;                          //  break
        
        if (strcmp(args[0], "cd") == 0)     //  jika perintah = "cd"
        {
            chdir(args[1]);                 //  ganti direktori
            continue;                       //  continue
        }

        pid_t pid;                          //  buat proses child:
        pid = fork();
        if (pid == 0)
        {
            execvp(args[0], args);          //  exec string perintah
            perror(args[0]);                //  cetak pesan error
            return -1;                      //  keluar dengan kode -1
        }
        else
            wait(NULL);                     //  tunggu child selesai
    }

    return 0;
}