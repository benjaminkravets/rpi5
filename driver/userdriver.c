#include <stdio.h>     // for printf, perror
#include <stdint.h>    // for uint32_t
#include <fcntl.h>     // for open, O_RDWR, O_SYNC
#include <sys/mman.h>  // for mmap, PROT_READ, PROT_WRITE, MAP_SHARED, MAP_FAILED
#include <sys/types.h> // for off_t (optional, but good practice)
#include <sys/stat.h>  // for open
#include <unistd.h>    // for close
#include <errno.h>     // for errno
#include <string.h>    // for strerror

int main()
{
    int memfd = open("/dev/mem", O_RDWR | O_SYNC);

    uint32_t *map = (uint32_t *)mmap(
        NULL,
        64 * 1024 * 1024,
        (PROT_READ | PROT_WRITE),
        MAP_SHARED,
        memfd,
        0x1f00000000);
    if (map == MAP_FAILED)
    {
        printf("mmap failed: %s\n", strerror(errno));
        return (-1);
    };
    close(memfd);
}
