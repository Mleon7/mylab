#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

#define BLOCK_SIZE 512
// const int BLOCK_SIZE = 512;

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    // 你的程序应该接受正好一个命令行参数，即要从中恢复JPEG图像的法庭图像的名称。
    // 如果你的程序没有正好执行一个命令行参数，它应该提醒用户正确的使用方法，并且主函数应该返回1。
    // $ ./recover
    // Usage: ./recover IMAGE

    if (argc != 2)
    {
        printf("Usage: ./recover IMAGE\n");
        return 1;
    }

    // 如果无法打开法庭图像进行读取，你的程序应该向用户提供相应信息，并且主函数应该返回1。
    FILE *input = fopen(argv[1], "r");
    if (input == NULL)
    {
        printf("Could not open %s.\n", argv[1]);
        return 1;
    }

    BYTE buff[BLOCK_SIZE];
    FILE *output = NULL;
    char filename[8];
    int jpgcnt = 0;
    // int begin = FALSE;

    // 2023-06-19
    // 参考：https://github.com/mancuoj/CS50x/blob/master/Week4/2-recover.c
    // 败在读懂题意上了
    // 题意是：一旦发现了以 ff d8 ff e* 开头的，就是jpeg图片的开头，那到什么时候结束呢？
    // 下一张图片的开始就是上一张图片的结束！这样一直到最后。(我没看懂的题意就在这了)
    // 也就是说，只要找到第一张jpeg图片，接下来的全是jpeg图片

    // cs50中文件操作函数：fopen, fclose, fread, fwrite 

    while (fread(&buff, BLOCK_SIZE, 1, input))
    {
        if (buff[0] == 0xff && buff[1] == 0xd8 && buff[2] == 0xff && (buff[3] & 0xf0) == 0xe0)
        {
            // 最开始cnt为0，还未打开output_file
            // 打开第1个output_file后，cnt不再为0
            // 而且在这个if中，要开始写入一个新的jpg，就需要关闭上一个打开的jpg
            if (jpgcnt)
            {
                fclose(output);
            }
            // 你生成的文件应该分别命名为###.jpg，其中###是一个三位数的十进制数，从第一张图像的000开始递增。
            sprintf(filename, "%03d.jpg", jpgcnt);
            jpgcnt++;
            output = fopen(filename, "w");
            // 打开新的jpg
            // 这里不需要write，因为下面的if中会写
        }
        if (jpgcnt)
        {
            fwrite(&buff, BLOCK_SIZE, 1, output);
        }
    }

    fclose(input);
    fclose(output); // 最后一个jpg还没关闭，因此这里要关闭最后的jpg
}