#include"main.h"
#include"slist.h"

extern pid_t pid;

void signal_handler(int sig_num)
{
   if(pid > 0) //if child exsists
   {
       //use kill system call to send signal to child
       if(sig_num == SIGINT)
       {
           kill(pid,SIGKILL);
       }
       else if(sig_num == SIGTSTP)
       {
           kill(pid,SIGSTOP);
       }
   }
}
