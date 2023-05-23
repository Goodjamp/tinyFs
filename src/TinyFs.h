#ifndef __TINY_FS_H__
#define __TINY_FS_H__

#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>


typedef enum {
	TINY_FS_OK,
	TINY_FS_BUFF_ERROR,
	TINY_FS_FS_MEM_NULL_ERROR,
	TINY_FS_FS_MEM_SIZE_ERROR,
	TINY_FS_FS_H_ERROR,
	TINY_FS_CB_WRITE_BUFF_ERROR,
	TINY_FS_CB_READ_BUFF_ERROR,
} TinyFsRez;

typedef struct {
 	uint16_t readPos;
 	uint16_t writePos;
 	uint8_t firstSector;
} TinyFsFile;

typedef struct {
    bool (*writeBuff)(size_t offset,
                            uint8_t *data,
                            size_t dataLen);
    bool (*readBuff)(size_t offset,
                           uint8_t *data,
                           size_t dataLen);
    bool (*lock)(bool lock);
} TinyFsCb;

typedef struct {
    uint8_t *mem;
    uint32_t memSize;
    TinyFsCb cb;
} TinyFsH;

TinyFsRez tinyFsInit(uint8_t *fsMem, size_t fsMemSize,
                     TinyFsCb FsCb, TinyFsH *TinyFsH);
TinyFsRez tinyFsGetLastError(TinyFsH *TinyFsH);
TinyFsRez tinyFsCreateFile(TinyFsH *TinyFsH, uint16_t fileName);
TinyFsRez tinyFsOpenFile(TinyFsH *TinyFsH, uint16_t fileName, TinyFsFile *file);
TinyFsRez tinyFsCloseFile(TinyFsH *TinyFsH, TinyFsFile *file);
             
/**
 * @arg	[in,out] - input: target data size
  output: the number of writed data
 */
TinyFsRez tinyFsWriteFile(TinyFsH *TinyFsH, TinyFsFile *file, uint8_t *data, size_t *dataSize);
              
/**
 * @arg	[in,out] - input: target data size
 *                 output: the number of read data
 */
TinyFsRez tinyFsReadFile(TinyFsH *TinyFsH, TinyFsFile *file, uint8_t *data, size_t *dataSize);
 
#endif
