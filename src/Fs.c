#include <stdint.h>
#include <stdio.h>

#include "Fs.h"

/*
 * FAT entry description
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

FsRez FsGetLastError(void)
{
	printf("fs get last error");
}

FsRez fsInit(uint8_t *fsMem, size_t fsMemSize,
             FsCb fsCb, FsH *fsH)
{
	if(fsMem == NULL)
	{
		return FS_FS_MEM_NULL_ERROR;
	}
	if(fsMemSize == 0)
	{
		return FS_FS_MEM_SIZE_ERROR;
	}
	if(fsH == NULL)
	{
		return FS_FS_H_ERROR;
	}
	if (fsCb.fsWriteBuff == NULL) {
		return FS_CB_WRITE_BUFF_ERROR;
	}
    if (fsCb.fsReadBuff == NULL) {
    	return FS_CB_READ_BUFF_ERROR;
    }

    fsH->fsMem = fsMem;
    fsH->fsMemSize = fsMemSize;
    fsH->cb = fsCb;

    /*
     * The file system  consist of two generic parts: file alocation
     * table and files sectors. Each entry of fat pointed to the one file  sectror.
     * The number of fat entry must be 2 more than number of files sectors. The 2 additional entry caled services entri. Services entry used to save state of FS: init,not init
     */
    
    
}

