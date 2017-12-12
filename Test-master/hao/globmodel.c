#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include<linux/fcntl.h>

int main() {
	int fd;
	char buf1[]="testglobalmen data!";//写入memdev设备的内容
	char buf_read[4096]; //memdev设备的内容读入到该buf中

	if((fd=open("/dev/globalmem0",O_RDWR))==-1) { //打开memdev设备
		printf("open globalmem0 WRONG！\n");
		return 0;
	}

	int count = 0;
	while(count<=100) {
		printf("openglobalmem0 SUCCESS!\n");
		printf("buf is %s\n",buf1);
		write(fd,buf1,sizeof(buf1));//把buf中的内容写入memdev设备
		lseek(fd,0,SEEK_SET); //把文件指针重新定位到文件开始的位置
		read(fd,buf_read,sizeof(buf1));//把memdev设备中的内容读入到buf_read中
		printf("buf_read is %s\n",buf_read);
		count++;
	}

	close(fd);
	return 0;
}
