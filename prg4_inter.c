 #include <stdio.h>
   #include <stdlib.h>
    #include <fcntl.h>
    #include <sys/stat.h>
    #include <sys/types.h>
    #include <unistd.h>
    int main() {
    char *fifoFile = "myfifo"; 
    mkfifo(fifoFile, 0666); 
    int fd = open(fifoFile, O_WRONLY); 
    if (fd ==-1) {
    perror("Error opening FIFO");  
   exit(EXIT_FAILURE); 
    }
    char message[] = "Hello, Reader!"; 
    write(fd, message, sizeof(message)); 
    close(fd); 
    printf("Message sent to the reader: %s\n", message);
    return 0;
    
   }
  //reader.c (Reader Process)
    #include <stdio.h>
    #include <stdlib.h>
   #include <fcntl.h>
    #include <sys/stat.h>
    #include <sys/types.h>
    #include <unistd.h>
    int main() {
    char *fifoFile = "myfifo";
   mkfifo(fifoFile, 0666);
    int fd = open(fifoFile, O_RDONLY); 
    if (fd ==-1) {
    perror("Error opening FIFO"); 
    exit(EXIT_FAILURE); 
    }
    char message[100]; 
    read(fd, message, sizeof(message)); 
    printf("Message received from the writer: %s\n", message);
    close(fd); 
    return 0;
    }
