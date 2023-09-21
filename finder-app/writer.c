#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// #include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <syslog.h>




int main(int argsNumber, char * argsString[]){

    openlog("Assignment2-log", LOG_PID, LOG_USER);

    if(argsNumber != 3){
        printf("Error: incorrect number of arguments.Your command should looklike something like this:\n");
        printf("%s /path/to/write/directory your_write_string\n", argsString[0]);

        syslog(LOG_ERR, "Error: incorrect number of arguments.");
        
        return 1;
    }

    // Saving user arguments (full file path and write string)
    const char *writeFileDir = argsString[1];
    const char *writeStr = argsString[2];


    // Creating file and writing the new data to it. (overwriting)
    FILE *file2 = fopen(writeFileDir, "w"); 
    if (file2 == NULL) {
        printf("Error:Failed to create the file: %s\n", writeFileDir);
        syslog(LOG_ERR, "Error: Failed to create the file: %s", writeFileDir);
        return 1;
    }else{
        printf("The file %s was created successfully\n", writeFileDir);
        syslog(LOG_DEBUG, "The file: %s was created successfully", writeFileDir);
    }

    // Writing "writeStr" to the file
    if (fprintf(file2, "%s", writeStr) < 0) {
        printf("Error writing to file\n");
        syslog(LOG_ERR, "Error writing to file");
        return 1;
    }else{
        printf("The value (%s) was successfully written to the file: %s\n", writeStr, writeFileDir);
        syslog(LOG_DEBUG, "The value (%s) was successfully written to the file: %s", writeStr, writeFileDir);
    }

    // Closing the file
    if (fclose(file2) != 0) {
        printf("Error closing file\n");
        syslog(LOG_ERR, "Error closing file");
        return 1;
    }else{
        printf("The file %s was closed successfully\n", writeFileDir);
        syslog(LOG_DEBUG, "The file: %s was closed successfully", writeFileDir);
    }

    closelog();

    return 0;
}