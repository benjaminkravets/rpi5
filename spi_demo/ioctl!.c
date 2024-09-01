#include <stdint.h>
#include <linux/spi/spidev.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <linux/spi/spi.h>

int spifd;
static uint8_t mode =  SPI_MODE_3;
static uint8_t bits = 8;
static uint32_t speed = 200000000;

// the buffer looks like this because the logic analyzer that i use only goes up to 24MHz
uint8_t buf[] = {0xFF,0xFF,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0xFF};

int main(){

    spifd = open("/dev/spidev0.0",O_RDWR);
    
    ioctl(spifd, SPI_IOC_WR_MODE, &mode);
    
    ioctl(spifd, SPI_IOC_WR_BITS_PER_WORD, &bits);
    
    ioctl(spifd, SPI_IOC_WR_MAX_SPEED_HZ, &speed);
    
    struct spi_ioc_transfer tr = {
        .tx_buf = (uint64_t)&buf,
        .rx_buf = (uint64_t)&buf,
        .len = (uint32_t)sizeof(buf),
        .speed_hz = speed,
        .delay_usecs = 0,
        .bits_per_word = bits,
    };

    ioctl(spifd, SPI_IOC_MESSAGE(1), &tr);
}