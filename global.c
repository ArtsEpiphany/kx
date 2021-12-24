#include"global.h"
const UID_CID_TYPE uid_array[1<<UID_CID_BITS]=
{
	'0',
	'1',
	'2',
	'3',
	'4',
	'5',
	'6',
	'7',
	'8',
	'9',
	'a',
	'b',
	'c',
	'd',
	'e',
	'f'
};
UID_UID_TYPE uid_inv(const UID_CID_TYPE a)
{
	if((a>='0')&&(a<='9'))
		return (UID_UID_TYPE)(a-'0');
	else
		return (UID_UID_TYPE)(a-'a'+10);
}
