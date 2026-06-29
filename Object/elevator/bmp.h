#ifndef BMP_H
#define BMP_H

#include <stdint.h>

#define BMP_CACHE_SIZE  32

typedef struct {
    int width;
    int height;
    uint8_t *data;
} bmp_t;

bmp_t *bmp_load(const char *filename);
void bmp_free(bmp_t *bmp);

int bmp_cache_init(void);
void bmp_cache_destroy(void);
bmp_t *bmp_get_cached(const char *filename);
int bmp_load_all(void);

#endif