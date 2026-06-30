#include "bmp.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static bmp_t *bmp_cache[BMP_CACHE_SIZE];
static int bmp_cache_count = 0;

bmp_t *bmp_load(const char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (!fp) {
        fprintf(stderr, "[BMP] Error: Cannot open %s\n", filename);
        return NULL;
    }

    uint8_t header[54];
    if (fread(header, 1, 54, fp) != 54) {
        fprintf(stderr, "[BMP] Error: Cannot read header from %s\n", filename);
        fclose(fp);
        return NULL;
    }

    if (header[0] != 'B' || header[1] != 'M') {
        fprintf(stderr, "[BMP] Error: Not a valid BMP file %s\n", filename);
        fclose(fp);
        return NULL;
    }

    int img_w = *(int*)&header[18];
    int img_h = *(int*)&header[22];
    int bit_count = *(short*)&header[28];
    int data_off = *(int*)&header[10];

    if (bit_count != 24 && bit_count != 32) {
        fprintf(stderr, "[BMP] Error: Unsupported bpp %d in %s (expected 24 or 32)\n", 
                bit_count, filename);
        fclose(fp);
        return NULL;
    }

    bmp_t *bmp = (bmp_t *)malloc(sizeof(bmp_t));
    if (!bmp) {
        fclose(fp);
        return NULL;
    }

    bmp->width = img_w;
    bmp->height = img_h;
    bmp->data = (uint8_t *)malloc(img_w * img_h * 4);
    if (!bmp->data) {
        free(bmp);
        fclose(fp);
        return NULL;
    }

    fseek(fp, data_off, SEEK_SET);
    int row_size = ((img_w * bit_count / 8 + 3) / 4) * 4;
    uint8_t *row_buf = (uint8_t *)malloc(row_size);

    for (int y = 0; y < img_h; y++) {
        if (fread(row_buf, 1, row_size, fp) != (size_t)row_size) {
            free(row_buf);
            bmp_free(bmp);
            fclose(fp);
            return NULL;
        }

        for (int x = 0; x < img_w; x++) {
            int src_idx = x * (bit_count / 8);
            int dst_idx = (y * img_w + x) * 4;

            bmp->data[dst_idx + 0] = row_buf[src_idx + 0];
            bmp->data[dst_idx + 1] = row_buf[src_idx + 1];
            bmp->data[dst_idx + 2] = row_buf[src_idx + 2];
            bmp->data[dst_idx + 3] = (bit_count == 32) ? row_buf[src_idx + 3] : 0xFF;
        }
    }

    free(row_buf);
    fclose(fp);
    
    printf("[BMP] Loaded %s: %dx%d, %d bpp\n", filename, img_w, img_h, bit_count);
    return bmp;
}

void bmp_free(bmp_t *bmp) {
    if (!bmp) return;
    if (bmp->data) {
        free(bmp->data);
        bmp->data = NULL;
    }
    free(bmp);
}

int bmp_cache_init(void) {
    bmp_cache_count = 0;
    for (int i = 0; i < BMP_CACHE_SIZE; i++) {
        bmp_cache[i] = NULL;
    }
    return 0;
}

void bmp_cache_destroy(void) {
    for (int i = 0; i < bmp_cache_count; i++) {
        if (bmp_cache[i]) {
            bmp_free(bmp_cache[i]);
            bmp_cache[i] = NULL;
        }
    }
    bmp_cache_count = 0;
}

bmp_t *bmp_get_cached(const char *filename) {
    for (int i = 0; i < bmp_cache_count; i++) {
        if (bmp_cache[i]) {
            return bmp_cache[i];
        }
    }
    return NULL;
}

int bmp_load_all(void) {
    bmp_cache_init();
    return 0;
}