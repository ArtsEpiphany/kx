#ifndef _GLOBAL_H_
#define _GLOBAL_H_
#define UID_UID_TYPE unsigned long long int
#define UID_CID_TYPE char
#define UID_UID_BITS (sizeof(UID_UID_TYPE)<<3)
#define UID_CID_BITS (4)
#define UID_NUM (UID_UID_BITS/UID_CID_BITS)
#define UID_UID_LENGTH (4)
#define UID_CID_LENGTH (UID_UID_LENGTH*UID_NUM)
#define FILE_D_TYPE char
#define FILE_S_TYPE unsigned long long int
#define FILE_MAX_SIZE (1<<24)
extern const UID_CID_TYPE uid_array[1<<UID_CID_BITS];
UID_UID_TYPE uid_inv(const UID_CID_TYPE a);
#endif
