#include <stdint.h>
#include <stdio.h>

#include "TinyFs.h"

/*
 * FAT entry description
 *
 * File begin:
 * - Type (1 byte)
 * - File name (2 bytes)
 * - File size (2 bytes)
 * - Next sector address (2 bytes)
 *
 * File next:
 * - Type (1 byte)
 * - Next sector address (2 bytes)
 * - First sector address (2 bytes)
 *
 * File last:
 * - Type (1 byte)
 * - Bytes per sector (2 bytes)
 * - First sector address (2 bytes)
 *
 * File alone:
 * - Type (1 byte)
 * - File name (2 bytes)
 * - File size (2 bytes)
 * 
 * +------+-----------------------------------+
 * | size |   description                     |
 * +------+-----------------------------------+
 * |  1   | Sector status: empty, file begin, |
*  +      +                                   +
 * |      | file next, file last, file alone  |
 * +------+-----------------------------------+
 * |   2  | Bytes per sector                  |
 * +------+-----------------------------------+
 * |  3   | Next sector index                 |
 * +------+-----------------------------------+
 * |  4   | File name                         |
 * +------+-----------------------------------+
 * |  5   | File size                         |
 * +------+-----------------------------------+
 */

TinyFsRez FsGetLastError(void)
{
	printf("fs get last error");
}

TinyFsRez fsInit(uint8_t *fsMem, size_t fsMemSize,
                 TinyFsCb fsCb, TinyFsH *fsH)
{
	if(fsMem == NULL)
	{
		return TINY_FS_FS_MEM_NULL_ERROR;
	}
	if(fsMemSize == 0)
	{
		return TINY_FS_FS_MEM_SIZE_ERROR;
	}
	if(fsH == NULL)
	{
		return TINY_FS_FS_H_ERROR;
	}
	if (fsCb.writeBuff == NULL) {
		return TINY_FS_CB_WRITE_BUFF_ERROR;
	}
    if (fsCb.readBuff == NULL) {
    	return TINY_FS_CB_READ_BUFF_ERROR;
    }

    fsH->mem = fsMem;
    fsH->memSize = fsMemSize;
    fsH->cb = fsCb;

    /*
     * The file system  consist of two generic parts: file alocation
     * table and files sectors. Each entry of fat pointed to the one file  sectror.
     * The number of fat entry must be 2 more than number of files sectors. The 2 additional entry caled services entri. Services entry used to save state of FS: init,not init
     */
    
    
}

