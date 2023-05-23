#ifndef __FS_H__
#define __FS_H__

#include <stdint.h>
#include <stdbool.h>


typedef enum {
	FS_OK,
	FS_BUFF_ERROR,
	FS_FS_MEM_NULL_ERROR,
	FS_FS_MEM_SIZE_ERROR,
	FS_FS_H_ERROR,
	FS_CB_WRITE_BUFF_ERROR,
	FS_CB_READ_BUFF_ERROR,
} FsRez;

typedef struct {
 	uint16_t readPos;
 	uint16_t writePos;
 	uint8_t firstSector;
} FsFile;

typedef struct {
    bool (*fsWriteBuff)(size_t offset,
                        uint8_t *data,
                        size_t dataLen);
    bool (*fsReadBuff)(size_t offset,
                       uint8_t *data,
                       size_t dataLen);
    bool (*fsLock)(bool lock);
} FsCb;

typedef struct {
    uint8_t *fsMem;
    uint32_t fsMemSize;
    FsCb cb;
} FsH;

FsRez fsInit(uint8_t *fsMem, size_t fsMemSize,
             FsCb FsCb, FsH *fsH);
FsRez fsGetLastError(FsH *fsH);
FsRez fsCreateFile(FsH *fsH, uint16_t fileName);
FsRez fsOpenFile(FsH *fsH, uint16_t fileName, FsFile *file);
FsRez fsCloseFile(FsH *fsH, FsFile *file);
             
/*!
 * \arg	[in,out] - input: target data size
  output: the number of writed data
 */
FsRez fsWriteFile(FsH *fsH, FsFile *file, uint8_t *data, size_t *dataSize);
              
/*!
 * \arg	[in,out] - input: target data size
 *                 output: the number of read data
 */
FsRez fsReadFile(FsH *fsH, FsFile *file, uint8_t *data, size_t *dataSize);
 
#endif
