 #include <stdlib.h>
 #include <stdio.h>
 #include <getopt.h>
 #include <unistd.h>
 #include <sys/types.h>
 #include <sys/wait.h>
 #include <string.h>

  int main(int argc, char *argv[])
 {
 int value, count,  status;
 int pid, p[2];
 FILE *fd;
 FILE *fd1;
 if(argc < 3)
 { 
 printf("need atleast 3 agrumetn");
 exit(1);
 }
 if (argc < 4)
 {
 for ( value =1; value < (argc -1); value++)
 if (pipe(p) == -1)
 {
 perror("error");
 exit(1);
 }
 pid = fork();

 if (pid == 0)
 {//child
 close(p[1]);
 dup2(p[0],0);
 char *arg[] = {"/usr/bin/cat", "-b"};
 close(p[0]);
 execl(arg[0], arg[0], arg[1], argv[1], NULL);
 }
 else
 { //parent
 close(p[0]);
 dup2(p[1],1);
 close(p[1]);
fd = fopen(argv[1], "r");
if (!fd )
{ fprintf(stderr, "error");
exit(1);
}
fd1= fopen(argv[2], "w");
if(!fd1)
{
fprintf(stderr, "error");
exit(1);
}
while(((count=fgetc(fd))) != EOF )
{
fprintf(stdout, "%c", count);
fputc(count, fd1);
}
fclose(fd);
fclose(fd1);
 wait(&status);
 }
 
 }
 return 0;
 }
