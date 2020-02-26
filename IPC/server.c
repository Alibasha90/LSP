#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#define FIFO_FILE "MYFIFO"
int main() {
   int rd;
   char readbuf[80];
   char end[10];
   int to_end;
   int read_bytes;
   
   /* Create the FIFO if it does not exist */
   mknod(FIFO_FILE, S_IFIFO|0666, 0);
   strcpy(end, "end");
   while(1) {
      rd = open(FIFO_FILE, O_RDONLY);
//	strcpy(readbuf," ");
      read_bytes = read(rd, readbuf, sizeof(readbuf));
	if(read_bytes <0)
	{
	perror("read_bytes");
}
printf("retuned:-%d",read_bytes);
      readbuf[read_bytes] = '\0';
      printf("Received string: \"%s\" and length is %d\n", readbuf, (int)strlen(readbuf));
      to_end = strcmp(readbuf, end);
      if (to_end == 0) {
         close(rd);
         break;
      }
   }
   return 0;
}
