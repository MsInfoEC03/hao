#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include<linux/fcntl.h>

int main() {
	int fd;
	char buf1[]="testglobalmen data!";//д��memdev�豸������
	char buf_read[4096]; //memdev�豸�����ݶ��뵽��buf��

	if((fd=open("/dev/globalmem0",O_RDWR))==-1) { //��memdev�豸
		printf("open globalmem0 WRONG��\n");
		return 0;
	}

	int count = 0;
	while(count<=100) {
		printf("openglobalmem0 SUCCESS!\n");
		printf("buf is %s\n",buf1);
		write(fd,buf1,sizeof(buf1));//��buf�е�����д��memdev�豸
		lseek(fd,0,SEEK_SET); //���ļ�ָ�����¶�λ���ļ���ʼ��λ��
		read(fd,buf_read,sizeof(buf1));//��memdev�豸�е����ݶ��뵽buf_read��
		printf("buf_read is %s\n",buf_read);
		count++;
	}

	close(fd);
	return 0;
}
