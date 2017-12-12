 1 /*测试程序：该程序用于监控 globalfifo 的可读 可写状态（是否可以非阻塞读写）*/  
 2 #include<stdio.h>  
 3 #include<sys/select.h>  
 4 #include<fcntl.h>  
 5   
 6 #define FIFO_CLEAR 0X1  
 7 #define BUFFER_LEN 20  
 8   
 9 int main(void)  
10 {  
11     int fd, num;  
12     char rd_ch[BUFFER_LEN];  
13     fd_set rfds, wfds; /*读写文件描述符集*/  
14   
15     /*以非阻塞的方式打开 设备文件*/  
16     fd = open("/dev/globalfifo", O_RDONLY | O_NONBLOCK);  
17     if(fd != -1){  
18         /*FIFO 清零*/  
19         //if(ioctl(fd, FIFO_CLEAR, 0) < 0)  
20         //  printf("ioctl command failed\n");  
21   
22         while(1){  
23             FD_ZERO(&rfds); /*清除一个文件描述符集*/  
24             FD_ZERO(&wfds);  
25             FD_SET(fd, &rfds); /*将一个文件描述符 加入 文件描述符集中*/  
26             FD_SET(fd, &wfds);  
27   
28 /*最高文件描述符+1 要监控的 读    写     异常  等待超时返回*/  
29             select(fd + 1, &rfds, &wfds, NULL, NULL); /*该函数最终调用poll*/  
30   
31             /*数据可获得*/  
32             if(FD_ISSET(fd, &rfds))  
33                 printf("Poll monitor:can be read\n");  
34   
35             /*数据可写入*/  
36             if(FD_ISSET(fd, &wfds))  
37                 printf("Poll monitor:can be written\n");  
38         }  
39     }else{  
40         printf("Device open failure\n");  
41     }  
42     return 0;  
43 }  
