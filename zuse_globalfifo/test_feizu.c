 1 /*���Գ��򣺸ó������ڼ�� globalfifo �Ŀɶ� ��д״̬���Ƿ���Է�������д��*/  
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
13     fd_set rfds, wfds; /*��д�ļ���������*/  
14   
15     /*�Է������ķ�ʽ�� �豸�ļ�*/  
16     fd = open("/dev/globalfifo", O_RDONLY | O_NONBLOCK);  
17     if(fd != -1){  
18         /*FIFO ����*/  
19         //if(ioctl(fd, FIFO_CLEAR, 0) < 0)  
20         //  printf("ioctl command failed\n");  
21   
22         while(1){  
23             FD_ZERO(&rfds); /*���һ���ļ���������*/  
24             FD_ZERO(&wfds);  
25             FD_SET(fd, &rfds); /*��һ���ļ������� ���� �ļ�����������*/  
26             FD_SET(fd, &wfds);  
27   
28 /*����ļ�������+1 Ҫ��ص� ��    д     �쳣  �ȴ���ʱ����*/  
29             select(fd + 1, &rfds, &wfds, NULL, NULL); /*�ú������յ���poll*/  
30   
31             /*���ݿɻ��*/  
32             if(FD_ISSET(fd, &rfds))  
33                 printf("Poll monitor:can be read\n");  
34   
35             /*���ݿ�д��*/  
36             if(FD_ISSET(fd, &wfds))  
37                 printf("Poll monitor:can be written\n");  
38         }  
39     }else{  
40         printf("Device open failure\n");  
41     }  
42     return 0;  
43 }  
